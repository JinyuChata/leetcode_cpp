//给出 n 个数对。 在每一个数对中，第一个数字总是比第二个数字小。 
//
// 现在，我们定义一种跟随关系，当且仅当 b < c 时，数对(c, d) 才可以跟在 (a, b) 后面。我们用这种形式来构造一个数对链。 
//
// 给定一个数对集合，找出能够形成的最长数对链的长度。你不需要用到所有的数对，你可以以任何顺序选择其中的一些数对来构造。 
//
// 
//
// 示例： 
//
// 
//输入：[[1,2], [2,3], [3,4]]
//输出：2
//解释：最长的数对链是 [1,2] -> [3,4]
// 
//
// 
//
// 提示： 
//
// 
// 给出数对的个数在 [1, 1000] 范围内。 
// 
// Related Topics 贪心 数组 动态规划 排序 👍 180 👎 0

#include "bits/stdc++.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // 同样道理，排序[一级排序]+LIS，一级内顺序不影响结果
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        int res = 1;
        sort(pairs.begin(), pairs.end(), [](vector<int>& p1, vector<int>& p2){
            return p1[0] < p2[0];
            // j a<b  i c<d
            // b<c: 则a<c是必要条件，所以先把必要条件满足，后面一定从必要条件的序列中选，且满足条件的序列一定在原序列中有序
        });

        vector<int> dp(n, 1);
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (pairs[j][1] < pairs[i][0]) dp[i] = max(dp[i], dp[j]+1);
            }
            res = max(res, dp[i]);
        }

        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
}