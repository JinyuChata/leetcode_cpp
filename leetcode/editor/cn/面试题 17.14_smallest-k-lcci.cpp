//设计一个算法，找出数组中最小的k个数。以任意顺序返回这k个数均可。 
//
// 示例： 
//
// 输入： arr = [1,3,5,7,2,4,6,8], k = 4
//输出： [1,2,3,4]
// 
//
// 提示： 
//
// 
// 0 <= len(arr) <= 100000 
// 0 <= k <= min(100000, len(arr)) 
// 
// Related Topics 数组 分治 快速选择 排序 堆（优先队列） 
// 👍 66 👎 0

#include "bits/stdc++.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
struct Compare {
    inline bool operator()(const int &x, const int &y) {
        return x < y;
    }
};

class Solution {
public:
    vector<int> smallestK(vector<int> &arr, int k) {
        vector<int> heap;
        if (k == 0) {
            return heap;
        }
        for (int &i : arr) {
            if (heap.size() < k) {
                heap.push_back(i);
                push_heap(heap.begin(), heap.end(), Compare());
            } else if (i < heap[0]) {
                pop_heap(heap.begin(), heap.end(), Compare());
                heap.pop_back();

                heap.push_back(i);
                push_heap(heap.begin(), heap.end(), Compare());
            }
        }

        return heap;
    }
};


//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    vector<int> in = {1,3,5,7,2,4,6,8};
    s.smallestK(in, 4);

}