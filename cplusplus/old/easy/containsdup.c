#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// O(nlog(n)) solution.
// but with extra space.

void merge(int *nums1, int *nums2, int numsSize1, int numsSize2) {
    int *tempNums = (int *)malloc(sizeof(int) * (numsSize1 + numsSize2));
    int i1, i2, i3;

    for (i1 = 0, i2 = 0, i3 = 0; i1 < numsSize1 && i2 < numsSize2; i3++) {
        if (nums1[i1] < nums2[i2]) {
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

void mergeSort(int *nums, int left, int right) {
    if (left >= right) {
        return;
    }
    int mid = left + (right - left) / 2;
    mergeSort(nums, left, mid);
    mergeSort(nums, mid + 1, right);

    merge(nums + left, nums + mid + 1, mid - left + 1, right - mid);
}

bool containsDuplicate(int *nums, int numsSize) {
    mergeSort(nums, 0, numsSize - 1);

    int j = 0;
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] == nums[j]) return true;
        j = i;
    }

    return false;
}

void printA(int *a, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main() {
    int nums[] = {1, 4, 52, 3, 42, 1};
    int size = sizeof(nums) / sizeof(nums[0]);

    printA(nums, size);

    printf("%d\n", containsDuplicate(nums, size));

    printA(nums, size);

    return 0;
}
