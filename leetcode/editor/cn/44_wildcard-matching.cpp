//给定一个字符串 (s) 和一个字符模式 (p) ，实现一个支持 '?' 和 '*' 的通配符匹配。 
//
// '?' 可以匹配任何单个字符。
//'*' 可以匹配任意字符串（包括空字符串）。
// 
//
// 两个字符串完全匹配才算匹配成功。 
//
// 说明: 
//
// 
// s 可能为空，且只包含从 a-z 的小写字母。 
// p 可能为空，且只包含从 a-z 的小写字母，以及字符 ? 和 *。 
// 
//
// 示例 1: 
//
// 输入:
//s = "aa"
//p = "a"
//输出: false
//解释: "a" 无法匹配 "aa" 整个字符串。 
//
// 示例 2: 
//
// 输入:
//s = "aa"
//p = "*"
//输出: true
//解释: '*' 可以匹配任意字符串。
// 
//
// 示例 3: 
//
// 输入:
//s = "cb"
//p = "?a"
//输出: false
//解释: '?' 可以匹配 'c', 但第二个 'a' 无法匹配 'b'。
// 
//
// 示例 4: 
//
// 输入:
//s = "adceb"
//p = "*a*b"
//输出: true
//解释: 第一个 '*' 可以匹配空字符串, 第二个 '*' 可以匹配字符串 "dce".
// 
//
// 示例 5: 
//
// 输入:
//s = "acdcb"
//p = "a*c?b"
//输出: false 
// Related Topics 贪心算法 字符串 动态规划 回溯算法 
// 👍 690 👎 0

#include <bits/stdc++.h>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool isMatch(string s, string p) {
        int nj = s.size();
        int ni = p.size();
        // dp[i][j]
        // 指 p[...i] 匹配 s[...j]
        vector<vector<int>> dp(ni+1, vector<int>(nj+1));

        // dp[0][0] 为 1
        dp[0][0] = 1;
        for (int j = 1; j <= nj; j++)
            dp[0][j] = 0;

        for (int i = 1; i <= ni; i++) {
            for (int j = 0; j <= nj; j++) {
                if (j == 0) {
                    // 有pattern, 无string
                    if (i == 1 && p[i-1] == '*') dp[i][j] = 1;
                    else if (p[i-1] != '*') dp[i][j] = 0;
                    else dp[i][j] = dp[i-1][j];
                } else {
                    char cs = s[j-1];
                    char cp = p[i-1];
                    if (cp != '?' && cp != '*') {
                        dp[i][j] = cp == cs && dp[i-1][j-1];
                    } else if (cp == '?') {
                        dp[i][j] = dp[i-1][j-1];
                    } else {
                        dp[i][j] = dp[i-1][j] || dp[i][j-1];
                    }
                }
            }
        }

        return dp[ni][nj];

    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    s.isMatch("ab", "?*");
}