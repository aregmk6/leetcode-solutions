#include <iostream>
#include <string>
#include <vector>

using namespace std;

// can make this faster with a histogram
class Solution {
  public:
    int lengthOfLongestSubstring(string s) {
        vector<char> seen_chars{};
        int left = 0;
        int right = 0;

        int cur_size = 0;
        int max_size = s.empty() ? 0 : 1;

        while (s[right] != '\0') {
            char new_char = s[right];
            for (int i = 0; i < seen_chars.size(); i++) {
                if (seen_chars[i] == s[right]) {
                    /* move left past the repeating char */
                    while (s[left] != new_char) {
                        for (auto it = seen_chars.begin();
                             it != seen_chars.end();
                             it++) {
                            if (*it == s[left]) {
                                seen_chars.erase(it);
                                break;
                            }
                        }

                        left++;
                    }

                    left++;

                    /* earse repeating char */
                    for (auto it = seen_chars.begin(); it != seen_chars.end();
                         it++) {
                        if (*it == s[right]) {
                            seen_chars.erase(it);
                            break;
                        }
                    }
                }
            }
            cur_size = right - left + 1;
            if (cur_size > max_size) {
                max_size = cur_size;
            }
            seen_chars.push_back(new_char);
            right++;
        }

        return max_size;
    }
};

int main() {
    Solution sol;
    cout << sol.lengthOfLongestSubstring("tmmzuxt") << endl;
}
