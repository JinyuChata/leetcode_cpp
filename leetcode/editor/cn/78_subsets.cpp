//给你一个整数数组 nums ，数组中的元素 互不相同 。返回该数组所有可能的子集（幂集）。 
//
// 解集 不能 包含重复的子集。你可以按 任意顺序 返回解集。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [1,2,3]
//输出：[[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
// 
//
// 示例 2： 
//
// 
//输入：nums = [0]
//输出：[[],[0]]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 10 
// -10 <= nums[i] <= 10 
// nums 中的所有元素 互不相同 
// 
// Related Topics 位运算 数组 回溯算法 
// 👍 1204 👎 0

// 试试位运算
// 位运算，计算2^i很好算：(1 << i)
#include "bits/stdc++.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<int> t;
        vector<vector<int>> ress;
        for (int mask = 0; mask < (1 << n); mask ++) {
            t.clear();
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    t.push_back(nums[i]);
                }
            }
            ress.emplace_back(t);
        }

        return ress;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
}