//n 皇后问题 研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。 
//
// 给你一个整数 n ，返回 n 皇后问题 不同的解决方案的数量。 
//
// 
//
// 
// 
// 示例 1： 
//
// 
//输入：n = 4
//输出：2
//解释：如上图所示，4 皇后问题存在两个不同的解法。
// 
//
// 示例 2： 
//
// 
//输入：n = 1
//输出：1
// 
//
// 
//
// 提示： 
//
// 
// 1 <= n <= 9 
// 皇后彼此不能相互攻击，也就是说：任何两个皇后都不能处于同一条横行、纵行或斜线上。 
// 
// 
// 
// Related Topics 回溯算法 
// 👍 262 👎 0

#include "bits/stdc++.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<string>> ress;

    bool canPutOnCol(vector<string>& table, int n, int i, int j) {
        // 纵行
        for (int k = 0; k < n; k++) {
            if (table[k][j] != '.') return false;
        }
        // 斜线
        int ii = i, jj = j;
        // 向右下角
        while (ii < n && jj < n && ii >= 0 && jj >= 0) {
            if (table[ii][jj] != '.') return false;
            ii++; jj++;
        }
        ii = i, jj = j;
        // 向左上角
        while (ii < n && jj < n && ii >= 0 && jj >= 0) {
            if (table[ii][jj] != '.') return false;
            ii--; jj--;
        }
        ii = i, jj = j;
        // 向左下角
        while (ii < n && jj < n && ii >= 0 && jj >= 0) {
            if (table[ii][jj] != '.') return false;
            ii++; jj--;
        }
        ii = i, jj = j;
        // 向左上角
        while (ii < n && jj < n && ii >= 0 && jj >= 0) {
            if (table[ii][jj] != '.') return false;
            ii--; jj++;
        }

        return true;
    }

    void traceback(int n, int i, vector<string>& res) {
        // 要放在第i行，看看放在哪
        if (i == n) {
            ress.emplace_back(res);
            return;
        }

        for (int j = 0; j < n; j++) {
            if (canPutOnCol(res, n, i, j)) {
                res[i][j] = 'Q';
                traceback(n, i+1, res);
                res[i][j] = '.';
            }
        }
    }

    int totalNQueens(int n) {
        vector<string> res;
        string lineStr;
        for (int i = 0; i < n; i++) {
            lineStr += ".";
        }
        for (int i = 0; i < n; i++) {
            res.emplace_back(lineStr);
        }
        traceback(n, 0, res);
        return ress.size();
    }
};
//leetcode submit region end(Prohibit modification and deletion)
