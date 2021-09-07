//给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。 
//
// 求在该柱状图中，能够勾勒出来的矩形的最大面积。 
//
// 
//
// 示例 1: 
//
// 
//
// 
//输入：heights = [2,1,5,6,2,3]
//输出：10
//解释：最大的矩形为图中红色区域，面积为 10
// 
//
// 示例 2： 
//
// 
//
// 
//输入： heights = [2,4]
//输出： 4 
//
// 
//
// 提示： 
//
// 
// 1 <= heights.length <=105 
// 0 <= heights[i] <= 104 
// 
// Related Topics 栈 数组 单调栈 
// 👍 1519 👎 0

#include "bits/stdc++.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(-1);
        heights.insert(heights.begin(), -1);

        int n = heights.size();
        vector<int> left(n, 0);
        vector<int> right(n, n-1);

        // 从左到右，单调增栈遍历，找到第一个比当前小的
        stack<int> stk;
        for (int i = 0; i < n; i++) {
            while (!stk.empty() && heights[i] < heights[stk.top()]) {
                int idx = stk.top(); stk.pop();
                right[idx] = i;
            }
            stk.push(i);
        }

        stk = stack<int>();
        for (int i = n-1; i >= 0; i--) {
            while (!stk.empty() && heights[i] < heights[stk.top()]) {
                int idx = stk.top(); stk.pop();
                left[idx] = i;
            }
            stk.push(i);
        }

//        for (int i = 0; i < n; i++) {
//            cout << left[i] << " ";
//        }
//        cout << endl;
//
//        for (int i = 0; i < n; i++) {
//            cout << right[i] << " ";
//        }
//        cout << endl;

        int maxSize = 0;
        for (int i = 1; i < n-1; i++) {
            maxSize = max(maxSize, heights[i]*(right[i]-left[i]-1));
        }
        return maxSize;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
}