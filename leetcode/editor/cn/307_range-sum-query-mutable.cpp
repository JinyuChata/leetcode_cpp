//给你一个数组 nums ，请你完成两类查询，其中一类查询要求更新数组下标对应的值，另一类查询要求返回数组中某个范围内元素的总和。 
//
// 实现 NumArray 类： 
//
// 
// 
// 
// NumArray(int[] nums) 用整数数组 nums 初始化对象 
// void update(int index, int val) 将 nums[index] 的值更新为 val 
// int sumRange(int left, int right) 返回子数组 nums[left, right] 的总和（即，nums[left] + 
//nums[left + 1], ..., nums[right]） 
// 
//
// 
//
// 示例： 
//
// 
//输入：
//["NumArray", "sumRange", "update", "sumRange"]
//[[[1, 3, 5]], [0, 2], [1, 2], [0, 2]]
//输出：
//[null, 9, null, 8]
//
//解释：
//NumArray numArray = new NumArray([1, 3, 5]);
//numArray.sumRange(0, 2); // 返回 9 ，sum([1,3,5]) = 9
//numArray.update(1, 2);   // nums = [1,2,5]
//numArray.sumRange(0, 2); // 返回 8 ，sum([1,2,5]) = 8
// 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 3 * 10⁴ 
// -100 <= nums[i] <= 100 
// 0 <= index < nums.length 
// -100 <= val <= 100 
// 0 <= left <= right < nums.length 
// 最多调用 3 * 10⁴ 次 update 和 sumRange 方法 
// 
// 
// 
// Related Topics 设计 树状数组 线段树 数组 👍 293 👎 0

#include "bits/stdc++.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class NumArray {
public:
    int n = 0;
    vector<int> tree;

    // 左子树、右子树更新后，更新root节点
    void pushUp(int root) {
        int left = tree[root<<1];
        int right = tree[root<<1|1];
        tree[root] = left+right;
    }

    // 递归建树
    // root 代表 [l, r]
    void buildTree(vector<int>& nums, int l, int r, int root) {
        if (l == r) {
            tree[root] = nums[l]; return;
        }
        int mid = (l+r)>>1;
        buildTree(nums, l, mid, root<<1);
        buildTree(nums, mid+1, r, root<<1|1);
        pushUp(root);
    }

    NumArray(vector<int>& nums) {
        // 先开数组 4*n
        n = nums.size();
        tree = vector<int>(4*n);
        // 建树
        buildTree(nums, 0, n-1, 1);
        for (int i = 1; i < 4*n; i++)
            cout << tree[i] << " ";
    }

    // l..r 工作区间
    // index 在工作区间的一个值
    void updateTree(int index, int l, int r, int root, int change) {
        if (l == r) {
            tree[root] = change;
            return;
        }
        int mid = (l+r)>>1;
        if (index <= mid) updateTree(index, l, mid, root<<1, change);
        else updateTree(index, mid+1, r, root<<1|1, change);
        pushUp(root);
    }

    void update(int index, int val) {
        updateTree(index, 0, n-1, 1, val);
    }

    // lr 操作区间
    // LR 求和区间
    int sumTree(int l, int r, int L, int R, int root) {
        if (L <= l && r <= R) return tree[root];
        int mid = (l+r)>>1;
        int ans = 0;
        if (L <= mid) ans += sumTree(l, mid, L, R, root<<1);
        if (R > mid) ans += sumTree(mid+1, r, L, R, root<<1|1);
        return ans;
    }
    
    int sumRange(int left, int right) {
        return sumTree(0, n-1, left, right, 1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
}