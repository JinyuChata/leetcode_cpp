//给定一个非负整数 N，找出小于或等于 N 的最大的整数，同时这个整数需要满足其各个位数上的数字是单调递增。 
//
// （当且仅当每个相邻位数上的数字 x 和 y 满足 x <= y 时，我们称这个整数是单调递增的。） 
//
// 示例 1: 
//
// 输入: N = 10
//输出: 9
// 
//
// 示例 2: 
//
// 输入: N = 1234
//输出: 1234
// 
//
// 示例 3: 
//
// 输入: N = 332
//输出: 299
// 
//
// 说明: N 是在 [0, 10^9] 范围内的一个整数。 
// Related Topics 贪心 数学 
// 👍 195 👎 0

#include "bits/stdc++.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        // 首先找到第一个 s[i], 使得 s[i] > s[i+1]
        string s = to_string(n);
        int nn = s.size();
        vector<char> res;

        int idx = 0;
        for (idx = 0; idx < nn-1; idx++) {
            if (s[idx] <= s[idx+1]) {
                res.push_back(s[idx]);
            } else break;
        }

        res.push_back(s[idx]);
        int to_idx = idx;
        if (idx != nn-1) {
            // 被卡住了
            do {
                res[idx]--;
                idx--;
            } while (idx >= 0 && res[idx] > res[idx+1]);

            idx += 2;
            int ssize = res.size();
            while (idx < nn) {
                if (idx < ssize) {
                    res[idx] = '9';
                } else {
                    res.push_back('9');
                }
                idx++;
            }
        }

        stringstream ss;
        for (char c : res) {
            ss << c;
        }

        return stoi(ss.str());


    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    cout << s.monotoneIncreasingDigits(10) << endl;
}