//给你一个字符串 s，请你将 s 分割成一些子串，使每个子串都是 回文串 。返回 s 所有可能的分割方案。 
//
// 回文串 是正着读和反着读都一样的字符串。 
//
// 
//
// 示例 1： 
//
// 
//输入：s = "aab"
//输出：[["a","a","b"],["aa","b"]]
// 
//
// 示例 2： 
//
// 
//输入：s = "a"
//输出：[["a"]]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= s.length <= 16 
// s 仅由小写英文字母组成 
// 
// Related Topics 深度优先搜索 动态规划 回溯算法 
// 👍 734 👎 0

#include <bits/stdc++.h>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    map<string, int> memo;

    int isPalind(string s) {
        if (memo.find(s) != memo.end()) return memo[s];

        int isOK = 1;
        for (int i = 0; i < s.size()/2; i++) {
            int j = s.size() - 1 - i;
            if (s[i] != s[j]) {
                isOK = 0;
                break;
            }
        }
        memo[s] = isOK;
        return isOK;
    }

    void traceback(string& s, int partI, vector<string>& vs, vector<vector<string>>& res) {
        if (partI == s.size()) {
            // 回溯到末尾，向res中添加
            res.emplace_back(vs);
            return;
        }

        // 在 partI -> s.size()-1 处切一刀
        for (int partTo = partI; partTo < s.size(); partTo++) {
            // [partI .. partTo]
            string next = s.substr(partI, partTo-partI+1);
            if (!isPalind(next)) continue;
            vs.emplace_back(next);
            traceback(s, partTo+1, vs, res);
            vs.pop_back();
        }
    }

    vector<vector<string>> partition(string s) {
        // 回溯算法
        vector<vector<string>> res;
        vector<string> vs;
        traceback(s, 0, vs, res);
        return res;
    }


};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
}