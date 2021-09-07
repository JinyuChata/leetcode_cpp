//在本问题中，有根树指满足以下条件的 有向 图。该树只有一个根节点，所有其他节点都是该根节点的后继。该树除了根节点之外的每一个节点都有且只有一个父节点，而根节
//点没有父节点。 
//
// 输入一个有向图，该图由一个有着 n 个节点（节点值不重复，从 1 到 n）的树及一条附加的有向边构成。附加的边包含在 1 到 n 中的两个不同顶点间，这条
//附加的边不属于树中已存在的边。 
//
// 结果图是一个以边组成的二维数组 edges 。 每个元素是一对 [ui, vi]，用以表示 有向 图中连接顶点 ui 和顶点 vi 的边，其中 ui 是 
//vi 的一个父节点。 
//
// 返回一条能删除的边，使得剩下的图是有 n 个节点的有根树。若有多个答案，返回最后出现在给定二维数组的答案。 
//
// 
//
// 示例 1： 
//
// 
//输入：edges = [[1,2],[1,3],[2,3]]
//输出：[2,3]
// 
//
// 示例 2： 
//
// 
//输入：edges = [[1,2],[2,3],[3,4],[4,1],[1,5]]
//输出：[4,1]
// 
//
// 
//
// 提示： 
//
// 
// n == edges.length 
// 3 <= n <= 1000 
// edges[i].length == 2 
// 1 <= ui, vi <= n 
// 
// Related Topics 深度优先搜索 广度优先搜索 并查集 图 
// 👍 258 👎 0

#include "bits/stdc++.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> disjoint_set;

    int find(int pos) {
        if (disjoint_set[pos] != -1) return find(disjoint_set[pos]);
        return pos;
    }

    bool join(int posA, int posB) {
        int tA = find(posA);
        int tB = find(posB);
        if (tA == tB) return true;
        disjoint_set[tA] = tB;
        return false;
    }

    void reset(int n) {
        for (int i = 0; i <= n; i++) {
            disjoint_set[i] = -1;
        }
    }

    bool isTree(vector<vector<int>> &edges, int toDeleted) {
        reset(edges.size());
        for (int i = 0; i < edges.size(); i++) {
            if (i == toDeleted) continue;
            join(edges[i][0], edges[i][1]);
        }
        int cnt = 0;
        for (int i = 1; i <= edges.size(); i++) if (disjoint_set[i] == -1) cnt++;
        return cnt == 1;
    }

    vector<int> findRedundantDirectedConnection(vector<vector<int>> &edges) {
        // 记录每个节点的入度
        int n = edges.size();
        for (int i = 0; i <= n; i++) {
            disjoint_set.push_back(-1);
        }

        vector<int> inDegrees(n+1);
        for (vector<int>& edge: edges) {
            inDegrees[edge[1]]++;
        }
        // 入度为2的节点，边记录下来
        vector<int> mayBeDeleted;
        for (int i = n-1; i >= 0; i--) {
            vector<int>& edge = edges[i];
            if (inDegrees[edge[1]] == 2) {
                mayBeDeleted.push_back(i);
            }
        }
        // 如果有入度为2的节点，尝试看看删除哪一个
        if (!mayBeDeleted.empty()) {
            // 此时，构成树的条件，就直接是【能连起来即可】
            if (isTree(edges, mayBeDeleted[0])) return edges[mayBeDeleted[0]];
            return edges[mayBeDeleted[1]];
        }
        // 现在没有入度为2的节点，说明成环
        // 画个图看看，成环的情况，随便拆一个即可
        for (int i = n-1; i >= 0; i--) {
            if (isTree(edges, i)) return edges[i];
        }


        return edges[0];
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
}