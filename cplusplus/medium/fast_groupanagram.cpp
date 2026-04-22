#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

constexpr int ALPH = 'z' - 'a' + 1;

struct hist {
    static constexpr int size = ALPH;
    int *data = new int[size];

    hist(const string &str) {
        for (const auto &ch : str) {
            data[ch - 'a'] += 1;
        }
    }

    bool operator==(const hist &other) const {
        for (int i = 0; i < ALPH; i++) {
            if (this->data[i] != other.data[i]) return false;
        }
        return true;
    }

    const int &operator[](int index) const {
        return data[index];
    }
};

struct entry {
    const string *str;
    hist str_hist;

    entry(const string &_str) : str(&_str), str_hist(_str) {}

    bool operator==(const entry &other) const {
        return this->str_hist == other.str_hist;
    }
};

struct item_hash {
    size_t operator()(const hist &str_hist) const {
        int m = 2;
        size_t p = 1;
        size_t sum = 0;
        for (int i = 0; i < ALPH; i++) {
            sum += str_hist[i] * p;
            p *= m;
        }
        return sum;
    }
};

class Solution {
  public:
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        unordered_map<hist, vector<string>, item_hash> map{};

        for (const auto &str : strs) {
            entry new_ent(str);
            auto it = map.find(new_ent.str_hist);
            if (it == map.end()) {
                map.emplace(                       //
                    new_ent.str_hist,              //
                    vector<string>{*new_ent.str}); //
            } else {
                it->second.push_back(*new_ent.str);
            }
        }

        vector<vector<string>> ret;
        for (const auto &item : map) {
            ret.push_back(std::move(item.second));
        }

        return ret;
    }
};

int main() {

    Solution sol;
    auto strs = vector<string>{"eat", "tea", "tan", "ate", "nat", "bat"};

    auto ans = sol.groupAnagrams(strs);

    for (const auto &vec : ans) {
        cout << "[ ";
        for (const auto &str : vec) {
            cout << str << ' ';
        }
        cout << "]" << endl;
    }

    printf("\n");

    return 0;
}
