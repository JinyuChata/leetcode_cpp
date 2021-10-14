//一条包含字母 A-Z 的消息通过以下的方式进行了编码： 
//
// 'A' -> 1
//'B' -> 2
//...
//'Z' -> 26
// 
//
// 除了上述的条件以外，现在加密字符串可以包含字符 '*'了，字符'*'可以被当做1到9当中的任意一个数字。 
//
// 给定一条包含数字和字符'*'的加密信息，请确定解码方法的总数。 
//
// 同时，由于结果值可能会相当的大，所以你应当对10⁹ + 7取模。（翻译者标注：此处取模主要是为了防止溢出） 
//
// 示例 1 : 
//
// 输入: "*"
//输出: 9
//解释: 加密的信息可以被解密为: "A", "B", "C", "D", "E", "F", "G", "H", "I".
// 
//
// 示例 2 : 
//
// 输入: "1*"
//输出: 9 + 9 = 18（翻译者标注：这里1*可以分解为1,* 或者当做1*来处理，所以结果是9+9=18）
// 
//
// 说明 : 
//
// 
// 输入的字符串长度范围是 [1, 10⁵]。 
// 输入的字符串只会包含字符 '*' 和 数字'0' - '9'。 
// 
// Related Topics 字符串 动态规划 👍 91 👎 0

#include "bits/stdc++.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
#define MOD 1000000007

class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<long long> dp(n+1, 0);
         dp[0] = 1;
        // dp[1]
        if (s[0] == '*') dp[1] = 9;
        else if (s[0] != '0') dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            // [0 ... i-1]
            // 先看能不能和前面的组成两位
            char left = s[i-2];
            char curr = s[i-1];
            if (left == '*') {
                if ('0' <= curr && curr <= '6') {
                    dp[i] += 2 * dp[i-2] % MOD;
                } else if ('6' < curr && curr <= '9') {
                    dp[i] += dp[i-2] % MOD;
                } else if (curr == '*') {
                    dp[i] += 15 * dp[i-2] % MOD;
                }
            } else if (left == '2') {
                if ('0' <= curr && curr <= '6') {
                    dp[i] += dp[i-2] % MOD;
                } else if (curr == '*') {
                    dp[i] += 6 * dp[i-2] % MOD;
                }
            } else if (left == '1') {
                if (curr == '*') {
                    dp[i] += dp[i-2] * 9 % MOD;
                } else {
                    dp[i] += dp[i-2] % MOD;
                }
            }

            // 然后是组成一位
            if (curr == '*') {
                dp[i] += 9 * dp[i-1] % MOD;
            } else if (curr != '0') {
                dp[i] += dp[i-1] % MOD;
            }
            dp[i] %= MOD;
        }
        return dp[n];
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    s.numDecodings("1*");
}