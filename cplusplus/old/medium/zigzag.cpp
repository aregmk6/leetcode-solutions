#include <iostream>
#include <string>

using namespace std;

class Solution {
    class CharNode {

      public:
        char c;
        CharNode *next;
        CharNode(char _c, CharNode *_next = nullptr) : c(_c), next(_next) {}
    };

    class RowStr {
        CharNode *head = nullptr;
        CharNode *tail = nullptr;

      public:
        void insert(char c) {
            CharNode *leaf = new CharNode{c, nullptr};
            if (head == nullptr) {
                tail = head = leaf;
            } else {
                tail->next = leaf;
                tail = leaf;
            }
        }

        string createString() const {
            string ret;
            CharNode *cur = head;
            while (cur != nullptr) {
                ret += cur->c;
                cur = cur->next;
            }
            return ret;
        }
    };

  public:
    string convert(string s, int numRows) {

        if (numRows == 1) return s;

        int cur = 0, row = 0, size = s.size();
        RowStr *root = new RowStr[numRows];
        string ret;

        while (cur < size) {
            for (; row < numRows; row++) {
                if (cur >= size) break;
                root[row].insert(s[cur++]);
            }

            row -= 2;

            for (; row >= 0; row--) {
                if (cur >= size) break;
                root[row].insert(s[cur++]);
            }

            row += 2;
        }

        for (int i = 0; i < numRows; i++) {
            ret += root[i].createString();
        }

        return ret;
    }
};

int main() {
    Solution sol;
    cout << sol.convert("PAYPALISHIRING", 3);

    return 0;
}
