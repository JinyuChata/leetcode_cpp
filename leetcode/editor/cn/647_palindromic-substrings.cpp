//给定一个字符串，你的任务是计算这个字符串中有多少个回文子串。 
//
// 具有不同开始位置或结束位置的子串，即使是由相同的字符组成，也会被视作不同的子串。 
//
// 
//
// 示例 1： 
//
// 输入："abc"
//输出：3
//解释：三个回文子串: "a", "b", "c"
// 
//
// 示例 2： 
//
// 输入："aaa"
//输出：6
//解释：6个回文子串: "a", "a", "a", "aa", "aa", "aaa" 
//
// 
//
// 提示： 
//
// 
// 输入的字符串长度不会超过 1000 。 
// 
// Related Topics 字符串 动态规划 
// 👍 662 👎 0

#include "bits/stdc++.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size(); int result = 0;
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        // dp[i][i]
        for (int i = 0; i < n; i++) {
            dp[i][i] = true; result++;
        }
        // dp[i][i+1]
        for (int i = 0; i < n-1; i++) {
            if (s[i] == s[i+1]) {
                result++; dp[i][i+1] = true;
            }
        }
        // 间隔为k的
        for (int k = 2; k < n; k++) {
            for (int i = 0; i < n-k; i++) {
                if (dp[i+1][i+k-1] && s[i] == s[i+k]) {
                    result++;
                    dp[i][i+k] = true;
                }
            }
        }

        return result;

    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
}