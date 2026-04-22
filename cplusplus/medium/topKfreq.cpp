#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;
using freq = int;

class Solution {
  public:
    vector<int> topKFrequent(vector<int> &nums, int k) {
        unordered_map<int, freq> hist{};
        vector<pair<int, freq>> helper_vec;

        for (const auto &num : nums) {
            auto it = hist.find(num);
            if (it != hist.end()) {
                it->second++;
            } else {
                hist.insert({num, 1});
            }
        }

        for (auto &p : hist) {
            helper_vec.push_back(std::move(p));
        }

        sort(helper_vec.begin(),
             helper_vec.end(),
             [](const pair<int, freq> &lhs, const pair<int, freq> &rhs) {
                 return lhs.second > rhs.second;
             });

        vector<int> ret{};

        int count = 0;
        for (const auto &p : helper_vec) {
            ret.push_back(p.first);
            count++;
            if (count >= k) break;
        }

        return ret;
    }
};
