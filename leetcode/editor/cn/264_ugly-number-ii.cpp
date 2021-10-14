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
    static bool cmp(int& i, int& j) {
        return i > j;
    }

    int nthUglyNumber(int n) {
        // 最小堆
        priority_queue<long long, vector<int>, decltype(&cmp)> heap(cmp);
        unordered_set<long long> collected;
        collected.insert(1);
        heap.push(1);

        while (true) {
            n--;
            int curr = heap.top(); heap.pop();
            if (n == 0) return curr;
            // *2 *3 *5
            if (!collected.count(curr*2)) {
                heap.push(curr*2); collected.insert(curr*2);
            }
            if (!collected.count(curr*3)) {
                heap.push(curr*3); collected.insert(curr*3);
            }
            if (!collected.count(curr*5)) {
                heap.push(curr*5); collected.insert(curr*5);
            }
        }
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    cout << s.nthUglyNumber(10);
}