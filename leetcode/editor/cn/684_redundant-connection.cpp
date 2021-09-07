//树可以看成是一个连通且 无环 的 无向 图。 
//
// 给定往一棵 n 个节点 (节点值 1～n) 的树中添加一条边后的图。添加的边的两个顶点包含在 1 到 n 中间，且这条附加的边不属于树中已存在的边。图的信
//息记录于长度为 n 的二维数组 edges ，edges[i] = [ai, bi] 表示图中在 ai 和 bi 之间存在一条边。 
//
// 请找出一条可以删去的边，删除后可使得剩余部分是一个有着 n 个节点的树。如果有多个答案，则返回数组 edges 中最后出现的边。 
//
// 
//
// 示例 1： 
//
// 
//
// 
//输入: edges = [[1,2], [1,3], [2,3]]
//输出: [2,3]
// 
//
// 示例 2： 
//
// 
//
// 
//输入: edges = [[1,2], [2,3], [3,4], [1,4], [1,5]]
//输出: [1,4]
// 
//
// 
//
// 提示: 
//
// 
// n == edges.length 
// 3 <= n <= 1000 
// edges[i].length == 2 
// 1 <= ai < bi <= edges.length 
// ai != bi 
// edges 中无重复元素 
// 给定的图是连通的 
// 
// Related Topics 深度优先搜索 广度优先搜索 并查集 图 
// 👍 381 👎 0

#include "bits/stdc++.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // 用并查集做
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

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int m = 0;
        for (vector<int> &edge: edges) {
            m = max(m, edge[0]);
            m = max(m, edge[1]);
        }

        for (int i = 0; i <= m; i++) {
            disjoint_set.push_back(-1);
        }

        for (vector<int> &edge: edges) {
            if (join(edge[0], edge[1])) return edge;
        }

        return edges[0];
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
}