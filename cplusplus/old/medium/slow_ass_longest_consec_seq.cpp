#include <iostream>
#include <list>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
  public:
    int longestConsecutive(vector<int> &nums) {
        using seq = list<int>;
        using head = int;
        using tail = int;

        unordered_map<head, seq *> tail_map{};
        unordered_map<tail, seq *> head_map{};

        for (const auto &n : nums) {
            auto tail_it = tail_map.find(n - 1);
            auto head_it = head_map.find(n + 1);
            auto cur_tail_it = tail_map.find(n);
            if (cur_tail_it != tail_map.end()) continue;
            auto cur_head_it = head_map.find(n);
            if (cur_head_it != head_map.end()) continue;

            if (tail_it != tail_map.end()) {
                tail_it->second->push_back(n);
                auto nh = tail_map.extract(tail_it);
                nh.key() += 1;
                tail_map.insert(std::move(nh));
            }

            if (head_it != head_map.end()) {
                cur_tail_it = tail_map.find(n);
                if (cur_tail_it != tail_map.end()) {
                    seq *dest_seq = cur_tail_it->second;
                    seq *src_seq = head_it->second;
                    auto target_head_it = tail_map.find(src_seq->back());
                    target_head_it->second = dest_seq;
                    head_map.erase(head_it);
                    tail_map.erase(cur_tail_it);
                    dest_seq->splice(dest_seq->end(), *src_seq);
                } else {
                    head_it->second->push_front(n);
                    auto nh = head_map.extract(head_it);
                    nh.key() -= 1;
                    head_map.insert(std::move(nh));
                }
            }

            if (head_it == head_map.end() && tail_it == tail_map.end()) {
                seq *new_seq = new seq{n};
                tail_map.insert({n, new_seq});
                head_map.insert({n, new_seq});
            }
        }

        size_t max = 0;
        for (const auto &p : head_map) {
            auto size = p.second->size();
            if (size > max) {
                max = size;
            }
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
