//给定一个仅包含 0 和 1 、大小为 rows x cols 的二维二进制矩阵，找出只包含 1 的最大矩形，并返回其面积。 
//
// 
//
// 示例 1： 
//
// 
//输入：matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"]
//,["1","0","0","1","0"]]
//输出：6
//解释：最大矩形如上图所示。
// 
//
// 示例 2： 
//
// 
//输入：matrix = []
//输出：0
// 
//
// 示例 3： 
//
// 
//输入：matrix = [["0"]]
//输出：0
// 
//
// 示例 4： 
//
// 
//输入：matrix = [["1"]]
//输出：1
// 
//
// 示例 5： 
//
// 
//输入：matrix = [["0","0"]]
//输出：0
// 
//
// 
//
// 提示： 
//
// 
// rows == matrix.length 
// cols == matrix[0].length 
// 0 <= row, cols <= 200 
// matrix[i][j] 为 '0' 或 '1' 
// 
// Related Topics 栈 数组 哈希表 动态规划 
// 👍 931 👎 0

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
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if (m == 0) return 0;
        int n = matrix[0].size();
        if (n == 0) return 0;

        vector<vector<int>> rects (m, vector<int>(n, 0));
        // 按列遍历，从左到右
        for (int j = 0; j < n; j++) {
            int tmp = 0;
            for (int i = 0; i < m; i++) {
                if (!(matrix[i][j] - '0')) {
                    tmp = 0;
                    continue;
                }
                tmp++;
                rects[i][j] = tmp;
            }
        }

        int maxSize = 0;
        for (int i = 0; i < m; i++) {
            maxSize = max(maxSize, maxRectLine(rects[i]));
        }

        return maxSize;
    }

    int maxRectLine(vector<int>& heights) {
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