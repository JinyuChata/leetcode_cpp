//给定一个非负索引 rowIndex，返回「杨辉三角」的第 rowIndex 行。 
//
// 在「杨辉三角」中，每个数是它左上方和右上方的数的和。 
//
// 
//
// 
//
// 示例 1: 
//
// 
//输入: rowIndex = 3
//输出: [1,3,3,1]
// 
//
// 示例 2: 
//
// 
//输入: rowIndex = 0
//输出: [1]
// 
//
// 示例 3: 
//
// 
//输入: rowIndex = 1
//输出: [1,1]
// 
//
// 
//
// 提示: 
//
// 
// 0 <= rowIndex <= 33 
// 
//
// 
//
// 进阶： 
//
// 你可以优化你的算法到 O(rowIndex) 空间复杂度吗？ 
// Related Topics 数组 动态规划 👍 318 👎 0

#include "bits/stdc++.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if (rowIndex == 0) return {1};
        if (rowIndex == 1) return {1,1};
        vector<int> row = {1,1};
        for (int i = 2; i <= rowIndex; i++) {
            vector<int> curr = {1};
            for (int j = 1; j < i; j++) {
                curr.push_back(row[j-1] + row[j]);
            }
            curr.push_back(1);
            row = curr;
        }

        return row;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
}