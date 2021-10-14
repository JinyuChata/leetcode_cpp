//在无限长的数轴（即 x 轴）上，我们根据给定的顺序放置对应的正方形方块。 
//
// 第 i 个掉落的方块（positions[i] = (left, side_length)）是正方形，其中 left 表示该方块最左边的点位置(
//positions[i][0])，side_length 表示该方块的边长(positions[i][1])。 
//
// 每个方块的底部边缘平行于数轴（即 x 轴），并且从一个比目前所有的落地方块更高的高度掉落而下。在上一个方块结束掉落，并保持静止后，才开始掉落新方块。 
//
// 方块的底边具有非常大的粘性，并将保持固定在它们所接触的任何长度表面上（无论是数轴还是其他方块）。邻接掉落的边不会过早地粘合在一起，因为只有底边才具有粘性。
// 
//
// 
//
// 返回一个堆叠高度列表 ans 。每一个堆叠高度 ans[i] 表示在通过 positions[0], positions[1], ..., 
//positions[i] 表示的方块掉落结束后，目前所有已经落稳的方块堆叠的最高高度。 
//
// 
//
// 
//
// 示例 1: 
//
// 输入: [[1, 2], [2, 3], [6, 1]]
//输出: [2, 5, 5]
//解释:
//
//第一个方块 positions[0] = [1, 2] 掉落：
//_aa
//_aa
//-------
//方块最大高度为 2 。
//
//第二个方块 positions[1] = [2, 3] 掉落：
//__aaa
//__aaa
//__aaa
//_aa__
//_aa__
//--------------
//方块最大高度为5。
//大的方块保持在较小的方块的顶部，不论它的重心在哪里，因为方块的底部边缘有非常大的粘性。
//
//第三个方块 positions[1] = [6, 1] 掉落：
//__aaa
//__aaa
//__aaa
//_aa
//_aa___a
//-------------- 
//方块最大高度为5。
//
//因此，我们返回结果[2, 5, 5]。
// 
//
// 
//
// 示例 2: 
//
// 输入: [[100, 100], [200, 100]]
//输出: [100, 100]
//解释: 相邻的方块不会过早地卡住，只有它们的底部边缘才能粘在表面上。
// 
//
// 
//
// 注意: 
//
// 
// 1 <= positions.length <= 1000. 
// 1 <= positions[i][0] <= 10^8. 
// 1 <= positions[i][1] <= 10^6. 
// 
//
// 
// Related Topics 线段树 数组 有序集合 👍 63 👎 0

#include "bits/stdc++.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
#define MAX 1000000

class Solution {
public:
    // 存最大值
    int tree[4*MAX]{0};

    int getMaxValue(int l, int r, int L, int R, int root) {
        if (l == r) {
            if (L <= l && r <= R) return tree[root];
            else return 0;
        }

        if (L > r || R < l) return 0;
        if (L <= l && r <= R) return tree[root];

        int mid = l + (r-l)/2;
        // [l,mid] [mid+1,r]
        int left = root*2; int right = root*2+1;
        int ll = getMaxValue(l, mid, L, R, left);
        int rr = getMaxValue(mid+1, r, L, R, right);
        return max(ll,rr);
    }

    void insert(int l, int r, int L, int R, int value, int root) {
        if (L > r || R < l) return;
        if (l == r) {
            tree[root] = value; return;
        }

        tree[root] = max(tree[root], value);
        int mid = l + (r-l)/2;
        int left = root*2; int right = root*2+1;
        insert(l, mid, L, R, value, left);
        insert(mid+1, r, L, R, value, right);
    }

    vector<int> fallingSquares(vector<vector<int>>& positions) {
        vector<int> result;
        // 建立树
        memset(tree, 0, sizeof(tree));
        int maxHeight = 0;

        // 范围：1...MAX
        for (vector<int>& position : positions) {
            int x = position[0];
            int edge = position[1];
            // [x,x+edge)
            // 先取到 [x,x+edge-1]的最高高度
            int height = getMaxValue(1, MAX, x, x+edge-1, 1);
            height += edge;
            maxHeight = max(maxHeight, height);
            result.push_back(maxHeight);
            insert(1, MAX, x, x+edge-1, height, 1);
            for (int i = 0; i < 28; i++) {
                cout << tree[i] << " ";
            }
            cout << endl;
        }

        return result;

    }

};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    vector<vector<int>> in = {
            {1,2}, {2,3}, {6,1}
    };
    s.fallingSquares(in);
}