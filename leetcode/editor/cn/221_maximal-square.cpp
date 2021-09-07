//在一个由 '0' 和 '1' 组成的二维矩阵内，找到只包含 '1' 的最大正方形，并返回其面积。 
//
// 
//
// 示例 1： 
//
// 
//输入：matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"]
//,["1","0","0","1","0"]]
//输出：4
// 
//
// 示例 2： 
//
// 
//输入：matrix = [["0","1"],["1","0"]]
//输出：1
// 
//
// 示例 3： 
//
// 
//输入：matrix = [["0"]]
//输出：0
// 
//
// 
//
// 提示： 
//
// 
// m == matrix.length 
// n == matrix[i].length 
// 1 <= m, n <= 300 
// matrix[i][j] 为 '0' 或 '1' 
// 
// Related Topics 数组 动态规划 矩阵 
// 👍 859 👎 0

#include "bits/stdc++.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        // dp[i][j] 以ij为右下角，最大正方形大小
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> dp(m, vector<int>(n,0));
        // 初始化第一行
        int maxmax = 0;

        for (int j = 0; j < n; j++) {
            dp[0][j] = matrix[0][j] == '1' ? 1 : 0;
            maxmax = max(maxmax, dp[0][j]);
        }
        for (int i = 0; i < m; i++) {
            dp[i][0] = matrix[i][0] == '1' ? 1 : 0;
            maxmax = max(maxmax, dp[i][0]);
        }


        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == '0') dp[i][j] = 0;
                else {
                    int l = dp[i-1][j]; int r = dp[i][j-1];
                    if (l == r) {
                        if (matrix[i-l][j-l] == '1') dp[i][j] = l+1;
                        else dp[i][j] = l;
                    } else {
                        dp[i][j] = min(l,r)+1;
                    }
                    maxmax = max(maxmax, dp[i][j]);
                }
            }
        }

//        for (int i = 0; i < m; i++) {
//            for (int j = 0; j < n; j++) {
//                cout << dp[i][j] << " ";
//            }
//            cout << endl;
//        }

        return maxmax*maxmax;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
}