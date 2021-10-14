//给定一个数组 nums ，如果 i < j 且 nums[i] > 2*nums[j] 我们就将 (i, j) 称作一个重要翻转对。 
//
// 你需要返回给定数组中的重要翻转对的数量。 
//
// 示例 1: 
//
// 
//输入: [1,3,2,3,1]
//输出: 2
// 
//
// 示例 2: 
//
// 
//输入: [2,4,3,5,1]
//输出: 3
// 
//
// 注意: 
//
// 
// 给定数组的长度不会超过50000。 
// 输入数组中的所有数字都在32位整数的表示范围内。 
// 
// Related Topics 树状数组 线段树 数组 二分查找 分治 有序集合 归并排序 👍 297 👎 0

#include "bits/stdc++.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        vector<int> tmp(n);
        return mergeSort(nums, tmp, 0, n-1);

    }

    int mergeSort(vector<int>& nums, vector<int>& tmp, int l, int r) {
        if (l >= r) return 0;
        int mid = l + (r-l)/2;
        int ret = mergeSort(nums, tmp, l, mid)
                + mergeSort(nums, tmp, mid+1, r);
        for (int i = l; i <= r; i++)
            tmp[i] = nums[i];

//        cout << l << " " << mid << " " << r << endl;
        int i = l; int j = mid+1;
        while (i <= mid) {
            while ( j <= r && (long long) nums[i] > (long long) nums[j]* (long long)2)
                j++;

            ret += j-mid-1;
            i++;
        }

        // merge
        i = l; j = mid+1;
        for (int k = l; k <= r; k++) {
            if (i <= mid && j <= r) {
                if (tmp[i] <= tmp[j]) {
                    nums[k] = tmp[i++];
                } else {
                    nums[k] = tmp[j++];
                }
            } else if (i > mid) {
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