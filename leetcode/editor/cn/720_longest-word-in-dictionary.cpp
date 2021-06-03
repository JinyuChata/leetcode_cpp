//给出一个字符串数组words组成的一本英语词典。从中找出最长的一个单词，该单词是由words词典中其他单词逐步添加一个字母组成。若其中有多个可行的答案，则返
//回答案中字典序最小的单词。 
//
// 若无答案，则返回空字符串。 
//
// 
//
// 示例 1： 
//
// 输入：
//words = ["w","wo","wor","worl", "world"]
//输出："world"
//解释： 
//单词"world"可由"w", "wo", "wor", 和 "worl"添加一个字母组成。
// 
//
// 示例 2： 
//
// 输入：
//words = ["a", "banana", "app", "appl", "ap", "apply", "apple"]
//输出："apple"
//解释：
//"apply"和"apple"都能由词典中的单词组成。但是"apple"的字典序小于"apply"。
// 
//
// 
//
// 提示： 
//
// 
// 所有输入的字符串都只包含小写字母。 
// words数组长度范围为[1,1000]。 
// words[i]的长度范围为[1,30]。 
// 
// Related Topics 字典树 哈希表 
// 👍 135 👎 0
#include "bits/stdc++.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class TrieNode {
public:
    string word = "";
    int val = 0;
    vector<TrieNode*> children;

    TrieNode(): children(vector<TrieNode*>(26, nullptr)) {}
};

class Solution {
public:
    string res;
    void dfs(TrieNode* p) {
        if (!p) return;
        if (p->val && p->word.size() > res.size() || (p->word.size() == res.size() && p->word < res)) {
            res = p->word;
        }

        if (p->val) {
            for (int i = 0; i < 26; i++) {
                dfs(p->children[i]);
            }
        }
    }

    string longestWord(vector<string>& words) {
        auto* root = new TrieNode;
        root->val = 1;
        for (string& word : words) {
            auto p = root;
            for (char c : word) {
                if (!p->children[c-'a']) p->children[c-'a'] = new TrieNode;
                p = p->children[c-'a'];
            }
            p->word = word;
            p->val = 1;
        }

        // dfs 表
        dfs(root);
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    vector<string> res = {"w","wo","wor","worl", "world"};
    s.longestWord(res);
}