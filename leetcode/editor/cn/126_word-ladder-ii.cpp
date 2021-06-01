//按字典 wordList 完成从单词 beginWord 到单词 endWord 转化，一个表示此过程的 转换序列 是形式上像 beginWord -> s
//1 -> s2 -> ... -> sk 这样的单词序列，并满足： 
//
// 
// 
// 
// 每对相邻的单词之间仅有单个字母不同。 
// 转换过程中的每个单词 si（1 <= i <= k）必须是字典 wordList 中的单词。注意，beginWord 不必是字典 wordList 中的单
//词。 
// sk == endWord 
// 
//
// 给你两个单词 beginWord 和 endWord ，以及一个字典 wordList 。请你找出并返回所有从 beginWord 到 endWord 的
// 最短转换序列 ，如果不存在这样的转换序列，返回一个空列表。每个序列都应该以单词列表 [beginWord, s1, s2, ..., sk] 的形式返回。 
//
// 
//
// 示例 1： 
//
// 
//输入：beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","lo
//g","cog"]
//输出：[["hit","hot","dot","dog","cog"],["hit","hot","lot","log","cog"]]
//解释：存在 2 种最短的转换序列：
//"hit" -> "hot" -> "dot" -> "dog" -> "cog"
//"hit" -> "hot" -> "lot" -> "log" -> "cog"
// 
//
// 示例 2： 
//
// 
//输入：beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","lo
//g"]
//输出：[]
//解释：endWord "cog" 不在字典 wordList 中，所以不存在符合要求的转换序列。
// 
//
// 
//
// 提示： 
//
// 
// 1 <= beginWord.length <= 7 
// endWord.length == beginWord.length 
// 1 <= wordList.length <= 5000 
// wordList[i].length == beginWord.length 
// beginWord、endWord 和 wordList[i] 由小写英文字母组成 
// beginWord != endWord 
// wordList 中的所有单词 互不相同 
// 
// 
// 
// Related Topics 广度优先搜索 数组 字符串 回溯算法 
// 👍 433 👎 0

#include "bits/stdc++.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int minSize = 9999999;
    vector<vector<string>> ress;

    int isNeighbor(string &w1, string &w2) {
        if (w1.size() != w2.size()) return 0;
        int diff = 0;
        for (int i = 0; i < w1.size(); i++) {
            if (w1[i] != w2[i]) diff++;
            if (diff > 1) return 0;
        }
        return diff == 1;
    }

    // trace中已经包含curWord
    void traceback(string &curWord, string &toWord, vector<string> &trace, vector<int> &visited,
                   vector<string> &wordList) {
        // 成功
        if (curWord == toWord) {
            if (trace.size() < minSize) {
                minSize = trace.size();
                ress.clear();
            }
            ress.emplace_back(trace);
            return;
        }

        // 如果这一个对不上，且长度已经达到最小长度
        if (trace.size() == minSize) {
            return;
        }

        // 尝试对
        int n = wordList.size();
        for (int i = 0; i < n; i++) {
            if (!visited[i] && isNeighbor(curWord, wordList[i])) {
                visited[i] = 1;
                trace.push_back(wordList[i]);
                traceback(wordList[i], toWord, trace, visited, wordList);
                trace.pop_back();
                visited[i] = 0;
            }
        }
    }

    vector<vector<string>> findLaddersDFS(string beginWord, string endWord, vector<string> &wordList) {
        vector<int> visit(wordList.size(), 0);
        vector<string> trace;
        trace.push_back(beginWord);
        traceback(beginWord, endWord, trace, visit, wordList);
        return ress;
    }

    // BFS 做题
    void tracebackk(string& currEndWord, string& beginWord,
                    vector<string>& trace, map<string, vector<string>>& record) {
        trace.insert(trace.begin(), currEndWord);
        if (currEndWord == beginWord) {
            if (trace.size() < minSize) {
                minSize = trace.size();
                ress.clear();
                ress.emplace_back(trace);
            } else if (trace.size() == minSize) {
                ress.emplace_back(trace);
            }
            trace.erase(trace.begin());
            return;
        }

        for (string nxt : record[currEndWord]) {
            tracebackk(nxt, beginWord, trace, record);
        }

        trace.erase(trace.begin());
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList) {
        queue<string> que;

        // 先把beginWord放进去
        int contains = -1;
        for (int i = 0; i < wordList.size(); i++) {
            string &s = wordList[i];
            if (s == beginWord) {
                contains = i;
                break;
            }
        }
        if (contains == -1) {
            wordList.push_back(beginWord);
            contains = wordList.size() - 1;
        }

        // 已经访问到一遍的元素，如果有层数(即value!=-1)
        // 则在更高层无法访问第二次
        vector<int> visitLvl(wordList.size(), -1);

        // child -> parents
        map<string, vector<string>> record;

        int lvl = 0, size = 1;
        que.push(beginWord);
        visitLvl[contains] = 0;
        lvl++;

        while (!que.empty() && size > 0) {
            int newSize = 0;
            int meetTarget = 0;
            for (int i = 0; i < size; i++) {
                string curr = que.front();
                que.pop();
                cout << "POPED " << curr << endl;
                // 遍历一遍
                for (int j = 0; j < wordList.size(); j++) {
                    if (visitLvl[j] != -1 && visitLvl[j] != lvl) {
                        // 已经访问过
                        continue;
                    }
                    string &nxt = wordList[j];
                    if (!isNeighbor(curr, nxt)) {
                        continue;
                    }
                    cout << "FIND " << nxt << endl;
                    if (record.find(nxt) == record.end()) {
                        record[nxt] = {curr};
                    } else {
                        record[nxt].push_back(curr);
                    }
                    if (visitLvl[j] == -1) {
                        if (nxt == endWord) meetTarget = 1;
                        que.push(nxt);
                        visitLvl[j] = lvl;
                        newSize++;
                    }
                }

            }
            if (meetTarget) break;
            size = newSize;
            lvl++;

        }

        // 向前回溯
        vector<string> trace;
        tracebackk(endWord, beginWord, trace, record);
        return ress;


    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    vector<string> vs{"hot","cog","dog","tot","hog","hop","pot","dot"};
    s.findLadders("hot", "dog", vs);
}