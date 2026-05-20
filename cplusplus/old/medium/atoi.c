#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int isAlpha(char c) {
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '.') return 1;
    return 0;
}

int myAtoi(char *s) {
    char *start = s, *end;
    int len, mul, num_start = 0, ret = 0, sign = 1;

    while (*start) {
        if (isAlpha(*start) || (*start == ' ' && num_start)) {
            return 0;
        } else if (*start == '+' || *start == '-') {
            if (!num_start)
                num_start = 1;
            else
                return 0;
            if (*start == '-') sign = -1;
        } else if (*start >= '0' && *start <= '9') {
            if (*start == '0') {
                if (!num_start) num_start = 1;
            } else {
                break;
            }
        }

        start++;
    }

    end = start;

    while (*end) {
        if (!(*end >= '0' && *end <= '9')) {
            *end = 0;
            break;
        }

        end++;
    }

    len = strlen(start);

    if (len > 10 || (len == 10 && *start > '2')) {
        return (sign == 1) ? INT_MAX : INT_MIN;
    }
    mul = pow(10, len - 1);

    while (*start) {
        if (ret > INT_MAX - (*start - '0') * mul) {
            return (sign == 1) ? INT_MAX : INT_MIN;
        }
        ret += (*start - '0') * mul;
        mul /= 10;

        start++;
    }

    return ret * sign;
}

int main() {
    char s[] = "2147483646";

    printf("%d", myAtoi(s));

    return 0;
}
