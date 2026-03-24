#include <iostream>

constexpr unsigned int FULL_MASK = -1;

class Solution {
  public:
    int divide(int dividend, int divisor) {
        int sign = 0;
        if (dividend == (FULL_MASK << 31)) {
            if (divisor == 1) return FULL_MASK << 31;
            if (divisor == -1) return FULL_MASK >> 1;
        }

        unsigned int u_dividend = static_cast<unsigned int>(dividend);
        unsigned int u_divisor = static_cast<unsigned int>(divisor);

        if (dividend < 0) {
            sign = sign ^ 1;
            u_dividend = u_dividend ^ FULL_MASK;
            u_dividend += 1;
        }
        if (divisor < 0) {
            sign = sign ^ 1;
            u_divisor = u_divisor ^ FULL_MASK;
            u_divisor += 1;
        }

        unsigned int or_helper = (static_cast<unsigned int>(-1) >> 1) + 1;
        unsigned int mask = or_helper;

        unsigned int cur, cur_div;
        unsigned int tmp_ans;
        unsigned int final = 0;
        unsigned int leftover = u_dividend;

        short shift_amnt = 31;
        while (shift_amnt >= 0) {
            cur = leftover & mask;

            cur_div = cur >> shift_amnt;

            if (cur_div >= u_divisor) {
                tmp_ans = 1;
                leftover -= u_divisor << shift_amnt;
            } else {
                tmp_ans = 0;
            }

            final |= tmp_ans;
            final <<= 1;

            // update mask
            mask = (mask >> 1) | or_helper;
            --shift_amnt;
        }

        final >>= 1;

        if (sign) {
            final = final ^ FULL_MASK;
            final += 1;
        }
        return final;
    }
};

int main() {
    Solution sol;
    std::cout << sol.divide(-2147483648, 2) << std::endl;
    return 0;
}
