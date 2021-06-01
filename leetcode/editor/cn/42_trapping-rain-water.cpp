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
// 👍 2364 👎 0
#include <bits/stdc++.h>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n < 2) return 0;

        vector<int> left_max(n);
        vector<int> right_max(n);

        // 找到左侧、右侧的最高柱子
        left_max[1] = height[0];
        for (int i = 2; i < n; ++i) {
            left_max[i] = max(left_max[i-1], height[i-1]);
        }

        right_max[n-2] = height[n-1];
        for (int i = n-3; i >= 0; i--) {
            right_max[i] = max(right_max[i+1], height[i+1]);
        }

        // 遍历柱子，
        // 分别看左侧、右侧的最高柱子的较小值，是不是比当前柱子高
        // 如果高，则可以存水
        int sum = 0;
        for (int i = 1; i < n-1; ++i) {
            int left = left_max[i];
            int right = right_max[i];
            int minV = min(left, right);
            if (minV > height[i]) {
                sum += minV - height[i];
            }
        }

        return sum;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
}