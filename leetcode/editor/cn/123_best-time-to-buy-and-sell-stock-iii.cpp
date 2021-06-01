//给定一个数组，它的第 i 个元素是一支给定的股票在第 i 天的价格。 
//
// 设计一个算法来计算你所能获取的最大利润。你最多可以完成 两笔 交易。 
//
// 注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。 
//
// 
//
// 示例 1: 
//
// 
//输入：prices = [3,3,5,0,0,3,1,4]
//输出：6
//解释：在第 4 天（股票价格 = 0）的时候买入，在第 6 天（股票价格 = 3）的时候卖出，这笔交易所能获得利润 = 3-0 = 3 。
//     随后，在第 7 天（股票价格 = 1）的时候买入，在第 8 天 （股票价格 = 4）的时候卖出，这笔交易所能获得利润 = 4-1 = 3 。 
//
// 示例 2： 
//
// 
//输入：prices = [1,2,3,4,5]
//输出：4
//解释：在第 1 天（股票价格 = 1）的时候买入，在第 5 天 （股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5-1 = 4 。   
//     注意你不能在第 1 天和第 2 天接连购买股票，之后再将它们卖出。   
//     因为这样属于同时参与了多笔交易，你必须在再次购买前出售掉之前的股票。
// 
//
// 示例 3： 
//
// 
//输入：prices = [7,6,4,3,1] 
//输出：0 
//解释：在这个情况下, 没有交易完成, 所以最大利润为 0。 
//
// 示例 4： 
//
// 
//输入：prices = [1]
//输出：0
// 
//
// 
//
// 提示： 
//
// 
// 1 <= prices.length <= 105 
// 0 <= prices[i] <= 105 
// 
// Related Topics 数组 动态规划 
// 👍 772 👎 0

#include <bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
/**
 * 第i天结束
 * 现在是j 持有(0) 未持有(1)
 * 已经买入了k次 (2,1,0)
 * Base Case:
 * dp[0][1][2]= 0
 * dp[0][1][1]=dp[0][1][0]= -1
 * dp[0][0][1]= -p[0]
 * dp[0][0][2]=dp[0][0][0]= -1
 *
 * 状态转移:
 * dp[i][0][k] = max{ dp[i-1][1][k+1]-p[i], dp[i-1][0][k] }
 * dp[i][1][k] = max{ dp[i-1][1][k], dp[i-1][0][k]+p[i] }
 * 最多完成两笔交易：dp[i][j][k]
 */
#define INVALID -10086
class Solution {
public:
    /**
     * 1,2
     * dp[0][1]
     * @param prices
     * @return
     */
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n,
                vector<vector<int>>(2,
                        vector<int>(3, INVALID)));
        // base case
        for (int k = 2; k >= 0; k--) dp[0][1][k] = 0;
        for (int k = 1; k >= 0; k--) dp[0][0][k] = -prices[0];
        // 循环
        for (int i = 1; i < n; i++) {
            for (int k = 0; k <= 2; k++) {
                // j=0 持有
                dp[i][0][k] = dp[i - 1][0][k];
                if (k < 2 && dp[i - 1][1][k + 1] != INVALID)
                    dp[i][0][k] = max(dp[i][0][k], dp[i - 1][1][k + 1] - prices[i]);
                // j=1 不持有
                dp[i][1][k] = dp[i - 1][1][k];
                if (dp[i - 1][0][k] != INVALID)
                    dp[i][1][k] = max(dp[i][1][k], dp[i - 1][0][k] + prices[i]);
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= 1; j++) {
                for (int k = 0; k <= 2; k++) {
                    cout << i << j << k << ":" << dp[i][j][k] << endl;
                }
            }
        }
        return max(max(dp[n-1][1][0], dp[n-1][1][1]), dp[n-1][1][2]);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
}