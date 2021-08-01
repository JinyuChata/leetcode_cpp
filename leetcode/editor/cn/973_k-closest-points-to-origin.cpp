//我们有一个由平面上的点组成的列表 points。需要从中找出 K 个距离原点 (0, 0) 最近的点。 
//
// （这里，平面上两点之间的距离是欧几里德距离。） 
//
// 你可以按任何顺序返回答案。除了点坐标的顺序之外，答案确保是唯一的。 
//
// 
//
// 示例 1： 
//
// 输入：points = [[1,3],[-2,2]], K = 1
//输出：[[-2,2]]
//解释： 
//(1, 3) 和原点之间的距离为 sqrt(10)，
//(-2, 2) 和原点之间的距离为 sqrt(8)，
//由于 sqrt(8) < sqrt(10)，(-2, 2) 离原点更近。
//我们只需要距离原点最近的 K = 1 个点，所以答案就是 [[-2,2]]。
// 
//
// 示例 2： 
//
// 输入：points = [[3,3],[5,-1],[-2,4]], K = 2
//输出：[[3,3],[-2,4]]
//（答案 [[-2,4],[3,3]] 也会被接受。）
// 
//
// 
//
// 提示： 
//
// 
// 1 <= K <= points.length <= 10000 
// -10000 < points[i][0] < 10000 
// -10000 < points[i][1] < 10000 
// 
// Related Topics 几何 数组 数学 分治 快速选择 排序 堆（优先队列） 
// 👍 260 👎 0

#include "bits/stdc++.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
// 最近的点，最大堆，小于
int calc(const vector<int>& p) {
    return p[0] * p[0] + p[1] * p[1];
}

struct Compare{
    inline bool operator() (const vector<int>& a, const vector<int>& b) {
        return (a[0] * a[0] + a[1] * a[1]) < (b[0] * b[0] + b[1] * b[1]);
    }
};

class Solution {
public:

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> heap;
        for (vector<int>& p : points) {
            if (heap.size() < k) {
                heap.push_back(p);
                push_heap(p.begin(), p.end(), Compare());
                continue;
            }
            int dist = calc(p);
            if (dist < calc(heap[0])) {
                pop_heap(heap.begin(), heap.end(), Compare());
                heap[heap.size()-1] = p;
                push_heap(heap.begin(), heap.end(), Compare());
            }
        }

        return heap;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    vector<vector<int>> in = {{1, 3}, {-2, 2}};
    s.kClosest(in, 1);

}