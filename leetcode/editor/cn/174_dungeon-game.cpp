//
//
// 一些恶魔抓住了公主（P）并将她关在了地下城的右下角。地下城是由 M x N 个房间组成的二维网格。我们英勇的骑士（K）最初被安置在左上角的房间里，他必须穿
//过地下城并通过对抗恶魔来拯救公主。 
//
// 骑士的初始健康点数为一个正整数。如果他的健康点数在某一时刻降至 0 或以下，他会立即死亡。 
//
// 有些房间由恶魔守卫，因此骑士在进入这些房间时会失去健康点数（若房间里的值为负整数，则表示骑士将损失健康点数）；其他房间要么是空的（房间里的值为 0），要么
//包含增加骑士健康点数的魔法球（若房间里的值为正整数，则表示骑士将增加健康点数）。 
//
// 为了尽快到达公主，骑士决定每次只向右或向下移动一步。 
//
// 
//
// 编写一个函数来计算确保骑士能够拯救到公主所需的最低初始健康点数。 
//
// 例如，考虑到如下布局的地下城，如果骑士遵循最佳路径 右 -> 右 -> 下 -> 下，则骑士的初始健康点数至少为 7。 
//
// 
// 
// -2 (K) 
// -3 
// 3 
// 
// 
// -5 
// -10 
// 1 
// 
// 
// 10 
// 30 
// -5 (P) 
// 
// 
//
//
// 
//
// 说明: 
//
// 
// 
// 骑士的健康点数没有上限。 
// 
// 任何房间都可能对骑士的健康点数造成威胁，也可能增加骑士的健康点数，包括骑士进入的左上角房间以及公主被监禁的右下角房间。 
// Related Topics 二分查找 动态规划 
// 👍 466 👎 0

#include <bits/stdc++.h>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();
        // dp 从某个点开始，到右下角需要的能量
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = m-1; i >= 0; i--) {
            for (int j = n-1; j >= 0; j--) {
                int point = dungeon[i][j] <= 0 ? 1 - dungeon[i][j] : 1;
                if (i == m-1 && j == n-1) {
                    // 初始化右下角
                    dp[i][j] = point;
                    continue;
                }
                int minNeed = 9999999;
                if (i != m-1) {
                    // 可以向下
                    if (dungeon[i][j] >= dp[i+1][j]) minNeed = 1;
                    else minNeed = min(minNeed, dp[i+1][j] - dungeon[i][j]);
                }
                if (j != n-1) {
                    // 可以向右
                    if (dungeon[i][j] >= dp[i][j+1]) minNeed = 1;
                    else minNeed = min(minNeed, dp[i][j+1] - dungeon[i][j]);
                }
                dp[i][j] = minNeed;
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cout << dp[i][j] << "  ";
            }
            cout << endl;
        }

        return dp[0][0];
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    vector<vector<int>> dungeon(3, vector<int>(0));
    dungeon[0].push_back(-2);
    dungeon[0].push_back(-3);
    dungeon[0].push_back(3);
    dungeon[1].push_back(-5);
    dungeon[1].push_back(-10);
    dungeon[1].push_back(1);
    dungeon[2].push_back(10);
    dungeon[2].push_back(30);
    dungeon[2].push_back(-5);
    cout << s.calculateMinimumHP(dungeon);
}