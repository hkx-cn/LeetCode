//1502. 判断能否形成等差数列
//给你一个数字数组 arr 。
//
//如果一个数列中，任意相邻两项的差总等于同一个常数，那么这个数列就称为 等差数列 。
//
//如果可以重新排列数组形成等差数列，请返回 true ；否则，返回 false 。
//
//
//
//示例 1： 
//输入：arr = [3, 5, 1]
//输出：true
//解释：对数组重新排序得到[1, 3, 5] 或者[5, 3, 1] ，任意相邻两项的差分别为 2 或 - 2 ，可以形成等差数列。
//
//示例 2： 
//输入：arr = [1, 2, 4]
//输出：false
//解释：无法通过重新排序得到等差数列。
//
//
//提示：
//
//2 <= arr.length <= 1000
//- 10 ^ 6 <= arr[i] <= 10 ^ 6
#include "LeetCode1502.h"
bool Solution::canMakeArithmeticProgression(vector<int>& arr) {
	sort(arr.begin(), arr.end());
	int dif = arr[1] - arr[0];
	if (arr.size() == 2)
	{
		return true;
	}
	for (size_t i = 2; i < arr.size(); i++)
	{
		if (arr[i] - arr[i - 1] != dif)
		{
			return false;
		}
	}
	return true;
};
//方法一：模拟
//思路与算法
//
//首先我们对原序列排序，假设排序之后序列为{ a0,a1,⋯an }，如果对 i∈[1, n−1] 中的每个数都有 ai×2 = ai−1 + ai+1 成立，那么这个数列就是等差数列。
//class Solution {
//public:
//	bool canMakeArithmeticProgression(vector<int>& arr) {
//		sort(arr.begin(), arr.end());
//		for (int i = 1; i < arr.size() - 1; ++i) {
//			if (arr[i] * 2 != arr[i - 1] + arr[i + 1]) {
//				return false;
//			}
//		}
//		return true;
//	}
//};
//复杂度分析
//
//时间复杂度：O(nlog⁡n)。排序的时间代价为 O(nlog⁡n)，遍历序列的时间代价是 O(n)，故渐进时间复杂度为 O(nlog⁡n + n) = O(nlog⁡n)。
//空间复杂度：O(log⁡n)。快速排序中使用的栈空间期望是 O(log⁡n)。