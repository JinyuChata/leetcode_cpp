//给出集合 [1,2,3,...,n]，其所有元素共有 n! 种排列。 
//
// 按大小顺序列出所有排列情况，并一一标记，当 n = 3 时, 所有排列如下： 
//
// 
// "123" 
// "132" 
// "213" 
// "231" 
// "312" 
// "321" 
// 
//
// 给定 n 和 k，返回第 k 个排列。 
//
// 
//
// 示例 1： 
//
// 
//输入：n = 3, k = 3
//输出："213"
// 
//
// 示例 2： 
//
// 
//输入：n = 4, k = 9
//输出："2314"
// 
//
// 示例 3： 
//
// 
//输入：n = 3, k = 1
//输出："123"
// 
//
// 
//
// 提示： 
//
// 
// 1 <= n <= 9 
// 1 <= k <= n! 
// 
// Related Topics 数学 回溯算法 
// 👍 523 👎 0
#include "bits/stdc++.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string getPermutation(int n, int k) {
        int mem[]{
            1,1,2,6,24,120,720,5040,40320,362880
        };

        vector<int> nums;
        for (int i = 1; i <= n; i++)
            nums.push_back(i);

        k--;
        // 现在决定第几位
        string res;
        for (int i = n; i >= 1; i--) {
            int idx = 0;
            while (k >= mem[i-1]) {
                k-=mem[i-1];
                idx++;
            }
            res += string(1, nums[idx]+'0');
            nums.erase(nums.begin()+idx);
        }

        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    cout << s.getPermutation(3,3);
}