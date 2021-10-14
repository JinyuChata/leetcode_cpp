//给定一个单词数组和一个长度 maxWidth，重新排版单词，使其成为每行恰好有 maxWidth 个字符，且左右两端对齐的文本。 
//
// 你应该使用“贪心算法”来放置给定的单词；也就是说，尽可能多地往每行中放置单词。必要时可用空格 ' ' 填充，使得每行恰好有 maxWidth 个字符。 
//
// 要求尽可能均匀分配单词间的空格数量。如果某一行单词间的空格不能均匀分配，则左侧放置的空格数要多于右侧的空格数。 
//
// 文本的最后一行应为左对齐，且单词之间不插入额外的空格。 
//
// 说明: 
//
// 
// 单词是指由非空格字符组成的字符序列。 
// 每个单词的长度大于 0，小于等于 maxWidth。 
// 输入单词数组 words 至少包含一个单词。 
// 
//
// 示例: 
//
// 输入:
//words = ["This", "is", "an", "example", "of", "text", "justification."]
//maxWidth = 16
//输出:
//[
//   "This    is    an",
//   "example  of text",
//   "justification.  "
//]
// 
//
// 示例 2: 
//
// 输入:
//words = ["What","must","be","acknowledgment","shall","be"]
//maxWidth = 16
//输出:
//[
//  "What   must   be",
//  "acknowledgment  ",
//  "shall be        "
//]
//解释: 注意最后一行的格式应为 "shall be    " 而不是 "shall     be",
//     因为最后一行应为左对齐，而不是左右两端对齐。       
//     第二行同样为左对齐，这是因为这行只包含一个单词。
// 
//
// 示例 3: 
//
// 输入:
//words = ["Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"]
//maxWidth = 20
//输出:
//[
//  "Science  is  what we",
//  "understand      well",
//  "enough to explain to",
//  "a  computer.  Art is",
//  "everything  else  we",
//  "do                  "
//]
// 
// Related Topics 字符串 模拟 👍 180 👎 0

#include "bits/stdc++.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int nextIdx = 0;
        int n = words.size();

        vector<string> result;
        queue<string> q;
        int curLineCharSize = 0;

        while (nextIdx < n || !q.empty()) {
            bool toSumUp = false;
            // 尝试把下一个也加进去，看看行不行
            while (nextIdx < n) {
                int minLineSize = curLineCharSize + words[nextIdx].size() + q.size();
                if (minLineSize <= maxWidth) {
                    q.push(words[nextIdx]);
                    curLineCharSize += words[nextIdx].size();
                    nextIdx++;
                } else {
                    toSumUp = true;
                    break;
                }
            }

            if (nextIdx >= n) toSumUp = true;
            if (toSumUp) {
                string line = "";
                if (nextIdx >= n) {
                    // 文本最后一行

                    while (!q.empty()) {
                        string curr = q.front(); q.pop();
                        if (!q.empty()) curr += " ";
                        line += curr;
                    }

                    while (line.size() < maxWidth) {
                        line += " ";
                    }
                } else {
                    int cntInterval = q.size()-1;
                    if (cntInterval == 0) cntInterval++;
                    int baseSize = (maxWidth - curLineCharSize) / cntInterval;
                    int remain = (maxWidth - curLineCharSize) - baseSize * cntInterval;
                    curLineCharSize = 0;

                    while (!q.empty()) {
                        string curr = q.front(); q.pop();
                        if (cntInterval > 0) {
                            for (int i = 0; i < baseSize; i++) curr += " ";
                            if (remain > 0) {
                                curr += " "; remain--;
                            }
                            cntInterval--;
                        }
                        line += curr;
                    }
                }

                result.push_back(line);
            }

        }

//        for (string& s : result) {
//            cout << "\"" << s << "\"" << endl;
//        }

        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    vector<string> in = {"shall", "be"};
    s.fullJustify(in, 16);
}