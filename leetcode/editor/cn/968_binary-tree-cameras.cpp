//给定一个二叉树，我们在树的节点上安装摄像头。 
//
// 节点上的每个摄影头都可以监视其父对象、自身及其直接子对象。 
//
// 计算监控树的所有节点所需的最小摄像头数量。 
//
// 
//
// 示例 1： 
//
// 
//
// 输入：[0,0,null,0,0]
//输出：1
//解释：如图所示，一台摄像头足以监控所有节点。
// 
//
// 示例 2： 
//
// 
//
// 输入：[0,0,null,0,null,0,null,null,0]
//输出：2
//解释：需要至少两个摄像头来监视树的所有节点。 上图显示了摄像头放置的有效位置之一。
// 
//
// 
//提示： 
//
// 
// 给定树的节点数的范围是 [1, 1000]。 
// 每个节点的值都是 0。 
// 
// Related Topics 树 深度优先搜索 动态规划 二叉树 
// 👍 313 👎 0

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
    map<TreeNode*, int> mapMinCameraCover;
    map<TreeNode*, int> mapMinCameraCoverInnerFalse;
    map<TreeNode*, int> mapMinCameraCoverInnerTrue;

    int minCameraCover(TreeNode* root) {
        if (root == nullptr) return 0;
        if (mapMinCameraCover.find(root) != mapMinCameraCover.end()) {
            return mapMinCameraCover[root];
        }

        int res;
        int off = minCameraCoverInner(root, false);
        int on = minCameraCoverInner(root, true);
        if (off != -1) res = min(off, on);
        else res = on;
        mapMinCameraCover[root] = res;
        return res;
    }

    int minCameraCoverNoWay(TreeNode* root) {
        // root已经被监视
        if (root == nullptr) return 0;
        return min(minCameraCoverInner(root, true), minCameraCover(root->left) + minCameraCover(root->right));
    }

    int minCameraCoverInner(TreeNode* root, bool isCheckRoot) {
        if (root == nullptr) return 0;
        if (!isCheckRoot && mapMinCameraCoverInnerFalse.find(root) != mapMinCameraCoverInnerFalse.end()) {
            return mapMinCameraCoverInnerFalse[root];
        }
        if (isCheckRoot && mapMinCameraCoverInnerTrue.find(root) != mapMinCameraCoverInnerTrue.end()) {
            return mapMinCameraCoverInnerTrue[root];
        }

        int res = 0;
        if (isCheckRoot) {
            res += 1;
            res += minCameraCoverNoWay(root->left);
            res += minCameraCoverNoWay(root->right);
            mapMinCameraCoverInnerTrue[root] = res;

        } else {
            if (root->left != nullptr && root->right != nullptr) {
                int leftOn = minCameraCoverInner(root->left, true);
                int leftOff = minCameraCoverInner(root->left, false);
                int rightOn = minCameraCoverInner(root->right, true);
                int rightOff = minCameraCoverInner(root->right, false);
                if (leftOff != -1 && rightOff != -1)
                    res += min(leftOn+rightOn, min(leftOff+rightOn, leftOn+rightOff));
                else if (leftOff != -1)
                    res += min(leftOn+rightOn, leftOff+rightOn);
                else if (rightOff != -1)
                    res += min(leftOn+rightOn, rightOff+leftOn);
                else res += leftOn+rightOn;

            } else if (root->left != nullptr) {
                res += minCameraCoverInner(root->left, true);
            } else if (root->right != nullptr) {
                res += minCameraCoverInner(root->right, true);
            } else {
                res = -1;
            }
            mapMinCameraCoverInnerFalse[root] = res;
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    TreeNode* r = new TreeNode(0);
    cout << s.minCameraCover(r);
}