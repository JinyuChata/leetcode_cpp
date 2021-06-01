//给你一个整数 n ，请你生成并返回所有由 n 个节点组成且节点值从 1 到 n 互不相同的不同 二叉搜索树 。可以按 任意顺序 返回答案。 
//
// 
//
// 
// 
// 示例 1： 
//
// 
//输入：n = 3
//输出：[[1,null,2,null,3],[1,null,3,2],[2,1,3],[3,1,null,null,2],[3,2,null,1]]
// 
//
// 示例 2： 
//
// 
//输入：n = 1
//输出：[[1]]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= n <= 8 
// 
// 
// 
// Related Topics 树 动态规划 
// 👍 883 👎 0

#include <bits/stdc++.h>
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
    TreeNode* copyTreeNode(TreeNode* t, int bias) {
        if (t == nullptr) return nullptr;
        return new TreeNode(t->val+bias,
                copyTreeNode(t->left, bias),
                copyTreeNode(t->right, bias));
    }

    vector<TreeNode *> generateTrees(int n) {
        vector<vector<TreeNode *>> dp(n+1, vector<TreeNode *>(0));   // dp[0] = nullptr
        dp[0].push_back(nullptr);

        for (int i = 1; i <= n; i++) {
            for (int k = 1; k <= i; k++) {
                int left = k-1; int right = i-k;
                for (TreeNode* l : dp[left]) {
                    for (TreeNode* r : dp[right]) {
                        TreeNode* t = new TreeNode(k);
                        t->left = copyTreeNode(l, 0);
                        t->right = copyTreeNode(r, k);
                        dp[i].push_back(t);
                    }
                }
            }
        }
        return dp[n];

    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
}