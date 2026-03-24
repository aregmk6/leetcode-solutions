#include <iostream>
#include <vector>

using std::vector;

class Solution {
  public:
    int search(vector<int> &nums, int target) {
        int left = 0, right = nums.size() - 1, logical_mid, mid, offset;

        while (left <= right) {
            logical_mid = (left + right) / 2;

            if (logical_mid - 1 >= 0 &&
                (nums[logical_mid - 1] > nums[logical_mid]))
                break;
            if (nums[logical_mid] > nums[right]) {
                left = logical_mid + 1;
            } else {
                right = logical_mid - 1;
            }
        }

        offset = nums.size() - logical_mid;
        left = 0;
        right = nums.size() - 1;
        while (left <= right) {
            mid = ((left + right) / 2);
            logical_mid =
                mid - offset < 0 ? nums.size() + (mid - offset) : mid - offset;

            if (nums[logical_mid] == target) return logical_mid;
            if (nums[logical_mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }

        return -1;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {1};
    int target = 0;

    std::cout << sol.search(nums, target) << std::endl;

    return 0;
}
