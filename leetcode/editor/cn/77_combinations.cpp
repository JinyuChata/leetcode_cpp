//给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。 
//
// 示例: 
//
// 输入: n = 4, k = 2
//输出:
//[
//  [2,4],
//  [3,4],
//  [2,3],
//  [1,2],
//  [1,3],
//  [1,4],
//] 
// Related Topics 回溯算法 
// 👍 592 👎 0

#include "bits/stdc++.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> ress;

    void traceback(int nextNum, int remainingCnt, vector<int>& mem, int n) {
        if (remainingCnt == 0) {
            ress.emplace_back(mem);
            return;
        }

        // 选 or 不选
        if (n-nextNum+1 < remainingCnt) {
            return;
        }

        mem.push_back(nextNum);
        traceback(nextNum+1, remainingCnt-1, mem, n);
        mem.pop_back();
        traceback(nextNum+1, remainingCnt, mem, n);
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int> v;
        traceback(1, k, v, n);
        return ress;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
}