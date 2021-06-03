//实现一个 MapSum 类，支持两个方法，insert 和 sum： 
//
// 
// MapSum() 初始化 MapSum 对象 
// void insert(String key, int val) 插入 key-val 键值对，字符串表示键 key ，整数表示值 val 。如果键 ke
//y 已经存在，那么原来的键值对将被替代成新的键值对。 
// int sum(string prefix) 返回所有以该前缀 prefix 开头的键 key 的值的总和。 
// 
//
// 
//
// 示例： 
//
// 
//输入：
//["MapSum", "insert", "sum", "insert", "sum"]
//[[], ["apple", 3], ["ap"], ["app", 2], ["ap"]]
//输出：
//[null, null, 3, null, 5]
//
//解释：
//MapSum mapSum = new MapSum();
//mapSum.insert("apple", 3);  
//mapSum.sum("ap");           // return 3 (apple = 3)
//mapSum.insert("app", 2);    
//mapSum.sum("ap");           // return 5 (apple + app = 3 + 2 = 5)
// 
//
// 
//
// 提示： 
//
// 
// 1 <= key.length, prefix.length <= 50 
// key 和 prefix 仅由小写英文字母组成 
// 1 <= val <= 1000 
// 最多调用 50 次 insert 和 sum 
// 
// Related Topics 字典树 
// 👍 88 👎 0
#include "bits/stdc++.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class TrieNode {
public:
    vector<TrieNode*> children;
    string key = "";
    int val;

    TrieNode(): children(vector<TrieNode*>(26, nullptr)) {}
};

class MapSum {
public:
    TrieNode* root;

    /** Initialize your data structure here. */
    MapSum() {
        root = new TrieNode;
    }
    
    void insert(string key, int val) {
        TrieNode* p = root;
        for (char c : key) {
            if (!p->children[c-'a']) p->children[c-'a'] = new TrieNode;
            p = p->children[c-'a'];
        }
        p->key = key;
        p->val = val;
    }

    void dfs(TrieNode* node, int& sum) {
        if (!node) return;
        if (!node->key.empty()) sum += node->val;

        for (int i = 0; i < 26; i++) {
            dfs(node->children[i], sum);
        }
    }
    
    int sum(string prefix) {
        TrieNode* p = root;
        int sum = 0;
        for (char c : prefix) {
            if (!p->children[c-'a']) return 0;
            p = p->children[c-'a'];
        }
        // 找完前缀之后
        dfs(p, sum);
        return sum;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
}