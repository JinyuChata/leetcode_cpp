//给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。 
//
// 
//
// 示例 1： 
//
// 
//
// 
//输入：height = [0,1,0,2,1,0,1,3,2,1,2,1]
//输出：6
//解释：上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。 
// 
//
// 示例 2： 
//
// 
//输入：height = [4,2,0,3,2,5]
//输出：9
// 
//
// 
//
// 提示： 
//
// 
// n == height.length 
// 0 <= n <= 3 * 104 
// 0 <= height[i] <= 105 
// 
// Related Topics 栈 数组 双指针 动态规划 
// 👍 2387 👎 0
#include "bits/stdc++.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() == 0) return 0;
        // 分别计算左侧和右侧的max
        int n = height.size();
        vector<int> leftMax(n);
        vector<int> rightMax(n);

        leftMax[0] = 0;
        rightMax[n-1] = 0;
        for (int i = 1; i < n; i++) {
            leftMax[i] = max(leftMax[i-1], height[i-1]);
        }

        for (int i = n-2; i >= 0; i--) {
            rightMax[i] = max(rightMax[i+1], height[i+1]);
        }

        int res = 0;
        for (int i = 0; i < n; i++) {
            int m = min(leftMax[i], rightMax[i]);
            if (m > height[i]) res += m - height[i];
        }

        return res;

    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
}