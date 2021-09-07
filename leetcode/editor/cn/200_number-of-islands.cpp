//给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。 
//
// 岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。 
//
// 此外，你可以假设该网格的四条边均被水包围。 
//
// 
//
// 示例 1： 
//
// 
//输入：grid = [
//  ["1","1","1","1","0"],
//  ["1","1","0","1","0"],
//  ["1","1","0","0","0"],
//  ["0","0","0","0","0"]
//]
//输出：1
// 
//
// 示例 2： 
//
// 
//输入：grid = [
//  ["1","1","0","0","0"],
//  ["1","1","0","0","0"],
//  ["0","0","1","0","0"],
//  ["0","0","0","1","1"]
//]
//输出：3
// 
//
// 
//
// 提示： 
//
// 
// m == grid.length 
// n == grid[i].length 
// 1 <= m, n <= 300 
// grid[i][j] 的值为 '0' 或 '1' 
// 
// Related Topics 深度优先搜索 广度优先搜索 并查集 数组 矩阵 
// 👍 1307 👎 0

#include "bits/stdc++.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> root;

    int find(int i) {
        if (root[i] < 0) return i;
        return root[i] = find(root[i]);
    }

    void join(int i, int j) {
        int ri = find(i);
        int rj = find(j);
        if (ri == rj) return;
        root[ri] = rj;
    }

    int numIslands(vector<vector<char>> &grid) {
        int m = grid.size();
        int n = grid[0].size();
        root = vector<int>(m * n, -1);

        int x_i[4] = {-1, 1, 0, 0};
        int x_j[4] = {0, 0, -1, 1};

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '0') continue;
                for (int k = 0; k < 4; k++) {
                    int xi = i + x_i[k];
                    int xj = j + x_j[k];
                    if (xi < 0 || xi >= m || xj < 0 || xj >= n) continue;
                    if (grid[xi][xj] == '1') join(i * m + j, xi * m + xj);
                }
            }
        }

        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cout << root[i * m + j] << " ";
                if (grid[i][j] == '1' && root[i * m + j] == -1) res++;
            }
            cout << endl;
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    vector<vector<char>> grid = {
            {'1'},
            {'1'},
    };
    cout << s.numIslands(grid);
}