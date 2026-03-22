#include <iostream>
#include <string>

using namespace std;

constexpr char NONE = 'n';

class Solution {
    bool rec(const char *str, char opening, size_t str_size, size_t *index) {

        while (*index < str_size) {
            char c = str[*index];
            (*index)++;
            switch (c) {
            case '(':
                if (!rec(str, '(', str_size, index)) return false;
                break;
            case '[':
                if (!rec(str, '[', str_size, index)) return false;
                break;
            case '{':
                if (!rec(str, '{', str_size, index)) return false;
                break;
            case ')':
                return opening == '(' ? true : false;
            case ']':
                return opening == '[' ? true : false;
            case '}':
                return opening == '{' ? true : false;
            }
        }

        return opening == NONE ? true : false;
    }

  public:
    bool isValid(string s) {
        size_t index = 0;
        if (s.size() <= 1) return false;

        return rec(s.c_str(), NONE, s.size(), &index);
    }
};

int main() {
    Solution sol;
    cout << sol.isValid("((") << endl;
    return 0;
}
