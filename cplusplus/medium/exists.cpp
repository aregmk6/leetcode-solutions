#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution
{
    struct Point {
        int row;
        int col;
        int last_idx;
    };

    stack<Point, vector<Point>> stk;

    bool findWord(Point p, vector<vector<char>>& board, string& word,
                  vector<bool>& in_stk, int width, int height)
    {
        stk.push(p);
        in_stk[width * p.row + p.col] = true;
        while (!stk.empty()) {
        cont:
            Point& curp = stk.top();
            int cur_ch  = stk.size();

            for (; curp.last_idx < 4; ++curp.last_idx) {
                switch (curp.last_idx) {
                case 0:
                    if (curp.col + 1 < width &&
                        board[curp.row][curp.col + 1] == word[cur_ch] &&
                        in_stk[width * curp.row + curp.col + 1] == false) {
                        ++curp.last_idx;
                        Point new_p{curp.row, curp.col + 1};
                        in_stk[width * curp.row + curp.col] = true;
                        stk.push(new_p);

                        if (cur_ch + 1 < word.size()) {
                            goto cont;
                        }

                        return true;
                    }
                    break;
                case 1:
                    if (curp.col - 1 >= 0 &&
                        board[curp.row][curp.col - 1] == word[cur_ch] &&
                        in_stk[width * curp.row + curp.col - 1] == false) {
                        ++curp.last_idx;
                        Point new_p{curp.row, curp.col - 1};
                        in_stk[width * curp.row + curp.col] = true;
                        stk.push(new_p);

                        if (cur_ch + 1 < word.size()) {
                            goto cont;
                        }
                        return true;
                    }
                    break;
                case 2:
                    if (curp.row + 1 < height &&
                        board[curp.row + 1][curp.col] == word[cur_ch] &&
                        in_stk[width * (curp.row + 1) + curp.col] == false) {
                        ++curp.last_idx;
                        Point new_p{curp.row + 1, curp.col};
                        in_stk[width * curp.row + curp.col] = true;
                        stk.push(new_p);

                        if (cur_ch + 1 < word.size()) {
                            goto cont;
                        }
                        return true;
                    }
                    break;
                case 3:
                    if (curp.row - 1 >= 0 &&
                        board[curp.row - 1][curp.col] == word[cur_ch] &&
                        in_stk[width * (curp.row - 1) + curp.col] == false) {
                        ++curp.last_idx;
                        Point new_p{curp.row - 1, curp.col};
                        in_stk[width * curp.row + curp.col] = true;
                        stk.push(new_p);

                        if (cur_ch + 1 < word.size()) {
                            goto cont;
                        }
                        return true;
                    }
                    break;
                }
            }

            stk.pop();
            in_stk[width * curp.row + curp.col] = false;
        }

        return false;
    }

  public:
    bool exist(vector<vector<char>>& board, string word)
    {
        if (word.empty()) {
            return false;
        }

        if (word.size() == 1) {
            for (const auto& vec_row : board) {
                for (const auto& c : vec_row) {
                    if (c == word[0]) {
                        return true;
                    }
                }
            }

            return false;
        }

        int width  = board[0].size();
        int height = board.size();

        vector<bool> in_stk(board[0].size() * board.size());

        int row = 0;
        for (const auto& vec_row : board) {
            int col = 0;
            for (const auto& c : vec_row) {
                if (c == word[0]) {
                    if (findWord({row, col}, board, word, in_stk, width,
                                 height)) {
                        return true;
                    }
                }
                ++col;
            }
            ++row;
        }

        return false;
    }
};

int main()
{
    Solution s;
    vector<vector<char>> board{
        {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}}};

    cout << s.exist(board, "ABCB") << endl;

    return 0;
}
