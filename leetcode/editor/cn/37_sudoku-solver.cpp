//编写一个程序，通过填充空格来解决数独问题。 
//
// 数独的解法需 遵循如下规则： 
//
// 
// 数字 1-9 在每一行只能出现一次。 
// 数字 1-9 在每一列只能出现一次。 
// 数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。（请参考示例图） 
// 
//
// 数独部分空格内已填入了数字，空白格用 '.' 表示。 
//
// 
//
// 
// 
// 
// 示例： 
//
// 
//输入：board = [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5","."
//,".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".","."
//,"3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"
//],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],["
//.",".",".",".","8",".",".","7","9"]]
//输出：[["5","3","4","6","7","8","9","1","2"],["6","7","2","1","9","5","3","4","8"
//],["1","9","8","3","4","2","5","6","7"],["8","5","9","7","6","1","4","2","3"],["
//4","2","6","8","5","3","7","9","1"],["7","1","3","9","2","4","8","5","6"],["9","
//6","1","5","3","7","2","8","4"],["2","8","7","4","1","9","6","3","5"],["3","4","
//5","2","8","6","1","7","9"]]
//解释：输入的数独如上图所示，唯一有效的解决方案如下所示：
//
//
// 
//
// 
//
// 提示： 
//
// 
// board.length == 9 
// board[i].length == 9 
// board[i][j] 是一位数字或者 '.' 
// 题目数据 保证 输入数独仅有一个解 
// 
// 
// 
// 
// Related Topics 哈希表 回溯算法 
// 👍 847 👎 0
#include "bits/stdc++.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int solveStep(vector<vector<char>>& board, int i, int j,
                  vector<vector<int>>& dpRow, vector<vector<int>>& dpCol,
                  vector<vector<vector<int>>>& dpBatch) {
        while (i < 9 && j < 9) {
            if (board[i][j] == '.') break;
            if (j+1 < 9) j++;
            else {
                i++; j=0;
            }
        }

        if (i == 9) {
            cout << "^^" << endl;
            return 1;
        }

        // 在i/j处填一个值
        for (int val = 1; val <= 9; val++) {
            if (!dpRow[i][val] && !dpCol[j][val] && !dpBatch[i/3][j/3][val]) {
                // val 可能可以填入
                board[i][j] = val+'0';
                dpRow[i][val] = 1;
                dpCol[j][val] = 1;
                dpBatch[i/3][j/3][val] = 1;
                if (solveStep(board, j+1>=9 ? i+1 : i, j+1>=9 ? 0 : j+1, dpRow, dpCol, dpBatch))
                    return 1;
                board[i][j] = '.';
                dpRow[i][val] = 0;
                dpCol[j][val] = 0;
                dpBatch[i/3][j/3][val] = 0;
            }
        }

        return 0;
    }

    void solveSudoku(vector<vector<char>>& board) {
        // 记录行 9行，每行(1-9)是否出现过 -> m/i
        vector<vector<int>> dpRow(9, vector<int>(10, 0));
        // 记录列 9列，每列(1-9)是否出现过 -> n/j
        vector<vector<int>> dpCol(9, vector<int>(10, 0));
        // 记录九宫格 i/3, j/3 (1-9)是否出现过
        vector<vector<vector<int>>> dpBatch(3, vector<vector<int>>(3, vector<int>(10, 0)));

        // 初始化
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char c = board[i][j];
                if (c != '.') {
                    dpRow[i][c-'0'] = 1;
                    dpCol[j][c-'0'] = 1;
                    dpBatch[i/3][j/3][c-'0'] = 1;
                }
            }
        }

        // 递归，选择填k
        solveStep(board,0,0,dpRow,dpCol,dpBatch);

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }

    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main() {
    Solution s;
    vector<vector<char>> board = {{'5','3','.','.','7','.','.','.','.'},
                                  {'6','.','.','1','9','5','.','.','.'},
                                  {'.','9','8','.','.','.','.','6','.'},
                                  {'8','.','.','.','6','.','.','.','3'},
                                  {'4','.','.','8','.','3','.','.','1'},
                                  {'7','.','.','.','2','.','.','.','6'},
                                  {'.','6','.','.','.','.','2','8','.'},
                                  {'.','.','.','4','1','9','.','.','5'},
                                  {'.','.','.','.','8','.','.','7','9'}};
    s.solveSudoku(board);
}