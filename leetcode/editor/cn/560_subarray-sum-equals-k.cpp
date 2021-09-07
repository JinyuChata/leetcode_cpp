//给定一个整数数组和一个整数 k，你需要找到该数组中和为 k 的连续的子数组的个数。 
//
// 示例 1 : 
//
// 
//输入:nums = [1,1,1], k = 2
//输出: 2 , [1,1] 与 [1,1] 为两种不同的情况。
// 
//
// 说明 : 
//
// 
// 数组的长度为 [1, 20,000]。 
// 数组中元素的范围是 [-1000, 1000] ，且整数 k 的范围是 [-1e7, 1e7]。 
// 
// Related Topics 数组 哈希表 前缀和 
// 👍 1073 👎 0

#include "bits/stdc++.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int> tailSum; tailSum.push_back(0);
        unordered_map<int, int> map; map[0] = 1;
        int sum = 0;
        for (int num : nums) {
            sum += num;
            tailSum.push_back(sum);
            if (!map.count(sum)) map[sum] = 1;
            else map[sum]++;
        }

        int result = 0;
        for (int ts : tailSum) {
            map[ts]--;
            int target = k+ts;
            if (map.count(target)) {
                result += map[target];
            }
        }

        return result;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
}