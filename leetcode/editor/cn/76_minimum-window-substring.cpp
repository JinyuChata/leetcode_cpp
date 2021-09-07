//给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 "" 。 
//
// 
//
// 注意： 
//
// 
// 对于 t 中重复字符，我们寻找的子字符串中该字符数量必须不少于 t 中该字符数量。 
// 如果 s 中存在这样的子串，我们保证它是唯一的答案。 
// 
//
// 
//
// 示例 1： 
//
// 
//输入：s = "ADOBECODEBANC", t = "ABC"
//输出："BANC"
// 
//
// 示例 2： 
//
// 
//输入：s = "a", t = "a"
//输出："a"
// 
//
// 示例 3: 
//
// 
//输入: s = "a", t = "aa"
//输出: ""
//解释: t 中两个字符 'a' 均应包含在 s 的子串中，
//因此没有符合条件的子字符串，返回空字符串。 
//
// 
//
// 提示： 
//
// 
// 1 <= s.length, t.length <= 105 
// s 和 t 由英文字母组成 
// 
//
// 
//进阶：你能设计一个在 o(n) 时间内解决此问题的算法吗？ Related Topics 哈希表 字符串 滑动窗口 
// 👍 1325 👎 0

#include "bits/stdc++.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() > s.size()) return "";

        pair<int,unordered_map<char,int>> record;
        // 还剩几个，现在已经有的
        record.first = t.size();
        for (char c : t) {
            if (!record.second.count(c)) record.second[c] = 1;
            else record.second[c]++;
        }

        int left = 0, right = -1;
        string ret = "";
        int minSize = INT32_MAX;
        while (left < s.size() && right < (int) s.size()) {
            if (record.first > 0) {
                right++; char c = s[right];
                if (record.second.count(c)) {
                    record.second[c]--;
                    if (record.second[c] >= 0) {
                        record.first--;
                    }
                }
            } else {
                char c = s[left];
                if (right-left+1 < minSize) {
                    minSize = right-left+1;
                    ret = s.substr(left, right-left+1);
                }
                left++;
                if (record.second.count(c)) {
                    record.second[c]++;
                    if (record.second[c] > 0) {
                        record.first++;
                    }
                }
            }
        }
        return ret;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    cout << s.minWindow("ADOBECODEBANC", "ABC");
}