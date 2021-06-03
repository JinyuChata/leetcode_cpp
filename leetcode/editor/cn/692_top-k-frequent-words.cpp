//给一非空的单词列表，返回前 k 个出现次数最多的单词。 
//
// 返回的答案应该按单词出现频率由高到低排序。如果不同的单词有相同出现频率，按字母顺序排序。 
//
// 示例 1： 
//
// 
//输入: ["i", "love", "leetcode", "i", "love", "coding"], k = 2
//输出: ["i", "love"]
//解析: "i" 和 "love" 为出现次数最多的两个单词，均为2次。
//    注意，按字母顺序 "i" 在 "love" 之前。
// 
//
// 
//
// 示例 2： 
//
// 
//输入: ["the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"], k
// = 4
//输出: ["the", "is", "sunny", "day"]
//解析: "the", "is", "sunny" 和 "day" 是出现次数最多的四个单词，
//    出现次数依次为 4, 3, 2 和 1 次。
// 
//
// 
//
// 注意： 
//
// 
// 假定 k 总为有效值， 1 ≤ k ≤ 集合元素数。 
// 输入的单词均由小写字母组成。 
// 
//
// 
//
// 扩展练习： 
//
// 
// 尝试以 O(n log k) 时间复杂度和 O(n) 空间复杂度解决。 
// 
// Related Topics 堆 字典树 哈希表 
// 👍 348 👎 0

#include "bits/stdc++.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
bool wordCompare(pair<string, int>& a,pair<string, int>& b)
{
    // 小顶堆，greater
    if (a.second != b.second) return a.second > b.second;
    return a.first < b.first;
}

class Solution {
public:

    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> counts;
        for (string& str : words) {
            if (counts.find(str) == counts.end()) counts[str] = 0;
            counts[str] ++;
        }

        // 构建堆
        vector<pair<string, int>> heap;
        int count = 0;
        make_heap(heap.begin(), heap.end(), wordCompare);
        for (auto& pir : counts) {
            cout << pir.first << " " << pir.second << endl;
            heap.emplace_back(pir);
            push_heap(heap.begin(), heap.end(), wordCompare);
            count++;
            if (count > k) {
                count--;
                pop_heap(heap.begin(), heap.end(), wordCompare);
                heap.pop_back();
            }
        }

        vector<string> res;
        for (int i = 0; i < k; i++) {
            pop_heap(heap.begin(), heap.end(), wordCompare);
            res.insert(res.begin(), heap[heap.size()-1].first);
            heap.pop_back();
        }

        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    vector<string> words = {"the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"};
    s.topKFrequent(words, 4);
}