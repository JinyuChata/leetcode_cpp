//给定一组 互不相同 的单词， 找出所有 不同 的索引对 (i, j)，使得列表中的两个单词， words[i] + words[j] ，可拼接成回文串。 
//
// 
//
// 示例 1：
//
// 
//输入：words = ["abcd","dcba","lls","s","sssll"]
//输出：[[0,1],[1,0],[3,2],[2,4]] 
//解释：可拼接成的回文串为 ["dcbaabcd","abcddcba","slls","llssssll"]
// 
//
// 示例 2： 
//
// 
//输入：words = ["bat","tab","cat"]
//输出：[[0,1],[1,0]] 
//解释：可拼接成的回文串为 ["battab","tabbat"] 
//
// 示例 3： 
//
// 
//输入：words = ["a",""]
//输出：[[0,1],[1,0]]
// 
// 
//
// 提示： 
//
// 
// 1 <= words.length <= 5000 
// 0 <= words[i].length <= 300 
// words[i] 由小写英文字母组成 
// 
// Related Topics 字典树 哈希表 字符串 
// 👍 230 👎 0

#include "bits/stdc++.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
// 建立字典树，逆向存入words；遍历每个word的同时，遍历索引树
class TrieNode {
public:
    int idx = -1;
    string word = "";
    vector<TrieNode *> children;

    TrieNode() : children(vector<TrieNode *>(26, nullptr)) {}
};

class Solution {
public:
    vector<vector<int>> ress;

    bool isPar(const string &s) {
        int n = s.size();
        if (n == 0) return true;
        for (int i = 0; i <= n / 2; i++) {
            int j = n - i - 1;
            if (s[i] != s[j]) return false;
        }
        return true;
    }

    vector<vector<int>> palindromePairs(vector<string> &words) {
        // 建立逆序的索引树
        auto *root = new TrieNode;

        for (int k = 0; k < words.size(); k++) {
            string &word = words[k];
            TrieNode *p = root;
            string rev;
            for (int i = word.size() - 1; i >= 0; i--) {
                char c = word[i];
                if (!p->children[c - 'a']) p->children[c - 'a'] = new TrieNode;
                p = p->children[c - 'a'];
                rev += string(1, c);
            }
            p->idx = k;
            p->word = rev;
        }

        // 遍历每一个元素，寻找对应的逆序串
        for (int i = 0; i < words.size(); i++) {
            // i 要和某一个匹配
            string &s1 = words[i];
            cout << "Checking " << i << ", s1= " << s1 << endl;
//            if (s1.empty()) {
//                // 检查其他的，能和所有回文串构成回文串
//                for (int j = 0; j < words.size(); j++) {
//                    if (i != j && isPar(words[j]))
//                        ress.push_back({i,j});
//                }
//            }

            if (isPar(s1) && root->idx != -1 && root->idx != i) {
                ress.push_back({i, root->idx});
            }

            auto *p = root;
            for (int j = 0; j < s1.size(); j++) {
                char c = s1[j];
                if (!p->children[c - 'a']) {
                    // 找不到了
                    p = p->children[c - 'a'];
                    break;
                }
                p = p->children[c - 'a'];
                // 找到p, 查看是否为某个单词的结尾
                if (p->idx != -1) {
                    if (i != p->idx && s1.size() == words[p->idx].size()) {
                        // s1 == s2 确定没问题
                        ress.push_back({i, p->idx});
                    } else if (i != p->idx && isPar(s1.substr(words[p->idx].size()))) {
                        // s1 > s2
                        ress.push_back({i, p->idx});
                    }
                }
            }

            // s1 < s2, s2还有内容
            if (p) {
                dfs("", p, words, i, 0);
            }
        }
        return ress;
    }

    void dfs(const string &append, TrieNode *tn, vector<string> &words, int s1Idx, int lvl) {
        if (!tn) return;
        if (tn->idx != -1 && isPar(append) && s1Idx != tn->idx && lvl > 0) {
            ress.push_back({s1Idx, tn->idx});
        }
        for (int i = 0; i < 26; i++) {
            if (tn->children[i]) {
                dfs(append + string(1, (char) (i + 'a')), tn->children[i], words, s1Idx, lvl + 1);
            }
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)

/*
测试结果:[[5,5],[5,7],[5,9],[5,2],[5,1],[5,0],[6,0],[7,5],[7,4],[8,9],[8,2],[9,5],[9,0]]
期望结果:[[9,0],[5,0],[5,1],[8,2],[5,2],[7,4],[6,0],[7,5],[5,7],[8,9],[9,5],[5,9]]
 */

int main() {
    Solution s;
    vector<string> v = {"a",""};
    s.palindromePairs(v);
}