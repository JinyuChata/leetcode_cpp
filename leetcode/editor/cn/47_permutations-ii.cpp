//给定一个可包含重复数字的序列 nums ，按任意顺序 返回所有不重复的全排列。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [1,1,2]
//输出：
//[[1,1,2],
// [1,2,1],
// [2,1,1]]
// 
//
// 示例 2： 
//
// 
//输入：nums = [1,2,3]
//输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 8 
// -10 <= nums[i] <= 10 
// 
// Related Topics 回溯算法 
// 👍 708 👎 0
#include "bits/stdc++.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> ress;
    set<string> quchong;

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
            string s;
            for (int i : permuting) {
                s += string(1, (char) (i+11));
            }
            if (quchong.find(s) == quchong.end()) {
                // 第一个，可以放入
                quchong.insert(s);
                ress.emplace_back(permuting);
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> isPermuted(nums.size());
        vector<int> permuting;
        traceback(nums, isPermuted, permuting);
        return ress;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
