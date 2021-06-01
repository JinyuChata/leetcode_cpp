//给定一个 m x n 二维字符网格 board 和一个单词（字符串）列表 words，找出所有同时在二维网格和字典中出现的单词。 
//
// 单词必须按照字母顺序，通过 相邻的单元格 内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母在一个单词中不允许被重复使
//用。 
//
// 
//
// 示例 1： 
//
// 
//输入：board = [["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l"
//,"v"]], words = ["oath","pea","eat","rain"]
//输出：["eat","oath"]
// 
//
// 示例 2： 
//
// 
//输入：board = [["a","b"],["c","d"]], words = ["abcb"]
//输出：[]
// 
//
// 
//
// 提示： 
//
// 
// m == board.length 
// n == board[i].length 
// 1 <= m, n <= 12 
// board[i][j] 是一个小写英文字母 
// 1 <= words.length <= 3 * 104 
// 1 <= words[i].length <= 10 
// words[i] 由小写英文字母组成 
// words 中的所有字符串互不相同 
// 
// Related Topics 字典树 回溯算法 
// 👍 394 👎 0

#include "bits/stdc++.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
// 字典树 模板
class TrieNode{
public:
    string word = "";           // 如果是某个word的结尾，则word不为空 (标记字典树节点涂色)
    vector<TrieNode*> nodes;

    // 字典树的优势：查找字符串快
    // 先对每个节点都赋予空值，表示没有下一个可能的连接
    TrieNode(): nodes(vector<TrieNode*>(26, nullptr)) {}

};


class Solution {
public:
    set<string> resSet;
    vector<string> res;

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        auto* node = new TrieNode;
        // 字典树建树
        for (const string& word : words) {
            auto p = node;
            for (char c : word) {
                if (!p->nodes[c-'a']) {
                    // 需要连上一个新节点
                    p->nodes[c-'a'] = new TrieNode;
                }
                p = p->nodes[c-'a'];
            }
            p->word = word;
        }

        // dfs模板
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                dfs(board, i, j, node);
            }
        }

        return res;
    }

    // root 指上一级
    void dfs(vector<vector<char>>& board, int i, int j, TrieNode* root) {
        // 退出条件
        int m = board.size();
        int n = board[0].size();

        char c = board[i][j];
        if (c == '.' || !root->nodes[c-'a']) {
            return;
        }
        root = root->nodes[c-'a'];

        // 已经找到一个了
        if (!root->word.empty()) {
            if (resSet.find(root->word) == resSet.end()) {
                res.push_back(root->word);
                resSet.insert(root->word);
            }
        }

        board[i][j] = '.';
        if (i-1 >= 0) dfs(board, i-1, j, root);
        if (i+1 < m) dfs(board, i+1, j, root);
        if (j-1 >= 0) dfs(board, i, j-1, root);
        if (j+1 < n) dfs(board, i, j+1, root);
        board[i][j] = c;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
}