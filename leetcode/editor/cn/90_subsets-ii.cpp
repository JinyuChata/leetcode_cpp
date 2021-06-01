//给你一个整数数组 nums ，其中可能包含重复元素，请你返回该数组所有可能的子集（幂集）。 
//
// 解集 不能 包含重复的子集。返回的解集中，子集可以按 任意顺序 排列。 
//
// 
// 
// 
//
// 示例 1： 
//
// 
//输入：nums = [1,2,2]
//输出：[[],[1],[1,2],[1,2,2],[2],[2,2]]
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
// 
// 
// 
// Related Topics 数组 回溯算法 
// 👍 581 👎 0
#include "bits/stdc++.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        vector<int> t;
        vector<vector<int>> ress;
        set<string> sset;
        for (int mask = 0; mask < (1 << n); mask ++) {
            t.clear();
            string s;
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    t.push_back(nums[i]);
                }
            }

            sort(t.begin(), t.end());
            for (int num : t) {
                s += string(1,(char) (20+num));
            }

            if (sset.find(s) == sset.end()) {
                ress.emplace_back(t);
                sset.insert(s);
            }
        }

        return ress;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
}