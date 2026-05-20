#include <cctype>
#include <string>
#include <string_view>

using namespace std;

class Solution {
  public:
    bool isPalindrome(string s) {
        string_view window = s;

        while (!window.empty()) {
            char front = window.front();
            char back = window.back();
            if (!isalpha(front) && !isdigit(front)) {
                window.remove_prefix(1);
                continue;
            }
            if (!isalpha(back) && !isdigit(back)) {
                window.remove_suffix(1);
                continue;
            }
            if (tolower(front) != tolower(back)) return false;
            window.remove_prefix(1);
            if (!window.empty()) window.remove_suffix(1);
        }

        return true;
    }
};
