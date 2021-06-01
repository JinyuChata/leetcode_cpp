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
        // dp[i][j]: [i..j]是不是回文串
        int maxSize = 1;
        int from = 0, to = 0;

        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 0; i < n; ++i) {
            dp[i][i] = 1;
        }

        for (int i = n-2; i >= 0; i--) {
            for (int j = i+1; j < n; j++) {
                if (s[i] == s[j] && (dp[i+1][j-1] || j-i==1)) dp[i][j] = 1;
                if (dp[i][j] && j-i+1 > maxSize) {
                    maxSize = j-i+1;
                    from = i; to = j;
                }
            }
        }

        return s.substr(from, maxSize);
    }
};

//leetcode submit region end(Prohibit modification and deletion)
int main() {
    Solution solution;
    cout << solution.longestPalindrome("cnjkdnkjsnsj");
}