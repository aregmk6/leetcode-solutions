#include <algorithm>
#include <climits>
#include <vector>

using namespace std;

class Solution {

    double median(vector<int> &nums) {
        int rightMid = nums.size() / 2;
        int leftMid = rightMid - 1;
        if (nums.size() % 2 == 0)
            return (double)(nums[leftMid] + nums[rightMid]) / 2;
        return (double)nums[rightMid];
    }

  public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        int left, right, mid1, mid2;
        int l1, r1, l2, r2;

        if (nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2, nums1);

        int size1 = nums1.size();
        int size2 = nums2.size();

        if (nums1.empty()) return median(nums2);
        if (nums2.empty()) return median(nums1);

        left = 0, right = size1;

        while (true) {
            mid1 = (left + right) / 2;
            mid2 = (size1 + size2 + 1) / 2 - mid1;

            l1 = mid1 - 1 < 0 ? INT_MIN : nums1[mid1 - 1];
            r1 = mid1 >= size1 ? INT_MAX : nums1[mid1];
            l2 = mid2 - 1 < 0 ? INT_MIN : nums2[mid2 - 1];
            r2 = mid2 >= size2 ? INT_MAX : nums2[mid2];

            if (l1 > r2) {
                right = mid1 - 1;
            } else if (l2 > r1) {
                left = mid1 + 1;
            } else {
                if (mid1 >= size1) mid1--;
                if (mid2 >= size2) mid2--;
                if ((size1 + size2) % 2 == 0) { // even
                    return (double)(max(l1, l2) + min(r1, r2)) / 2;
                } else { // odd
                    return (double)(max(l1, l2));
                }
            }
        }
    }
};

#include <iostream>

int main() {
    vector<int> nums1 = {2, 2, 4, 4};
    vector<int> nums2 = {2, 2, 2, 4, 4};

    Solution sol;

    double res = sol.findMedianSortedArrays(nums1, nums2);

    cout << res << endl;

    return 0;
}
