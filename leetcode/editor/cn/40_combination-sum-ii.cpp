//给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。 
//
// candidates 中的每个数字在每个组合中只能使用一次。 
//
// 说明： 
//
// 
// 所有数字（包括目标数）都是正整数。 
// 解集不能包含重复的组合。 
// 
//
// 示例 1: 
//
// 输入: candidates = [10,1,2,7,6,1,5], target = 8,
//所求解集为:
//[
//  [1, 7],
//  [1, 2, 5],
//  [2, 6],
//  [1, 1, 6]
//]
// 
//
// 示例 2: 
//
// 输入: candidates = [2,5,2,1,2], target = 5,
//所求解集为:
//[
//  [1,2,2],
//  [5]
//] 
// Related Topics 数组 回溯算法 
// 👍 590 👎 0
#include "bits/stdc++.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> ress;
    set<string> quchong;

    void traceback(vector<int> &candidates, vector<int> &chosens,
                   int sum, int target, int idx) {
        if (sum > target) return;
        if (sum == target) {
            vector<int> ch(chosens);
            sort(ch.begin(), ch.end());
            string s;
            for (char c : ch) {
                s += string(1, c);
            }
            if (quchong.find(s) == quchong.end()) {
                quchong.insert(s);
                ress.emplace_back(chosens);
            }

        }
        if (idx == candidates.size()) return;

        // 对于idx，选择 or 不选择(跳过)
        chosens.push_back(candidates[idx]);
        traceback(candidates, chosens, sum + candidates[idx], target, idx+1);
        chosens.pop_back();

        traceback(candidates, chosens, sum, target, idx + 1);
    }

    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        vector<int> chosens;
        traceback(candidates, chosens, 0, target, 0);
        return ress;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
