#include <iostream>
#include <vector>

using std::vector;

class Solution {
  public:
    void rotate(vector<int> &nums, int k) {
        k = k % nums.size();
        if (k == 0) return;

        vector<int> helper(k);
        int count = 0, temp;

        for (auto it = nums.begin(); it != nums.end(); ++it) {
            helper[count++] = *it;
            if (count >= k) break;
        }

        count = 0;
        for (auto it_src = nums.begin(), it_dst = nums.begin() + k;
             it_dst != nums.end();
             ++it_src, ++it_dst) {

            temp = *it_dst;
            *it_dst = helper[count];
            helper[count] = temp;

            count = (count + 1) % k;
        }

        for (auto it = nums.begin(); it != nums.begin() + k; ++it) {
            *it = helper[count];
            count = (count + 1) % k;
        }
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;
    sol.rotate(nums, k);

    for (const auto &n : nums) {
        std::cout << n << ' ';
    }
    std::cout << std::endl;

    return 0;
}
