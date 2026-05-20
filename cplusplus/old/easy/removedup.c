#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int removeDuplicates(int *nums, int numsSize) {
    bool *bin_hist = (bool *)malloc(sizeof(bool) * 201);
    memset(bin_hist, 0, sizeof(bool) * 201);
    int place = 0, count = 0;

    for (int i = 0; i < numsSize; i++) {
        if (!bin_hist[nums[i] + 100]) {
            count++;
            bin_hist[nums[i] + 100] = true;
        }
    }

    for (int i = 0; i < 201; i++) {
        if (bin_hist[i]) {
            nums[place] = i - 100;
            place++;
        }
    }

    free(bin_hist);

    return count;
}

int main() {
    int nums[] = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    int numsSize = sizeof(nums) / sizeof(int);

    printf("%d\n", removeDuplicates(nums, numsSize));
    for (int i = 0; i < sizeof(nums) / sizeof(int); i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    return 0;
}
