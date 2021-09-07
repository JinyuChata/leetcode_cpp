//给你一个整数方阵 arr ，定义「非零偏移下降路径」为：从 arr 数组中的每一行选择一个数字，且按顺序选出来的数字中，相邻数字不在原数组的同一列。 
//
// 请你返回非零偏移下降路径数字和的最小值。 
//
// 
//
// 示例 1： 
//
// 
//输入：arr = [[1,2,3],[4,5,6],[7,8,9]]
//输出：13
//解释：
//所有非零偏移下降路径包括：
//[1,5,9], [1,5,7], [1,6,7], [1,6,8],
//[2,4,8], [2,4,9], [2,6,7], [2,6,8],
//[3,4,8], [3,4,9], [3,5,7], [3,5,9]
//下降路径中数字和最小的是 [1,5,7] ，所以答案是 13 。
// 
//
// 
//
// 提示： 
//
// 
// 1 <= arr.length == arr[i].length <= 200 
// -99 <= arr[i][j] <= 99 
// 
// Related Topics 数组 动态规划 矩阵 
// 👍 46 👎 0

#include "bits/stdc++.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        // 每一行，记录最小值、次小值
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(2,-1));
        vector<int> dpp(n, -1);
        for (int j = 0; j < n; j++) {
            dpp[j] = grid[0][j];
        }

        for (int i = 1; i < m; i++) {
            // 找出最小值、次小值
            int minVal = dpp[0];
            int lastMinVal = INT32_MAX; int counter = 0;
            for (int k = 1; k < n; k++) {
                minVal = min(minVal, dpp[k]);
            }
            for (int k = 0; k < n; k++) {
                if (minVal == dpp[k] && counter == 0) {
                    counter++;
                } else {
                    lastMinVal = min(lastMinVal, dpp[k]);
                }
            }

            for (int j = 0; j < n; j++) {
                int target = minVal;
                if (grid[i-1][j] == minVal) {
                    target = lastMinVal;
                }

                dpp[j] = grid[i][j] + target;
            }
        }
        int minmin = INT32_MAX;
        for (int& dppp: dpp) {
            minmin = min(minmin, dppp);
        }
        return minmin;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
}