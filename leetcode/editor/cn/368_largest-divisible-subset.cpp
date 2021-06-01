//给你一个由 无重复 正整数组成的集合 nums ，请你找出并返回其中最大的整除子集 answer ，子集中每一元素对 (answer[i], answer[
//j]) 都应当满足：
// 
// answer[i] % answer[j] == 0 ，或 
// answer[j] % answer[i] == 0 
// 
//
// 如果存在多个有效解子集，返回其中任何一个均可。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [1,2,3]
//输出：[1,2]
//解释：[1,3] 也会被视为正确答案。
// 
//
// 示例 2： 
//
// 
//输入：nums = [1,2,4,8]
//输出：[1,2,4,8]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 1000 
// 1 <= nums[i] <= 2 * 109 
// nums 中的所有整数 互不相同 
// 
// Related Topics 数学 动态规划 
// 👍 351 👎 0
#include <bits/stdc++.h>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        int maxLength = 1;
        int maxLengthPos = 0;
        sort(nums.begin(), nums.end());
        vector<vector<int>> dps{{nums[0]}};


        for (int i = 1; i < n; i++) {
            int curr = nums[i];
            int maxSize = 1;
            int maxSizePos = -1;
            for (int j = 0; j < dps.size(); j++) {
                if (curr % dps[j][dps[j].size()-1] == 0 && dps[j].size()+1 > maxSize) {
                    maxSize = dps[j].size()+1;
                    maxSizePos = j;
                }
            }

            if (maxSizePos == -1) {
                // 加入{curr}
                dps.push_back({curr});
            } else {
                // 加入{..., maxSize, curr}
                vector<int> toAdd(dps[maxSizePos]);
                toAdd.push_back(curr);
                dps.push_back(toAdd);
                if (toAdd.size() > maxLength) {
                    maxLength = toAdd.size();
                    maxLengthPos = dps.size()-1;
                }
            }
        }
        return dps[maxLengthPos];
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
}