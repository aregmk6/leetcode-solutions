#include <stdio.h>
#include <stdlib.h>

typedef struct hash_item {
    int val;
    int index;
} pair;

void merge(pair *nums1, pair *nums2, int numsSize1, int numsSize2) {
    pair *tempNums = (pair *)malloc(sizeof(pair) * (numsSize1 + numsSize2));
    int i1, i2, i3;

    for (i1 = 0, i2 = 0, i3 = 0; i1 < numsSize1 && i2 < numsSize2; i3++) {
        if (nums1[i1].val < nums2[i2].val) {
            tempNums[i3] = nums1[i1];
            i1++;
        } else {
            tempNums[i3] = nums2[i2];
            i2++;
        }
    }

    while (i1 < numsSize1) {
        tempNums[i3++] = nums1[i1++];
    }
    while (i2 < numsSize2) {
        tempNums[i3++] = nums2[i2++];
    }

    for (int i = 0; i < (numsSize1 + numsSize2); i++) {
        nums1[i] = tempNums[i];
    }

    free(tempNums);
}

void mergeSort(pair *nums, int left, int right) {
    if (left >= right) {
        return;
    }
    int mid = left + (right - left) / 2;
    mergeSort(nums, left, mid);
    mergeSort(nums, mid + 1, right);

    merge(nums + left, nums + mid + 1, mid - left + 1, right - mid);
}

int binary_search(pair *items, int numsSize, int target) {
    int mid, left = 0, right = numsSize - 1;
    while (left <= right) {
        mid = (left + right) / 2;

        if (items[mid].val == target)
            return mid;
        else if (items[mid].val < target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1;
}

int *twoSum(int *nums, int numsSize, int target, int *returnSize) {
    int *ret = (int *)malloc(sizeof(int) * 2);
    *returnSize = 2;

    pair *items = (pair *)malloc(sizeof(pair) * numsSize);
    for (int i = 0; i < numsSize; i++) {
        items[i].val = nums[i];
        items[i].index = i;
    }

    mergeSort(items, 0, numsSize - 1);

    int res, index;
    for (int i = 0; i < numsSize - 1; i++) {
        res = binary_search(        //
            items + i + 1,          //
            numsSize - i - 1,       //
            target - items[i].val); //
        if (res == -1) continue;

        index = res + i + 1;
        ret[0] = items[i].index;
        ret[1] = items[index].index;
        return ret;
    }

    returnSize = 0;
    return NULL;
}

int main() {
    int retSize;

    int nums[] = {3, 2, 3};
    int size = sizeof(nums) / sizeof(nums[0]);
    int *res = twoSum(nums, size, 6, &retSize);

    for (int i = 0; i < size; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    for (int i = 0; i < retSize; i++) {
        printf("%d ", res[i]);
    }
    printf("\n");

    return 0;
}
