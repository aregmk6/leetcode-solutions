#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

typedef struct ListNode Node;

void printList(Node *head) {
    while (head) {
        printf("%d", head->val);
        head = head->next;
    }
}

struct ListNode *removeNthFromEnd(struct ListNode *head, int n) {
    if (head == NULL) return NULL;

    Node *victim = head, *start = NULL, *end = head;
    int count = 0;

    while (count < n) {
        if (end) end = end->next;
        count++;
    }

    while (end) {
        end = end->next;
        victim = victim->next;
        if (start)
            start = start->next;
        else
            start = head;
    }

    if (start) {
        start->next = victim->next;
    } else {
        head = victim->next;
    }
    victim->next = NULL;

    free(victim);

    return head;
}

int main() {
    // Manually creating a list: 1 -> 2 -> 3 -> 4 -> 5
    Node *head = (Node *)malloc(sizeof(Node));
    head->val = 1;
    head->next = (Node *)malloc(sizeof(Node));
    head->next->val = 2;
    head->next->next = (Node *)malloc(sizeof(Node));
    head->next->next->val = 3;
    head->next->next->next = (Node *)malloc(sizeof(Node));
    head->next->next->next->val = 4;
    head->next->next->next->next = (Node *)malloc(sizeof(Node));
    head->next->next->next->next->val = 5;
    head->next->next->next->next->next = NULL;

    int n = 2;
    printf("Original list: ");
    printList(head);
    printf("\n");

    printf("insert n: ");
    scanf("%d", &n);

    printf("Removing %d-th node from end...\n", n);
    head = removeNthFromEnd(head, n);

    printf("Resulting list: ");
    printList(head);
    printf("\n");

    return 0;
}
