//给定一个字符串 s 和一个字符串 t ，计算在 s 的子序列中 t 出现的个数。 
//
// 字符串的一个 子序列 是指，通过删除一些（也可以不删除）字符且不干扰剩余字符相对位置所组成的新字符串。（例如，"ACE" 是 "ABCDE" 的一个子序列
//，而 "AEC" 不是） 
//
// 题目数据保证答案符合 32 位带符号整数范围。 
//
// 
//
// 示例 1： 
//
// 
//输入：s = "rabbbit", t = "rabbit"
//输出：3
//解释：
//如下图所示, 有 3 种可以从 s 中得到 "rabbit" 的方案。
//(上箭头符号 ^ 表示选取的字母)
//rabbbit
//^^^^ ^^
//rabbbit
//^^ ^^^^
//rabbbit
//^^^ ^^^
// 
//
// 示例 2： 
//
// 
//输入：s = "babgbag", t = "bag"
//输出：5
//解释：
//如下图所示, 有 5 种可以从 s 中得到 "bag" 的方案。 
//(上箭头符号 ^ 表示选取的字母)
//babgbag
//^^ ^
//babgbag
//^^    ^
//babgbag
//^    ^^
//babgbag
//  ^  ^^
//babgbag
//    ^^^ 
//
// 
//
// 提示： 
//
// 
// 0 <= s.length, t.length <= 1000 
// s 和 t 由英文字母组成 
// 
// Related Topics 字符串 动态规划 
// 👍 525 👎 0

#include <bits/stdc++.h>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int numDistinct(string s, string t) {
        int ns = s.length();
        int nt = t.length();

        // dp[i][j]: s[0..i]经过删除后，得到t[0..j]的方法数
        vector<vector<unsigned int>> dp(ns+1, vector<unsigned int>(nt+1, 0));
        dp[0][0] = 1;
        // 初始化第一行：dp[0][j] -> 无须初始化，都是0
        // 初始化第一列：dp[i][0]
        for (int i = 1; i <= ns; i++) {
            dp[i][0] = 1;   // 只有一种方法：全部删完
        }

        for (int i = 1; i <= ns; i++) {
            for (int j = 1; j <= nt; j++) {
                unsigned int tot = 0;
                // skip
                tot += dp[i-1][j];
                if (s[i-1] == t[j-1]) {
                    tot += dp[i-1][j-1];
                }

                dp[i][j] = tot;
            }
        }


        return dp[ns][nt];
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    s.numDistinct("rabbbit", "rabbit");
}