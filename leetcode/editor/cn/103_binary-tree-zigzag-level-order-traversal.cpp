//给定一个二叉树，返回其节点值的锯齿形层序遍历。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。 
//
// 例如： 
//给定二叉树 [3,9,20,null,null,15,7], 
//
// 
//    3
//   / \
//  9  20
//    /  \
//   15   7
// 
//
// 返回锯齿形层序遍历如下： 
//
// 
//[
//  [3],
//  [20,9],
//  [15,7]
//]
// 
// Related Topics 栈 树 广度优先搜索 
// 👍 450 👎 0
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ress;
        if (!root) return ress;
        int lvl = 0;
        int newLvl = 0;
        int lvlSize = 1;
        queue<TreeNode*> qt;
        qt.push(root);

        while (!qt.empty()) {
            vector<int> res;
            newLvl = 0;
            for (int i = 0; i < lvlSize; i++) {
                int qI = qt.front()->val;
                if (lvl % 2 == 1) {
                    // 逆序
                    res.insert(res.begin(), qI);
                } else {
                    res.push_back(qI);
                }
                if (qt.front()->left) { qt.push(qt.front()->left); newLvl ++; }
                if (qt.front()->right) { qt.push(qt.front()->right); newLvl ++; }
                qt.pop();
            }
            lvl ++;
            lvlSize = newLvl;
            ress.push_back(res);
        }
        return ress;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
}