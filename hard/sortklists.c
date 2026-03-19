#include <math.h>
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

typedef struct ListNode ListNode;

typedef struct List {
    ListNode *head;
    ListNode *tail;
} List;

void insert(List *list, int val) {
    ListNode *newNode = (ListNode *)malloc(sizeof(ListNode));
    newNode->val = val;
    newNode->next = NULL;
    if (!list->head) {
        list->head = list->tail = newNode;
    } else {
        list->tail->next = newNode;
        list->tail = newNode;
    }
}

int getSize(ListNode *listHead) {
    int count = 0;
    while (listHead) {
        listHead = listHead->next;
        count++;
    }

    return count;
}

void fill(ListNode *listhead, int *heap) {
    int i = 0;
    while (listhead) {
        heap[i++] = listhead->val;
        listhead = listhead->next;
    }
}

void heapify(int **heap, int targetIdx, int size) {
    int **target = NULL, **lc = NULL, **rc = NULL, **minChild = NULL;
    int childIdx = -1;
    target = heap + targetIdx;

    if (2 * targetIdx + 1 < size) lc = heap + 2 * targetIdx + 1;
    if (2 * targetIdx + 2 < size) rc = heap + 2 * targetIdx + 2;

    if (!lc && !rc) return;

    if (lc && rc) {
        minChild = **lc > **rc ? rc : lc;
        childIdx = **lc > **rc ? 2 * targetIdx + 2 : 2 * targetIdx + 1;
    } else if (!lc) {
        minChild = rc;
        childIdx = 2 * targetIdx + 2;
    } else if (!rc) {
        minChild = lc;
        childIdx = 2 * targetIdx + 1;
    }

    if (*target > *minChild) {
        int **temp = target;
        target = minChild;
        minChild = temp;
        heapify(heap, childIdx, size);
    }
}

void makeMinHeap(int **heap, int size) {
    for (int targetIdx = size / 2 - 1; targetIdx >= 0; targetIdx--) {
        heapify(heap, targetIdx, size);
    }
}

struct ListNode *mergeKLists(struct ListNode **lists, int listsSize) {
    List ret = {0};

    int **listHeaps = (int **)malloc(sizeof(int *) * listsSize);
    int **mainHeap = (int **)malloc(sizeof(int *) * listsSize);

    int finisedHeaps = 0;

    for (int i = 0; i < listsSize; i++) {
        int size;
        size = getSize(lists[i]);
        listHeaps[i] = (int *)malloc(sizeof(int) * size);
        fill(lists[i], listHeaps[i]);
    }

    for (int i = 0; i < listsSize; i++) {
        mainHeap[i] = listHeaps[i];
    }

    makeMinHeap(mainHeap, listsSize);

    while (finisedHeaps < listsSize) {
        // get min listHeap from mainHeap
        // get min val from that listHeap
        // insert the val into the ret list
        // reinsert that listHeap if it's not empty
    }
}
