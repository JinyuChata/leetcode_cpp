//给定一棵二叉树，你需要计算它的直径长度。一棵二叉树的直径长度是任意两个结点路径长度中的最大值。这条路径可能穿过也可能不穿过根结点。 
//
// 
//
// 示例 : 
//给定二叉树 
//
//           1
//         / \
//        2   3
//       / \     
//      4   5    
// 
//
// 返回 3, 它的长度是路径 [4,2,1,3] 或者 [5,2,1,3]。 
//
// 
//
// 注意：两结点之间的路径长度是以它们之间边的数目表示。 
// Related Topics 树 深度优先搜索 二叉树 
// 👍 781 👎 0

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
class Solution {
public:
    int result = 0;

    int dfs(TreeNode* root) {
        // 返回 以root为根，最长的单条路径
        if (root == nullptr) return 0;
        int left = dfs(root->left);
        int right = dfs(root->right);
        result = max(result, left + right + 1);
        return 1 + max(left, right);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if (root == nullptr) return 0;
        dfs(root);
        return result - 1;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
}