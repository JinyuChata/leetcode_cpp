//序列化是将一个数据结构或者对象转换为连续的比特位的操作，进而可以将转换后的数据存储在一个文件或者内存中，同时也可以通过网络传输到另一个计算机环境，采取相反方
//式重构得到原数据。 
//
// 请设计一个算法来实现二叉树的序列化与反序列化。这里不限定你的序列 / 反序列化算法执行逻辑，你只需要保证一个二叉树可以被序列化为一个字符串并且将这个字符串
//反序列化为原始的树结构。 
//
// 提示: 输入输出格式与 LeetCode 目前使用的方式一致，详情请参阅 LeetCode 序列化二叉树的格式。你并非必须采取这种方式，你也可以采用其他的
//方法解决这个问题。 
//
// 
//
// 示例 1： 
//
// 
//输入：root = [1,2,3,null,null,4,5]
//输出：[1,2,3,null,null,4,5]
// 
//
// 示例 2： 
//
// 
//输入：root = []
//输出：[]
// 
//
// 示例 3： 
//
// 
//输入：root = [1]
//输出：[1]
// 
//
// 示例 4： 
//
// 
//输入：root = [1,2]
//输出：[1,2]
// 
//
// 
//
// 提示： 
//
// 
// 树中结点数在范围 [0, 104] 内 
// -1000 <= Node.val <= 1000 
// 
// Related Topics 树 深度优先搜索 广度优先搜索 设计 字符串 二叉树 
// 👍 627 👎 0

#include "bits/stdc++.h"
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//leetcode submit region begin(Prohibit modification and deletion)
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        queue<TreeNode*> q;
        if (root == nullptr) return "";

        q.push(root);
        string ret = "";
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* curr = q.front(); q.pop();
                ret += ',';
                if (curr == nullptr) {
                    ret += "null";
                } else {
                    q.push(curr->left); q.push(curr->right);
                    ret += to_string(curr->val);
                }
            }
        }

        return ret;
    }

    // ret, toIdx
    pair<string,int> getNext(string& data, int from) {
        if (from >= data.size()) return {"",-1};
        if (data[from] != ',') return {"",-1};
        string ret = ""; from++;
        while (from < data.size() && data[from] != ',') {
            ret += data[from];
            from++;
        }
        return {ret, from};
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "") return nullptr;

        auto [next, idx] = getNext(data, 0);
        TreeNode* root = new TreeNode(stoi(next));
        queue<TreeNode*> q; q.push(root);

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* curr = q.front(); q.pop();

                auto pa = getNext(data, idx);
                idx = pa.second; next = pa.first;
                TreeNode* left = nullptr;
                if (next != "null") { left = new TreeNode(stoi(next)); q.push(left); }

                pa = getNext(data, idx);
                idx = pa.second; next = pa.first;
                TreeNode* right = nullptr;
                if (next != "null") { right = new TreeNode(stoi(next)); q.push(right); }

                curr->left = left; curr->right = right;
            }
        }
        return root;
        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
//leetcode submit region end(Prohibit modification and deletion)


int main() {
//    Solution s;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);
    root->right->right->left = new TreeNode(6);
    Codec c;
    cout << c.serialize(root);
    c.deserialize(c.serialize(root));
    cout << "";
}