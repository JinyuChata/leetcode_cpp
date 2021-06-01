//请你设计一个数据结构，支持 添加新单词 和 查找字符串是否与任何先前添加的字符串匹配 。 
//
// 实现词典类 WordDictionary ： 
//
// 
// WordDictionary() 初始化词典对象 
// void addWord(word) 将 word 添加到数据结构中，之后可以对它进行匹配 
// bool search(word) 如果数据结构中存在字符串与 word 匹配，则返回 true ；否则，返回 false 。word 中可能包含一些 '
//.' ，每个 . 都可以表示任何一个字母。 
// 
//
// 
//
// 示例： 
//
// 
//输入：
//["WordDictionary","addWord","addWord","addWord","search","search","search","se
//arch"]
//[[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]
//输出：
//[null,null,null,null,false,true,true,true]
//
//解释：
//WordDictionary wordDictionary = new WordDictionary();
//wordDictionary.addWord("bad");
//wordDictionary.addWord("dad");
//wordDictionary.addWord("mad");
//wordDictionary.search("pad"); // return False
//wordDictionary.search("bad"); // return True
//wordDictionary.search(".ad"); // return True
//wordDictionary.search("b.."); // return True
// 
//
// 
//
// 提示： 
//
// 
// 1 <= word.length <= 500 
// addWord 中的 word 由小写英文字母组成 
// search 中的 word 由 '.' 或小写英文字母组成 
// 最多调用 50000 次 addWord 和 search 
// 
// Related Topics 深度优先搜索 设计 字典树 回溯算法 
// 👍 247 👎 0
#include "bits/stdc++.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
#define MAX_NODE 50000
#define CHAR_SET 26
// 字符集大小: 0-26

class WordDictionary {
public:
    // -1 说明还没有连上
    int tries[MAX_NODE][CHAR_SET] = {0};
    int color[MAX_NODE] = {0};
    int k = 1;      // 下一个可以使用的空闲节点是啥
    // 0号节点，是所有单词的parent，是空节点

    /** Initialize your data structure here. */
    WordDictionary() = default;
    
    void addWord(string word) {
        int p = 0;
        for (char c : word) {
            int charNo = c - 'a';
            if (!tries[p][charNo]) {
                tries[p][charNo] = k++;
            }
            p = tries[p][charNo];
        }
        color[p] = 1;
    }
    
    bool search(string word) {
        int p = 0;
        int lvlSize = 1;
        queue<int> nodeQueue;

        nodeQueue.push(0);
        for (char c : word) {
            int newSize = 0;
            for (int i = 0; i < lvlSize; i++) {
                // 出队列
                int parNo = nodeQueue.front();
                nodeQueue.pop();
                if (c == '.') {
                    // 将这个parNo的所有儿子推进去
                    for (int j = 0; j < CHAR_SET; j++) {
                        if (tries[parNo][j]) {
                            nodeQueue.push(tries[parNo][j]);
                            newSize++;
                        }
                    }
                } else {
                    int charNo = c - 'a';
                    if (tries[parNo][charNo]) {
                        nodeQueue.push(tries[parNo][charNo]);
                        newSize++;
                    }
                }
            }
            lvlSize = newSize;
            if (lvlSize == 0) return false;
        }
        for (int i = 0; i < lvlSize; i++) {
            int parNo = nodeQueue.front();
            nodeQueue.pop();
            if (color[parNo]) return true;
        }

        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    WordDictionary w;
    w.addWord("bad");
    w.addWord("dad");
    w.addWord("pad");
}