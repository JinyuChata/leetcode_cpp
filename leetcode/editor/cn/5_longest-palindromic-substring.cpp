//给你一个字符串 s，找到 s 中最长的回文子串。 
// 示例 1：
//输入：s = "babad"
//输出："bab"
//解释："aba" 同样是符合题意的答案。
// 示例 2：
//输入：s = "cbbd"
//输出："bb"
// 示例 3：
//输入：s = "a"
//输出："a"
// 示例 4：
//输入：s = "ac"
//输出："a"
// 提示：
// 1 <= s.length <= 1000
// s 仅由数字和英文字母（大写和/或小写）组成
// Related Topics 字符串 动态规划
// 👍 3668 👎 0



//leetcode submit region begin(Prohibit modification and deletion)
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        // dp[i][j]: i..j是不是回文串
        // dp[i][i]
        // dp[i][i+1]
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, 0));
        for (int i = 0; i < n; i++) dp[i][i] = true;
        int start = 0;
        int res = 1;
        for (int i = 0; i < n - 1; i++) {
            dp[i][i + 1] = s[i] == s[i + 1];
            if (dp[i][i+1]) { start = i; res = 2; }
        }

        for (int k = 2; k <= n - 1; k++) {
            for (int i = 0; i < n - k; i++) {
                if (dp[i + 1][i + k - 1] && s[i] == s[i + k]) {
                    dp[i][i+k] = true;
                    res = k+1;
                    start = i;
                }
            }
        }

        return s.substr(start, res);
    }
};

//leetcode submit region end(Prohibit modification and deletion)
int main() {
    Solution solution;
    cout << solution.longestPalindrome("cnjkdnkjsnsj");
}