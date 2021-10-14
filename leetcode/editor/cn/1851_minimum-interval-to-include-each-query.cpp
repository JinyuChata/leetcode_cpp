//给你一个二维整数数组 intervals ，其中 intervals[i] = [lefti, righti] 表示第 i 个区间开始于 lefti 、结束
//于 righti（包含两侧取值，闭区间）。区间的 长度 定义为区间中包含的整数数目，更正式地表达是 righti - lefti + 1 。 
//
// 再给你一个整数数组 queries 。第 j 个查询的答案是满足 lefti <= queries[j] <= righti 的 长度最小区间 i 的长度
// 。如果不存在这样的区间，那么答案是 -1 。 
//
// 以数组形式返回对应查询的所有答案。 
//
// 
//
// 示例 1： 
//
// 
//输入：intervals = [[1,4],[2,4],[3,6],[4,4]], queries = [2,3,4,5]
//输出：[3,3,1,4]
//解释：查询处理如下：
//- Query = 2 ：区间 [2,4] 是包含 2 的最小区间，答案为 4 - 2 + 1 = 3 。
//- Query = 3 ：区间 [2,4] 是包含 3 的最小区间，答案为 4 - 2 + 1 = 3 。
//- Query = 4 ：区间 [4,4] 是包含 4 的最小区间，答案为 4 - 4 + 1 = 1 。
//- Query = 5 ：区间 [3,6] 是包含 5 的最小区间，答案为 6 - 3 + 1 = 4 。
// 
//
// 示例 2： 
//
// 
//输入：intervals = [[2,3],[2,5],[1,8],[20,25]], queries = [2,19,5,22]
//输出：[2,-1,4,6]
//解释：查询处理如下：
//- Query = 2 ：区间 [2,3] 是包含 2 的最小区间，答案为 3 - 2 + 1 = 2 。
//- Query = 19：不存在包含 19 的区间，答案为 -1 。
//- Query = 5 ：区间 [2,5] 是包含 5 的最小区间，答案为 5 - 2 + 1 = 4 。
//- Query = 22：区间 [20,25] 是包含 22 的最小区间，答案为 25 - 20 + 1 = 6 。
// 
//
// 
//
// 提示： 
//
// 
// 1 <= intervals.length <= 10⁵ 
// 1 <= queries.length <= 10⁵ 
// queries[i].length == 2 
// 1 <= lefti <= righti <= 10⁷ 
// 1 <= queries[j] <= 10⁷ 
// 
// Related Topics 数组 二分查找 排序 扫描线 堆（优先队列） 👍 27 👎 0

#include "bits/stdc++.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    struct LogRecord {
        int position;
        vector<int> interval;
        int state;

        bool operator<(const LogRecord &l2) const {
            int l1s = interval[1] - interval[0] + 1;
            int l2s = l2.interval[1] - l2.interval[0] + 1;
            return l1s < l2s;
        }

    };

    static bool cmp(const vector<int>& l1, const vector<int>& l2) {
        int l1s = l1[1] - l1[0] + 1;
        int l2s = l2[1] - l2[0] + 1;
        return l1s < l2s;
    }

    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        int OPEN = 0, QUERY = 1, CLOSE = 2;

        vector<LogRecord> records;

        for (vector<int>& interval : intervals) {
            LogRecord lOpen; lOpen.interval = interval; lOpen.position = interval[0]; lOpen.state = OPEN; records.push_back(lOpen);
            LogRecord lClose; lClose.interval = interval; lClose.position = interval[1]; lClose.state = CLOSE; records.push_back(lClose);
        }

        for (int& i : queries) {
            LogRecord lQuery; lQuery.position = i; lQuery.state = QUERY;
            records.push_back(lQuery);
        }

        sort(records.begin(), records.end(), [](LogRecord& l1, LogRecord& l2){
            if (l1.position != l2.position) return l1.position < l2.position;
            return l1.state < l2.state;
        });

        unordered_map<int, int> results;
        multiset<vector<int>, decltype(&cmp)> invs(cmp);
        for (LogRecord& logRecord : records) {
            if (logRecord.state == OPEN) {
                invs.insert(logRecord.interval);
            } else if (logRecord.state == QUERY) {
                if (!results.count(logRecord.position)) {
                    if (invs.begin() == invs.end()) {
                        results[logRecord.position] = -1;
                    } else {
                        int l0 = (*invs.begin())[0];
                        int l1 = (*invs.begin())[1];
                        results[logRecord.position] = l1-l0+1;
                    }
                }
            } else {
                // delete
                invs.erase(invs.find(logRecord.interval));
            }
        }

        vector<int> revs;
        for (int& i : queries) {
            revs.push_back(results[i]);
        }

        return revs;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    vector<vector<int>> ins = {{2,3},{2,5},{1,8},{20,25}};
    vector<int> qs = {2,19,5,22};
    s.minInterval(ins,qs);
}