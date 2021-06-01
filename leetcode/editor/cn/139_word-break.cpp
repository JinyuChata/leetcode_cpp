//给定一个非空字符串 s 和一个包含非空单词的列表 wordDict，判定 s 是否可以被空格拆分为一个或多个在字典中出现的单词。 
//
// 说明： 
//
// 
// 拆分时可以重复使用字典中的单词。 
// 你可以假设字典中没有重复的单词。 
// 
//
// 示例 1： 
//
// 输入: s = "leetcode", wordDict = ["leet", "code"]
//输出: true
//解释: 返回 true 因为 "leetcode" 可以被拆分成 "leet code"。
// 
//
// 示例 2： 
//
// 输入: s = "applepenapple", wordDict = ["apple", "pen"]
//输出: true
//解释: 返回 true 因为 "applepenapple" 可以被拆分成 "apple pen apple"。
//     注意你可以重复使用字典中的单词。
// 
//
// 示例 3： 
//
// 输入: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
//输出: false
// 
// Related Topics 动态规划 
// 👍 996 👎 0

#include <bits/stdc++.h>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int isSameTail(string& dictWord, string word) {
        if (word.size() < dictWord.size()) return 0;
        int i = dictWord.size() -1;
        int j = word.size() - 1;
        for (;i >= 0; i--, j--) {
            if (dictWord[i] != word[j]) return 0;
        }

        return 1;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        for (int i = 1; i <= n; i++) {
            // s[0 .. i) 是否能拆分
            for (string& dw : wordDict) {
                if (isSameTail(dw, s.substr(0, i)) && dp[i-dw.size()]) {
                    dp[i] = 1;
                }
            }
        }

        return dp[n];
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    vector<string> wd;
    wd.push_back("leet");
    wd.push_back("code");
    cout << s.wordBreak("leetcode", wd);
}