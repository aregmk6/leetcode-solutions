#include <iostream>
#include <stack>
#include <string>
#include <vector>

using std::stack;
using std::string;
using std::vector;

enum class OP { ADD, SUB, MUL, DIV, NONE };

class Solution {
    void double_pop(stack<int> &s, int &first, int &second) {
        first = s.top();
        s.pop();
        second = s.top();
        s.pop();
    }

  public:
    int evalRPN(vector<string> &tokens) {
        stack<int> s;
        int first, second;

        for (const auto &t : tokens) {
            switch (t[0]) {
            case '+':
                double_pop(s, first, second);
                s.push(second + first);
                break;
            case '-':
                if (t[1]) goto fallback;
                double_pop(s, first, second);
                s.push(second - first);
                break;
            case '/':
                double_pop(s, first, second);
                s.push(second / first);
                break;
            case '*':
                double_pop(s, first, second);
                s.push(second * first);
                break;
            default:
            fallback:
                s.push(std::stoi(t));
                break;
            }
        }

        return s.top();
    }
};

int main() {
    Solution sol;
    vector<string> tokens = {
        "10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    std::cout << sol.evalRPN(tokens) << std::endl;
    return 0;
}
