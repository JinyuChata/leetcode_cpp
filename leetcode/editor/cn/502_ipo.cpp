//假设 力扣（LeetCode）即将开始其 IPO。为了以更高的价格将股票卖给风险投资公司，力扣 希望在 IPO 之前开展一些项目以增加其资本。 由于资源有限
//，它只能在 IPO 之前完成最多 k 个不同的项目。帮助 力扣 设计完成最多 k 个不同项目后得到最大总资本的方式。 
//
// 给定若干个项目。对于每个项目 i，它都有一个纯利润 Pi，并且需要最小的资本 Ci 来启动相应的项目。最初，你有 W 资本。当你完成一个项目时，你将获得纯
//利润，且利润将被添加到你的总资本中。 
//
// 总而言之，从给定项目中选择最多 k 个不同项目的列表，以最大化最终资本，并输出最终可获得的最多资本。 
//
// 
//
// 示例： 
//
// 
//输入：k=2, W=0, Profits=[1,2,3], Capital=[0,1,1].
//输出：4
//解释：
//由于你的初始资本为 0，你仅可以从 0 号项目开始。
//在完成后，你将获得 1 的利润，你的总资本将变为 1。
//此时你可以选择开始 1 号或 2 号项目。
//由于你最多可以选择两个项目，所以你需要完成 2 号项目以获得最大的资本。
//因此，输出最后最大化的资本，为 0 + 1 + 3 = 4。
// 
//
// 
//
// 提示： 
//
// 
// 假设所有输入数字都是非负整数。 
// 表示利润和资本的数组的长度不超过 50000。 
// 答案保证在 32 位有符号整数范围内。 
// 
// Related Topics 贪心 数组 排序 堆（优先队列） 
// 👍 86 👎 0

#include "bits/stdc++.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Node {
public:
    int capital;
    int profit;

    Node(int capital, int profit) : capital(capital), profit(profit) {}
};

bool CompLittle(Node &n1, Node &n2) {
    return n1.capital > n2.capital;
}

bool CompBig(Node &n1, Node &n2) {
    return n1.profit < n2.profit;
}

class Solution {
public:
    // capital 启动资金
    // k 最多k个项目；w 现有资本
    int findMaximizedCapital(int k, int w, vector<int> &profits, vector<int> &capital) {
        int n = profits.size();
        // 两个优先队列：
        // 1. pqCap 小根堆，首先初始建堆
        // 2. pqPro 大根堆，从小根堆里拿出来放进去
        vector<Node> pqCap;
        vector<Node> pqPro;
        for (int i = 0; i < n; i++) {
            pqCap.emplace_back(capital[i], profits[i]);
            push_heap(pqCap.begin(), pqCap.end(), CompLittle);
        }

        while (k > 0) {
            while (!pqCap.empty() && pqCap[0].capital <= w) {
                pop_heap(pqCap.begin(), pqCap.end(), CompLittle);

                pqPro.push_back(pqCap[pqCap.size()-1]);
                push_heap(pqPro.begin(), pqPro.end(), CompBig);

                pqCap.pop_back();
            }

            if (pqPro.empty()) break;
            w += pqPro[0].profit;
            pop_heap(pqPro.begin(), pqPro.end(), CompBig);
            pqPro.pop_back();
            k--;
        }

        return w;
    }

    int findMaximizedCapital2(int k, int w, vector<int> &profits, vector<int> &capital) {
        // 纯利润，每次都取到【能够取的、纯利润最大的】就行了
        int cnt = 0, n = capital.size();
        while (cnt < k && cnt < n) {
            int maxProfit = -1;
            int idx = -1;
            for (int i = 0; i < n; i++) {
                if (maxProfit < profits[i] && capital[i] <= w) {
                    maxProfit = profits[i];
                    idx = i;
                }
            }

            if (idx == -1) return w;
            capital[idx] = INT32_MAX;
            cnt++;
            w += maxProfit;
        }
        return w;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    vector<int> profits({1,2,3});
    vector<int> capitals({0,1,1});
    s.findMaximizedCapital(2, 0, profits, capitals);
}