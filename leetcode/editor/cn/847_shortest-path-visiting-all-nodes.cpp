//存在一个由 n 个节点组成的无向连通图，图中的节点按从 0 到 n - 1 编号。 
//
// 给你一个数组 graph 表示这个图。其中，graph[i] 是一个列表，由所有与节点 i 直接相连的节点组成。 
//
// 返回能够访问所有节点的最短路径的长度。你可以在任一节点开始和停止，也可以多次重访节点，并且可以重用边。 
//
// 
//
// 
// 
//
// 示例 1： 
//
// 
//输入：graph = [[1,2,3],[0],[0],[0]]
//输出：4
//解释：一种可能的路径为 [1,0,2,0,3] 
//
// 示例 2： 
//
// 
//
// 
//输入：graph = [[1],[0,2,4],[1,3,4],[2],[1,2]]
//输出：4
//解释：一种可能的路径为 [0,1,4,2,3]
// 
//
// 
//
// 提示： 
//
// 
// n == graph.length 
// 1 <= n <= 12 
// 0 <= graph[i].length < n 
// graph[i] 不包含 i 
// 如果 graph[a] 包含 b ，那么 graph[b] 也包含 a 
// 输入的图总是连通图 
// 
// Related Topics 位运算 广度优先搜索 图 动态规划 状态压缩 
// 👍 235 👎 0

#include "bits/stdc++.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int shortestPathLength(vector<vector<int>> &graph) {
        int n = graph.size();
        // idx, mask, dist 代表现在正在检查的点
        queue<tuple<int, int, int>> q;
        // 每个节点的每种状态，都需要做visited的记录
        vector<vector<bool>> vis(n, vector<bool>(1 << n));
        for (int i = 0; i < n; i++) {
            q.push({i, 1<<i, 0});
            vis[i][1<<i] = true;
        }

        // 搜索
        while (!q.empty()) {
            auto [cur, mask, dist] = q.front();
            q.pop();
            if (mask == (1<<n)-1) return dist;
            for (int x : graph[cur]) {
                int nextmask = (1 << x) | mask;
                if (!vis[x][nextmask]) {
                    q.push({x, nextmask, dist+1});
                    vis[x][nextmask] = true;
                }
            }

        }
        return 0;

    }

    int shortestPathLengthI(vector<vector<int>> &graph) {
        int n = graph.size();

        // 1.初始化队列及标记数组，存入起点
        queue<tuple<int, int, int> > q; // 三个属性分别为 idx, mask, dist
        vector<vector<bool>> vis(n, vector<bool>(1 << n)); // 节点编号及当前状态
        for (int i = 0; i < n; i++) {
            q.push({i, 1 << i, 0}); // 存入起点，起始距离0，标记
            vis[i][1 << i] = true;
        }

        // 开始搜索
        while (!q.empty()) {
            auto[cur, mask, dist] = q.front(); // 弹出队头元素
            q.pop();

            // 找到答案，返回结果
            if (mask == (1 << n) - 1) return dist;

            // 扩展
            for (int x : graph[cur]) {
                int nextmask = mask | (1 << x);
                if (!vis[x][nextmask]) {
                    q.push({x, nextmask, dist + 1});
                    vis[x][nextmask] = true;
                }
            }
        }
        return 0;

    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
}