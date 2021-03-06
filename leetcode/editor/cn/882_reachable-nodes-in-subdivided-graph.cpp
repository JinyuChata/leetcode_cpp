//给你一个无向图（原始图），图中有 n 个节点，编号从 0 到 n - 1 。你决定将图中的每条边细分为一条节点链，每条边之间的新节点数各不相同。 
//
// 图用由边组成的二维数组 edges 表示，其中 edges[i] = [ui, vi, cnti] 表示原始图中节点 ui 和 vi 之间存在一条边，cn
//ti 是将边细分后的新节点总数。注意，cnti == 0 表示边不可细分。 
//
// 要细分边 [ui, vi] ，需要将其替换为 (cnti + 1) 条新边，和 cnti 个新节点。新节点为 x1, x2, ..., xcnti ，新边
//为 [ui, x1], [x1, x2], [x2, x3], ..., [xcnti+1, xcnti], [xcnti, vi] 。 
//
// 现在得到一个新的 细分图 ，请你计算从节点 0 出发，可以到达多少个节点？节点 是否可以到达的判断条件 为：如果节点间距离是 maxMoves 或更少，则
//视为可以到达；否则，不可到达。 
//
// 给你原始图和 maxMoves ，返回新的细分图中从节点 0 出发 可到达的节点数 。 
//
// 
//
// 示例 1： 
//
// 
//输入：edges = [[0,1,10],[0,2,1],[1,2,2]], maxMoves = 6, n = 3
//输出：13
//解释：边的细分情况如上图所示。
//可以到达的节点已经用黄色标注出来。
// 
//
// 示例 2： 
//
// 
//输入：edges = [[0,1,4],[1,2,6],[0,2,8],[1,3,1]], maxMoves = 10, n = 4
//输出：23
// 
//
// 示例 3： 
//
// 
//输入：edges = [[1,2,4],[1,4,5],[1,3,1],[2,3,4],[3,4,5]], maxMoves = 17, n = 5
//输出：1
//解释：节点 0 与图的其余部分没有连通，所以只有节点 0 可以到达。
// 
//
// 
//
// 提示： 
//
// 
// 0 <= edges.length <= min(n * (n - 1) / 2, 104) 
// edges[i].length == 3 
// 0 <= ui < vi < n 
// 图中 不存在平行边 
// 0 <= cnti <= 104 
// 0 <= maxMoves <= 109 
// 1 <= n <= 3000 
// 
// Related Topics 图 最短路 堆（优先队列） 
// 👍 40 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {

    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
}