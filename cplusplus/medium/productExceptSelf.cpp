#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<int> productExceptSelf(vector<int> &nums) {
        vector<int> left_prod_vec{};
        vector<int> right_prod_vec{};
        vector<int> ret{};
        ret.reserve(nums.size());
        left_prod_vec.reserve(nums.size());
        right_prod_vec.reserve(nums.size());

        for (int i = 0; i < nums.size(); i++) {
            if (i == 0) {
                left_prod_vec.push_back(nums[i]);
                right_prod_vec.push_back(nums[nums.size() - 1 - i]);
            } else {
                left_prod_vec.push_back(nums[i] * left_prod_vec[i - 1]);
                right_prod_vec.push_back(nums[nums.size() - 1 - i] *
                                         right_prod_vec[i - 1]);
            }
        }

        for (int i = 0; i < nums.size(); i++) {
            if (i == 0)
                ret.push_back(right_prod_vec[nums.size() - i - 2]);
            else if (i == nums.size() - 1)
                ret.push_back(left_prod_vec[i - 1]);
            else
                ret.push_back(left_prod_vec[i - 1] *
                              right_prod_vec[nums.size() - i - 2]);
        }

        return ret;
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 4};
    Solution sol;
    auto ans = sol.productExceptSelf(nums);

    for (const auto &num : ans) {
        cout << num << ' ';
    }
    cout << endl;

    return 0;
}
