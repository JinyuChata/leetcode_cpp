//给你一个由若干括号和字母组成的字符串 s ，删除最小数量的无效括号，使得输入的字符串有效。 
//
// 返回所有可能的结果。答案可以按 任意顺序 返回。 
//
// 
//
// 示例 1： 
//
// 
//输入：s = "()())()"
//输出：["(())()","()()()"]
// 
//
// 示例 2： 
//
// 
//输入：s = "(a)())()"
//输出：["(a())()","(a)()()"]
// 
//
// 示例 3： 
//
// 
//输入：s = ")("
//输出：[""]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= s.length <= 25 
// s 由小写英文字母以及括号 '(' 和 ')' 组成 
// s 中至多含 20 个括号 
// 
// Related Topics 广度优先搜索 字符串 回溯 
// 👍 488 👎 0

#include "bits/stdc++.h"
using namespace std;


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int size = 0;
    unordered_set<string> result;

    void dfs(string& s, int curr, int m, int score, string curStr) {
        if (curr == s.size()) {
            if (score == 0) {
                if (curStr.size() > size) {
                    result.clear(); size = curStr.size(); result.insert(curStr);
                } else if (curStr.size() == size) {
                    result.insert(curStr);
                }
            }
            return;
        }

        if (s[curr] != '(' && s[curr] != ')') {
            dfs(s, curr+1, m, score, curStr+s[curr]);
            return;
        }

        if (s[curr] == '(') {
            if (score+1 <= m) dfs(s, curr+1, m, score+1, curStr+'(');
            dfs(s, curr+1, m, score, curStr);
        } else {    // ')'
            if (score > 0) dfs(s, curr+1, m, score-1, curStr+')');
            dfs(s, curr+1, m, score, curStr);
        }
    }

    vector<string> removeInvalidParentheses(string s) {
        int left = 0, right = 0;
        for (char c : s) {
            if (c == '(') left++;
            else if (c == ')') right++;
        }
        int m = min(left, right);
        dfs(s, 0, m, 0, "");
        vector<string> ret;
        for (string s : result) ret.push_back(s);
        return ret;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    s.removeInvalidParentheses("()())()");
}