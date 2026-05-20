/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume
 * caller calls free().
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HIST_SIZE 'z' - 'a' + 1

int *createHist() {
    int *hist = (int *)malloc(sizeof(int) * (HIST_SIZE));
    return hist;
}

void fillHist(char *s, int *hist) {
    while (*s) {
        hist[*s - 'a'] += 1;
        s++;
    }
}

void clearHist(int *hist) {
    memset(hist, 0, sizeof(int) * (HIST_SIZE));
}

bool isAnagram(int *hist1, int *hist2) {
    for (int i = 0; i < HIST_SIZE; i++) {
        if (hist1[i] != hist2[i]) return false;
    }

    return true;
}

char ***groupAnagrams(char **strs, int strsSize, int *returnSize,
                      int **returnColumnSizes) {
    char ***ret = (char ***)malloc(sizeof(char **) * strsSize);
    bool *done_strs = (bool *)malloc(sizeof(bool) * strsSize);
    memset(done_strs, 0, sizeof(bool) * strsSize);
    int *column_sizes = (int *)malloc(sizeof(int) * strsSize);

    int *hist1 = createHist();
    int *hist2 = createHist();

    int inner_count;
    int group_count = 0;
    bool res;
    for (int i = 0; i < strsSize; i++) {
        if (done_strs[i]) continue;
        clearHist(hist1);
        fillHist(strs[i], hist1);
        char **str_group = (char **)malloc(sizeof(char *) * strsSize);
        str_group[0] = strs[i];
        inner_count = 1;
        done_strs[i] = true;
        for (int j = 0; j < strsSize; j++) {
            if (i == j || done_strs[j]) continue;
            clearHist(hist2);
            fillHist(strs[j], hist2);
            res = isAnagram(hist1, hist2);

            if (res) {
                done_strs[j] = true;
                str_group[inner_count] = strs[j];
                inner_count++;
            }
        }

        column_sizes[group_count] = inner_count;

        ret[group_count] = str_group;
        group_count++;
    }

    *returnColumnSizes = column_sizes;
    *returnSize = group_count;
    return ret;
}

int main() {
    char *strs[] = {"eat", "tea", "tan", "ate", "nat", "bat"};
    int strsSize = 6;

    int returnSize;
    int *returnColumnSizes;

    char ***ret =
        groupAnagrams(strs, strsSize, &returnSize, &returnColumnSizes);

    for (int i = 0; i < returnSize; i++) {
        printf("[ ");
        for (int j = 0; j < returnColumnSizes[i]; j++) {
            printf("%s ", ret[i][j]);
        }
        printf("]");
    }

    printf("\n");

    return 0;
}
