//给你一个整数数组 nums 和一个整数 k ，请你返回其中出现频率前 k 高的元素。你可以按 任意顺序 返回答案。 
//
// 
//
// 示例 1: 
//
// 
//输入: nums = [1,1,1,2,2,3], k = 2
//输出: [1,2]
// 
//
// 示例 2: 
//
// 
//输入: nums = [1], k = 1
//输出: [1] 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 105 
// k 的取值范围是 [1, 数组中不相同的元素的个数] 
// 题目数据保证答案唯一，换句话说，数组中前 k 个高频元素的集合是唯一的 
// 
//
// 
//
// 进阶：你所设计算法的时间复杂度 必须 优于 O(n log n) ，其中 n 是数组大小。 
// Related Topics 数组 哈希表 分治 桶排序 计数 快速选择 排序 堆（优先队列） 
// 👍 853 👎 0

#include "bits/stdc++.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    static bool cmp(pair<int,int>& m, pair<int,int>& n) {
        return m.second > n.second;
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        // hashMap+堆
        unordered_map<int, int> hash;
        for (int& num : nums) {
            hash[num]++;
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(&cmp)> heap(cmp);
        for (auto& [num, count]: hash) {
            if (heap.size() == k) {
                // 小顶堆，弹出最小的
                if (heap.top().second < count) {
                    heap.pop();
                    heap.push({num, count});
                }
            } else {
                heap.push({num, count});
            }
        }

        vector<int> ret;
        while (!heap.empty()) {
            auto [num, count] = heap.top();
            heap.pop();
            ret.push_back(num);
        }

        return ret;

    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    vector<int> nums = {1,1,1,2,2,3};
    s.topKFrequent(nums, 2);
}