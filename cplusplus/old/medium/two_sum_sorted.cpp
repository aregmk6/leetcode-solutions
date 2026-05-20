#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        auto l_it = numbers.begin();
        auto r_it = numbers.end() - 1;

        while (l_it != r_it) {
            if (*l_it + *r_it == target)
                return vector<int>{static_cast<int>(l_it - numbers.begin()) + 1,
                                   static_cast<int>(r_it - numbers.begin()) +
                                       1};

            if (*l_it + *r_it < target) {
                l_it++;
            } else {
                r_it--;
            }
        }

        return {};
    }
};

int main() {
    Solution sol;
    vector<int> numbers = {1, 4, 5, 6, 10, 11, 20};
    int target = 14;

    auto ans = sol.twoSum(numbers, target);

    for (const auto &n : ans) {
        cout << n << ' ';
    }

    cout << endl;

    return 0;
}
