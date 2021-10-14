//我们给出了一个（轴对齐的）矩形列表 rectangles 。 对于 rectangle[i] = [x1, y1, x2, y2]，其中（x1，y1）是矩形
// i 左下角的坐标，（x2，y2）是该矩形右上角的坐标。 
//
// 找出平面中所有矩形叠加覆盖后的总面积。 由于答案可能太大，请返回它对 10 ^ 9 + 7 取模的结果。 
//
// 
//
// 示例 1： 
//
// 输入：[[0,0,2,2],[1,0,2,3],[1,0,3,1]]
//输出：6
//解释：如图所示。
// 
//
// 示例 2： 
//
// 输入：[[0,0,1000000000,1000000000]]
//输出：49
//解释：答案是 10^18 对 (10^9 + 7) 取模的结果， 即 (10^9)^2 → (-7)^2 = 49 。
// 
//
// 提示： 
//
// 
// 1 <= rectangles.length <= 200 
// rectanges[i].length = 4 
// 0 <= rectangles[i][j] <= 10^9 
// 矩形叠加覆盖后的总面积不会超越 2^63 - 1 ，这意味着可以用一个 64 位有符号整数来保存面积结果。 
// 
// Related Topics 线段树 数组 有序集合 扫描线 👍 79 👎 0

#include "bits/stdc++.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
#define MOD 1000000007
#define OPEN 1
#define CLOSE 0

class Solution {
public:
    int rectangleArea(vector<vector<int>> &rectangles) {
        // tuple {y, x1, x2, OPEN/CLOSE}
        vector<tuple<int, int, int, int>> rects;
        for (vector<int> &rectangle: rectangles) {
            int x1 = rectangle[0], y1 = rectangle[1], x2 = rectangle[2], y2 = rectangle[3];
            tuple<int, int, int, int> rectOpen = {y1, x1, x2, OPEN};
            tuple<int, int, int, int> rectClose = {y2, x1, x2, CLOSE};
            rects.push_back(rectOpen);
            rects.push_back(rectClose);
        }

        sort(rects.begin(), rects.end());
        auto lastY = get<0>(rects[0]);

        multiset<pair<int, int>> collectedLines;
        int result = 0;
        for (auto[y, x1, x2, state]: rects) {
            if (lastY != y) {
                // result+=面积
                int l = INT32_MIN;
                int ss = 0;
                for (auto[x0, x1]: collectedLines) {
                    if (x0 > l) {
                        ss += (x1-x0) % MOD;
                        l = x1;
                    } else if (x0 <= l && l <= x1) {
                        ss += (x1-l) % MOD;
                        l = x1;
                    }
                }

                result = ((long long)result + ((long long)(y-lastY) * (long long)ss))  % MOD;
            }

            lastY = y;
            pair<int, int> p = {x1, x2};
            if (state == OPEN) {
                collectedLines.insert(p);
            } else {
                collectedLines.erase(collectedLines.find(p));
            }
        }

        return result;

    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    vector<vector<int>> in = {{11,4,22,74},{11,33,22,85}};
    cout << s.rectangleArea(in);
}