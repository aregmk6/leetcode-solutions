#include <cstdlib>
#include <iostream>
#include <string>
#include <string_view>
#include <vector>

using namespace std;

class Solution
{
    inline static constexpr string_view letters[] = {
        "abc",  // 2
        "def",  // 3
        "ghi",  // 4
        "jkl",  // 5
        "mno",  // 6
        "pqrs", // 7
        "tuv",  // 8
        "wxyz", // 9
    };

    static void rec(vector<string>& res, const vector<int>& nums, int idx,
                    string& cur_str)
    {
        if (idx >= nums.size()) {
            res.push_back(cur_str);
            cur_str.pop_back();
            return;
        }

        int num = nums[idx];
        for (char c : letters[num - 2]) {
            cur_str.push_back(c);
            rec(res, nums, idx + 1, cur_str);
        }

        if (!cur_str.empty()) {
            cur_str.pop_back();
        }
    }

  public:
    vector<string> letterCombinations(string digits)
    {
        if (digits.empty()) {
            return {};
        }

        vector<string> res{};

        vector<int> nums{};
        for (char c : digits) {
            nums.push_back(static_cast<int>(c - '0'));
        }

        string str_base{};

        rec(res, nums, 0, str_base);

        return res;
    }
};

int main()
{

    Solution s{};
    auto res = s.letterCombinations("23");

    return 0;
}
