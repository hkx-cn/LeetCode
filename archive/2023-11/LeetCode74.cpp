// 74. 搜索二维矩阵
// 给你一个满足下述两条属性的 m x n 整数矩阵：

// 每行中的整数从左到右按非严格递增顺序排列。
// 每行的第一个整数大于前一行的最后一个整数。
// 给你一个整数 target ，如果 target 在矩阵中，返回 true ；否则，返回 false 。

//
// 示例 1：
// 输入：matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
// 输出：true
//
// 示例 2：
// 输入：matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
// 输出：false

// 提示：
// m == matrix.length
// n == matrix[i].length
// 1 <= m, n <= 100
// -10^4 <= matrix[i][j], target <= 10^4
#include "LeetCode74.hpp"
bool Solution::searchMatrix(vector<vector<int>> &matrix, int target)
{
    // 结果范围[0,m*n-1]
    int left = 0, right = matrix.size() * matrix[0].size() - 1, mid = -1, i, j;
    while (left <= right)
    {
        mid = left + (right - left + 1) / 2;
        i = mid / matrix[0].size();
        j = mid % matrix[0].size();
        if (matrix[i][j] < target)
            left = mid + 1;
        else if (matrix[i][j] > target)
            right = mid - 1;
        else
            return true;
    }
    return false;
}
// bool Solution::searchMatrix(vector<vector<int>> &matrix, int target)
// {
//     int left = 0, right = matrix.size() * matrix[0].size() - 1, mid = -1, i, j;
//     while (left <= right)
//     {
//         mid = left + (right - left) / 2;
//         i = mid / matrix[0].size();
//         j = mid % matrix[0].size();
//         if (matrix[i][j] == target)
//             return true;
//         else if (matrix[i][j] < target)
//             left = mid + 1;
//         else
//             right = mid - 1;
//     }
//     return false;
// }
// 方法一：两次二分查找
// 思路
// 由于每行的第一个元素大于前一行的最后一个元素，且每行元素是升序的，所以每行的第一个元素大于前一行的第一个元素，因此矩阵第一列的元素是升序的。
// 我们可以对矩阵的第一列的元素二分查找，找到最后一个不大于目标值的元素，然后在该元素所在行中二分查找目标值是否存在。
// class Solution {
// public:
//     bool searchMatrix(vector<vector<int>> matrix, int target) {
//         auto row = upper_bound(matrix.begin(), matrix.end(), target, [](const int b, const vector<int> &a) {
//             return b < a[0];
//         });
//         if (row == matrix.begin()) {
//             return false;
//         }
//         --row;
//         return binary_search(row->begin(), row->end(), target);
//     }
// };
// 复杂度分析
// 时间复杂度：O(log⁡m+log⁡n)=O(log⁡mn)，其中 m 和 n 分别是矩阵的行数和列数。
// 空间复杂度：O(1)。

// 方法二：一次二分查找
// 思路
// 若将矩阵每一行拼接在上一行的末尾，则会得到一个升序数组，我们可以在该数组上二分找到目标元素。
// 代码实现时，可以二分升序数组的下标，将其映射到原矩阵的行和列上。
// class Solution {
// public:
//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
//         int m = matrix.size(), n = matrix[0].size();
//         int low = 0, high = m * n - 1;
//         while (low <= high) {
//             int mid = (high - low) / 2 + low;
//             int x = matrix[mid / n][mid % n];
//             if (x < target) {
//                 low = mid + 1;
//             } else if (x > target) {
//                 high = mid - 1;
//             } else {
//                 return true;
//             }
//         }
//         return false;
//     }
// };
// 复杂度分析
// 时间复杂度：O(log⁡mn)，其中 m 和 n 分别是矩阵的行数和列数。
// 空间复杂度：O(1)。
// 结语
// 两种方法殊途同归，都利用了二分查找，在二维矩阵上寻找目标值。值得注意的是，若二维数组中的一维数组的元素个数不一，方法二将会失效，而方法一则能正确处理。