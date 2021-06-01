//数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。 
//
// 
//
// 示例 1： 
//
// 
//输入：n = 3
//输出：["((()))","(()())","(())()","()(())","()()()"]
// 
//
// 示例 2： 
//
// 
//输入：n = 1
//输出：["()"]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= n <= 8 
// 
// Related Topics 字符串 回溯算法 
// 👍 1804 👎 0
#include "bits/stdc++.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<string> ress;

    void traceback(int remainLeft, int remainRight, string s) {
        if (remainLeft == 0) {
            while (remainRight > 0) {
                s += ")";
                remainRight--;
            }
            ress.push_back(s);
            return;
        }

        // 正常情况
        // 加一个左括号
        traceback(remainLeft-1, remainRight+1, s+"(");
        // 如果可以，加一个右括号
        if (remainRight > 0) {
            traceback(remainLeft, remainRight-1, s+")");
        }
    }

    vector<string> generateParenthesis(int n) {
        traceback(n, 0, "");
        return ress;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
