//一只青蛙想要过河。 假定河流被等分为若干个单元格，并且在每一个单元格内都有可能放有一块石子（也有可能没有）。 青蛙可以跳上石子，但是不可以跳入水中。 
//
// 给你石子的位置列表 stones（用单元格序号 升序 表示）， 请判定青蛙能否成功过河（即能否在最后一步跳至最后一块石子上）。 
//
// 开始时， 青蛙默认已站在第一块石子上，并可以假定它第一步只能跳跃一个单位（即只能从单元格 1 跳至单元格 2 ）。 
//
// 如果青蛙上一步跳跃了 k 个单位，那么它接下来的跳跃距离只能选择为 k - 1、k 或 k + 1 个单位。 另请注意，青蛙只能向前方（终点的方向）跳跃。
// 
//
// 
//
// 示例 1： 
//
// 
//输入：stones = [0,1,3,5,6,8,12,17]
//输出：true
//解释：青蛙可以成功过河，按照如下方案跳跃：跳 1 个单位到第 2 块石子, 然后跳 2 个单位到第 3 块石子, 接着 跳 2 个单位到第 4 块石子, 然
//后跳 3 个单位到第 6 块石子, 跳 4 个单位到第 7 块石子, 最后，跳 5 个单位到第 8 个石子（即最后一块石子）。 
//
// 示例 2： 
//
// 
//输入：stones = [0,1,2,3,4,8,9,11]
//输出：false
//解释：这是因为第 5 和第 6 个石子之间的间距太大，没有可选的方案供青蛙跳跃过去。 
//
// 
//
// 提示： 
//
// 
// 2 <= stones.length <= 2000 
// 0 <= stones[i] <= 231 - 1 
// stones[0] == 0 
// 
// Related Topics 动态规划 
// 👍 340 👎 0
#include <bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool canCross(vector<int> &stones) {
        if (stones[1] != 1) return false;
        // 做一次映射
        int n = stones.size();
        map<int, int> realPos;  // 单位计数 -> 第几个石子
        for (int i = 0; i < n; i++) {
            realPos[stones[i]] = i;
        }

        vector<set<int>> dp(n, set<int>());  // 存放上一步可能k值
        dp[1].insert(1);
        for (int i = 1; i < n; i++) {
            int pos = stones[i];
            for (int k : dp[i]) {
                if (k - 1 > 0 && realPos.find(pos + k - 1) != realPos.end()) {
                    dp[realPos[pos + k - 1]].insert(k - 1);
                }
                if (realPos.find(pos + k) != realPos.end()) {
                    dp[realPos[pos + k]].insert(k);
                }
                if (realPos.find(pos + k + 1) != realPos.end()) {
                    dp[realPos[pos + k + 1]].insert(k + 1);
                }
            }
        }

        return !dp[n - 1].empty();

    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    vector<int> v = {0, 1, 3, 5, 6, 8, 12, 17};
    s.canCross(v);
}