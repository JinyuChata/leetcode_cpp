//N 对情侣坐在连续排列的 2N 个座位上，想要牵到对方的手。 计算最少交换座位的次数，以便每对情侣可以并肩坐在一起。 一次交换可选择任意两人，让他们
// 站起来交换座位。
//
// 人和座位用 0 到 2N-1 的整数表示，情侣们按顺序编号，第一对是 (0, 1)，第二对是 (2, 3)，以此类推，最后一对是 (2N-2, 2N-1)
//。 
//
// 这些情侣的初始座位 row[i] 是由最初始坐在第 i 个座位上的人决定的。 
//
// 示例 1: 
//
// 
//输入: row = [0, 2, 1, 3]
//输出: 1
//解释: 我们只需要交换row[1]和row[2]的位置即可。
// 
//
// 示例 2: 
//
// 
//输入: row = [3, 2, 0, 1]
//输出: 0
//解释: 无需交换座位，所有的情侣都已经可以手牵手了。
// 
//
// 说明: 
//
// 
// len(row) 是偶数且数值在 [4, 60]范围内。 
// 可以保证row 是序列 0...len(row)-1 的一个全排列。 
// 
// Related Topics 贪心 深度优先搜索 广度优先搜索 并查集 图 
// 👍 280 👎 0

#include "bits/stdc++.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> disjoint_set;

    int find(int id) {
        if (disjoint_set[id] < 0) return id;
        return find(disjoint_set[id]);
    }

    void join(int i1, int i2) {
        int r1 = find(i1);
        int r2 = find(i2);
        if (r1 == r2) return;
        if (disjoint_set[r1] < disjoint_set[r2]) {
            // r2挂到r1
            disjoint_set[r1] += disjoint_set[r2];
            disjoint_set[r2] = r1;
        } else {
            disjoint_set[r2] += disjoint_set[r1];
            disjoint_set[r1] = r2;
        }
    }

    int minSwapsCouples(vector<int>& row) {
        // 想一想：情侣的错误环
        // 就看总共形成多少组[情侣错误环]，每组里有几个[错误情侣]
        int n = row.size();
        int n_couple = n/2;
        for (int i = 0; i < n_couple; i++)
            disjoint_set.push_back(-1);

        // 遍历，构造并查集
        for (int i = 0; i < n_couple; i++) {
            // 2i, 2i+1
            join(row[2*i]/2, row[2*i+1]/2);
        }

        int result = 0;
        for (int i = 0; i < n_couple; i++) {
            int target = -disjoint_set[i];
            if (target > 0) {
                result += (target-1);
            }
        }

        return result;

    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
}