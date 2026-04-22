#include <array>
#include <iostream>
#include <vector>

using namespace std;

constexpr int NUM_ROWS = 9;
constexpr int NUM_COLS = 9;
constexpr int NUM_REC = 9;
constexpr int NUMS = 9;
constexpr int NUMS_IN_REC = 3;

class Solution {
  public:
    bool isValidSudoku(vector<vector<char>> &board) {
        array<array<bool, NUMS>, NUM_ROWS + NUM_COLS> rw_cl_arr = {0};
        array<array<bool, NUMS>, NUM_REC> rec_arr = {0};

        int cur_block = -1;
        int block_row = -1;
        int cur_num;
        for (int row = 0; row < board.size(); row++) {
            bool new_row = true;
            for (int col = 0; col < board[row].size(); col++) {
                if (new_row && row % NUMS_IN_REC == 0) {
                    new_row = false;
                    block_row++;
                }

                if (col % NUMS_IN_REC == 0) {
                    cur_block = ((cur_block + 1) % NUMS_IN_REC) //
                                + NUMS_IN_REC * block_row;      //
                }

                if (board[row][col] == '.') continue;

                cur_num = board[row][col] - '0' - 1;

                if (rec_arr[cur_block][cur_num] ||        //
                    rw_cl_arr[row][cur_num] ||            //
                    rw_cl_arr[col + NUM_ROWS][cur_num]) { //
                    return false;
                }

                rec_arr[cur_block][cur_num] = true;
                rw_cl_arr[row][cur_num] = true;
                rw_cl_arr[col + NUM_ROWS][cur_num] = true;
            }
        }

        return true;
    }
};

int main() {
    Solution sol;

    vector<vector<char>> board{{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                               {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                               {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                               {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                               {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                               {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                               {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                               {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                               {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    bool ret = sol.isValidSudoku(board);

    cout << ret << endl;

    return 0;
}
