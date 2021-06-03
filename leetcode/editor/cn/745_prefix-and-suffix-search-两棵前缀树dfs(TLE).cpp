//给定多个 words，words[i] 的权重为 i 。 
//
// 设计一个类 WordFilter 实现函数WordFilter.f(String prefix, String suffix)。这个函数将返回具有前缀 p
//refix 和后缀suffix 的词的最大权重。如果没有这样的词，返回 -1。 
//
// 例子: 
//
// 
//输入:
//WordFilter(["apple"])
//WordFilter.f("a", "e") // 返回 0
//WordFilter.f("b", "") // 返回 -1
// 
//
// 注意: 
//
// 
// words的长度在[1, 15000]之间。 
// 对于每个测试用例，最多会有words.length次对WordFilter.f的调用。 
// words[i]的长度在[1, 10]之间。 
// prefix, suffix的长度在[0, 10]之前。 
// words[i]和prefix, suffix只包含小写字母。 
// 
// Related Topics 字典树 
// 👍 64 👎 0

#include "bits/stdc++.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class TrieNode {
public:
    int weigh = -1;
    string word = "";
    vector<TrieNode*> children;

    TrieNode(): children(vector<TrieNode*>(26, nullptr)) {}
};

class WordFilter {
public:
    TrieNode* ascend;
    TrieNode* descend;

    WordFilter(vector<string>& words) {
        ascend = new TrieNode;
        descend = new TrieNode;
        for (int i = 0; i < words.size(); i++) {
            string& word = words[i];
            TrieNode* p = ascend;
            for (char c : word) {
                if (!p->children[c-'a']) p->children[c-'a'] = new TrieNode;
                p = p->children[c-'a'];
            }
            p->weigh = i;
            p->word = word;

            p = descend;
            for (int j = word.size() - 1; j >= 0; j--) {
                char c = word[j];
                if (!p->children[c-'a']) p->children[c-'a'] = new TrieNode;
                p = p->children[c-'a'];
            }
            p->weigh = i;
            p->word = word;
        }
    }

    void dfs(set<int>& counted, TrieNode* p, int& res) {
        if (!p) return;
        if (p->weigh != -1) {
            // 放入counted
            if (counted.find(p->weigh) == counted.end()) {
                counted.insert(p->weigh);
            } else {
                // 可以替换
                if (p->weigh > res) res = p->weigh;
            }
        }

        // 循环
        for (int i = 0; i < 26; i++) {
            dfs(counted, p->children[i], res);
        }
    }

    int f(string prefix, string suffix) {
        set<int> counted;
        string rev_suffix;
        for (int i = suffix.size()-1; i >= 0; i--)
            rev_suffix += suffix[i];

        TrieNode* p_asc = ascend;
        for (char c : prefix) {
            if (!p_asc->children[c - 'a']) return -1;
            p_asc = p_asc->children[c - 'a'];
        }

        TrieNode* p_desc = descend;
        for (char c : rev_suffix) {
            if (!p_desc->children[c - 'a']) return -1;
            p_desc = p_desc->children[c - 'a'];
        }

        int res = -1;
        dfs(counted, p_asc, res);
        dfs(counted, p_desc, res);

        return res;

    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */
//leetcode submit region end(Prohibit modification and deletion)


int main() {
//    Solution s;
    vector<string> vs = {"apple"};
    WordFilter w(vs);
    cout << w.f("a", "e") << endl;
    cout << w.f("b", "") << endl;
}