#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

typedef struct ListNode Node;

struct ListNode *reverseKGroup(struct ListNode *head, int k) {
    if (!head) return NULL;
    if (!head->next || k == 0 || k == 1) return head;

    Node *cur = head;
    Node *next = head->next;
    Node *prev = NULL;
    Node *prev_g = NULL;
    Node *next_g = head;
    Node *checker;
    Node *ret = head;

    int count = 0;
    int check_counter = 0;
    int flag = 1;

    while (cur) {

        if (count == 0) {
            checker = cur;
            while (checker && check_counter < k) {
                checker = checker->next;
                check_counter++;
            }

            if (check_counter < k) {
                if (prev_g) prev_g->next = next_g;
                flag = 0;
                break;
            }
            check_counter = 0;
        }

        if (count >= k - 1) {
            // connect groups
            if (prev_g) {
                prev_g->next = cur;
                prev_g = next_g;
                next_g = cur->next;
            } else {
                ret = cur;
                prev_g = next_g;
                next_g = cur->next;
            }
        }

        cur->next = prev;
        prev = cur;
        cur = next;
        if (next) next = next->next;

        count = (count + 1) % k;
    }

    if (flag) prev_g->next = NULL;
    return ret;
}

// 1 -> 2 -> 3 -> 4 -> 5

int main() {
    Node *head = (Node *)malloc(sizeof(Node));
    Node *cur = head;
    int size = 7;
    for (int i = 1; i < size; i++) {
        cur->val = i;
        if (i + 1 == size) {
            cur->next = NULL;
            break;
        }
        cur->next = (Node *)malloc(sizeof(Node));
        cur = cur->next;
    }

    cur = head;
    while (cur) {
        printf("%d", cur->val);
        cur = cur->next;
    }
    printf("\n");

    Node *new_head = reverseKGroup(head, 2);

    cur = new_head;
    while (cur) {
        printf("%d", cur->val);
        cur = cur->next;
    }
    printf("\n");

    return 0;
}
