//在由 1 x 1 方格组成的 N x N 网格 grid 中，每个 1 x 1 方块由 /、\ 或空格构成。这些字符会将方块划分为一些共边的区域。 
//
// （请注意，反斜杠字符是转义的，因此 \ 用 "\\" 表示。）。 
//
// 返回区域的数目。 
//
// 
//
// 
// 
//
// 示例 1： 
//
// 输入：
//[
//  " /",
//  "/ "
//]
//输出：2
//解释：2x2 网格如下：
// 
//
// 示例 2： 
//
// 输入：
//[
//  " /",
//  "  "
//]
//输出：1
//解释：2x2 网格如下：
// 
//
// 示例 3： 
//
// 输入：
//[
//  "\\/",
//  "/\\"
//]
//输出：4
//解释：（回想一下，因为 \ 字符是转义的，所以 "\\/" 表示 \/，而 "/\\" 表示 /\。）
//2x2 网格如下：
// 
//
// 示例 4： 
//
// 输入：
//[
//  "/\\",
//  "\\/"
//]
//输出：5
//解释：（回想一下，因为 \ 字符是转义的，所以 "/\\" 表示 /\，而 "\\/" 表示 \/。）
//2x2 网格如下：
// 
//
// 示例 5： 
//
// 输入：
//[
//  "//",
//  "/ "
//]
//输出：3
//解释：2x2 网格如下：
//
// 
//
// 
//
// 提示： 
//
// 
// 1 <= grid.length == grid[0].length <= 30 
// grid[i][j] 是 '/'、'\'、或 ' '。 
// 
// Related Topics 深度优先搜索 广度优先搜索 并查集 图 
// 👍 271 👎 0

#include "bits/stdc++.h"
using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> root;

    int find(int i) {
        if (root[i] < 0) return i;
        return root[i] = find(root[i]);
    }

    void join(int i, int j) {
        int ri = find(i); int rj = find(j);
        if (ri == rj) return;
        root[ri] = rj;
    }

    void joinTwo(int i0, int j0, int pos0, int i1, int j1, int pos1,
                 int m, int n) {
        // 首先，验证i1,j1是否出界
        if (i1 < 0 || i1 >= m || j1 < 0 || j1 >= n) return;
        if (i0 < 0 || i0 >= m || j0 < 0 || j0 >= n) return;
        int p1 = (i0*n+j0)*4 + pos0;
        int p2 = (i1*n+j1)*4 + pos1;
        join(p1,p2);
    }

    int regionsBySlashes(vector<string>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        for (int i = 0; i < 4*m*n; i++) {
            root.push_back(-1);
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                joinTwo(i,j,0,i,j-1,2,m,n);
                joinTwo(i,j,1,i-1,j,3,m,n);
                joinTwo(i,j,2,i,j+1,0,m,n);
                joinTwo(i,j,3,i+1,j,1,m,n);
                if (grid[i][j] != '\\') {
                    joinTwo(i,j,0,i,j,1,m,n);
                    joinTwo(i,j,2,i,j,3,m,n);
                }
                if (grid[i][j] != '/') {
                    joinTwo(i,j,2,i,j,1,m,n);
                    joinTwo(i,j,0,i,j,3,m,n);
                }
            }
        }

        int res = 0;
        for (int i = 0; i < n*m*4; i++) {
            if (root[i] == -1) res += 1;
        }
        return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    vector<string> in = {" /", "/ "};
    s.regionsBySlashes(in);
}