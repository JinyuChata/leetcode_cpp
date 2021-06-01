//给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。如果 word 存在于网格中，返回 true ；否则，返回 false 。 
//
// 单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。
// 同一个单元格内的字母不允许被重复使用。
//
// 
//
// 示例 1： 
//
// 
//输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "AB
//CCED"
//输出：true
// 
//
// 示例 2： 
//
// 
//输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SE
//E"
//输出：true
// 
//
// 示例 3： 
//
// 
//输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "AB
//CB"
//输出：false
// 
//
// 
//
// 提示： 
//
// 
// m == board.length 
// n = board[i].length 
// 1 <= m, n <= 6 
// 1 <= word.length <= 15 
// board 和 word 仅由大小写英文字母组成 
// 
//
// 
//
// 进阶：你可以使用搜索剪枝的技术来优化解决方案，使其在 board 更大的情况下可以更快解决问题？ 
// Related Topics 数组 回溯算法 
// 👍 917 👎 0

#include "bits/stdc++.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> dirs{{1,  0},
                             {0,  1},
                             {-1, 0},
                             {0, -1}};

    int traceback(vector<vector<char>> &board, vector<vector<int>>& visited,
                  string word, int i, int j, int wIdx) {
        int m = board.size();
        int n = board[0].size();
        if (wIdx == word.size()) {
            // 已经成功找到
            return 1;
        }
        if (i < 0 || i >= m || j < 0 || j >= n) return 0;
        if (board[i][j] != word[wIdx]) return 0;
        if (visited[i][j]) return 0;

        // 这一步走了
        visited[i][j] = 1;

        for (vector<int>& dir : dirs) {
            int ii = i + dir[0];
            int jj = j + dir[1];
            if (traceback(board, visited, word, ii, jj, wIdx+1))
                return 1;
        }

        visited[i][j] = 0;
        return 0;

    }

    bool exist(vector<vector<char>> &board, string word) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0] && traceback(board, visited, word, i, j, 0)) {
                    return true;
                }
            }
        }
        // 从0,0开始，搜索word的第0位
        return false;

    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
}