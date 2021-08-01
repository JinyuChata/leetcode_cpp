//给定一个平衡括号字符串 S，按下述规则计算该字符串的分数： 
//
// 
// () 得 1 分。 
// AB 得 A + B 分，其中 A 和 B 是平衡括号字符串。 
// (A) 得 2 * A 分，其中 A 是平衡括号字符串。 
// 
//
// 
//
// 示例 1： 
//
// 输入： "()"
//输出： 1
// 
//
// 示例 2： 
//
// 输入： "(())"
//输出： 2
// 
//
// 示例 3： 
//
// 输入： "()()"
//输出： 2
// 
//
// 示例 4： 
//
// 输入： "(()(()))"
//输出： 6
// 
//
// 
//
// 提示： 
//
// 
// S 是平衡括号字符串，且只含有 ( 和 ) 。 
// 2 <= S.length <= 50 
// 
// Related Topics 栈 字符串 
// 👍 216 👎 0

#include "bits/stdc++.h"
using namespace std;

// ()(())
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // [start, end]
    double parse(string& s, int start, int end) {
        cout << start << ", " << end << endl;
        if (start > end) return 0.5;
        double res = 0;
        // 先拆分平级
        int counter = 0, lastIdx = start, idx;
        // 遇到idx=0, 则[lastIdx,idx]可以被拆分
        for (idx = start; idx <= end; idx++) {
            if (s[idx] == '(') counter++;
            else if (s[idx] == ')') counter--;

            if (counter == 0) {
                // [lastIdx, idx]
                res += 2.0 * parse(s, lastIdx+1, idx-1);
                lastIdx = idx+1;
            }
        }
        return res;
    }

    int scoreOfParentheses(string s) {
        return (int) parse(s, 0, s.size()-1);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
}