//给定一个 m x n 整数矩阵 matrix ，找出其中 最长递增路径 的长度。 
//
// 对于每个单元格，你可以往上，下，左，右四个方向移动。 你 不能 在 对角线 方向上移动或移动到 边界外（即不允许环绕）。 
//
// 
//
// 示例 1： 
//
// 
//输入：matrix = [[9,9,4],[6,6,8],[2,1,1]]
//输出：4 
//解释：最长递增路径为 [1, 2, 6, 9]。 
//
// 示例 2： 
//
// 
//输入：matrix = [[3,4,5],[3,2,6],[2,2,1]]
//输出：4 
//解释：最长递增路径是 [3, 4, 5, 6]。注意不允许在对角线方向上移动。
// 
//
// 示例 3： 
//
// 
//输入：matrix = [[1]]
//输出：1
// 
//
// 
//
// 提示： 
//
// 
// m == matrix.length 
// n == matrix[i].length 
// 1 <= m, n <= 200 
// 0 <= matrix[i][j] <= 231 - 1 
// 
// Related Topics 深度优先搜索 广度优先搜索 图 拓扑排序 记忆化搜索 动态规划 
// 👍 515 👎 0

#include "bits/stdc++.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> log;
    int volX[4] {-1,1,0,0};
    int volY[4] {0,0,-1,1};

    int recurse(vector<vector<int>> &matrix, int i, int j) {
        if (log[i][j] != -1) return log[i][j];

        int m = matrix.size();
        int n = matrix[0].size();
        int nextMax = 0;

        for (int k = 0; k < 4; k++) {
            int kx = i + volX[k];
            int ky = j + volY[k];
            if (kx < 0 || kx >= m || ky < 0 || ky >= n) continue;
            if (matrix[kx][ky] >= matrix[i][j]) continue;
            nextMax = max(nextMax, recurse(matrix,kx,ky));
        }

        log[i][j] = nextMax+1;
        return nextMax+1;
    }

    int longestIncreasingPath(vector<vector<int>> &matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        for (int i = 0; i < m; i++) {
            vector<int> l;
            for (int j = 0; j < n; j++) {
                l.push_back(-1);
            }
            log.push_back(l);
        }

        // 开始递归
        int res = 1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (log[i][j] != -1) {
                    res = max(res, log[i][j]);
                    continue;
                }
                recurse(matrix, i, j);
                res = max(res, log[i][j]);
            }
        }

        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
}