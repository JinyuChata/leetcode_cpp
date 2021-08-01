//给定一个整数数组 asteroids，表示在同一行的行星。 
//
// 对于数组中的每一个元素，其绝对值表示行星的大小，正负表示行星的移动方向（正表示向右移动，负表示向左移动）。每一颗行星以相同的速度移动。 
//
// 找出碰撞后剩下的所有行星。碰撞规则：两个行星相互碰撞，较小的行星会爆炸。如果两颗行星大小相同，则两颗行星都会爆炸。两颗移动方向相同的行星，永远不会发生碰撞
//。 
//
// 
//
// 示例 1： 
//
// 
//输入：asteroids = [5,10,-5]
//输出：[5,10]
//解释：10 和 -5 碰撞后只剩下 10 。 5 和 10 永远不会发生碰撞。 
//
// 示例 2： 
//
// 
//输入：asteroids = [8,-8]
//输出：[]
//解释：8 和 -8 碰撞后，两者都发生爆炸。 
//
// 示例 3： 
//
// 
//输入：asteroids = [10,2,-5]
//输出：[10]
//解释：2 和 -5 发生碰撞后剩下 -5 。10 和 -5 发生碰撞后剩下 10 。 
//
// 示例 4： 
//
// 
//输入：asteroids = [-2,-1,1,2]
//输出：[-2,-1,1,2]
//解释：-2 和 -1 向左移动，而 1 和 2 向右移动。 由于移动方向相同的行星不会发生碰撞，所以最终没有行星发生碰撞。 
//
// 
//
// 提示： 
//
// 
// 2 <= asteroids.length <= 104 
// -1000 <= asteroids[i] <= 1000 
// asteroids[i] != 0 
// 
// Related Topics 栈 
// 👍 151 👎 0

#include "bits/stdc++.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> asteroidCollision(vector<int> &asteroids) {
        vector<int> toRightStk;
        vector<int> blackHole;
        for (int &asteroid: asteroids) {
            if (asteroid > 0) toRightStk.push_back(asteroid);
            else {
                // 向左移动，就看他啥时候消失
                while (asteroid < 0) {
                    if (toRightStk.empty()) {
                        blackHole.push_back(asteroid);
                        asteroid = 0;
                    }
                    else if (-asteroid > toRightStk[toRightStk.size()-1]) toRightStk.pop_back();
                    else if (-asteroid == toRightStk[toRightStk.size()-1]) {
                        toRightStk.pop_back();
                        asteroid = 0;
                    } else {
                        // -asteriod < toRightStk.top()
                        asteroid = 0;
                    }
                }
            }
        }
        for (int& i : toRightStk) {
            blackHole.push_back(i);
        }
        return blackHole;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
}