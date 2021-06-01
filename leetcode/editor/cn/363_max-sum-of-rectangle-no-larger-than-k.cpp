//给你一个 m x n 的矩阵 matrix 和一个整数 k ，找出并返回矩阵内部矩形区域的不超过 k 的最大数值和。 
//
// 题目数据保证总会存在一个数值和不超过 k 的矩形区域。 
//
// 
//
// 示例 1： 
//
// 
//输入：matrix = [[1,0,1],[0,-2,3]], k = 2
//输出：2
//解释：蓝色边框圈出来的矩形区域 [[0, 1], [-2, 3]] 的数值和是 2，且 2 是不超过 k 的最大数字（k = 2）。
// 
//
// 示例 2： 
//
// 
//输入：matrix = [[2,2,-1]], k = 3
//输出：3
// 
//
// 
//
// 提示： 
//
// 
// m == matrix.length 
// n == matrix[i].length 
// 1 <= m, n <= 100 
// -100 <= matrix[i][j] <= 100 
// -105 <= k <= 105 
// 
//
// 
//
// 进阶：如果行数远大于列数，该如何设计解决方案？ 
// Related Topics 队列 二分查找 动态规划 
// 👍 326 👎 0
#include <bits/stdc++.h>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        // 前缀和预处理
        int m = matrix.size();
        int n = matrix[0].size();
        // (m+1)*(n+1) -> 记录前缀和
        vector<vector<int>> preSum(m+1, vector<int>(n+1, 0));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                preSum[i][j] = preSum[i-1][j] + preSum[i][j-1] - preSum[i-1][j-1] + matrix[i-1][j-1];
            }
        }

        int res = -999999;

        // 抽象一维，lowerbound法
        // 确定矩阵的 top/bottom, 然后只需定好左/右即可
        for (int top = 1; top <= m; top++) {
            for (int bottom = top; bottom <= m; bottom++) {
                // 需要定好l,r
                // 定好后面积计算公式：preSum[bottom][r] - preSum[top-1][r] - preSum[bottom][l-1] + preSum[top-1][l-1]
                // 维护一个set, 记录遍历r的过程
                set<int> ts;
                ts.insert(0);
                for (int r = 1; r <= n; r++) {
                    int rSize = preSum[bottom][r] - preSum[top-1][r] - preSum[bottom][0] + preSum[top-1][0];
                    // 查找left可能的(值 -> 而非位置)
                    auto l = ts.lower_bound(rSize - k);
                    if (l != ts.end()) {
                        res = max(res, rSize - *l);
                    }
                    ts.insert(rSize);
                }
            }
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    vector<vector<int>> m{{1,0,1}, {0,-2,3}};
    s.maxSumSubmatrix(m, 4);
}