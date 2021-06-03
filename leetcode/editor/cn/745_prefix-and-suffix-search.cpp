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
    string word;
    int weighMax = -1;
    vector<TrieNode *> children;

    TrieNode() : children(vector<TrieNode *>(27, nullptr)) {}
};

class WordFilter {
public:
    TrieNode *root = new TrieNode;

    WordFilter(vector<string> &words) {
        // 建立前缀树，拼接每个单词的可能 suffix#word
        for (int i = 0; i < words.size(); i++) {
            string& word = words[i];
            for (int start = 0; start < word.size(); start++) {
                auto p = root;
                string nS = word.substr(start) + "#" + word;
                bool after = false;
                for (char c : nS) {
                    int idx = c == '#' ? 26 : c - 'a';

                    if (!p->children[idx]) {
                        p->children[idx] = new TrieNode;
                    }
                    p = p->children[idx];
                    if (idx == 26) after = true;
                    if (after) {
                        p->word = nS;
                        p->weighMax = max(p->weighMax, i);
                    }
                }
            }
        }
    }

    int f(string prefix, string suffix) {
        string concat = suffix + "#" + prefix;
        int res;
        auto p = root;
        for (char c : concat) {
            int idx = c == '#' ? 26 : c - 'a';
            if (!p->children[idx]) {
                return -1;
            }
            p = p->children[idx];
        }

        return p->weighMax;
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
}