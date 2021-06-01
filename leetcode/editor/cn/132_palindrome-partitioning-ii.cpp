//给你一个字符串 s，请你将 s 分割成一些子串，使每个子串都是回文。 
//
// 返回符合要求的 最少分割次数 。 
//
// 
// 
// 
//
// 示例 1： 
//
// 
//输入：s = "aab"
//输出：1
//解释：只需一次分割就可将 s 分割成 ["aa","b"] 这样两个回文子串。
// 
//
// 示例 2： 
//
// 
//输入：s = "a"
//输出：0
// 
//
// 示例 3： 
//
// 
//输入：s = "ab"
//输出：1
// 
//
// 
//
// 提示： 
//
// 
// 1 <= s.length <= 2000 
// s 仅由小写英文字母组成 
// 
// 
// 
// Related Topics 动态规划 
// 👍 431 👎 0
#include <bits/stdc++.h>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)


class Solution {
public:
    vector<vector<int>> palind;

    void preProcess(string& s) {
        int n = s.size();
        palind = vector<vector<int>>(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
            palind[i][i] = 1;

        for (int i = n-2; i >= 0; i--) {
            for (int j = i+1; j < n; j++) {
                // [i .. j]
                if (s[i] != s[j]) continue;
                if (i+1 == j) palind[i][j] = 1;
                else palind[i][j] = palind[i+1][j-1];
            }
        }
    }

    int minCut(string s) {
        int n = s.size();
        if (n == 1) return 0;
        // 先预处理，搞出某段是否为回文
        preProcess(s);

        vector<int> dp(n);
        dp[0] = 0;
        // 对某一个i, dp[i] 是 [0..i]切分回文的最小个数
        for (int i = 1; i < n; i++) {
            // 全部集合
            if (palind[0][i]) {
                dp[i] = 0;
                continue;
            }
            // 独立i
            int minVal = 1 + dp[i-1];
            // 与前面 1,2...i-1 - i 组成回文
            for (int j = 1; j < i; j++) {
                // [j .. i]
                if (!palind[j][i]) continue;
                minVal = min(minVal, 1+dp[j-1]);
            }
            dp[i] = minVal;
        }

        return dp[n-1];
    }

};
//leetcode submit region end(Prohibit modification and deletion)

int main() {
    Solution s;
    cout << s.minCut("aab") << endl;
}
