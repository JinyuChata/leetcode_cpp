//给定一个非空字符串 s 和一个包含非空单词列表的字典 wordDict，在字符串中增加空格来构建一个句子，使得句子中所有的单词都在词典中。返回所有这些可能的
//句子。 
//
// 说明： 
//
// 
// 分隔时可以重复使用字典中的单词。 
// 你可以假设字典中没有重复的单词。 
// 
//
// 示例 1： 
//
// 输入:
//s = "catsanddog"
//wordDict = ["cat", "cats", "and", "sand", "dog"]
//输出:
//[
//  "cats and dog",
//  "cat sand dog"
//]
// 
//
// 示例 2： 
//
// 输入:
//s = "pineapplepenapple"
//wordDict = ["apple", "pen", "applepen", "pine", "pineapple"]
//输出:
//[
//  "pine apple pen apple",
//  "pineapple pen apple",
//  "pine applepen apple"
//]
//解释: 注意你可以重复使用字典中的单词。
// 
//
// 示例 3： 
//
// 输入:
//s = "catsandog"
//wordDict = ["cats", "dog", "sand", "and", "cat"]
//输出:
//[]
// 
// Related Topics 动态规划 回溯算法 
// 👍 459 👎 0

#include <bits/stdc++.h>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // 回溯时，加上word+" "
    vector<string> res;

    void traceback(string& s, int splitFrom, vector<string>& splited, vector<string>& wordDict) {
        int n = s.size();
        // 到达最后
        if (splitFrom == n) {
            string resStr;
            for (int i = 0; i < splited.size(); i++) {
                resStr += splited[i];
                if (i != splited.size()-1) resStr += " ";
            }
            res.push_back(resStr);
            return;
        }

        // 未到达最后 [splitFrom, n)
        for (string& dw : wordDict) {
            if (dw.size() > n - splitFrom) continue;
            int si = splitFrom;
            int isOK = 1;
            for (int wi = 0; wi < dw.size(); si++, wi++) {
                if (dw[wi] != s[si]) { isOK = 0; break; }
            }
            if (isOK) {
                splited.push_back(dw);
                traceback(s, splitFrom+dw.size(), splited, wordDict);
                splited.pop_back();
            }
        }

    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        // 回溯
        vector<string> splited;
        traceback(s, 0, splited, wordDict);
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
}