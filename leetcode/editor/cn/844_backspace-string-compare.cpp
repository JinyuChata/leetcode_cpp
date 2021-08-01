//给定 S 和 T 两个字符串，当它们分别被输入到空白的文本编辑器后，判断二者是否相等，并返回结果。 # 代表退格字符。 
//
// 注意：如果对空文本输入退格字符，文本继续为空。 
//
// 
//
// 示例 1： 
//
// 
//输入：S = "ab#c", T = "ad#c"
//输出：true
//解释：S 和 T 都会变成 “ac”。
// 
//
// 示例 2： 
//
// 
//输入：S = "ab##", T = "c#d#"
//输出：true
//解释：S 和 T 都会变成 “”。
// 
//
// 示例 3： 
//
// 
//输入：S = "a##c", T = "#a#c"
//输出：true
//解释：S 和 T 都会变成 “c”。
// 
//
// 示例 4： 
//
// 
//输入：S = "a#c", T = "b"
//输出：false
//解释：S 会变成 “c”，但 T 仍然是 “b”。 
//
// 
//
// 提示： 
//
// 
// 1 <= S.length <= 200 
// 1 <= T.length <= 200 
// S 和 T 只含有小写字母以及字符 '#'。 
// 
//
// 
//
// 进阶： 
//
// 
// 你可以用 O(N) 的时间复杂度和 O(1) 的空间复杂度解决该问题吗？ 
// 
//
// 
// Related Topics 栈 双指针 
// 👍 287 👎 0

#include "bits/stdc++.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        // 双指针，从后向前遍历
        int idx_s = s.size() - 1;
        int skip_s = 0;
        int idx_t = t.size() - 1;
        int skip_t = 0;
        while (idx_s >= 0 || idx_t >= 0) {
            // 先走idx_s
            while (idx_s >= 0) {
                if (s[idx_s] == '#') {
                    skip_s++;
                    idx_s--;
                } else {
                    if (skip_s > 0) {
                        idx_s--;
                        skip_s--;
                    } else {
                        break;
                    }
                }
            }
            // 再走idx_t
            while (idx_t >= 0) {
                if (t[idx_t] == '#') {
                    idx_t --;
                    skip_t++;
                } else {
                    if (skip_t > 0) {
                        idx_t--;
                        skip_t--;
                    } else {
                        break;
                    }
                }
            }
            // 对比两个值
            if (idx_s < 0 && idx_t < 0) {
                return true;
            } else if (idx_s < 0 || idx_t < 0) {
                return false;
            } else {
                if (s[idx_s] != t[idx_t]) return false;
                idx_s--;
                idx_t--;
            }
        }
        return idx_s == idx_t;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    s.backspaceCompare("bbbextm", "bbb#extm");

}