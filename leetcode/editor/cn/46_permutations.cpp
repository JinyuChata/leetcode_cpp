//给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [1,2,3]
//输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
// 
//
// 示例 2： 
//
// 
//输入：nums = [0,1]
//输出：[[0,1],[1,0]]
// 
//
// 示例 3： 
//
// 
//输入：nums = [1]
//输出：[[1]]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 6 
// -10 <= nums[i] <= 10 
// nums 中的所有整数 互不相同 
// 
// Related Topics 回溯算法 
// 👍 1382 👎 0

#include "bits/stdc++.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> ress;

    void traceback(vector<int>& nums, vector<int>& permuted, vector<int>& permuting) {
        int hasMore = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (permuted[i]) continue;
            hasMore = 1;
            // 未被排列
            permuted[i] = 1;
            permuting.push_back(nums[i]);
            traceback(nums, permuted, permuting);
            permuted[i] = 0;
            permuting.pop_back();
        }

        if (!hasMore) {
            // 可以结束了
            ress.emplace_back(permuting);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> isPermuted(nums.size());
        vector<int> permuting;
        traceback(nums, isPermuted, permuting);
        return ress;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
