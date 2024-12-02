// 867. 转置矩阵
// 给你一个二维整数数组 matrix， 返回 matrix 的 转置矩阵 。

// 矩阵的 转置 是指将矩阵的主对角线翻转，交换矩阵的行索引与列索引。
// 示例 1：
// 输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
// 输出：[[1,4,7],[2,5,8],[3,6,9]]
// 示例 2：
// 输入：matrix = [[1,2,3],[4,5,6]]
// 输出：[[1,4],[2,5],[3,6]]

// 提示：
// m == matrix.length
// n == matrix[i].length
// 1 <= m, n <= 1000
// 1 <= m * n <= 10^5
// -10^9 <= matrix[i][j] <= 10^9
#include "LeetCode867.hpp"

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** transpose(int** matrix, int matrixSize, int* matrixColSize, int* returnSize, int** returnColumnSizes) {
    int** result = (int**)malloc(matrixColSize[0] * sizeof(int*));
    *returnColumnSizes = (int*)malloc(matrixColSize[0] * sizeof(int*));
    *returnSize = matrixColSize[0];
    for (int i = 0; i < matrixColSize[0]; i++) {
        result[i] = (int*)malloc(matrixSize * sizeof(int));
        (*returnColumnSizes)[i] = matrixSize;
    }
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixColSize[0]; j++) {
            result[j][i] = matrix[i][j];
        }
    }
    return result;
}

// vector<vector<int>> Solution::transpose(vector<vector<int>>& matrix) {
//     int x = matrix.size();
//     int y = matrix[0].size();
//     vector<vector<int>> result(y, vector<int>(x, 0));
//     for (size_t i = 0; i < matrix.size(); i++) {
//         for (size_t j = 0; j < matrix[i].size(); j++) {
//             result[j][i] = matrix[i][j];
//         }
//     }
//     return result;
// };

// 方法一：模拟
// 如果矩阵 matrix 为 m 行 n 列，则转置后的矩阵 matrixT 为 n 行 m 列，且对任意
// 0≤i<m 和 0≤j<n，都有 matrixT[j][i]=matrix[i][j]。 创建一个 n 行 m
// 列的新矩阵，根据转置的规则对新矩阵中的每个元素赋值，则新矩阵为转置后的矩阵。
// class Solution {
// public:
//     vector<vector<int>> transpose(vector<vector<int>>& matrix) {
//         int m = matrix.size(), n = matrix[0].size();
//         vector<vector<int>> transposed(n, vector<int>(m));
//         for (int i = 0; i < m; i++) {
//             for (int j = 0; j < n; j++) {
//                 transposed[j][i] = matrix[i][j];
//             }
//         }
//         return transposed;
//     }
// };
// 复杂度分析
// 时间复杂度：O(mn)，其中 m 和 n 分别是矩阵 matrix
// 的行数和列数。需要遍历整个矩阵，并对转置后的矩阵进行赋值操作。
// 空间复杂度：O(1)。除了返回值以外，额外使用的空间为常数。
