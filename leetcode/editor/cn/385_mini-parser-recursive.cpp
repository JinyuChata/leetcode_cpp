//给定一个用字符串表示的整数的嵌套列表，实现一个解析它的语法分析器。 
//
// 列表中的每个元素只可能是整数或整数嵌套列表 
//
// 提示：你可以假定这些字符串都是格式良好的： 
//
// 
// 字符串非空 
// 字符串不包含空格 
// 字符串只包含数字0-9、[、-、,、] 
// 
//
// 
//
// 示例 1： 
//
// 给定 s = "324",
//
//你应该返回一个 NestedInteger 对象，其中只包含整数值 324。
// 
//
// 示例 2： 
//
// 给定 s = "[123,[456,[789]]]",
//
//返回一个 NestedInteger 对象包含一个有两个元素的嵌套列表：
//
//1. 一个 integer 包含值 123
//2. 一个包含两个元素的嵌套列表：
//    i.  一个 integer 包含值 456
//    ii. 一个包含一个元素的嵌套列表
//         a. 一个 integer 包含值 789
// 
// Related Topics 栈 字符串 
// 👍 63 👎 0

#include "bits/stdc++.h"

using namespace std;

class NestedInteger {
public:
    // Constructor initializes an empty nested list.
    NestedInteger();

    // Constructor initializes a single integer.
    NestedInteger(int value);

    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Set this NestedInteger to hold a single integer.
    void setInteger(int value);

    // Set this NestedInteger to hold a nested list and adds a nested integer to it.
    void add(const NestedInteger &ni);

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    NestedInteger de(string s, int startIdx, int &nextIdx) {
        NestedInteger ni;
        // s[startIdx] 是 数字
        if ((s[startIdx] >= '0' && s[startIdx] <= '9') || s[startIdx] == '-') {
            int i = startIdx;
            while (i < s.size() && ((s[i] >= '0' && s[i] <= '9') || s[i] == '-')) {
                i++;
            }
            ni.setInteger(stoi(s.substr(startIdx, i - startIdx)));
            // nextIdx处，可能是','，也可能是 ']'
            nextIdx = i;
            return ni;
        }

        // s[startIdx] 是 外套[
        // 直到检测到下一个位置，是]则停止
        int i = startIdx + 1;
        while (s[i] != ']') {
            ni.add(de(s, i, i));
            if (s[i] == ',') i++;
        }
        // s[i] 一定是 ']'
        i++;
        nextIdx = i;
        return ni;

    }

    NestedInteger deserialize(string s) {
        // 先检查是不是有外套 []
        int cnt = 0;
//        int noCover = 0;
//        for (int i = 0; i < s.size(); i++) {
//            if (cnt == 0) noCover = 1;
//            if (s[i] == '[') cnt++;
//            else if (s[i] == ']') cnt--;
//        }
        // 没有外套，就加上外套
//        if (noCover) s = "[" + s + "]";
        int tmp = 0;
        return de(s, 0, tmp);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
}