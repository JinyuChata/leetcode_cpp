//给你一个长度为 n 的整数数组 nums，其中 n > 1，返回输出数组 output ，其中 output[i] 等于 nums 中除 nums[i] 之
//外其余各元素的乘积。 
//
// 
//
// 示例: 
//
// 输入: [1,2,3,4]
//输出: [24,12,8,6] 
//
// 
//
// 提示：题目数据保证数组之中任意元素的全部前缀元素和后缀（甚至是整个数组）的乘积都在 32 位整数范围内。 
//
// 说明: 请不要使用除法，且在 O(n) 时间复杂度内完成此题。 
//
// 进阶： 
//你可以在常数空间复杂度内完成这个题目吗？（ 出于对空间复杂度分析的目的，输出数组不被视为额外空间。） 
// Related Topics 数组 前缀和 
// 👍 904 👎 0

#include "bits/stdc++.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // 前缀和 + 后缀和
        vector<int> front; vector<int> back;
        int left = 1; int right = 1;
        int n = nums.size();

        front.push_back(1); back.push_back(1);

        for (int i = 0; i < n; i++) {
            left *= nums[i]; right *= nums[n-1-i];
            front.push_back(left); back.push_back(right);
        }

        vector<int> ret;
        for (int i = 1; i <= n; i++) {
            ret.push_back(front[i-1]*back[n-i]);
        }

        return ret;

    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
}