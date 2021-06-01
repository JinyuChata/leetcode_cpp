//给你一个整数 n ，请你找出并返回第 n 个 丑数 。 
//
// 丑数 就是只包含质因数 2、3 和/或 5 的正整数。 
//
// 
//
// 示例 1： 
//
// 
//输入：n = 10
//输出：12
//解释：[1, 2, 3, 4, 5, 6, 8, 9, 10, 12] 是由前 10 个丑数组成的序列。
// 
//
// 示例 2： 
//
// 
//输入：n = 1
//输出：1
//解释：1 通常被视为丑数。
// 
//
// 
//
// 提示： 
//
// 
// 1 <= n <= 1690 
// 
// Related Topics 堆 数学 动态规划 
// 👍 664 👎 0

//leetcode submit region begin(Prohibit modification and deletion)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int nthUglyNumber(int n) {
        // minHeap shixian
        vector<int> factors = {2, 3, 5};
        unordered_set<long> seen;
        priority_queue<long, vector<long>, greater<long>> heap;
        seen.insert(1);
        heap.push(1);
        int ugly = 0;

        for (int i = 0; i < n; i++) {
            long curr = heap.top();
            heap.pop();
            ugly = (int) curr;
            for (int f : factors) {
                long next = curr*f;
                if (!seen.count(next)) {
                    seen.insert(next);
                    heap.push(next);
                }
            }
        }

        return ugly;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    cout << s.nthUglyNumber(10);
}