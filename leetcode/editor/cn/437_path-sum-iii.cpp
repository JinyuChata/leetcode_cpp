//给定一个二叉树的根节点 root ，和一个整数 targetSum ，求该二叉树里节点值之和等于 targetSum 的 路径 的数目。 
//
// 路径 不需要从根节点开始，也不需要在叶子节点结束，但是路径方向必须是向下的（只能从父节点到子节点）。 
//
// 
//
// 示例 1： 
//
// 
//
// 
//输入：root = [10,5,-3,3,2,null,11,3,-2,null,1], targetSum = 8
//输出：3
//解释：和等于 8 的路径有 3 条，如图所示。
// 
//
// 示例 2： 
//
// 
//输入：root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
//输出：3
// 
//
// 
//
// 提示: 
//
// 
// 二叉树的节点个数的范围是 [0,1000] 
// -109 <= Node.val <= 109 
// -1000 <= targetSum <= 1000 
// 
// Related Topics 树 深度优先搜索 二叉树 
// 👍 962 👎 0

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
    int target;
    map<pair<TreeNode*, int>, int> memo;
    int dfs2(TreeNode* root, int sum) {
        if (root == nullptr) return 0;
//        if (memo.count({root, sum}))
//            return memo[{root, sum}];
        int res = 0;
        sum += root->val;
        if (sum == target) res++;
        res += dfs2(root->left, sum);
        res += dfs2(root->right, sum);
//        memo[{root, sum}] = res;
        return res;
    }

    int dfs1(TreeNode* root) {
        if (root == nullptr) return 0;
        int res = 0;
        int t = dfs2(root, 0);
//        cout << "root: " << root->val << " cnt: " << t << endl;
        res += t;
        res += dfs1(root->left) + dfs1(root->right);
        return res;
    }

    int pathSum(TreeNode *root, int targetSum) {
        this->target = targetSum;
        return dfs1(root);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    TreeNode* t = new TreeNode(1,
                               new TreeNode(-2,
                                            new TreeNode(1,
                                                         new TreeNode(-1, nullptr, nullptr), nullptr), nullptr), nullptr);
    cout << s.pathSum(t, 1) << endl;
}