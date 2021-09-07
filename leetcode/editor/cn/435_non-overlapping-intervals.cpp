//给定一个区间的集合，找到需要移除区间的最小数量，使剩余区间互不重叠。 
//
// 注意: 
//
// 
// 可以认为区间的终点总是大于它的起点。 
// 区间 [1,2] 和 [2,3] 的边界相互“接触”，但没有相互重叠。 
// 
//
// 示例 1: 
//
// 
//输入: [ [1,2], [2,3], [3,4], [1,3] ]
//
//输出: 1
//
//解释: 移除 [1,3] 后，剩下的区间没有重叠。
// 
//
// 示例 2: 
//
// 
//输入: [ [1,2], [1,2], [1,2] ]
//
//输出: 2
//
//解释: 你需要移除两个 [1,2] 来使剩下的区间没有重叠。
// 
//
// 示例 3: 
//
// 
//输入: [ [1,2], [2,3] ]
//
//输出: 0
//
//解释: 你不需要移除任何区间，因为它们已经是无重叠的了。
// 
// Related Topics 贪心 数组 动态规划 排序 
// 👍 466 👎 0

#include "bits/stdc++.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // 1. dp，左侧排序后，dp[i]是以第i个为末尾的，无重叠区间最大个数
        // 2. 贪心
        // 按照右侧排序，右侧最小的一定是贪心可以被选中的，然后再选下一个可以选中的... 以此类推
        sort(intervals.begin(), intervals.end(), [](vector<int>& v1, vector<int>& v2){
            return v1[1] < v2[1];
        });

        // 选中右侧最小的那一个
        int selected = 0, leftBound = INT32_MIN;
        for (vector<int>& i : intervals) {
            if (i[0] >= leftBound) {
                leftBound = i[1];
                selected++;
            }
        }

        return intervals.size() - selected;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
}