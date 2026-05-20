#include <array>
#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class Solution
{
    struct Trie {
        struct Node {
            // $ for end of string and NULL for nothing
            static constexpr int sigma = 'z' - 'a' + 2;

            array<unique_ptr<Node>, sigma> sons;

            char getNextChar(char start) const
            {
                for (int i = start - 'a'; i < sons.size() - 1; ++i) {
                    if (sons[i]) {
                        return i + 'a';
                    }
                }
                return '$';
            }
        };

        unique_ptr<Node> root;

        void rec(const string& str, int str_idx, unique_ptr<Node> node)
        {
            if (str_idx == str.size()) {
                node->sons[Node::sigma - 1] = make_unique<Node>();
                return;
            }

            int index         = str[str_idx] - 'a';
            node->sons[index] = make_unique<Node>();
        }

        void addString(const string& str)
        {
        }
    };

  public:
    bool wordBreak(string s, vector<string>& wordDict)
    {
    }
};
