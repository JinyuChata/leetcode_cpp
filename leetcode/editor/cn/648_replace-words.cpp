//在英语中，我们有一个叫做 词根(root)的概念，它可以跟着其他一些词组成另一个较长的单词——我们称这个词为 继承词(successor)。例如，词根an，
//跟随着单词 other(其他)，可以形成新的单词 another(另一个)。 
//
// 现在，给定一个由许多词根组成的词典和一个句子。你需要将句子中的所有继承词用词根替换掉。如果继承词有许多可以形成它的词根，则用最短的词根替换它。 
//
// 你需要输出替换之后的句子。 
//
// 
//
// 示例 1： 
//
// 输入：dictionary = ["cat","bat","rat"], sentence = "the cattle was rattled by th
//e battery"
//输出："the cat was rat by the bat"
// 
//
// 示例 2： 
//
// 输入：dictionary = ["a","b","c"], sentence = "aadsfasf absbs bbab cadsfafs"
//输出："a a b c"
// 
//
// 示例 3： 
//
// 输入：dictionary = ["a", "aa", "aaa", "aaaa"], sentence = "a aa a aaaa aaa aaa a
//aa aaaaaa bbb baba ababa"
//输出："a a a a a a a a bbb baba a"
// 
//
// 示例 4： 
//
// 输入：dictionary = ["catt","cat","bat","rat"], sentence = "the cattle was rattle
//d by the battery"
//输出："the cat was rat by the bat"
// 
//
// 示例 5： 
//
// 输入：dictionary = ["ac","ab"], sentence = "it is abnormal that this solution is
// accepted"
//输出："it is ab that this solution is ac"
// 
//
// 
//
// 提示： 
//
// 
// 1 <= dictionary.length <= 1000 
// 1 <= dictionary[i].length <= 100 
// dictionary[i] 仅由小写字母组成。 
// 1 <= sentence.length <= 10^6 
// sentence 仅由小写字母和空格组成。 
// sentence 中单词的总量在范围 [1, 1000] 内。 
// sentence 中每个单词的长度在范围 [1, 1000] 内。 
// sentence 中单词之间由一个空格隔开。 
// sentence 没有前导或尾随空格。 
// 
// Related Topics 字典树 哈希表 
// 👍 122 👎 0
#include "bits/stdc++.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class TrieNode {
public:
    string s = "";
    vector<TrieNode *> children;

    TrieNode() : children(vector<TrieNode *>(26, nullptr)) {}        // 看到a-z限定，想到字典树
};

class Solution {
public:
    string replaceWords(vector<string> &dictionary, string sentence) {
        // 建树
        TrieNode *root = new TrieNode;
        for (string &s : dictionary) {
            auto p = root;
            for (char c : s) {
                if (!p->children[c - 'a']) p->children[c - 'a'] = new TrieNode;
                p = p->children[c - 'a'];
            }
            p->s = s;
        }

        int lastIdx = 0;
        string res;
        for (int checkIdx = 0; checkIdx <= sentence.size(); checkIdx++) {
            if (checkIdx == sentence.size() || sentence[checkIdx] == ' ') {
                string s = sentence.substr(lastIdx, checkIdx - lastIdx);
                cout << "Check " << s << endl;
                lastIdx = checkIdx + 1;
                // 检查s
                auto p = root;
                for (int i = 0; i <= s.size(); i++) {
                    char c = s[i];

                    // 能匹配上
                    if (!p->s.empty()) {
                        res += p->s;
                        break;
                    }

                    if (i == s.size()) {
                        res += s;
                        break;
                    }

                    if (!p->children[c - 'a']) {
                        if (!p->s.empty()) {
                            res += p->s;
                            break;
                        } else {
                            res += s;
                            break;
                        }
                    }
                    p = p->children[c - 'a'];
                }

                if (checkIdx != sentence.size()) {
                    res += " ";
                }
            }
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    vector<string> vs {"a", "aa", "aaa", "aaaa"};
    s.replaceWords(vs, "a aa a aaaa aaa aaa aaa aaaaaa bbb baba ababa");
}