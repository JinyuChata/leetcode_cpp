//树是一个无向图，其中任何两个顶点只通过一条路径连接。 换句话说，一个任何没有简单环路的连通图都是一棵树。 
//
// 给你一棵包含 n 个节点的树，标记为 0 到 n - 1 。给定数字 n 和一个有 n - 1 条无向边的 edges 列表（每一个边都是一对标签），其中
// edges[i] = [ai, bi] 表示树中节点 ai 和 bi 之间存在一条无向边。 
//
// 可选择树中任何一个节点作为根。当选择节点 x 作为根节点时，设结果树的高度为 h 。在所有可能的树中，具有最小高度的树（即，min(h)）被称为 最小高度
//树 。 
//
// 请你找到所有的 最小高度树 并按 任意顺序 返回它们的根节点标签列表。 
//树的 高度 是指根节点和叶子节点之间最长向下路径上边的数量。
//
// 
//
// 示例 1： 
//
// 
//输入：n = 4, edges = [[1,0],[1,2],[1,3]]
//输出：[1]
//解释：如图所示，当根是标签为 1 的节点时，树的高度是 1 ，这是唯一的最小高度树。 
//
// 示例 2： 
//
// 
//输入：n = 6, edges = [[3,0],[3,1],[3,2],[3,4],[5,4]]
//输出：[3,4]
// 
//
// 示例 3： 
//
// 
//输入：n = 1, edges = []
//输出：[0]
// 
//
// 示例 4： 
//
// 
//输入：n = 2, edges = [[0,1]]
//输出：[0,1]
// 
//
// 
//
// 
// 
//
// 提示： 
//
// 
// 1 <= n <= 2 * 104 
// edges.length == n - 1 
// 0 <= ai, bi < n 
// ai != bi 
// 所有 (ai, bi) 互不相同 
// 给定的输入 保证 是一棵树，并且 不会有重复的边 
// 
// Related Topics 深度优先搜索 广度优先搜索 图 拓扑排序 
// 👍 365 👎 0

#include "bits/stdc++.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int> res;
        if (n == 1) {
            res.push_back(0); return res;
        }

        // 剥洋葱法
        vector<int> degrees(n);
        vector<int> existed(n);
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++) {
            degrees[i] = 0;
            existed[i] = 1;     // 一开始，全部都存在
                                // 后面，可能会删除
        }
        int existedCnt = n;
        for (vector<int>& edge : edges) {
            degrees[edge[0]]++;
            degrees[edge[1]]++;
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        // 先找出初始的叶子节点
        queue<int> leaf;
        for (int i = 0; i < n; i++) {
            if (degrees[i] == 1) {
                leaf.push(i);
            }
        }

        while (!leaf.empty()) {
            if (leaf.size() == existedCnt) {
                while (!leaf.empty()) {
                    res.push_back(leaf.front()); leaf.pop();
                }
                return res;
            }

            int s = leaf.size();
            for (int i = 0; i < s; i++) {
                int curr = leaf.front();
                leaf.pop();
                // 删除curr, 给所有临接节点的度-1
                existed[curr] = 0;
                existedCnt--;
                for (int a : adj[curr]) {
                    degrees[a]--;
                    if (degrees[a] == 1) leaf.push(a);
                }
            }
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
}