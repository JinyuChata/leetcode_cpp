//老师想给孩子们分发糖果，有 N 个孩子站成了一条直线，老师会根据每个孩子的表现，预先给他们评分。 
//
// 你需要按照以下要求，帮助老师给这些孩子分发糖果： 
//
// 
// 每个孩子至少分配到 1 个糖果。 
// 评分更高的孩子必须比他两侧的邻位孩子获得更多的糖果。 
// 
//
// 那么这样下来，老师至少需要准备多少颗糖果呢？ 
//
// 
//
// 示例 1： 
//
// 
//输入：[1,0,2]
//输出：5
//解释：你可以分别给这三个孩子分发 2、1、2 颗糖果。
// 
//
// 示例 2： 
//
// 
//输入：[1,2,2]
//输出：4
//解释：你可以分别给这三个孩子分发 1、2、1 颗糖果。
//     第三个孩子只得到 1 颗糖果，这已满足上述两个条件。 
// Related Topics 贪心 数组 
// 👍 605 👎 0

#include "bits/stdc++.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int candy(vector<int>& ratings) {
        // 左规则、右规则
        // 左规则：从左到右，如果 r[i] > r[i-1] 则给i加1
        vector<int> left;
        vector<int> right;
        int n = ratings.size();

        for (int i = 0; i < n; i++) {
            left.push_back(1); right.push_back(1);
        }

        // 左规则
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i-1]) {
                left[i] = 1 + left[i-1];
            }
        }

        // 右规则
        for (int i = n-2; i >= 0; i--) {
            if (ratings[i] > ratings[i+1]) {
                right[i] = 1 + right[i+1];
            }
        }

        int res = 0;
        for (int i = 0; i < n; i++) {
            res += max(left[i], right[i]);
        }

        return res;


    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
}