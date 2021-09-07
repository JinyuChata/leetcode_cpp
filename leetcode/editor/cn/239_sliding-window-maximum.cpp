//给你一个整数数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位
//。 
//
// 返回滑动窗口中的最大值。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [1,3,-1,-3,5,3,6,7], k = 3
//输出：[3,3,5,5,6,7]
//解释：
//滑动窗口的位置                最大值
//---------------               -----
//[1  3  -1] -3  5  3  6  7       3
// 1 [3  -1  -3] 5  3  6  7       3
// 1  3 [-1  -3  5] 3  6  7       5
// 1  3  -1 [-3  5  3] 6  7       5
// 1  3  -1  -3 [5  3  6] 7       6
// 1  3  -1  -3  5 [3  6  7]      7
// 
//
// 示例 2： 
//
// 
//输入：nums = [1], k = 1
//输出：[1]
// 
//
// 示例 3： 
//
// 
//输入：nums = [1,-1], k = 1
//输出：[1,-1]
// 
//
// 示例 4： 
//
// 
//输入：nums = [9,11], k = 2
//输出：[11]
// 
//
// 示例 5： 
//
// 
//输入：nums = [4,-2], k = 2
//输出：[4] 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 105 
// -104 <= nums[i] <= 104 
// 1 <= k <= nums.length 
// 
// Related Topics 队列 数组 滑动窗口 单调队列 堆（优先队列） 
// 👍 1158 👎 0


#include "bits/stdc++.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // 单调双端队列
        // front 最大的
        // 放到back，放的过程中，如果现有back1比放进去的backNew小，则出栈back1
        // [因为backNew会取代back1的地位]，backNew进去后，现有back1在接下来的过程中，不可能再作为滑动窗口中最大值了
        deque<int> q;
        vector<int> ret;
        // 解决第一组
        for (int i = 0; i < k; i++) {
            while (!q.empty() && nums[i] > nums[q.back()]) {
                q.pop_back();
            }
            q.push_back(i);
        }
//        for (int& i : q) cout << i << " ";
//        cout << endl;

        ret.push_back(nums[q.front()]);
        for (int i = 1; i + k <= nums.size(); i++) {
            // [i ... i+k-1]
            // front 出栈i-1[可能]；back入栈i+k-1
            if (q.front() == i-1) q.pop_front();
            while (!q.empty() && nums[i+k-1] > nums[q.back()]) {
                q.pop_back();
            }
            q.push_back(i+k-1);

            ret.push_back(nums[q.front()]);
        }

        return ret;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    vector<int> in = {1,3,-1,-3,5,3,6,7};
    s.maxSlidingWindow(in,3);
}