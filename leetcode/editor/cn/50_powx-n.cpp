//实现 pow(x, n) ，即计算 x 的 n 次幂函数（即，x⁴
//
// Related Topics 递归 数学 👍 732 👎 0

#include "bits/stdc++.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    double myPow(double x, int n) {
        double base = x; double result = 1;
        long nn = n;
        bool divideOne = false;
        if (n < 0) {
            divideOne = true; nn = -nn;
        }

        while (nn != 0) {
            if (nn & 1) result *= base;
            base *= base;
            nn >>= 1;
        }

        if (divideOne) {
            return 1 / result;
        } else return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
}