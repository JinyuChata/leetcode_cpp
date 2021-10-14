//以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi] 。请你合并所有重叠的区间，并返
//回一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间。 
//
// 
//
// 示例 1： 
//
// 
//输入：intervals = [[1,3],[2,6],[8,10],[15,18]]
//输出：[[1,6],[8,10],[15,18]]
//解释：区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
// 
//
// 示例 2： 
//
// 
//输入：intervals = [[1,4],[4,5]]
//输出：[[1,5]]
//解释：区间 [1,4] 和 [4,5] 可被视为重叠区间。 
//
// 
//
// 提示： 
//
// 
// 1 <= intervals.length <= 10⁴ 
// intervals[i].length == 2 
// 0 <= starti <= endi <= 10⁴ 
// 
// Related Topics 数组 排序 👍 1096 👎 0

#include "bits/stdc++.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int>& i1, vector<int>& i2){
            return i1[0] < i2[0];
        });

        vector<vector<int>> result;
        int n = intervals.size();
        int idx = 0;
        while (idx < n) {
            vector<int>& interval = intervals[idx];
            if (result.empty() || interval[0] > result[result.size()-1][1]) {
                result.push_back(interval);
            } else {
                result[result.size()-1][1] = max(result[result.size()-1][1], interval[1]);
            }
            idx++;
        }

        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
}