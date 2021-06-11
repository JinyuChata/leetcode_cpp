//给你一个整数数组 nums ，数组中共有 n 个整数。132 模式的子序列 由三个整数 nums[i]、nums[j] 和 nums[k] 组成，并同时满足
//：i < j < k 和 nums[i] < nums[k] < nums[j] 。 
//
// 如果 nums 中存在 132 模式的子序列 ，返回 true ；否则，返回 false 。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [1,2,3,4]
//输出：false
//解释：序列中不存在 132 模式的子序列。
// 
//
// 示例 2： 
//
// 
//输入：nums = [3,1,4,2]
//输出：true
//解释：序列中有 1 个 132 模式的子序列： [1, 4, 2] 。
// 
//
// 示例 3： 
//
// 
//输入：nums = [-1,3,2,0]
//输出：true
//解释：序列中有 3 个 132 模式的的子序列：[-1, 3, 2]、[-1, 3, 0] 和 [-1, 2, 0] 。
// 
//
// 
//
// 提示： 
//
// 
// n == nums.length 
// 1 <= n <= 2 * 105 
// -109 <= nums[i] <= 109 
// 
// Related Topics 栈 
// 👍 520 👎 0

#include "bits/stdc++.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // 单调栈的用处：
    // 1. (以单调增栈为例) 左侧第一个(存在)、右侧第一个(压倒) -> 想想柱状图矩形问题
    //    左侧第一个存在，是左边最近的、比自己小的元素
    //    右侧第一个压倒，是右边最近的、比自己小的元素(否则就不会压过来pop了)
    // 2. (以单调减栈为例) 某个元素被弹出，一定是因为(右边有元素比他大)
    bool find132pattern(vector<int>& nums) {
        // 逆向单调栈:
        // 单调减栈:  左侧第一个，是左侧第一个比他大的元素；右侧第一个把自己压碎的，是右侧第一个比他大的元素
        //          (某时刻)留下的都是(到某个时刻为止), (后面没有比自己大的元素)的那些元素
        //          被弹出的元素，一定因为比后面某个元素小
        // 逆向后，自左向右，保存被弹出的最大值(k)
        // k被弹出的原因，是比后面某个元素小(j)
        // 我现在只要找到一个元素，比k还小(i) 就可以说明能够组成132
        stack<int> downStk;
        int k = INT32_MIN;
        for (int idx = nums.size() - 1; idx >= 0; idx--) {
            if (k != INT32_MIN && nums[idx] < k) {
                return true;
            }
            if (downStk.empty() || nums[idx] <= downStk.top()) {
                downStk.push(nums[idx]);
            } else {
                while (!downStk.empty() && nums[idx] > downStk.top()) {
                    k = max(k, downStk.top());
                    downStk.pop();
                }
                downStk.push(nums[idx]);
            }
        }
        return false;

    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
}