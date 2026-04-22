#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
  public:
    int longestConsecutive(vector<int> &nums) {
        unordered_set<int> table{};
        for (const auto &num : nums) {
            table.insert(num);
        }

        int max = 0, count = 0;
        for (auto it = table.begin(); it != table.end(); ++it) {
            int cur_val = *it;
            auto prev_it = table.find(cur_val - 1);
            if (prev_it != table.end()) {
                continue;
            }

            count = 1;

            auto next = table.find(cur_val + 1);
            while (next != table.end()) {
                count++;
                next = table.find(*next + 1);
            }

            if (count > max) max = count;
        }

        return max;
    }
};

int main() {
    Solution sol;
    vector<int> target{0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    int ret = sol.longestConsecutive(target);
    cout << ret << endl;

    return 0;
}
