//设计一个使用单词列表进行初始化的数据结构，单词列表中的单词 互不相同 。 如果给出一个单词，请判定能否只将这个单词中一个字母换成另一个字母，使得所形成的新单
//词存在于你构建的字典中。 
//
// 实现 MagicDictionary 类： 
//
// 
// MagicDictionary() 初始化对象 
// void buildDict(String[] dictionary) 使用字符串数组 dictionary 设定该数据结构，dictionary 中的字
//符串互不相同 
// bool search(String searchWord) 给定一个字符串 searchWord ，判定能否只将字符串中 一个 字母换成另一个字母，使得
//所形成的新字符串能够与字典中的任一字符串匹配。如果可以，返回 true ；否则，返回 false 。 
// 
//
// 
//
// 
// 
// 
// 示例： 
//
// 
//输入
//["MagicDictionary", "buildDict", "search", "search", "search", "search"]
//[[], [["hello", "leetcode"]], ["hello"], ["hhllo"], ["hell"], ["leetcoded"]]
//输出
//[null, null, false, true, false, false]
//
//解释
//MagicDictionary magicDictionary = new MagicDictionary();
//magicDictionary.buildDict(["hello", "leetcode"]);
//magicDictionary.search("hello"); // 返回 False
//magicDictionary.search("hhllo"); // 将第二个 'h' 替换为 'e' 可以匹配 "hello" ，所以返回 True
//magicDictionary.search("hell"); // 返回 False
//magicDictionary.search("leetcoded"); // 返回 False
// 
//
// 
//
// 提示： 
//
// 
// 1 <= dictionary.length <= 100 
// 1 <= dictionary[i].length <= 100 
// dictionary[i] 仅由小写英文字母组成 
// dictionary 中的所有字符串 互不相同 
// 1 <= searchWord.length <= 100 
// searchWord 仅由小写英文字母组成 
// buildDict 仅在 search 之前调用一次 
// 最多调用 100 次 search 
// 
// 
// 
// 
// Related Topics 字典树 哈希表 
// 👍 83 👎 0

#include "bits/stdc++.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class TrieNode {
public:
    string word = "";
    vector<TrieNode*> children;

    TrieNode(): children(vector<TrieNode*>(26, nullptr)) {}
};

class MagicDictionary {
public:
    TrieNode* root;

    /** Initialize your data structure here. */
    MagicDictionary() {
        root = new TrieNode;
    }
    
    void buildDict(vector<string> dictionary) {
        // 建树
        for (string& word : dictionary) {
            TrieNode* p = root;
            for (char c : word) {
                if (!p->children[c-'a']) {
                    p->children[c-'a'] = new TrieNode;
                }
                p = p->children[c-'a'];
            }
            p->word = word;
        }
    }
    
    bool search(string searchWord) {
        // 记录一个count，dfs
        return dfs(root, searchWord, 0, 0);
    }

    bool dfs(TrieNode* rot, string& searchWord, int curIdx, int cnt = 0) {
        auto p = rot;
        for (int i = curIdx; i < searchWord.size(); i++) {
            // 变化
            char c = searchWord[i];
            if (cnt == 0) {
                for (int toChange = 0; toChange < 26; toChange++) {
                    if (p->children[toChange] && toChange != c-'a') {
                        if (dfs(p->children[toChange], searchWord, i+1, cnt+1)) return true;
                    }
                }
            }
            // 不变
            if (p->children[c-'a']) {
                p = p->children[c-'a'];
            } else return false;
        }

        if (cnt == 1 && p && !p->word.empty()) return true;
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */
//leetcode submit region end(Prohibit modification and deletion)


int main() {
//    Solution s;
    MagicDictionary m;
    vector<string> dict {"hello","leetcode"};
    m.buildDict(dict);
    cout << m.search("hhllo");
}