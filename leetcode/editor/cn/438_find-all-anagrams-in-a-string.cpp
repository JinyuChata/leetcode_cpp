//给定两个字符串 s 和 p，找到 s 中所有 p 的 异位词 的子串，返回这些子串的起始索引。不考虑答案输出的顺序。 
//
// 异位词 指字母相同，但排列不同的字符串。 
//
// 
//
// 示例 1: 
//
// 
//输入: s = "cbaebabacd", p = "abc"
//输出: [0,6]
//解释:
//起始索引等于 0 的子串是 "cba", 它是 "abc" 的异位词。
//起始索引等于 6 的子串是 "bac", 它是 "abc" 的异位词。
// 
//
// 示例 2: 
//
// 
//输入: s = "abab", p = "ab"
//输出: [0,1,2]
//解释:
//起始索引等于 0 的子串是 "ab", 它是 "ab" 的异位词。
//起始索引等于 1 的子串是 "ba", 它是 "ab" 的异位词。
//起始索引等于 2 的子串是 "ab", 它是 "ab" 的异位词。
// 
//
// 
//
// 提示: 
//
// 
// 1 <= s.length, p.length <= 3 * 104 
// s 和 p 仅包含小写字母 
// 
// Related Topics 哈希表 字符串 滑动窗口 
// 👍 600 👎 0

#include "bits/stdc++.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        int m=s.size();
        int n=p.size();
        if(m<n) return result;
        vector<int> win(26,0); //定义窗口字母统计数组
        vector<int> st(26,0);
        for(int i=0;i<n;i++) st[p[i]-'a']++;
        int slow=0;
        for(int fast=0;fast<m;fast++){
            win[s[fast]-'a']++;
            if(fast>=n){win[s[slow]-'a']--; slow++;} //达到p的大小后，每次fast和slow同时移动
            if(st==win){
                result.push_back(slow);
            }
        }
        return result;
    }
};

//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
}