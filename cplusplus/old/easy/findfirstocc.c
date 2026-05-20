#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *buildLPS(char *pat) {
    int size = strlen(pat);
    int len = 0;
    int *LPS = (int *)malloc(sizeof(int) * size);
    LPS[0] = 0;

    for (int i = 1; i < size; i++) {
        if (pat[i] == pat[len]) {
            LPS[i] = ++len;
        } else {
            if (len == 0) {
                LPS[i] = len;
            } else {
                while (len >= 0) {
                    len = LPS[len - 1];
                    if (pat[i] == pat[len]) {
                        LPS[i] = ++len;
                        break;
                    }
                    if (len == 0) {
                        LPS[i] = len;
                        break;
                    }
                }
            }
        }
    }

    return LPS;
}

int strStr(char *haystack, char *needle) {
    int needle_len = strlen(needle);
    int *LPS_ptr = buildLPS(needle);
    int *LPS = LPS_ptr;

    int needle_idx = 0;
    int hay_idx = 0;
    int count = 0;

    while (haystack[hay_idx]) {
        if (haystack[hay_idx] == needle[needle_idx]) {
            if (++count >= needle_len) {
                free(LPS_ptr);
                return hay_idx - needle_len + 1;
            }
            hay_idx++, needle_idx++;
        } else if (needle_idx) {
            count = needle_idx = LPS[needle_idx - 1];
        } else {
            hay_idx++;
        }
    }

    free(LPS_ptr);
    return -1;
}

int main() {
    char haystack[] = "mississippi";
    char needle[] = "issip";
    printf("%d\n", strStr(haystack, needle));

    return 0;
}

// "sadbuttrue"
// but
