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
// Related Topics 栈 数组 动态规划 矩阵 单调栈 
// 👍 1026 👎 0

#include "bits/stdc++.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int maxRect(vector<int> line) {
        line.push_back(-1);
        line.insert(line.begin(), -1);
        int n = line.size();

        vector<int> left(n, 0);
        vector<int> right(n, n-1);

        stack<int> stk;
        for (int i = 0; i < n; i++) {
            while (!stk.empty() && line[i] < line[stk.top()]) {
                right[stk.top()] = i;
                stk.pop();
            }
            stk.push(i);
        }

        stk = stack<int>();
        for (int i = n-1; i >= 0; i--) {
            while (!stk.empty() && line[i] < line[stk.top()]) {
                left[stk.top()] = i;
                stk.pop();
            }
            stk.push(i);
        }

        int maxSize = 0;
        for (int i = 1; i < n-1; i++) {
            maxSize = max(maxSize, line[i]*(right[i]-left[i]-1));
        }
        return maxSize;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if (m == 0) return 0;
        int n = matrix[0].size();

        vector<vector<int>> heights(m, vector<int>(n, 0));
        for (int j = 0; j < n; j++) {
            int curr = 0;
            for (int i = 0; i < m; i++) {
                if (matrix[i][j] == '0') curr = 0;
                else curr++;
                heights[i][j] = curr;
            }
        }

        int maxSize = 0;
        for (int i = 0; i < m; i++) {
            maxSize = max(maxSize, maxRect(heights[i]));
        }
        return maxSize;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
}