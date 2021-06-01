//给你两个单词 word1 和 word2，请你计算出将 word1 转换成 word2 所使用的最少操作数 。 
//
// 你可以对一个单词进行如下三种操作： 
//
// 
// 插入一个字符 
// 删除一个字符 
// 替换一个字符 
// 
//
// 
//
// 示例 1： 
//
// 
//输入：word1 = "horse", word2 = "ros"
//输出：3
//解释：
//horse -> rorse (将 'h' 替换为 'r')
//rorse -> rose (删除 'r')
//rose -> ros (删除 'e')
// 
//
// 示例 2： 
//
// 
//输入：word1 = "intention", word2 = "execution"
//输出：5
//解释：
//intention -> inention (删除 't')
//inention -> enention (将 'i' 替换为 'e')
//enention -> exention (将 'n' 替换为 'x')
//exention -> exection (将 'n' 替换为 'c')
//exection -> execution (插入 'u')
// 
//
// 
//
// 提示： 
//
// 
// 0 <= word1.length, word2.length <= 500 
// word1 和 word2 由小写英文字母组成 
// 
// Related Topics 字符串 动态规划 
// 👍 1622 👎 0

#include <bits/stdc++.h>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string w1;
    string w2;

    vector<vector<int>>* memo;

    int minDistance(string word1, string word2) {
        this->w1 = word1;
        this->w2 = word2;
        memo = new vector<vector<int>>(w1.size(), vector<int>(w2.size(), -1));

        return dp(word1.size()-1, word2.size()-1);
    }

    int dp(int i, int j) {
        if (i == -1) return j+1;        // w1已经没有字，则插入w2的内容
        if (j == -1) return i+1;        // w2已经没有字，则删除w1的内容

        if ((*memo)[i][j] != -1)
            return (*memo)[i][j];

        if (this->w1[i] == this->w2[j]) {
            // 两者相同 skip
            (*memo)[i][j] = dp(i-1, j-1);
        } else {
            (*memo)[i][j] = 1 + min(min(dp(i, j-1), dp(i-1, j)), dp(i-1, j-1));
        }

        return (*memo)[i][j];

    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
}