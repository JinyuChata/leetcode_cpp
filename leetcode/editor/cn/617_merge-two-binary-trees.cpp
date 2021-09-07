//给定两个二叉树，想象当你将它们中的一个覆盖到另一个上时，两个二叉树的一些节点便会重叠。 
//
// 你需要将他们合并为一个新的二叉树。合并的规则是如果两个节点重叠，那么将他们的值相加作为节点合并后的新值，否则不为 NULL 的节点将直接作为新二叉树的节点
//。 
//
// 示例 1: 
//
// 
//输入: 
//	Tree 1                     Tree 2                  
//          1                         2                             
//         / \                       / \                            
//        3   2                     1   3                        
//       /                           \   \                      
//      5                             4   7                  
//输出: 
//合并后的树:
//	     3
//	    / \
//	   4   5
//	  / \   \ 
//	 5   4   7
// 
//
// 注意: 合并必须从两个树的根节点开始。 
// Related Topics 树 深度优先搜索 广度优先搜索 二叉树 
// 👍 756 👎 0
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

//leetcode submit region begin(Prohibit modification and deletion)

class Solution {
public:
    TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2) {
        if (root1 == nullptr && root2 == nullptr) return nullptr;
        int val = 0;
        TreeNode* r1_left = nullptr, *r1_right = nullptr, *r2_left = nullptr, *r2_right = nullptr;
        if (root1 != nullptr) { val += root1->val; r1_left = root1->left; r1_right = root1->right; }
        if (root2 != nullptr) { val += root2->val; r2_left = root2->left; r2_right = root2->right; }
        return new TreeNode(val, mergeTrees(r1_left, r2_left), mergeTrees(r1_right, r2_right));
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
}