#include <stdbool.h>
#include <stdio.h>

bool isPalindrome(int x) {
    if (x < 0) return false;

    int t = x, mul = 1;
    int r_opp = 10;
    int l_opp;
    int r, l;
    while (t) {
        t /= 10;
        if (t != 0) mul *= 10;
    }

    t = x;
    l_opp = mul;

    while (t) {
        r = t % r_opp;
        l = t / l_opp;

        if (r != l) return false;

        t %= l_opp;
        t /= r_opp;

        l_opp /= 100;
    }

    return true;
}

int main() {
    printf("%d", isPalindrome(121));
    return 0;
}

// 12321
