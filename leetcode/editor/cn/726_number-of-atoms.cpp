//给定一个化学式formula（作为字符串），返回每种原子的数量。 
//
// 原子总是以一个大写字母开始，接着跟随0个或任意个小写字母，表示原子的名字。 
//
// 如果数量大于 1，原子后会跟着数字表示原子的数量。如果数量等于 1 则不会跟数字。例如，H2O 和 H2O2 是可行的，但 H1O2 这个表达是不可行的。
// 
//
// 两个化学式连在一起是新的化学式。例如 H2O2He3Mg4 也是化学式。 
//
// 一个括号中的化学式和数字（可选择性添加）也是化学式。例如 (H2O2) 和 (H2O2)3 是化学式。 
//
// 给定一个化学式，输出所有原子的数量。格式为：第一个（按字典序）原子的名子，跟着它的数量（如果数量大于 1），然后是第二个原子的名字（按字典序），跟着它的数
//量（如果数量大于 1），以此类推。 
//
// 示例 1: 
//
// 
//输入: 
//formula = "H2O"
//输出: "H2O"
//解释: 
//原子的数量是 {'H': 2, 'O': 1}。
// 
//
// 示例 2: 
//
// 
//输入: 
//formula = "Mg(OH)2"
//输出: "H2MgO2"
//解释: 
//原子的数量是 {'H': 2, 'Mg': 1, 'O': 2}。
// 
//
// 示例 3: 
//
// 
//输入: 
//formula = "K4(ON(SO3)2)2"
//输出: "K4N2O14S4"
//解释: 
//原子的数量是 {'K': 4, 'N': 2, 'O': 14, 'S': 4}。
// 
//
// 注意: 
//
// 
// 所有原子的第一个字母为大写，剩余字母都是小写。 
// formula的长度在[1, 1000]之间。 
// formula只包含字母、数字和圆括号，并且题目中给定的是合法的化学式。 
// 
// Related Topics 栈 递归 哈希表 
// 👍 121 👎 0

#include "bits/stdc++.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    map<string, int> parse(string& formula, int startIdx, int& nextIdx) {
        // 结束：见到`)`，或走到最后了
        int i = startIdx;
        map<string, int> mapper;

        while (i < formula.size() && formula[i] != ')') {
            map<string, int> innerMapper;
            if (formula[i] >= 'A' && formula[i] <= 'Z') {
                // 大写字母+小写字母
                string word = string(1, formula[i]);
                i++;
                while (formula[i] >= 'a' && formula[i] <= 'z') {
                    word += string(1, formula[i]);
                    i++;
                }
                innerMapper[word] = 1;
            } else if (formula[i] == '(') {
                innerMapper = parse(formula, i+1, i);     // 返回的是)的后一个
            }

            string counter;
            int times = 1;
            while (i < formula.size() && formula[i] >= '0' && formula[i] <= '9') {
                counter += string (1, formula[i]);
                i++;
            }
            if (!counter.empty()) {
                times = stoi(counter);
            }

            // 将innerMapper的内容，拷贝到mapper
            for (auto& par : innerMapper) {
                if (mapper.find(par.first) == mapper.end()) {
                    mapper[par.first] = times * par.second;
                } else {
                    mapper[par.first] += times * par.second;
                }
            }
        }

        if (i < formula.size() && formula[i] == ')') {
            i++;
        }
        nextIdx = i;
        return mapper;
    }

    string countOfAtoms(string formula) {
        vector<string> keys;
        int i = 0;
        map<string, int> mapper = parse(formula, 0, i);
        for (auto& par : mapper) {
            keys.push_back(par.first);
        }
        sort(keys.begin(), keys.end());
        string res;
        for (auto& key : keys) {
            res += key;
            if (mapper[key] > 1) {
                res += to_string(mapper[key]);
            }
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
}