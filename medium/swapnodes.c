#include <stdio.h>
#include <stdlib.h>
struct ListNode {
    int val;
    struct ListNode *next;
};

typedef struct ListNode Node;

struct ListNode *swapNodes(struct ListNode *head, int k) {
    if (!head->next) return head;

    Node *target_1 = head;
    Node *prev_1 = NULL;

    for (int i = 1; i < k; i++) {
        if (!target_1) return head;
        prev_1 = target_1;
        target_1 = target_1->next;
    }

    Node *end_helper = target_1;
    Node *target_2 = head;
    Node *prev_2 = NULL;

    while (end_helper->next) {
        prev_2 = target_2;
        target_2 = target_2->next;
        end_helper = end_helper->next;
    }

    // both targets and prevs are in place

    Node *new_next_for_target_2 = target_1->next;
    if (new_next_for_target_2 == target_2) {
        new_next_for_target_2 = target_1;
    }
    Node *new_next_for_target_1 = target_2->next;
    if (new_next_for_target_1 == target_1) {
        new_next_for_target_1 = target_2;
    }

    if (prev_1)
        prev_1->next = target_2;
    else
        head = target_2;
    target_2->next = new_next_for_target_2;

    if (prev_2)
        prev_2->next = target_1;
    else
        head = target_1;
    target_1->next = new_next_for_target_1;

    return head;
}

void printList(Node *head) {
    Node *cur = head;
    while (cur) {
        printf("%d", cur->val);
        cur = cur->next;
    }
    printf("\n");
}

int main() {
    Node *head = (Node *)malloc(sizeof(Node));
    Node *cur = head;
    int size = 3;
    for (int i = 1; i < size; i++) {
        cur->val = i;
        if (i + 1 == size) {
            cur->next = NULL;
            break;
        }
        cur->next = (Node *)malloc(sizeof(Node));
        cur = cur->next;
    }

    printList(head);

    Node *new_head = swapNodes(head, 2);

    cur = new_head;
    while (cur) {
        printf("%d", cur->val);
        cur = cur->next;
    }
    printf("\n");

    return 0;
}
