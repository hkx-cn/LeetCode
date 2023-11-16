//1534. 统计好三元组
//给你一个整数数组 arr ，以及 a、b 、c 三个整数。请你统计其中好三元组的数量。
//
//如果三元组(arr[i], arr[j], arr[k]) 满足下列全部条件，则认为它是一个 好三元组 。
//
//0 <= i < j < k < arr.length
//	| arr[i] - arr[j]| <= a
//	| arr[j] - arr[k]| <= b
//	| arr[i] - arr[k]| <= c
//	其中 | x | 表示 x 的绝对值。
//
//	返回 好三元组的数量 。
//
//
//
//	示例 1：
//
//	输入：arr = [3, 0, 1, 1, 9, 7], a = 7, b = 2, c = 3
//	输出：4
//	解释：一共有 4 个好三元组：[(3, 0, 1), (3, 0, 1), (3, 1, 1), (0, 1, 1)] 。
//	示例 2：
//
//	输入：arr = [1, 1, 2, 2, 3], a = 0, b = 0, c = 1
//	输出：0
//	解释：不存在满足所有条件的三元组。
//
//
//	提示：
//
//	3 <= arr.length <= 100
//	0 <= arr[i] <= 1000
//	0 <= a, b, c <= 1000
#include "LeetCode1534.h"
int Solution::countGoodTriplets(vector<int>& arr, int a, int b, int c) {
	int result = 0;
	for (size_t i = 0; i < arr.size(); i++)
	{
		for (size_t j = i + 1; j < arr.size(); j++)
		{
			for (size_t k = j + 1; k < arr.size(); k++)
			{
				if (abs(arr[i] - arr[j]) <= a && abs(arr[j] - arr[k]) <= b && abs(arr[i] - arr[k]) <= c)
				{
					result++;
				}
			}
		}
	}
	return result;
};
//方法一：枚举
//思路与算法
//
//用 O(n3)O(n ^ 3)O(n
//	3
//) 的循环依次枚举所有的(i, j, k)(i, j, k)(i, j, k)，这里 0≤i < j < k < arr.length0 \leq i < j < k < {\rm arr.length}0≤i < j < k < arr.length，对于每组(i, j, k)(i, j, k)(i, j, k)，判断 arr[i]{ \rm arr }[i]arr[i]、arr[j]{ \rm arr }[j]arr[j]、arr[k]{ \rm arr }[k]arr[k] 是否满足条件。
//
//	最终统计出所有满足条件的三元组的数量。
//	class Solution {
//	public:
//		int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
//			int n = arr.size(), cnt = 0;
//			for (int i = 0; i < n; ++i) {
//				for (int j = i + 1; j < n; ++j) {
//					for (int k = j + 1; k < n; ++k) {
//						if (abs(arr[i] - arr[j]) <= a && abs(arr[j] - arr[k]) <= b && abs(arr[i] - arr[k]) <= c) {
//							++cnt;
//						}
//					}
//				}
//			}
//			return cnt;
//		}
//};
//复杂度分析
//
//时间复杂度：O(n3)O(n ^ 3)O(n
//	3
//)，其中 nnn 是数组 arr\textit{ arr }arr 的长度。
//
//空间复杂度：O(1)O(1)O(1)。
//
//方法二：枚举优化
//思路与算法
//
//我们考虑 O(n2)O(n ^ 2)O(n
//	2
//) 枚举满足 ∣arr[j]−arr[k]∣≤b | \rm arr[j] - \rm arr[k] | \le b∣arr[j]−arr[k]∣≤b 的二元组(j, k)(j, k)(j, k)，统计这个二元组下有多少 iii 满足条件。由题目已知 iii 的限制条件为 ∣arr[i]−arr[j]∣≤a  && ∣arr[i]−arr[k]∣≤c | \rm arr[i] - \rm arr[j] | \le a \ \ & \ & \ | \rm arr[i] - \rm arr[k] | \le c∣arr[i]−arr[j]∣≤a  && ∣arr[i]−arr[k]∣≤c，我们可以拆开绝对值，得到符合条件的值一定是[arr[j]−a, arr[j] + a][\rm arr[j] - a, \rm arr[j] + a][arr[j]−a, arr[j] + a] 和[arr[k]−c, arr[k] + c][\rm arr[k] - c, \rm arr[k] + c][arr[k]−c, arr[k] + c] 两个区间的交集，我们记为[l, r][l, r][l, r]。因此，在枚举(j, k)(j, k)(j, k) 这个二元组的时候，我们只需要快速统计出满足 i < ji < ji < j 且 arr[i]\rm arr[i]arr[i] 的值域范围在[l, r][l, r][l, r] 的 iii 的个数即可。
//
//	很容易想到维护一个 arr[i]\rm arr[i]arr[i] 频次数组的前缀和 sum\rm sumsum，对于一个二元组(j, k)(j, k)(j, k)，我们可以 O(1)O(1)O(1) 得到答案为 sum[r]−sum[l−1]\rm sum[r] - \rm sum[l - 1]sum[r]−sum[l−1]。考虑怎么维护保证当前频次数组存的数的下标符合 i < ji < ji < j 的限制，我们只要从小到大枚举 jjj，每次 jjj 移动指针加一的时候，将 arr[j]\rm arr[j]arr[j] 的值更新到 sum\rm sumsum 数组中即可，这样能保证枚举到 jjj 的时候 sum\rm sumsum 数组里存的值的下标满足限制。
//
//	「将 arr[j]\rm arr[j]arr[j] 的值更新到 sum\rm sumsum 数组中」这个操作在本方法中是暴力更新，因为数组的值域上限很小，有能力的读者可以考虑怎么在进一步优化这一部分的复杂度，可以从离散化或者树状数组的角度考虑，这里不再赘述。
//
//	class Solution {
//	public:
//		int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
//			int ans = 0, n = arr.size();
//			vector<int> sum(1001, 0);
//			for (int j = 0; j < n; ++j) {
//				for (int k = j + 1; k < n; ++k) {
//					if (abs(arr[j] - arr[k]) <= b) {
//						int lj = arr[j] - a, rj = arr[j] + a;
//						int lk = arr[k] - c, rk = arr[k] + c;
//						int l = max(0, max(lj, lk)), r = min(1000, min(rj, rk));
//						if (l <= r) {
//							if (l == 0) {
//								ans += sum[r];
//							}
//							else {
//								ans += sum[r] - sum[l - 1];
//							}
//						}
//					}
//				}
//				for (int k = arr[j]; k <= 1000; ++k) {
//					++sum[k];
//				}
//			}
//			return ans;
//		}
//};
//复杂度分析
//
//时间复杂度：O(n2 + nS)O(n ^ 2 + nS)O(n
//	2
//	+ nS)，其中 nnn 是数组 arr\textit{ arr }arr 的长度，SSS 为数组的值域上限，这里为 100010001000。
//
//	空间复杂度：O(S)O(S)O(S)。我们需要 O(S)O(S)O(S) 的空间维护 arr[i]\rm arr[i]arr[i] 频次数组的前缀和。