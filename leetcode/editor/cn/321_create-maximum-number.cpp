//给定长度分别为 m 和 n 的两个数组，其元素由 0-9 构成，表示两个自然数各位上的数字。现在从这两个数组中选出 k (k <= m + n) 个数字拼接
//成一个新的数，要求从同一个数组中取出的数字保持其在原数组中的相对顺序。 
//
// 求满足该条件的最大数。结果返回一个表示该最大数的长度为 k 的数组。 
//
// 说明: 请尽可能地优化你算法的时间和空间复杂度。 
//
// 示例 1: 
//
// 输入:
//nums1 = [3, 4, 6, 5]
//nums2 = [9, 1, 2, 5, 8, 3]
//k = 5
//输出:
//[9, 8, 6, 5, 3] 
//
// 示例 2: 
//
// 输入:
//nums1 = [6, 7]
//nums2 = [6, 0, 4]
//k = 5
//输出:
//[6, 7, 6, 0, 4] 
//
// 示例 3: 
//
// 输入:
//nums1 = [3, 9]
//nums2 = [8, 9]
//k = 3
//输出:
//[9, 8, 9] 
// Related Topics 贪心算法 动态规划 
// 👍 383 👎 0
#include <bits/stdc++.h>
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> chooseK(vector<int>& nums, int k) {
        vector<int> stk;

        vector<int> res(k, 0);
        if (k == 0) return res;

        int n = nums.size();
        int toDelete = n-k;
        for (int num : nums) {
            while (!stk.empty() && toDelete > 0 && num > stk[stk.size()-1]) {
                toDelete--;
                stk.pop_back();
            }
            stk.push_back(num);
        }

        while (stk.size() > k) {
            stk.pop_back();
        }

        return stk;
    }

    void printVector(vector<int>& nums) {
        for (int n : nums) cout << n << "  ";
        cout << endl;
    }

    int check(vector<int>& vs1, vector<int>& vs2, int s1_idx, int s2_idx) {
        int maxVal = 0;
        if (s1_idx == vs1.size() - 1) {
            return 2;
        } else if (s2_idx == vs2.size() - 1) {
            return 1;
        } else {
            // 看后面的哪个大
            if (vs1[s1_idx+1] > vs2[s2_idx+1]) {
                return 1;
            } else if (vs1[s1_idx+1] < vs2[s2_idx+1]) {
                return 2;
            } else {
                return check(vs1, vs2, s1_idx+1, s2_idx+1);
            }
        }
    }

    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int s1_choose = 0;
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<int> res(k, 0);

        while (s1_choose <= k) {
            if (s1_choose > n1 || k-s1_choose > n2) {
                s1_choose++;
                continue;
            }
            int s2_choose = k - s1_choose;
            cout << "CHOOSE: " << s1_choose << ", " << s2_choose << endl;
            vector<int> vs1 = chooseK(nums1, s1_choose);
            vector<int> vs2 = chooseK(nums2, s2_choose);
            printVector(vs1);
            printVector(vs2);
            // merge
            int s1_idx = 0, s2_idx = 0;
            int bigger = 0;
            while (s1_idx < s1_choose || s2_idx < s2_choose) {
                // <= continue
                int maxVal = 0;
                if (s1_idx < s1_choose && s2_idx < s2_choose) {
                    if (vs1[s1_idx] > vs2[s2_idx]) {
                        maxVal = vs1[s1_idx]; s1_idx++;
                    } else if (vs1[s1_idx] < vs2[s2_idx]) {
                        maxVal = vs2[s2_idx]; s2_idx++;
                    } else {
                        // ==
                        if (check(vs1, vs2, s1_idx, s2_idx) == 1) {
                            maxVal = vs1[s1_idx]; s1_idx++;
                        } else {
                            maxVal = vs2[s2_idx]; s2_idx++;
                        }
//                        if (s1_idx == vs1.size() - 1) {
//                            maxVal = vs2[s2_idx]; s2_idx++;
//                        } else if (s2_idx == vs2.size() - 1) {
//                            maxVal = vs1[s1_idx]; s1_idx++;
//                        } else {
//                            // 看后面的哪个大
//                            if (vs1[s1_idx+1] > vs2[s2_idx+1]) {
//                                maxVal = vs1[s1_idx];
//                                s1_idx++;
//                            } else {
//                                maxVal = vs2[s2_idx];
//                                s2_idx++;
//                            }
//                        }
                    }
                } else if (s1_idx < s1_choose) {
                    maxVal = vs1[s1_idx];
                    s1_idx++;
                } else {
                    maxVal = vs2[s2_idx];
                    s2_idx++;
                }

                if (bigger) {
                    res[s1_idx + s2_idx - 1] = maxVal;
                } else if (maxVal > res[s1_idx + s2_idx - 1]) {
                    bigger = 1;
                    res[s1_idx + s2_idx - 1] = maxVal;
                } else if (maxVal < res[s1_idx + s2_idx - 1]) {
                    break;
                }
                cout << "RESULT: " ;
                printVector(res);
            }
            s1_choose++;
        }

        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    /**
[2,1,7,8,0,1,7,3,5,8,9,0,0,7,0,2,2,7,3,5,5]
[2,6,2,0,1,0,5,4,5,5,3,3,3,4]
35
     */
    vector<int> n1{2,1,7,8,0,1,7,3,5,8,9,0,0,7,0,2,2,7,3,5,5};
    vector<int> n2{2,6,2,0,1,0,5,4,5,5,3,3,3,4};
    Solution s;
    s.maxNumber(n1, n2, 35);
}