#include <iostream>
#include <stack>
#include <vector>

using std::stack;
using std::vector;

struct temp {
    int val;
    int dist;
};

class Solution {
  public:
    vector<int> dailyTemperatures(vector<int> &temperatures) {
        stack<temp, vector<temp>> s{};
        vector<int> ret{};
        ret.resize(temperatures.size());
        int dist = 0;
        for (auto it = temperatures.begin(); it != temperatures.end();) {
            if (!s.empty()) {
                if (*it > s.top().val) {
                    ret[s.top().dist] = dist - s.top().dist;
                    s.pop();
                    continue;
                }
            }
            s.push(temp{*it, dist});
            ++dist;
            ++it;
        }
        return ret;
    }
};

int main() {
    Solution sol;
    vector<int> temps{73, 74, 75, 71, 69, 72, 76, 73};
    auto ret = sol.dailyTemperatures(temps);
    for (const auto &num : ret) {
        std::cout << num << ' ';
    }
    std::cout << std::endl;

    return 0;
}
