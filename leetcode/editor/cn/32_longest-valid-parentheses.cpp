//给你一个只包含 '(' 和 ')' 的字符串，找出最长有效（格式正确且连续）括号子串的长度。 
// 示例 1：
//输入：s = "(()"
//输出：2
//解释：最长有效括号子串是 "()"
// 示例 2：
//输入：s = ")()())"
//输出：4
//解释：最长有效括号子串是 "()()"
// 示例 3：
//输入：s = ""
//输出：0
// 提示：
//
// 0 <= s.length <= 3 * 104 
// s[i] 为 '(' 或 ')' 
// Related Topics 字符串 动态规划 
// 👍 1315 👎 0

#include <bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        int maxSize = 0;
        if (n == 0) return 0;

        // dp[i] 以s[i]为结尾的，最长有效括号
        vector<int> dp(n);
        for (int i = 1; i < n; ++i) {
            if (s[i] == '(') {
                // s[i] == '('
                dp[i] = 0;
            } else {
                // s[i] == ')'
                if (s[i - 1] == '(') {
                    dp[i] = 2;
                    if (i - 2 >= 0) dp[i] += dp[i - 2];
                } else {
                    if (dp[i-1] != 0 && i-dp[i-1]-1 >= 0 && s[i-dp[i-1]-1] == '(') {
                        dp[i] = dp[i-1] + 2;
                        if (i-dp[i-1]-2 >= 0) {
                            dp[i] += dp[i-dp[i-1]-2];
                        }
                    }
                }
            }

            maxSize = max(maxSize, dp[i]);
        }

        return maxSize;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main() {
    Solution s;
    cout << s.longestValidParentheses("()(())") << endl;
}