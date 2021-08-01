//给定一组非负整数 nums，重新排列每个数的顺序（每个数不可拆分）使之组成一个最大的整数。 
//
// 注意：输出结果可能非常大，所以你需要返回一个字符串而不是整数。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [10,2]
//输出："210" 
//
// 示例 2： 
//
// 
//输入：nums = [3,30,34,5,9]
//输出："9534330"
// 
//
// 示例 3： 
//
// 
//输入：nums = [1]
//输出："1"
// 
//
// 示例 4： 
//
// 
//输入：nums = [10]
//输出："10"
// 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 100 
// 0 <= nums[i] <= 109 
// 
// Related Topics 贪心 字符串 排序 
// 👍 747 👎 0

//leetcode submit region begin(Prohibit modification and deletion)
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> str;
        for (auto& i : nums) {
            str.push_back(to_string(i));
        }

        // lambda 比较
        auto cmp = [](const string& left, const string& right) {
            return left + right > right + left;
        };

        sort(str.begin(), str.end(), cmp);
        stringstream ss;
        for (const auto& s : str) {
            ss << s;
        }

        string res = ss.str();
        if (res[0] == '0') return "0";
        return res;

    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    vector<int> in{3,30,34,5,9};
    s.largestNumber(in);
}