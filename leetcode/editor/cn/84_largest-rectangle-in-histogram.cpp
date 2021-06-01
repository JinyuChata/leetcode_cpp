//给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。 
//
// 求在该柱状图中，能够勾勒出来的矩形的最大面积。 
//
// 
//
// 
//
// 以上是柱状图的示例，其中每个柱子的宽度为 1，给定的高度为 [2,1,5,6,2,3]。 
//
// 
//
// 
//
// 图中阴影部分为所能勾勒出的最大矩形面积，其面积为 10 个单位。 
//
// 
//
// 示例: 
//
// 输入: [2,1,5,6,2,3]
//输出: 10 
// Related Topics 栈 数组 
// 👍 1373 👎 0

#include <bits/stdc++.h>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
struct Block {
    int id;
    int height;

    Block(int id, int height) : id(id), height(height) {}
};

class Solution {
public:
    // 单调栈解决
    // 对每一个height, 找到以这个Height为中心高度，能向两边扩散的最大长度
    int largestRectangleArea(vector<int>& heights) {
        int maxSize = 0;
        // 单调栈处理柱形图中最大矩形面积
        stack<Block> stk;
        stk.push(Block(-1, -1));

        // 遍历柱形图，建立单调栈，并计算一部分的`两侧最大面积`
        for (int i = 0; i < heights.size(); i++) {
            int curHeight = heights[i];
            while (curHeight < stk.top().height) {
                // 出栈一个，并计算其两侧面积
                int height = stk.top().height;
                stk.pop();
                int width = i - stk.top().id - 1;
                maxSize = max(maxSize, width * height);
            }
            // 入站
            stk.push(Block(i, curHeight));
        }

        // 如果还有剩余的柱子，则出栈并计算高度
        if (stk.top().id != -1) {
            int rightBound = stk.top().id;
            while (stk.top().id != -1) {
                int height = stk.top().height;
                stk.pop();
                int width = rightBound - stk.top().id;
                maxSize = max(maxSize, height * width);
            }
        }

        return maxSize;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
}