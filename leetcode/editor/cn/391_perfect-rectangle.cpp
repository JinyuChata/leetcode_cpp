//我们有 N 个与坐标轴对齐的矩形, 其中 N > 0, 判断它们是否能精确地覆盖一个矩形区域。 
//
// 每个矩形用左下角的点和右上角的点的坐标来表示。例如， 一个单位正方形可以表示为 [1,1,2,2]。 ( 左下角的点的坐标为 (1, 1) 以及右上角的点
//的坐标为 (2, 2) )。 
//
// 
//
// 示例 1: 
//
// rectangles = [
//  [1,1,3,3],
//  [3,1,4,2],
//  [3,2,4,4],
//  [1,3,2,4],
//  [2,3,3,4]
//]
//
//返回 true。5个矩形一起可以精确地覆盖一个矩形区域。
// 
//
// 
//
// 
//
// 示例 2: 
//
// rectangles = [
//  [1,1,2,3],
//  [1,3,2,4],
//  [3,1,4,2],
//  [3,2,4,4]
//]
//
//返回 false。两个矩形之间有间隔，无法覆盖成一个矩形。
// 
//
// 
//
// 
//
// 示例 3: 
//
// rectangles = [
//  [1,1,3,3],
//  [3,1,4,2],
//  [1,3,2,4],
//  [3,2,4,4]
//]
//
//返回 false。图形顶端留有间隔，无法覆盖成一个矩形。
// 
//
// 
//
// 
//
// 示例 4: 
//
// rectangles = [
//  [1,1,3,3],
//  [3,1,4,2],
//  [1,3,2,4],
//  [2,2,4,4]
//]
//
//返回 false。因为中间有相交区域，虽然形成了矩形，但不是精确覆盖。
// 
// Related Topics 数组 扫描线 👍 89 👎 0

#include "bits/stdc++.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    struct line {
        int x; int y0; int y1;
    };

    static bool cmp(const line& l1, const line& l2) {
        if (l1.x != l2.x) return l1.x > l2.x;
        if (l1.y0 != l2.y0) return l1.y0 > l2.y0;
        return l1.y1 > l2.y1;
    }

    // x0,y0  x1,y1
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        sort(rectangles.begin(), rectangles.end(), [](vector<int>& r1, vector<int>& r2) {
            if (r1[0] != r2[0]) return r1[0] < r2[0];
            if (r1[1] != r2[1]) return r1[1] < r2[1];
            return r1[3] < r2[3];
        });

//        for (vector<int>& rect : rectangles) {
//            cout << rect[0] << " " << rect[1] << " " << rect[2] << " " << rect[3] << " " << endl;
//        }

        // heap
        priority_queue<line, vector<line>, decltype(&cmp)> heap(cmp);
        int leftX = rectangles[0][0]; int idx = 0;
        int startY = rectangles[0][1];
        while (idx < rectangles.size() &&  rectangles[idx][0] == leftX) {
            if (rectangles[idx][1] != startY) return false;
            line l{};
            l.x = rectangles[idx][2]; l.y0 = rectangles[idx][1]; l.y1 = rectangles[idx][3];
            startY = l.y1;
            heap.push(l);
            idx++;
        }

        while (!heap.empty() && idx < rectangles.size()) {
            int x = heap.top().x;
            int yStart = heap.top().y0;
            int yEnd = heap.top().y1;
            heap.pop();
            while (!heap.empty() && x == heap.top().x && heap.top().y0 <= yEnd) {
                yEnd = heap.top().y1;
                heap.pop();
            }

            // 尝试从rects中，取到idx，看看idx左侧能不能匹配到这条线【能匹配多少】
            while (idx < rectangles.size() && rectangles[idx][0] == x
                     && rectangles[idx][1] == yStart && rectangles[idx][3] <= yEnd) {
                yStart = rectangles[idx][3];
                // push 一个
                line l;
                l.x = rectangles[idx][2];
                l.y0 = rectangles[idx][1];
                l.y1 = rectangles[idx][3];
                heap.push(l);
//                cout << heap.size() << endl;
                idx++;
            }

            if (yStart != yEnd) return false;
        }

        int x = 0;
        if (!heap.empty()) {
            x = heap.top().x;
        }

        while (!heap.empty()) {
            if (x != heap.top().x) return false;
            heap.pop();
        }

        return true;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    vector<vector<int>> rects = {{0,0,4,1},{0,0,4,1}};
    cout << s.isRectangleCover(rects);
}