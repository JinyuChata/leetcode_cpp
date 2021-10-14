//在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。输入一个数组，求出这个数组中的逆序对的总数。 
//
// 
//
// 示例 1: 
//
// 输入: [7,5,6,4]
//输出: 5 
//
// 
//
// 限制： 
//
// 0 <= 数组长度 <= 50000 
// Related Topics 树状数组 线段树 数组 二分查找 分治 有序集合 归并排序 👍 522 👎 0

#include "bits/stdc++.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int reversePairs(vector<int> &nums) {
        int n = nums.size();
        vector<int> tmp(n);
        return mergeSort(nums, tmp, 0, n-1);
    }

    int mergeSort(vector<int> &nums, vector<int> &tmp, int l, int r) {
        // 先将l..r 复制到tmp
        if (l >= r) return 0;
        int m = (l + r) / 2;
        int ret = mergeSort(nums, tmp, l, m) + mergeSort(nums, tmp, m + 1, r);

        // 合并
        for (int i = l; i <= r; i++) {
            tmp[i] = nums[i];
        }
        int i = l;
        int j = m + 1;
        for (int k = l; k <= r; k++) {
            if (i != m+1 && j != r+1) {
                // 没有到头
                int left = tmp[i]; int right = tmp[j];
                if (left <= right) {
                    nums[k] = tmp[i++];
                } else {
                    ret += (m - i + 1);
                    nums[k] = tmp[j++];
                }
            } else if (i == m+1) {
                nums[k] = tmp[j++];
            } else {
                nums[k] = tmp[i++];
            }
        }

        return ret;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
}