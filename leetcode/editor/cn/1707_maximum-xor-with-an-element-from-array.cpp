//给你一个由非负整数组成的数组 nums 。另有一个查询数组 queries ，其中 queries[i] = [xi, mi] 。 
//
// 第 i 个查询的答案是 xi 和任何 nums 数组中不超过 mi 的元素按位异或（XOR）得到的最大值。换句话说，答案是 max(nums[j] XOR
// xi) ，其中所有 j 均满足 nums[j] <= mi 。如果 nums 中的所有元素都大于 mi，最终答案就是 -1 。 
//
// 返回一个整数数组 answer 作为查询的答案，其中 answer.length == queries.length 且 answer[i] 是第 i 个
//查询的答案。 
//
// 
//
// 示例 1： 
//
// 输入：nums = [0,1,2,3,4], queries = [[3,1],[1,3],[5,6]]
//输出：[3,3,7]
//解释：
//1) 0 和 1 是仅有的两个不超过 1 的整数。0 XOR 3 = 3 而 1 XOR 3 = 2 。二者中的更大值是 3 。
//2) 1 XOR 2 = 3.
//3) 5 XOR 2 = 7.
// 
//
// 示例 2： 
//
// 输入：nums = [5,2,4,6,6,3], queries = [[12,4],[8,1],[6,3]]
//输出：[15,-1,5]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length, queries.length <= 105 
// queries[i].length == 2 
// 0 <= nums[j], xi, mi <= 109 
// 
// Related Topics 位运算 字典树 
// 👍 117 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
#include "bits/stdc++.h"
#include "cstring"
#define MAX 0b100000000000000000000000000000
using namespace std;

int compare(vector<int>& q1, vector<int>& q2) {
    return q1[1] < q2[1];
}

class TrieNode {
public:
    int value = -1;
    vector<TrieNode *> children;

    TrieNode() : children(vector<TrieNode *>(2, nullptr)) {}
};

class Solution {
public:
    vector<int> maximizeXor(vector<int> &nums, vector<vector<int>> &queries) {
        // 建树
        TrieNode *root = new TrieNode;
        // 构建过程中，记录构建的最大值
        int oldMax;
        int maxVal = -1;
        vector<int> ress;

        vector<vector<int>> q_backup = queries;
        sort(queries.begin(), queries.end(), compare);

        map<string, int> smap;

        for (vector<int>& q : queries) {
            int x = q[0];
            int m = q[1];

            if (smap.find(to_string(x) + "#" + to_string(m)) != smap.end()) continue;

            int res = -1;

            oldMax = maxVal;
            maxVal = max(maxVal, m);

            if (oldMax < maxVal) {
                // 建树
                for (int num : nums) {
                    if (num <= oldMax || num > maxVal) continue;
                    unsigned to = num;
                    auto p = root;
                    // 从右到左，检查30位
                    for (int i = 0; i < 32; i++) {
                        if ((to & INT32_MIN) != 0) {
                            // 1
                            if (!p->children[1]) p->children[1] = new TrieNode;
                            p = p->children[1];
                        } else {
                            // 0
                            if (!p->children[0]) p->children[0] = new TrieNode;
                            p = p->children[0];
                        }
                        to <<= 1;
                    }
                    p->value = num;
                }
            }

            // 查询
            auto p = root;
            int offset;
            for (offset = 0; offset < 32; offset++) {
                if (!p) break;

                int hope, back;
                if ((((unsigned) x << offset) & INT32_MIN) == 0) {
                    // 0
                    hope = 1;
                    back = 0;
                } else {
                    // 1
                    hope = 0;
                    back = 1;
                }

                if (p->children[hope]) {
                    p = p->children[hope];
                } else if (p->children[back]) {
                    p = p->children[back];
                } else break;
            }

            if (offset == 32 && p) {
                cout << m << endl;
                cout << p->value << endl;
                res = max((int) res, (int) (p->value ^ x));
            }

            smap[to_string(x) + "#" + to_string(m)] = res;
//            ress.push_back(res);
        }

        for (vector<int>& v : q_backup) {
            ress.push_back(smap[to_string(v[0]) + "#" + to_string(v[1])]);
        }

        return ress;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    vector<int> nums = {0,1,2,3,4};
    vector<vector<int>> queries = {{3, 1}, {1, 3}, {5, 6}};
    s.maximizeXor(nums, queries);
}