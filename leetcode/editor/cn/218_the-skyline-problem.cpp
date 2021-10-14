//城市的天际线是从远处观看该城市中所有建筑物形成的轮廓的外部轮廓。给你所有建筑物的位置和高度，请返回由这些建筑物形成的 天际线 。 
//
// 每个建筑物的几何信息由数组 buildings 表示，其中三元组 buildings[i] = [lefti, righti, heighti] 表示： 
//
//
// 
// lefti 是第 i 座建筑物左边缘的 x 坐标。 
// righti 是第 i 座建筑物右边缘的 x 坐标。 
// heighti 是第 i 座建筑物的高度。 
// 
//
// 天际线 应该表示为由 “关键点” 组成的列表，格式 [[x1,y1],[x2,y2],...] ，并按 x 坐标 进行 排序 。关键点是水平线段的左端点。
//列表中最后一个点是最右侧建筑物的终点，y 坐标始终为 0 ，仅用于标记天际线的终点。此外，任何两个相邻建筑物之间的地面都应被视为天际线轮廓的一部分。 
//
// 注意：输出天际线中不得有连续的相同高度的水平线。例如 [...[2 3], [4 5], [7 5], [11 5], [12 7]...] 是不正确的答
//案；三条高度为 5 的线应该在最终输出中合并为一个：[...[2 3], [4 5], [12 7], ...] 
//
// 
//
// 示例 1： 
//
// 
//输入：buildings = [[2,9,10],[3,7,15],[5,12,12],[15,20,10],[19,24,8]]
//输出：[[2,10],[3,15],[7,12],[12,0],[15,10],[20,8],[24,0]]
//解释：
//图 A 显示输入的所有建筑物的位置和高度，
//图 B 显示由这些建筑物形成的天际线。图 B 中的红点表示输出列表中的关键点。 
//
// 示例 2： 
//
// 
//输入：buildings = [[0,2,3],[2,5,3]]
//输出：[[0,3],[5,0]]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= buildings.length <= 10⁴ 
// 0 <= lefti < righti <= 2³¹ - 1 
// 1 <= heighti <= 2³¹ - 1 
// buildings 按 lefti 非递减排序 
// 
// Related Topics 树状数组 线段树 数组 分治 有序集合 扫描线 堆（优先队列） 👍 538 👎 0

#include "bits/stdc++.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // 最大堆
    static bool cmp(int l1, int l2) {
        return l1 < l2;
    }

    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> result;
        // 维护实时最大高度，用heap来做
        vector<int> currHeap;

        // position, height  其中左侧端点为负值
        vector<vector<int>> records;
        // {pos, height}
        for (vector<int>& building : buildings) {
            vector<int> left = {building[0], -building[2]};
            vector<int> right = {building[1], building[2]};
            records.push_back(left); records.push_back(right);
        }
        // 排序
        sort(records.begin(), records.end(), [](vector<int>& r1, vector<int>& r2){
            if (r1[0] != r2[0]) return r1[0] < r2[0];
            return r1[1] < r2[1];
        });


        int lastMaxHeight = 0;
        int lastPos = -1;
        int idx = 0;

        unordered_map<int, int> toDeleted;

        while (idx < records.size()) {
            while (idx < records.size() && (lastPos == -1 || lastPos == records[idx][0])) {
                int pos = records[idx][0];
                int height = records[idx][1];
                lastPos = pos;
                if (height < 0) {
                    // 左
                    currHeap.push_back(-height);
                    push_heap(currHeap.begin(), currHeap.end(), cmp);
                } else {
                    // 右, 先删除后makeHeap
                    // 使用"延迟删除"技巧，规避堆删除耗费的时间
                    if (!toDeleted.count(height)) {
                        toDeleted[height] = 0;
                    }
                    toDeleted[height]++;

//                    for (auto it = currHeap.begin(); it != currHeap.end(); it++) {
//                        if (*it == height) {
//                            currHeap.erase(it);
//                            break;
//                        }
//                    }
                    make_heap(currHeap.begin(), currHeap.end(), cmp);
                }
                idx++;
            }

            // 延迟删除
            while (!currHeap.empty()
                   && toDeleted.count(currHeap[0]) && toDeleted[currHeap[0]] > 0) {
                toDeleted[currHeap[0]] --;
                pop_heap(currHeap.begin(), currHeap.end(), cmp); currHeap.pop_back();
            }

            // lastPos处理完了
            if (currHeap.empty() && lastMaxHeight != 0) {
                vector<int> cu = {lastPos, 0};
                lastMaxHeight = 0;
                result.push_back(cu);
            } else if (currHeap[0] != lastMaxHeight) {
                lastMaxHeight = currHeap[0];
                vector<int> cu = {lastPos, currHeap[0]};
                result.push_back(cu);
            }
            lastPos = -1;
        }

        return result;

    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
}