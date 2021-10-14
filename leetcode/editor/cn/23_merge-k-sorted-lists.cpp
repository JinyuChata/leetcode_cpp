//给你一个链表数组，每个链表都已经按升序排列。 
//
// 请你将所有链表合并到一个升序链表中，返回合并后的链表。 
//
// 
//
// 示例 1： 
//
// 输入：lists = [[1,4,5],[1,3,4],[2,6]]
//输出：[1,1,2,3,4,4,5,6]
//解释：链表数组如下：
//[
//  1->4->5,
//  1->3->4,
//  2->6
//]
//将它们合并到一个有序链表中得到。
//1->1->2->3->4->4->5->6
// 
//
// 示例 2： 
//
// 输入：lists = []
//输出：[]
// 
//
// 示例 3： 
//
// 输入：lists = [[]]
//输出：[]
// 
//
// 
//
// 提示： 
//
// 
// k == lists.length 
// 0 <= k <= 10^4 
// 0 <= lists[i].length <= 500 
// -10^4 <= lists[i][j] <= 10^4 
// lists[i] 按 升序 排列 
// lists[i].length 的总和不超过 10^4 
// 
// Related Topics 链表 分治 堆（优先队列） 归并排序 
// 👍 1481 👎 0
#include "bits/stdc++.h"
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    static bool cmp(ListNode* l1, ListNode* l2) {
        return l2->val < l1->val;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, decltype(&cmp)> heap(cmp);
        // 先都放进去
        for (ListNode* ln : lists) { if (ln != nullptr) heap.push(ln); }
        ListNode* dumb = new ListNode; ListNode* curr = dumb;
        while (!heap.empty()) {
            ListNode* node = heap.top(); heap.pop();
            ListNode* next = node->next; node->next = nullptr;
            curr->next = node; curr = node;
            if (next != nullptr) heap.push(next);
        }

        return dumb->next;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
}