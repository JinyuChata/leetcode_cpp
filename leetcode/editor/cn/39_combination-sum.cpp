// 给定一个无重复元素的数组 candidates 和一个目标数 target ，
// 找出 candidates 中所有可以使数字和为 target 的组合。
//
// candidates 中的数字可以无限制重复被选取。 
//
// 说明： 
//
// 
// 所有数字（包括 target）都是正整数。 
// 解集不能包含重复的组合。 
// 
//
// 示例 1： 
//
// 输入：candidates = [2,3,6,7], target = 7,
//所求解集为：
//[
//  [7],
//  [2,2,3]
//]
// 
//
// 示例 2： 
//
// 输入：candidates = [2,3,5], target = 8,
//所求解集为：
//[
//  [2,2,2,2],
//  [2,3,3],
//  [3,5]
//] 
//
// 
//
// 提示： 
//
// 
// 1 <= candidates.length <= 30 
// 1 <= candidates[i] <= 200 
// candidate 中的每个元素都是独一无二的。 
// 1 <= target <= 500 
// 
// Related Topics 数组 回溯算法 
// 👍 1367 👎 0

#include "bits/stdc++.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> ress;
    set<string> quchong;

    void traceback(vector<int> &candidates, vector<int> &chosens,
                   int sum, int target, int idx, string s) {
        if (sum > target) return;
        if (sum == target && quchong.find(s) == quchong.end()) {
            quchong.insert(s);
            ress.emplace_back(chosens);
        }
        if (idx == candidates.size()) return;

        // 对于idx，选择 or 不选择(跳过)
        chosens.push_back(candidates[idx]);
        string ss = s + string(1, candidates[idx]);
        traceback(candidates, chosens, sum + candidates[idx], target, idx, ss);
        chosens.pop_back();

        traceback(candidates, chosens, sum, target, idx + 1, s);
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        vector<int> chosens;
        traceback(candidates, chosens, 0, target, 0, "");
        return ress;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
