//给定一个包含非负整数的数组，你的任务是统计其中可以组成三角形三条边的三元组个数。 
//
// 示例 1: 
//
// 
//输入: [2,2,3,4]
//输出: 3
//解释:
//有效的组合是: 
//2,3,4 (使用第一个 2)
//2,3,4 (使用第二个 2)
//2,2,3
// 
//
// 注意: 
//
// 
// 数组长度不超过1000。 
// 数组里整数的范围为 [0, 1000]。 
// 
// Related Topics 贪心 数组 双指针 二分查找 排序 
// 👍 289 👎 0

#include "bits/stdc++.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        // 双指针：先固定最大的
        int n = nums.size();
        if (n < 3) return 0;

        sort(nums.begin(), nums.end());

        int tot = 0;
        for (int k = n-1; k > 1; k--) {
            // 固定住k, 取i-j
            int i = 0; int j = k-1;
            while (i < j) {
                if (nums[i] + nums[j] > nums[k]) {
                    tot += j-i;
                    j--;
                } else {
                    i++;
                }
            }
        }

        return tot;

    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    vector<int> v = {2,2,3,4};
    cout << s.triangleNumber(v);
}