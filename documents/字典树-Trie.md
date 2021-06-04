# 字典树整理
> 2021-06-04

## 介绍
字典树用于(字典序单词的搜索)，其结构如下：

![](https://cse2020-dune.oss-cn-shanghai.aliyuncs.com/20210604145318.png)

- 上面的这一棵字典树，标记了a, abc, bac, bbc, ca
- 实质上，就是一个公用前缀的树
    - 当节点不被涂色时，说明到此节点还没遇到完整单词；
    - 当节点被涂色时，说明到此节点已经遇到了完整单词，但是下面可能还有其他单词

## 用途
1. 单词的搜索(字典序的搜索)
    - 211、212、208 (基础运用)
2. 回文对 拼接words[i] + words[j] 可形成回文串
    - 336 回文对
        - 建立Trie, 存逆序；遍历每个word，查找逆序Trie能否对上，最后判断剩余部分是否为回文串
3. 字符流 1032
4. 差一个字符的字符串比较 1638
5. 前后缀搜索 745
    - 745 给定(prefix+suffix)搜索
        - 用拼接优化，suffix#prefix (ple#apple) 建立Trie，直接搜索这棵树即可
6. 亦或的`极值` (好多题都TLE，但是确实可以用Trie做)
## 代码
```c++
// 建树
class TrieNode {
public:
    string word = "";     // 默认空串代表无色，即没到末尾
    vector<TrieNode*> children;
    
    // 构造函数：默认没有子分支，字典个数为26(a-z)
    TrieNode() : children(vector<TrieNode*>(26, nullptr)) {}
};

// 插入
auto p = root;      // TrieNode*
for (char c : word) {
    if (!p->children[c-'a']) {
        p->children[c-'a'] = new TrieNode;
    }
    p = p->children[c-'a'];
}
p->word = word;     // '上色'
```
