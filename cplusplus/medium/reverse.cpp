#include <climits>
#include <cmath>
#include <iostream>

class Solution {
  public:
    int reverse(int x) {
        if (x < 0) {
            if (x == INT_MIN) return 0;
            return -1 * reverse(-x);
        }

        int t = x, len = 0;
        int mul, ret = 0;
        int nums[10] = {0};

        while (t != 0) {
            nums[len] = t % 10;
            t /= 10;
            len++;
        }

        mul = (int)(pow(10, len - 1));
        for (int i = 0; i < len; i++) {
            if (mul == pow(10, 9) && nums[i] > 2) return 0;
            if (ret > INT_MAX - nums[i] * mul)
                return 0;
            else
                ret += nums[i] * mul;
            mul /= 10;
        }

        return ret;
    }
};

int main() {
    Solution sol;
    std::cout << sol.reverse(1534236469) << std::endl;

    return 0;
}

// 9876
// 9876 % 10 = 6
// 9876 / 10 = 987
// 987 % 10 = 7
// 987 / 10 = 98
// 98 % 10 = 8
// 98 / 10 = 9
// 9 % 10 = 9
// 9 / 10 = 0
