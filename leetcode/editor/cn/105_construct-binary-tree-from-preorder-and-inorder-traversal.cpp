//给定一棵树的前序遍历 preorder 与中序遍历 inorder。请构造二叉树并返回其根节点。 
//
// 
//
// 示例 1: 
//
// 
//Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
//Output: [3,9,20,null,null,15,7]
// 
//
// 示例 2: 
//
// 
//Input: preorder = [-1], inorder = [-1]
//Output: [-1]
// 
//
// 
//
// 提示: 
//
// 
// 1 <= preorder.length <= 3000 
// inorder.length == preorder.length 
// -3000 <= preorder[i], inorder[i] <= 3000 
// preorder 和 inorder 均无重复元素 
// inorder 均出现在 preorder 
// preorder 保证为二叉树的前序遍历序列 
// inorder 保证为二叉树的中序遍历序列 
// 
// Related Topics 树 数组 哈希表 分治 二叉树 
// 👍 1190 👎 0

#include "bits/stdc++.h"
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//leetcode submit region begin(Prohibit modification and deletion)
/**
  Definition for a binary tree node.

 */
class Solution {
public:
    // [preStart, preEnd)
    TreeNode* dfs(vector<int>& preorder, int preStart, int preEnd,
                  vector<int>& inorder, int inStart, int inEnd) {
        if (preStart == preEnd) return nullptr;
        int rootVal = preorder[preStart];
        int rootIdxIn = inStart;
        while (inorder[rootIdxIn] != rootVal)
            rootIdxIn++;

        int leftSize = rootIdxIn - inStart;
        int rightSize = inEnd - rootIdxIn - 1;

        auto* root = new TreeNode(rootVal);
        root->left = dfs(preorder, preStart+1, preStart+1+leftSize, inorder, inStart, rootIdxIn);
        root->right = dfs(preorder, preStart+1+leftSize, preEnd, inorder, rootIdxIn+1, inEnd);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return dfs(preorder, 0, preorder.size(), inorder, 0, inorder.size());
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
}