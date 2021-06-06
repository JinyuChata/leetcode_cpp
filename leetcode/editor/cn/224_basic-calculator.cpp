//给你一个字符串表达式 s ，请你实现一个基本计算器来计算并返回它的值。 
//
// 
//
// 示例 1： 
//
// 
//输入：s = "1 + 1"
//输出：2
// 
//
// 示例 2： 
//
// 
//输入：s = " 2-1 + 2 "
//输出：3
// 
//
// 示例 3： 
//
// 
//输入：s = "(1+(4+5+2)-3)+(6+8)"
//输出：23
// 
//
// 
//
// 提示： 
//
// 
// 1 <= s.length <= 3 * 105 
// s 由数字、'+'、'-'、'('、')'、和 ' ' 组成 
// s 表示一个有效的表达式 
// 
// Related Topics 栈 数学 
// 👍 573 👎 0

#include "bits/stdc++.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
map<char, int> prior;

class Solution {
public:
    int calculate(string s) {
        if (s.size() == 0) return 0;

        prior['('] = -1;
        prior[')'] = -1;
        prior['+'] = prior['-'] = 0;

        // 先转后序表达式
        stack<char> operatorStk;
        stack<int> numStk;

        int num = 0;
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (c == ' ') continue;
            // 遇到数字
            if (c >= '0' && c <= '9') {
                num *= 10;
                num += c - '0';
                if (i + 1 == s.size() || !(s[i + 1] >= '0' && s[i + 1] <= '9')) {
                    // 可以push num
                    numStk.push(num);
                    num = 0;
                }
            } else if (c == '(') {
                operatorStk.push(c);
            } else {
                while (!operatorStk.empty() && c != ' ' && prior[c] <= prior[operatorStk.top()]) {
                    char cc = operatorStk.top();
                    operatorStk.pop();
                    if (cc != '(') {
                        int n2 = numStk.top();
                        numStk.pop();
                        int n1 = numStk.top();
                        numStk.pop();
                        if (cc == '+') numStk.push(n1 + n2);
                        else if (cc == '-') numStk.push(n1 - n2);
                        else {
                            return -9999;
                        }
                    }
                    if (c == ')' && cc == '(') {
                        c = ' ';
                    }
                }
                if (c != ' ') operatorStk.push(c);
            }
        }

        while (!operatorStk.empty()) {
            char cc = operatorStk.top();
            operatorStk.pop();
            if (cc != '(') {
                int n2 = numStk.top();
                numStk.pop();
                int n1 = numStk.top();
                numStk.pop();
                if (cc == '+') numStk.push(n1 + n2);
                else if (cc == '-') numStk.push(n1 - n2);
                else {
                    return -9999;
                }
            }
        }

        return numStk.top();
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    cout << s.calculate("(1+(4+5+2)-3)+(6+8)");
}