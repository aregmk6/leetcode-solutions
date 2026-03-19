#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *longestCommonPrefix(char **strs, int strsSize) {
    int count = 0, first = 1, done = 0;
    char c;
    while (1) {
        for (int i = 0; i < strsSize; i++) {
            if (strs[i][count] != 0) {
                if (first) {
                    c = strs[i][count];
                    first = 0;
                } else if (strs[i][count] != c) {
                    done = 1;
                    break;
                }
            } else {
                done = 1;
                break;
            }
        }

        if (done) {
            break;
        }
        first = 1;
        count++;
    }
    char *ret = (char *)malloc(sizeof(char) * (count + 1));
    memcpy(ret, strs[0], count);
    ret[count] = 0;

    return ret;
}

int main() {
    char *strs[] = {"flower", "flow", "flight"};
    char *str = longestCommonPrefix(strs, 3);

    printf("%s", str);

    return 0;
}
