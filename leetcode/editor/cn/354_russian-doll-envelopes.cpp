//给你一个二维整数数组 envelopes ，其中 envelopes[i] = [wi, hi] ，表示第 i 个信封的宽度和高度。 
//
// 当另一个信封的宽度和高度都比这个信封大的时候，这个信封就可以放进另一个信封里，如同俄罗斯套娃一样。 
//
// 请计算 最多能有多少个 信封能组成一组“俄罗斯套娃”信封（即可以把一个信封放到另一个信封里面）。 
//
// 注意：不允许旋转信封。 
// 
//
// 示例 1： 
//
// 
//输入：envelopes = [[5,4],[6,4],[6,7],[2,3]]
//输出：3
//解释：最多信封的个数为 3, 组合为: [2,3] => [5,4] => [6,7]。 
//
// 示例 2： 
//
// 
//输入：envelopes = [[1,1],[1,1],[1,1]]
//输出：1
// 
//
// 
//
// 提示： 
//
// 
// 1 <= envelopes.length <= 5000 
// envelopes[i].length == 2 
// 1 <= wi, hi <= 10⁴ 
// 
// Related Topics 数组 二分查找 动态规划 排序 👍 580 👎 0

#include "bits/stdc++.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        vector<int> dp(n, 1);      // 以i为结尾的，最大套娃层数
        int m = 1;
        sort(envelopes.begin(), envelopes.end(), [](vector<int>& v1, vector<int>& v2){
            return v1[0] < v2[0];
        });

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (envelopes[i][0] > envelopes[j][0] &&
                    envelopes[i][1] > envelopes[j][1]) {
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
            m = max(m, dp[i]);
        }
        for (int i = 0; i < n; i++) {
            cout << dp[i] << endl;
        }
        return m;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
}