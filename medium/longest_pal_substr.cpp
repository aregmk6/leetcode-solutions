#include <iostream>
#include <string>

using namespace std;

class Solution {
  public:
    string longestPalindrome(string s) {
        int m = 0, l = 0, r = 0, max = 1, ans_l = 0, ans_r = 0;
        int len = s.size();
        while (m < len) {
            for (int i = 0; i < 2; i++) {
                l = r = m;
                if (i % 2 != 0) {
                    r++;
                    if (s[l] != s[r]) break;
                }

                while (s[l] == s[r] && !(l - 1 < 0 || r + 1 >= len)) {
                    l--;
                    r++;
                }

                if (s[l] != s[r]) l++, r--;

                if (r - l + 1 > max) {
                    max = r - l + 1;
                    ans_l = l;
                    ans_r = r;
                }
            }

            m++;
        }

        return s.substr(ans_l, ans_r - ans_l + 1);
    }
};

int main() {
    Solution sol;
    cout << sol.longestPalindrome("cbbd") << endl;

    return 0;
}
