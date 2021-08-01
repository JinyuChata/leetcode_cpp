//给定一个已排序的正整数数组 nums，和一个正整数 n 。从 [1, n] 区间内选取任意个数字补充到 nums 中，使得 [1, n] 区间内的任何数字都
//可以用 nums 中某几个数字的和来表示。请输出满足上述要求的最少需要补充的数字个数。 
//
// 示例 1: 
//
// 输入: nums = [1,3], n = 6
//输出: 1 
//解释:
//根据 nums 里现有的组合 [1], [3], [1,3]，可以得出 1, 3, 4。
//现在如果我们将 2 添加到 nums 中， 组合变为: [1], [2], [3], [1,3], [2,3], [1,2,3]。
//其和可以表示数字 1, 2, 3, 4, 5, 6，能够覆盖 [1, 6] 区间里所有的数。
//所以我们最少需要添加一个数字。 
//
// 示例 2: 
//
// 输入: nums = [1,5,10], n = 20
//输出: 2
//解释: 我们需要添加 [2, 4]。
// 
//
// 示例 3: 
//
// 输入: nums = [1,2,2], n = 5
//输出: 0
// 
// Related Topics 贪心 数组 
// 👍 282 👎 0

#include "bits/stdc++.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long total = 0;
        int cnt = 0;
        int index = 0;

        while (total < n) {
            // 需要继续
            if (index < nums.size() && total >= nums[index] - 1) {
                // 凭借下一个nums[index]，可以接上
                total = total + nums[index++];
            } else {
                // 接不上了，只能从外面取一个（total+1）
                // 贪心在这里：从外面取一个total+1，对数字和的影响最好
                // 例如，原来能到5，即1.2.3.4.5; 如果取6, 则能添加6 7 8 9 10 11
                cnt++;
                total = 2 * total + 1;
            }
        }

        return cnt;

    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
}