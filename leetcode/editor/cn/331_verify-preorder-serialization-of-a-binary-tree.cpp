//序列化二叉树的一种方法是使用前序遍历。当我们遇到一个非空节点时，我们可以记录下这个节点的值。
// 如果它是一个空节点，我们可以使用一个标记值记录，例如 #。
//
//      _9_
//    /   \
//   3     2
//  / \   / \
// 4   1  #  6
/// \ / \   / \
//# # # #   # #
// 
//
// 例如，上面的二叉树可以被序列化为字符串 "9,3,4,#,#,1,#,#,2,#,6,#,#"，其中 # 代表一个空节点。 
//
// 给定一串以逗号分隔的序列，验证它是否是正确的二叉树的前序序列化。编写一个在不重构树的条件下的可行算法。 
//
// 每个以逗号分隔的字符或为一个整数或为一个表示 null 指针的 '#' 。 
//
// 你可以认为输入格式总是有效的，例如它永远不会包含两个连续的逗号，比如 "1,,3" 。 
//
// 示例 1: 
//
// 输入: "9,3,4,#,#,1,#,#,2,#,6,#,#"
//输出: true 
//
// 示例 2: 
//
// 输入: "1,#"
//输出: false
// 
//
// 示例 3: 
//
// 输入: "9,#,#,1"
//输出: false 
// Related Topics 栈 
// 👍 317 👎 0

#include "bits/stdc++.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Node {
public:
    int val = 0;
    string chr;

    Node(string chr) : chr(chr) {}
};

class Solution {
public:
    bool isValidSerialization(string preorder) {
        if (preorder == "#") return true;

        stack<Node*> stkNodes;
        regex comma_re(",");
        vector<string> v(sregex_token_iterator(preorder.begin(), preorder.end(),
                                               comma_re, -1),
                         sregex_token_iterator());


        for (int i = 0; i < v.size(); i++) {
            string& s = v[i];
            if (i != 0 && stkNodes.empty()) return false;
            if (s != "#") {
                Node* n = new Node(s);
                stkNodes.push(n);
            } else {
                if (stkNodes.empty()) return false;
                while (!stkNodes.empty()) {
                    stkNodes.top()->val++;
                    if (stkNodes.top()->val < 2) break;
                    else {
                        stkNodes.pop();
                    }
                }
            }
        }

        return stkNodes.empty();
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
}