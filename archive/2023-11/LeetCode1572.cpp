//1572. 矩阵对角线元素的和
//给你一个正方形矩阵 mat，请你返回矩阵对角线元素的和。
//
//请你返回在矩阵主对角线上的元素和副对角线上且不在主对角线上元素的和。
//
//
//
//示例  1：
//
//
//
//输入：mat = [[1, 2, 3],
//[4, 5, 6],
//[7, 8, 9]]
//输出：25
//解释：对角线的和为：1 + 5 + 9 + 3 + 7 = 25
//请注意，元素 mat[1][1] = 5 只会被计算一次。
//示例  2：
//
//输入：mat = [[1, 1, 1, 1],
//[1, 1, 1, 1],
//[1, 1, 1, 1],
//[1, 1, 1, 1]]
//输出：8
//示例 3：
//
//输入：mat = [[5]]
//    输出：5
//
//
//        提示：
//
//        n == mat.length == mat[i].length
//        1 <= n <= 100
//        1 <= mat[i][j] <= 100
#include"LeetCode1572.h"
int Solution::diagonalSum(vector<vector<int>>& mat) {
	int len = mat[0].size(), result = 0;
	for (size_t i = 0; i < len; i++)
	{
		result += mat[i][i];
		result += mat[len - i - 1][i];
	}
	if (len % 2 == 1)
	{
		result -= mat[len / 2][len / 2];
	}
	return result;
};
//方法一：遍历矩阵
//思路与算法
//
//我们知道矩阵中某个位置(i, j)(i, j)(i, j) 处于对角线上，则一定满足下列条件之一：
//
//i = ji = ji = j；
//i + j = n−1i + j = n - 1i + j = n−1；
//根据上述结论，我们可以遍历整个矩阵，如果当前坐标(i, j)(i, j)(i, j) 满足 i = ji = ji = j 或者 i + j = n−1i + j = n - 1i + j = n−1 则表示该位置一定在对角线上，则把当前的数字加入到答案之中。
//class Solution {
//public:
//	int diagonalSum(vector<vector<int>>& mat) {
//		int n = mat.size(), sum = 0;
//		for (int i = 0; i < n; ++i) {
//			for (int j = 0; j < n; ++j) {
//				if (i == j || i + j == n - 1) {
//					sum += mat[i][j];
//				}
//			}
//		}
//		return sum;
//	}
//};
//复杂度分析
//
//时间复杂度：O(n2)O(n ^ 2)O(n
//	2
//)，其中 nnn 是矩阵 mat\textit{ mat }mat 的行数。
//空间复杂度：O(1)O(1)O(1)。
//方法二：枚举对角线元素
//思路与算法
//
//逐行遍历，记当前的行号为 iii，则当前行中处于对角线的元素为： 坐标(i, i)(i, i)(i, i) 和坐标(i, n−i−1)(i, n - i - 1)(i, n−i−1)，因此我们把(i, i)(i, i)(i, i) 与(i, n−i−1)(i, n - i - 1)(i, n−i−1) 处的数字加入到答案中。 如果 nnn 是奇数的话，则主对角线与副对角线存在交点(⌊n2⌋, ⌊n2⌋)(\lfloor \dfrac{ n }{2} \rfloor, \lfloor \dfrac{ n }{2} \rfloor)(⌊
//	2
//	n
//	​
//	⌋, ⌊
//	2
//	n
//	​
//	⌋)，该点会被计算两次。所以当 nnn 为奇数的时候，需要减掉交点处的值。
//	class Solution {
//	public:
//		int diagonalSum(vector<vector<int>>& mat) {
//			int n = mat.size(), sum = 0, mid = n / 2;
//			for (int i = 0; i < n; ++i) {
//				sum += mat[i][i] + mat[i][n - 1 - i];
//			}
//			return sum - mat[mid][mid] * (n & 1);
//		}
//};
//复杂度分析
//
//时间复杂度：O(n)O(n)O(n)，其中 nnn 是矩阵 mat\textit{ mat }mat 的行数。
//空间复杂度：O(1)O(1)O(1)。