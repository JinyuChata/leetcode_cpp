//给你一个字符串 s 和一个字符规律 p，请你来实现一个支持 '.' 和 '*' 的正则表达式匹配。 
// '.' 匹配任意单个字符
// '*' 匹配零个或多个前面的那一个元素 
// 所谓匹配，是要涵盖 整个 字符串 s的，而不是部分字符串。
// 示例 1：
//输入：s = "aa" p = "a"
//输出：false
//解释："a" 无法匹配 "aa" 整个字符串。
// 示例 2:
//输入：s = "aa" p = "a*"
//输出：true
//解释：因为 '*' 代表可以匹配零个或多个前面的那一个元素, 在这里前面的元素就是 'a'。因此，字符串 "aa" 可被视为 'a' 重复了一次。
// 示例 3：
//输入：s = "ab" p = ".*"
//输出：true
//解释：".*" 表示可匹配零个或多个（'*'）任意字符（'.'）。
// 示例 4：
//输入：s = "aab" p = "c*a*b"
//输出：true
//解释：因为 '*' 表示零个或多个，这里 'c' 为 0 个, 'a' 被重复一次。因此可以匹配字符串 "aab"。
// 示例 5：
//输入：s = "mississippi" p = "mis*is*p*."
//输出：false 
// 提示：
// 0 <= s.length <= 20
// 0 <= p.length <= 30 
// s 可能为空，且只包含从 a-z 的小写字母。 
// p 可能为空，且只包含从 a-z 的小写字母，以及字符 . 和 *。 
// 保证每次出现字符 * 时，前面都匹配到有效的字符 
// 
// Related Topics 字符串 动态规划 回溯算法 
// 👍 2130 👎 0

#include <bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool isMatch(string s, string p) {
        int nj = s.size();
        int ni = p.size();

        // dp 从1开始
        // dp[0][0] = 1, dp[0][k] = 0
        vector<vector<int>> dp(ni + 1, vector<int>(nj + 1));
        dp[0][0] = 1;
        for (int j = 1; j <= nj; j++) {
            dp[0][j] = 0;
        }

        // 扫描：从i=1, j=0开始
        for (int i = 1; i <= ni; i++) {
            for (int j = 0; j <= nj; j++) {
                // 正常匹配其他值
                char pc = p[i-1];
                char sc;
                if (j > 0) sc = s[j-1];
                if (pc != '.' && pc != '*') {
                    if (j != 0 && pc == sc)
                        dp[i][j] = dp[i - 1][j - 1];
                    else dp[i][j] = 0;
                } else if (pc == '.') {
                    // .
                    if (j != 0) dp[i][j] = dp[i-1][j-1];
                    else dp[i][j] = 0;
                } else {
                    // * 关注前一个字符是什么
                    char c = p[i-2];
                    if (j == 0) {
                        dp[i][j] = dp[i-2][j];
                    } else {
                        dp[i][j] = dp[i-2][j] || (dp[i][j-1] && (c == '.' || c == sc));
                    }
                }
            }
        }
        for (int i = 0; i <= ni; i++) {
            for (int j = 0; j <= nj; j++)
                cout << dp[i][j] << " ";
            cout << endl;
        }
        return dp[ni][nj];
    }
};
//leetcode submit region end(Prohibit modification and deletion)
int main() {
    Solution s;
    cout << s.isMatch("aab", "c*a*b");
}