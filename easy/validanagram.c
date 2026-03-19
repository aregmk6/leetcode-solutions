#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int letters = 'z' - 'a' + 1;

int *make_hist(char *s, int len) {
    int *hist = malloc(sizeof(int) * letters);
    memset(hist, 0, sizeof(int) * letters);
    for (int i = 0; i < len; i++) {
        hist[s[i] - 'a'] += 1;
    }

    return hist;
}

bool isAnagram(char *s, char *t) {
    int len1 = strlen(s);
    int len2 = strlen(t);
    if (len1 != len2) return false;

    int *hist1 = make_hist(s, len1);
    int *hist2 = make_hist(t, len2);

    for (int i = 0; i < letters; i++) {
        if (hist1[i] != hist2[i]) return false;
    }

    return true;
}
