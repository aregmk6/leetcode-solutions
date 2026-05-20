#include <iostream>
#include <vector>

using std::vector;

class Solution {
  public:
    int removeDuplicates(vector<int> &nums) {
        int prev = nums[0];
        for (auto it = nums.begin() + 1; it != nums.end();) {
            if (prev != *it) {
                prev = *it;
                ++it;
                continue;
            }

            int count = 0;
            while (prev == *it) {
                ++count;
                if (count >= 2) break;
                ++it;
            }
            if (it == nums.end()) break;

            while (count >= 2 && *it == prev && it != nums.end()) {
                it = nums.erase(it);
            }

            if (it == nums.end()) break;

            prev = *it;
            ++it;
        }

        return nums.size();
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 1, 1};
    std::cout << sol.removeDuplicates(nums) << std::endl;

    return 0;
}
