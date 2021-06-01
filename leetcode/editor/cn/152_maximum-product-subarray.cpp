//给你一个整数数组 nums ，请你找出数组中乘积最大的连续子数组（该子数组中至少包含一个数字），并返回该子数组所对应的乘积。 
//
// 示例 1: 
//
// 输入: [2,3,-2,4]
//输出: 6
//解释: 子数组 [2,3] 有最大乘积 6。
// 
//
// 示例 2: 
//
// 输入: [-2,0,-1]
//输出: 0
//解释: 结果不能为 2, 因为 [-2,-1] 不是子数组。 
// Related Topics 数组 动态规划 
// 👍 1119 👎 0
#include <bits/stdc++.h>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<int> dpMax(n);
        vector<int> dpMin(n);

        // 初始化0
        dpMax[0] = nums[0];
        dpMin[0] = nums[0];

        int maxVal = dpMax[0];
        for (int i = 1; i < n; i++) {
            int curr = nums[i];
            dpMin[i] = min(min(curr, curr*dpMax[i-1]), curr*dpMin[i-1]);
            dpMax[i] = max(max(curr, curr*dpMax[i-1]), curr*dpMin[i-1]);
            maxVal = max(dpMax[i], maxVal);
        }

        return maxVal;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
}