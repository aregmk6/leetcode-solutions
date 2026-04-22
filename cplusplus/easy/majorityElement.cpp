#include <vector>

using std::vector;

class Solution {
  public:
    int majorityElement(vector<int> &nums) {
        int candidate, votes = 0, count = 0;
        for (const auto &n : nums) {
            if (votes == 0) {
                candidate = n;
                ++votes;
                continue;
            }

            if (candidate == n)
                ++votes;
            else
                --votes;
        }

        return candidate;
    }
};
