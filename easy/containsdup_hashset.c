#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CAP 100000

typedef struct item_h item_h;

struct item_h {
    int val;
    item_h *next;
};

typedef struct Hash {
    item_h **items;
    int size;
    int capacity;
} Hash;

int hashFunction(Hash *table, int num) {
    if (num < 0) num = -num;
    return num % table->capacity;
}

int insert(Hash *table, int val) {
    int index = hashFunction(table, val);
    item_h *cur = table->items[index];
    while (cur) {
        if (cur->val == val) return 0;
        cur = cur->next;
    }
    item_h *new_item = (item_h *)malloc(sizeof(item_h));
    new_item->val = val;
    if (table->items[index]) {
        new_item->next = table->items[index];
    } else {
        new_item->next = NULL;
    }
    table->items[index] = new_item;
    table->size++;

    return 1;
}

Hash *construct_hash() {
    Hash *table = (Hash *)malloc(sizeof(Hash));
    table->items = (item_h **)malloc(sizeof(item_h *) * CAP);
    table->size = 0;
    table->capacity = CAP;
    memset(table->items, 0, sizeof(item_h *) * table->capacity);

    return table;
}

bool containsDuplicate(int *nums, int numsSize) {
    Hash *table = construct_hash();
    for (int i = 0; i < numsSize; i++) {
        if (!insert(table, nums[i])) {
            return true;
        }
    }

    return false;
}

int main() {
    int nums[] = {1, 5, -2, -4, 0};
    int size = sizeof(nums) / sizeof(nums[0]);

    printf("%d\n", containsDuplicate(nums, size));

    return 0;
}
