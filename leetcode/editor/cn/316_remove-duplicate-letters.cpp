//给你一个字符串 s ，请你去除字符串中重复的字母，使得每个字母只出现一次。需保证 返回结果的字典序最小（要求不能打乱其他字符的相对位置）。 
//
// 注意：该题与 1081 https://leetcode-cn.com/problems/smallest-subsequence-of-distinct
//-characters 相同 
//
// 
//
// 示例 1： 
//
// 
//输入：s = "bcabc"
//输出："abc"
// 
//
// 示例 2： 
//
// 
//输入：s = "cbacdcbc"
//输出："acdb" 
//
// 
//
// 提示： 
//
// 
// 1 <= s.length <= 104 
// s 由小写英文字母组成 
// 
// Related Topics 栈 贪心算法 字符串 
// 👍 536 👎 0
#include <bits/stdc++.h>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string removeDuplicateLetters(string s) {
        // dupTimes[i] == 1 则不能再删了
        vector<int> dupTimes = vector<int>('z'+1, 0);
        vector<int> existTime = vector<int>('z'+1, 0);
        for (char c : s)
            dupTimes[c]++;

        stack<char> stk;
        for (char c : s) {
            if (existTime[c] == 0) {

                while (!stk.empty() && dupTimes[stk.top()] > 0 && c < stk.top()) {
                    existTime[stk.top()]--;
                    stk.pop();
                }
                stk.push(c);
                existTime[stk.top()]++;
            }
            dupTimes[c]--;
        }

        string res = "";
        while (!stk.empty()) {
            res = stk.top() + res;
            stk.pop();
        }

        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    s.removeDuplicateLetters("edebbed");
}