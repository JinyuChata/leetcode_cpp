//给定一个无向、连通的树。树中有 N 个标记为 0...N-1 的节点以及 N-1 条边 。 
//
// 第 i 条边连接节点 edges[i][0] 和 edges[i][1] 。 
//
// 返回一个表示节点 i 与其他所有节点距离之和的列表 ans。 
//
// 示例 1: 
//
// 
//输入: N = 6, edges = [[0,1],[0,2],[2,3],[2,4],[2,5]]
//输出: [8,12,6,10,10,10]
//解释: 
//如下为给定的树的示意图：
//  0
// / \
//1   2
//   /|\
//  3 4 5
//
//我们可以计算出 dist(0,1) + dist(0,2) + dist(0,3) + dist(0,4) + dist(0,5) 
//也就是 1 + 1 + 2 + 2 + 2 = 8。 因此，answer[0] = 8，以此类推。
// 
//
// 说明: 1 <= N <= 10000 
// Related Topics 树 深度优先搜索 图 动态规划 
// 👍 298 👎 0

#include "bits/stdc++.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    /**
     * BFS-超时
     */
    vector<int> sumOfDistancesInTreeBFS(int n, vector<vector<int>> &edges) {
        // 换根
        vector<vector<int>> matrix(n, vector<int>());
        // 加边
        for (vector<int> &edge: edges) {
            matrix[edge[0]].push_back(edge[1]);
            matrix[edge[1]].push_back(edge[0]);
        }
        vector<int> result(n, 0);
        for (int i = 0; i < n; i++) {
            unordered_set<int> visited;
            queue<int> q;
            q.push(i);

            int size;
            int base = 0;
            while (!q.empty()) {
                size = q.size();
                for (int j = 0; j < size; j++) {
                    int curr = q.front();
                    q.pop();
                    visited.insert(curr);
                    for (int &node : matrix[curr]) {
                        if (!visited.count(node)) {
                            q.push(node);
                        }
                    }
                }
                result[i] += base * size;
                base++;
            }
        }

        return result;
    }

    vector<int> innerTreeSum;
    vector<int> innerTreeNum;

    void dfs(vector<vector<int>> &adjs, int current, unordered_set<int> &visited, int &sum, int &num) {
        if (innerTreeSum[current] != -1) {
            sum = innerTreeSum[current];
            num = innerTreeNum[current];
            return;
        }

        visited.insert(current);
        sum = 0, num = 1;
        for (int &ass : adjs[current]) {
            if (visited.count(ass)) continue;
            int a, b;
            dfs(adjs, ass, visited, a, b);
            sum += b + a;
            num += b;
        }
        innerTreeSum[current] = sum;
        innerTreeNum[current] = num;
        visited.erase(current);
    }

    void dfs2(vector<vector<int>> &adjs, int current, unordered_set<int> &visited, int parent, int n) {
        if (parent != -1) {
            // 更新当前的值
            innerTreeSum[current] = innerTreeSum[parent] + n - 2 * innerTreeNum[current];
        }
        visited.insert(current);
        for (int &adj : adjs[current]) {
            if (visited.count(adj)) continue;
            dfs2(adjs, adj, visited, current, n);
        }
        visited.erase(current);
    }


    vector<int> sumOfDistancesInTree(int n, vector<vector<int>> &edges) {
        innerTreeSum = vector<int>(n, -1);
        innerTreeNum = vector<int>(n, -1);
        vector<vector<int>> matrix(n, vector<int>());
        // 加边
        for (vector<int> &edge: edges) {
            matrix[edge[0]].push_back(edge[1]);
            matrix[edge[1]].push_back(edge[0]);
        }
        unordered_set<int> visited;
        int a, b;
        dfs(matrix, 0, visited, a, b);
        visited.clear();
        dfs2(matrix, 0, visited, -1, n);
        return innerTreeSum;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
}