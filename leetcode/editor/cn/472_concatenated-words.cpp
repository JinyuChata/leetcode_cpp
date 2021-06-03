//给定一个 不含重复 单词的字符串数组 words ，编写一个程序，返回 words 中的所有 连接词 。 
//
// 连接词 的定义为：一个字符串完全是由至少两个给定数组中的单词组成的。 
//
// 
//
// 示例 1： 
//
// 
//输入：words = ["cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"]
//输出：["catsdogcats","dogcatsdog","ratcatdogcat"]
//解释："catsdogcats"由"cats", "dog" 和 "cats"组成; 
//     "dogcatsdog"由"dog", "cats"和"dog"组成; 
//     "ratcatdogcat"由"rat", "cat", "dog"和"cat"组成。
// 
//
// 示例 2： 
//
// 
//输入：words = ["cat","dog","catdog"]
//输出：["catdog"] 
//
// 
//
// 提示： 
//
// 
// 1 <= words.length <= 104 
// 0 <= words[i].length <= 1000 
// words[i] 仅由小写字母组成 
// 0 <= sum(words[i].length) <= 6 * 105 
// 
// Related Topics 深度优先搜索 字典树 动态规划 
// 👍 103 👎 0

#include "bits/stdc++.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class TrieNode {
public:
    int idx = -1;
    vector<TrieNode*> children;

    TrieNode() : children(vector<TrieNode*>(26, nullptr)) {}
};

class Solution {
public:
    vector<string> res;
    set<string> resSet;

    void dfs(TrieNode* root, TrieNode* last, string& word, int idx, int count, vector<string>& words) {
        int j;
        auto p = root;
        for (j = idx; j < word.size(); j++) {
            char c = word[j];
            if (!p) return;
            if (p->idx != -1 && p != last) {
                dfs(root, p, word, j, count+1, words);
            }

            p = p->children[c-'a'];
            if (!p) return;

            if (j == word.size() - 1 && p->idx != -1) {
                // 查完了
                if (count && word != words[p->idx] && resSet.find(word) == resSet.end()) {
                    res.push_back(word);
                    resSet.insert(word);
                    return;
                }
            }
        }



    }

    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        auto* root = new TrieNode;
        // 建树
        for (int i = 0; i < words.size(); i++) {
            string& word = words[i];
            TrieNode* p = root;
            for (char c : word) {
                if (!p->children[c-'a']) {
                    p->children[c-'a'] = new TrieNode;
                }
                p = p->children[c-'a'];
            }
            p->idx = i;
        }

        // 查询
        for (int i = 0; i < words.size(); i++) {
            string& word = words[i];
            cout << "USE " << word << endl;
            dfs(root, nullptr, word, 0, 0, words);
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    vector<string> v {"cat","dog","catdog"};
    s.findAllConcatenatedWordsInADict(v);
}