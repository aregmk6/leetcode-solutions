#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

constexpr char OPEN = '(';
constexpr char CLOSE = ')';

class Solution {
    void gen(vector<string> &fill, string cur_str, char paran, int open,
             int close) const {
        if (open < 0 || close < 0) {
            return;
        }

        cur_str += paran;

        if (open == 0 && close == 0) fill.push_back(cur_str);

        gen(fill, cur_str, OPEN, open - 1, close);
        if (close - 1 >= open) gen(fill, cur_str, CLOSE, open, close - 1);
    }

  public:
    vector<string> generateParenthesis(int n) {
        vector<string> ret{};
        string cur_str;

        gen(ret, cur_str, OPEN, n - 1, n);

        return ret;
    }
};

int main() {
    Solution sol;
    vector<string> ans = sol.generateParenthesis(3);
    for (const auto &str : ans) {
        std::cout << str << std::endl;
    }

    return 0;
}
