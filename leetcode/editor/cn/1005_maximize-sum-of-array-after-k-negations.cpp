//给定一个整数数组 A，我们只能用以下方法修改该数组：我们选择某个索引 i 并将 A[i] 替换为 -A[i]，然后总共重复这个过程 K 次。（我们可以多次选
//择同一个索引 i。） 
//
// 以这种方式修改数组后，返回数组可能的最大和。 
//
// 
//
// 示例 1： 
//
// 输入：A = [4,2,3], K = 1
//输出：5
//解释：选择索引 (1,) ，然后 A 变为 [4,-2,3]。
// 
//
// 示例 2： 
//
// 输入：A = [3,-1,0,2], K = 3
//输出：6
//解释：选择索引 (1, 2, 2) ，然后 A 变为 [3,1,0,2]。
// 
//
// 示例 3： 
//
// 输入：A = [2,-3,-1,5,-4], K = 2
//输出：13
//解释：选择索引 (1, 4) ，然后 A 变为 [2,3,-1,5,4]。
// 
//
// 
//
// 提示： 
//
// 
// 1 <= A.length <= 10000 
// 1 <= K <= 10000 
// -100 <= A[i] <= 100 
// 
// Related Topics 贪心 数组 排序 
// 👍 94 👎 0

#include "bits/stdc++.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), [](int & a, int & b){
            return a < b;
        });
        // 负的变成正的，尽量多
        int idx = 0;
        while (k > 0 && idx < nums.size()) {
            if (nums[idx] >= 0) break;
            nums[idx] = -nums[idx];
            k--;
            idx++;
        }

        // 此时还有次数
        if (k > 0) {
            // 也就是说，全部>=0
            if (k % 2 != 0) {
                sort(nums.begin(), nums.end(), [](int & a, int & b){
                    return a < b;
                });
                nums[0] = -nums[0];
            }
        }

        int sum = 0;
        for (int i : nums) sum += i;

        return sum;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    vector<int> nums({3, -1, 0, 2});
    s.largestSumAfterKNegations(nums, 3);
}