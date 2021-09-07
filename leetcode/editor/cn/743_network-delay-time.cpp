//有 n 个网络节点，标记为 1 到 n。 
//
// 给你一个列表 times，表示信号经过 有向 边的传递时间。 times[i] = (ui, vi, wi)，其中 ui 是源节点，vi 是目标节点， w
//i 是一个信号从源节点传递到目标节点的时间。 
//
// 现在，从某个节点 K 发出一个信号。需要多久才能使所有节点都收到信号？如果不能使所有节点收到信号，返回 -1 。 
//
// 
//
// 示例 1： 
//
// 
//
// 
//输入：times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
//输出：2
// 
//
// 示例 2： 
//
// 
//输入：times = [[1,2,1]], n = 2, k = 1
//输出：1
// 
//
// 示例 3： 
//
// 
//输入：times = [[1,2,1]], n = 2, k = 2
//输出：-1
// 
//
// 
//
// 提示： 
//
// 
// 1 <= k <= n <= 100 
// 1 <= times.length <= 6000 
// times[i].length == 3 
// 1 <= ui, vi <= n 
// ui != vi 
// 0 <= wi <= 100 
// 所有 (ui, vi) 对都 互不相同（即，不含重复边） 
// 
// Related Topics 深度优先搜索 广度优先搜索 图 最短路 堆（优先队列） 
// 👍 420 👎 0

#include "bits/stdc++.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    void print(vector<vector<int>>& times, int n) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (times[i][j] == INT32_MAX) printf("%4d", -1);
                else printf("%4d", times[i][j]);
            }
            cout << endl;
        }
    }

    // Dijkstra
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // 单源最短路径 用dijkstra
        // book dist matrix[边]
        vector<int> book(n+1, 0);   // 最初都没有走过
        vector<vector<int>> matrix(n+1, vector<int>(n+1, INT32_MAX));
        for (int i = 1; i <= n; i++) matrix[i][i] = 0;
        for (vector<int>& time : times) matrix[time[0]][time[1]] = time[2];
        // dist
        vector<int> dist = matrix[k];       // dist 单源到其他位置的最小路径
        book[k] = 1;

        for (int i = 1; i <= n-1; i++) {
            // 寻找并更新n-1次，更新出 到其他所有点的最小值
            int minVal = INT32_MAX, u = 0;
            for (int j = 1; j <= n; j++) {
                if (book[j]) continue;
                if (dist[j] < minVal) {
                    minVal = dist[j];
                    u = j;
                }
            }
            if (minVal == INT32_MAX) break;
            book[u] = 1;        // 标记为 已经找到最小值
            // 循环一遍，看看能不能帮助其他点找到最小值
            for (int j = 1; j <= n; j++) {
                if (book[j] || matrix[u][j] == INT32_MAX) continue;
                dist[j] = min(dist[j], dist[u] + matrix[u][j]);
            }
        }

        int res = 0;
        for (int i = 1; i <= n; i++) {
            res = max(res, dist[i]);
        }

        return res == INT32_MAX ? -1 : res;
    }


        // u -> v, weight
    int networkDelayTimeFloyd(vector<vector<int>>& times, int n, int k) {
        // floyd 只能经过某些中间点
        vector<vector<int>> matrix(n+1, vector<int>(n+1, INT32_MAX));
        for (int i = 1; i <= n; i++) {
            matrix[i][i] = 0;
        }
        // 加边
        for (vector<int>& time : times) {
            int u = time[0]; int v = time[1]; int w = time[2];
            matrix[u][v] = w;
        }
        // floyd
        for (int kk = 1; kk <= n; kk++) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    if (i == j || matrix[i][kk] == INT32_MAX || matrix[kk][j] == INT32_MAX) continue;
                    matrix[i][j] = min(matrix[i][j], matrix[i][kk] + matrix[kk][j]);
                }
            }
        }
//        print(matrix, n);

        // 信号max
        int res = 0;
        for (int i = 1; i <= n; i++) {
            if (i == k) continue;
            res = max(res, matrix[k][i]);
            if (res == INT32_MAX) return -1;
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
}