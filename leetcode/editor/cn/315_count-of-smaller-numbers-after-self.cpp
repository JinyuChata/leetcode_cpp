//给你`一个整数数组 nums ，按要求返回一个新数组 counts 。数组 counts 有该性质： counts[i] 的值是 nums[i] 右侧小于 
//nums[i] 的元素的数量。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [5,2,6,1]
//输出：[2,1,1,0] 
//解释：
//5 的右侧有 2 个更小的元素 (2 和 1)
//2 的右侧仅有 1 个更小的元素 (1)
//6 的右侧有 1 个更小的元素 (1)
//1 的右侧有 0 个更小的元素
// 
//
// 示例 2： 
//
// 
//输入：nums = [-1]
//输出：[0]
// 
//
// 示例 3： 
//
// 
//输入：nums = [-1,-1]
//输出：[0,0]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 10⁵ 
// -10⁴ <= nums[i] <= 10⁴ 
// 
// Related Topics 树状数组 线段树 数组 二分查找 分治 有序集合 归并排序 👍 643 👎 0

#include "bits/stdc++.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class LineNode {
public:
    LineNode* left;
    LineNode* right;

    int minVal; int maxVal;
    int count = 0;
};

class Solution {
public:
    LineNode* buildNode(int minVal, int maxVal) {
        if (minVal > maxVal) return nullptr;
        LineNode* root = new LineNode;
        root->minVal = minVal; root->maxVal = maxVal;
        if (minVal == maxVal) return root;

        int mid = minVal + (maxVal - minVal) / 2;
        LineNode* leftNode = buildNode(minVal, mid);
        LineNode* rightNode = buildNode(mid+1, maxVal);
        root->left = leftNode; root->right = rightNode;

        return root;
    }

    // [l,r] 工作区间
    // [L,R] 要查询的区间
    int queryCounter(int l, int r, int L, int R, LineNode* root) {
        if (L > R) return 0; if (l > r) return 0;
        if (L > r || R < l) return 0;
        if (L <= l && r <= R) return root->count;

        if (l == r) {
            if (L <= l && r <= R) return root->count;
            return 0;
        }

        int ret = 0;
        int mid = l + (r-l)/2;
        ret += queryCounter(l, mid, L, R, root->left);
        ret += queryCounter(mid+1, r, L, R, root->right);
        return ret;
    }

    void insertValue(int l, int r, int val, LineNode* root) {
        if (r < l) return;
        if (l <= val && val <= r) root->count++;
        if (l == r) return;

        int mid = l + (r-l)/2;
        if (l <= val && val <= mid) insertValue(l, mid, val, root->left);
        if (mid+1 <= val && val <= r) insertValue(mid+1, r, val, root->right);
    }

    vector<int> countSmaller(vector<int>& nums) {
        int minVal = nums[0]; int maxVal = nums[0];
        int n = nums.size();
        for (int i = 1; i < n; i++) {
            if (nums[i] < minVal) minVal = nums[i];
            if (nums[i] > maxVal) maxVal = nums[i];
        }

        // 建树
        LineNode* root = buildNode(minVal, maxVal);
        vector<int> res;
        // 从右向左遍历，边遍历边查
        for (int i = n-1; i >= 0; i--) {
            int num = nums[i];
            // 先查询现有线段树中，小于 num 的元素
            res.insert(res.begin(), queryCounter(minVal, maxVal, minVal, num-1, root));
            // 再将num插入线段树
            insertValue(minVal, maxVal, num, root);
        }

        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
}