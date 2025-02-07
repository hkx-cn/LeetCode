//              59. 螺旋矩阵 II
//      中等 │ 1400  │ 70.9% 的 716.8K
//
// 给你一个正整数 n ，生成一个包含 1 到 n^2 所有元素，且元素按顺时针顺序螺旋排列的 n x n 正方形矩阵 matrix 。
//
// 󰛨 示例 1：
// [img](https://assets.leetcode.com/uploads/2020/11/13/spiraln.jpg)
// 	│ 输入：n = 3
// 	│ 输出：[[1,2,3],[8,9,4],[7,6,5]]
//
// 󰛨 示例 2：
// 	│ 输入：n = 1
// 	│ 输出：[[1]]
//
//  提示：
// 	* 1 <= n <= 20

#include "LeetCode59.hpp"
vector<vector<int>> Solution::generateMatrix(int n) {
    vector<vector<int>> result(n, vector<int>(n));
    int count = 0, limit = n, edge = 0, times = 1, idx1 = 0, idx2 = -1;
    for (size_t num = 1; num <= n * n; num++) {
        if (count >= limit) {
            count = 0;
            edge++;
            times--;
            if (times <= 0) {
                times = 2;
                limit--;
            }
        }
        count++;
        if (edge % 4 == 0) {
            idx2++;
        } else if (edge % 4 == 1) {
            idx1++;
        } else if (edge % 4 == 2) {
            idx2--;
        } else if (edge % 4 == 3) {
            idx1--;
        }
        result[idx1][idx2] = num;
    }
    return result;
}
