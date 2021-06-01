//如果一个数列至少有三个元素，并且任意两个相邻元素之差相同，则称该数列为等差数列。 
//
// 例如，以下数列为等差数列: 
//
// 
//1, 3, 5, 7, 9
//7, 7, 7, 7
//3, -1, -5, -9 
//
// 以下数列不是等差数列。 
//
// 
//1, 1, 2, 5, 7 
//
// 
//
// 数组 A 包含 N 个数，且索引从 0 开始。该数组子序列将划分为整数序列 (P0, P1, ..., Pk)，满足 0 ≤ P0 < P1 < ... 
//< Pk < N。 
//
// 
//
// 如果序列 A[P0]，A[P1]，...，A[Pk-1]，A[Pk] 是等差的，那么数组 A 的子序列 (P0，P1，…，PK) 称为等差序列。值得注意的
//是，这意味着 k ≥ 2。 
//
// 函数要返回数组 A 中所有等差子序列的个数。 
//
// 输入包含 N 个整数。每个整数都在 -231 和 231-1 之间，另外 0 ≤ N ≤ 1000。保证输出小于 231-1。 
//
// 
//
// 示例： 
//
// 
//输入：[2, 4, 6, 8, 10]
//
//输出：7
//
//解释：
//所有的等差子序列为：
//[2,4,6]
//[4,6,8]
//[6,8,10]
//[2,4,6,8]
//[4,6,8,10]
//[2,4,6,8,10]
//[2,6,10]
// 
//
// 
// Related Topics 动态规划 
// 👍 115 👎 0
#include "bits/stdc++.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        vector<map<long, int>> dp2(n, map<long, int>());
        vector<map<long, int>> dp3(n, map<long, int>());

        int res = 0;

        for (int i = 1; i < n; i++) {
            int curr = nums[i];
            for (int j = 0; j < i; j++) {
                long d = (long) curr - (long) nums[j];
                // dp2
                if (dp2[i].find(d) == dp2[i].end()) dp2[i][d] = 1;
                else dp2[i][d]++;

                // dp3
                if (dp2[j].find(d) != dp2[j].end()) {
                    if (dp3[i].find(d) == dp3[i].end()) dp3[i][d] = dp2[j][d];
                    else dp3[i][d] += dp2[j][d];
                }

                if (dp3[j].find(d) != dp3[j].end()) {
                    if (dp3[i].find(d) == dp3[i].end()) dp3[i][d] = dp3[j][d];
                    else dp3[i][d] += dp3[j][d];
                }
            }
            for (auto kv : dp3[i]) {
                res += kv.second;
            }
        }

        for (int i = 0; i < n; i++) {
            cout << i << ": " << nums[i] << endl;
            cout << "dp2: " << dp2[i][0] << endl;
            cout << "dp3: " << dp3[i][0] << endl;
        }

        return res;

    }
};
//leetcode submit region end(Prohibit modification and deletion)

int main() {
    Solution s;
    vector<int> v{0,2000000000,-294967296};
    s.numberOfArithmeticSlices(v);

}