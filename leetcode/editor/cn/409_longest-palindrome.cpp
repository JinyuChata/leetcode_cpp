//给定一个包含大写字母和小写字母的字符串，找到通过这些字母构造成的最长的回文串。 
//
// 在构造过程中，请注意区分大小写。比如 "Aa" 不能当做一个回文字符串。 
//
// 注意: 
//假设字符串的长度不会超过 1010。 
//
// 示例 1: 
//
// 
//输入:
//"abccccdd"
//
//输出:
//7
//
//解释:
//我们可以构造的最长的回文串是"dccaccd", 它的长度是 7。
// 
// Related Topics 贪心 哈希表 字符串 
// 👍 315 👎 0

#include "bits/stdc++.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int longestPalindrome(string s) {
        int log[255] = {0};
        for (char c : s) {
            log[c] += 1;
        }

        int res = 0;
        for (int i = 'a'; i <= 'z'; i++) {
            res += (log[i] / 2 * 2);
        }
        for (int i = 'A'; i <= 'Z'; i++) {
            res += (log[i] / 2 * 2);
        }

        if (res < s.size()) res++;

        return res;

    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
}