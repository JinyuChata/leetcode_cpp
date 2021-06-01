//给定一个只包含数字的字符串，用以表示一个 IP 地址，返回所有可能从 s 获得的 有效 IP 地址 。你可以按任何顺序返回答案。 
//
// 有效 IP 地址 正好由四个整数（每个整数位于 0 到 255 之间组成，且不能含有前导 0），整数之间用 '.' 分隔。 
//
// 例如："0.1.2.201" 和 "192.168.1.1" 是 有效 IP 地址，但是 "0.011.255.245"、"192.168.1.312" 
//和 "192.168@1.1" 是 无效 IP 地址。 
//
// 
//
// 示例 1： 
//
// 
//输入：s = "25525511135"
//输出：["255.255.11.135","255.255.111.35"]
// 
//
// 示例 2： 
//
// 
//输入：s = "0000"
//输出：["0.0.0.0"]
// 
//
// 示例 3： 
//
// 
//输入：s = "1111"
//输出：["1.1.1.1"]
// 
//
// 示例 4： 
//
// 
//输入：s = "010010"
//输出：["0.10.0.10","0.100.1.0"]
// 
//
// 示例 5： 
//
// 
//输入：s = "101023"
//输出：["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]
// 
//
// 
//
// 提示： 
//
// 
// 0 <= s.length <= 3000 
// s 仅由数字组成 
// 
// Related Topics 字符串 回溯算法 
// 👍 580 👎 0

#include "bits/stdc++.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<string> ips;

    // s, 正在检查的数字idx, 正在检查的组curr, 正在检查的组号0/1/2/3, 检查过的组vector
    void traceback(string& s, int idxDig, string curr, int idxGrp, vector<string> examed) {
        if (idxGrp == 4) {
            // 是否为最后一组？
            if (idxGrp == 4 && idxDig == s.size()) {
                string res;
                for (int i = 0; i < 4; i++) {
                    res += examed[i];
                    if (i != 3) res += ".";
                }
                cout << "Check! " << res << endl;
                ips.push_back(res);
                return;
            }
            return;
        }

        if (!curr.empty()) {
//            cout << "Examing " << curr << endl;
//            string res;
//            for (int i = 0; i < examed.size(); i++) {
//                res += examed[i];
//                if (i != 3) res += ".";
//            }
//            cout << "Examed " << res << endl;
//
//            if (curr == "13") {
//                cout << "hi" << endl;
//            }

            examed.push_back(curr);
            traceback(s, idxDig, "", idxGrp+1, examed);
            examed.pop_back();
        }

        if (idxDig < s.size()) {
            string toExam = curr+s.substr(idxDig, 1);
            if (toExam.size() > 3) return;
            if (curr != "0" && stoi(toExam) < 256) {
                // 可以放入
                traceback(s, idxDig+1, toExam, idxGrp, examed);
            }
        }


    }

    vector<string> restoreIpAddresses(string s) {
        vector<string> examed;
        traceback(s, 0, "", 0, examed);
        return ips;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    s.restoreIpAddresses("25525511135");
}