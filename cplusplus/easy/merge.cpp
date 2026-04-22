#include <vector>

using std::vector;

class Solution {
  public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
        int i1, i2, i3;
        vector<int> temp(n + m);
        for (i1 = i2 = i3 = 0; i1 < m && i2 < n; ++i3) {
            if (nums1[i1] < nums2[i2]) {
                temp[i3] = nums1[i1];
                ++i1;
            } else {
                temp[i3] = nums2[i2];
                ++i2;
            }
        }
        for (; i1 < m; ++i1, ++i3) {
            temp[i3] = nums1[i1];
        }
        for (; i2 < n; ++i2, ++i3) {
            temp[i3] = nums2[i2];
        }

        nums1 = temp;
    }
};
