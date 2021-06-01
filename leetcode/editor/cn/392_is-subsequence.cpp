//给定字符串 s 和 t ，判断 s 是否为 t 的子序列。 
//
// 字符串的一个子序列是原始字符串删除一些（也可以不删除）字符而不改变剩余字符相对位置形成的新字符串。（例如，"ace"是"abcde"的一个子序列，而"ae
//c"不是）。 
//
// 进阶： 
//
// 如果有大量输入的 S，称作 S1, S2, ... , Sk 其中 k >= 10亿，你需要依次检查它们是否为 T 的子序列。在这种情况下，你会怎样改变代
//码？ 
//
// 致谢： 
//
// 特别感谢 @pbrother 添加此问题并且创建所有测试用例。 
//
// 
//
// 示例 1： 
//
// 
//输入：s = "abc", t = "ahbgdc"
//输出：true
// 
//
// 示例 2： 
//
// 
//输入：s = "axc", t = "ahbgdc"
//输出：false
// 
//
// 
//
// 提示： 
//
// 
// 0 <= s.length <= 100 
// 0 <= t.length <= 10^4 
// 两个字符串都只由小写字符组成。 
// 
// Related Topics 贪心算法 二分查找 动态规划 
// 👍 452 👎 0
#include <bits/stdc++.h>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // 这也可以dp?
    // dp[i][j]: 第i个位置和之后，第一次出现字母j的位置
    bool isSubsequence(string s, string t) {
        string tmp = s;
        s = t;
        t = tmp;
        int sn = s.size();
        int tn = t.size();

        if (sn == 0 && tn == 0) return true;
        if (sn == 0) return false;
        if (tn == 0) return true;

        vector<vector<int>> dp(sn, vector<int>('z'+1, -1));
        dp[sn-1][s[sn-1]] = sn-1;
        // dp[i][j] = 自己 or dp[i+1][j]
        for (int i = sn-2; i >= 0; i--) {
            for (int j = 'a'; j <= 'z'; j++) {
                if (s[i] == j) dp[i][j] = i;
                else dp[i][j] = dp[i+1][j];
            }
        }

        int pos = 0;
        for (char c : t) {
            if (pos >= sn) return false;
            pos = dp[pos][c];
            if (pos == -1) return false;
            pos++;
        }
        return true;

    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    s.isSubsequence("abc", "ahbgdc");
}