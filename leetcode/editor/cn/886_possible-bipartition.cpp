//给定一组 N 人（编号为 1, 2, ..., N）， 我们想把每个人分进任意大小的两组。 
//
// 每个人都可能不喜欢其他人，那么他们不应该属于同一组。 
//
// 形式上，如果 dislikes[i] = [a, b]，表示不允许将编号为 a 和 b 的人归入同一组。 
//
// 当可以用这种方法将所有人分进两组时，返回 true；否则返回 false。 
//
// 
//
// 
// 
//
// 示例 1： 
//
// 
//输入：N = 4, dislikes = [[1,2],[1,3],[2,4]]
//输出：true
//解释：group1 [1,4], group2 [2,3]
// 
//
// 示例 2： 
//
// 
//输入：N = 3, dislikes = [[1,2],[1,3],[2,3]]
//输出：false
// 
//
// 示例 3： 
//
// 
//输入：N = 5, dislikes = [[1,2],[2,3],[3,4],[4,5],[1,5]]
//输出：false
// 
//
// 
//
// 提示： 
//
// 
// 1 <= N <= 2000 
// 0 <= dislikes.length <= 10000 
// dislikes[i].length == 2 
// 1 <= dislikes[i][j] <= N 
// dislikes[i][0] < dislikes[i][1] 
// 对于 dislikes[i] == dislikes[j] 不存在 i != j 
// 
// Related Topics 深度优先搜索 广度优先搜索 并查集 图 
// 👍 134 👎 0

#include "bits/stdc++.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // 并查集
    vector<int> root;
    int find(int a) {
        if (root[a] < 0) return a;
        return root[a] = find(root[a]);
    }

    void join(int a, int b) {
        int ra = find(a);
        int rb = find(b);
        if (ra == rb) return;
        root[rb] = ra;
    }

    bool isConnected(int a, int b) {
        return find(a) == find(b);
    }

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> edges(n+1, vector<int>());
        for (vector<int>& dislike : dislikes) {
            edges[dislike[0]].push_back(dislike[1]);
            edges[dislike[1]].push_back(dislike[0]);
        }
        for (int i = 0; i < n + 1; ++i) {
            root.push_back(-1);
        }

        for (int i = 1; i <= n; i++) {
            vector<int>& adjs = edges[i];
            for (int& adj : adjs) {
                if (isConnected(i,adj)) return false;
                join(adj,adjs[0]);
            }
        }
        return true;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
}