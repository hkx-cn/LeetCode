//1470. 重新排列数组
//给你一个数组 nums ，数组中有 2n 个元素，按[x1, x2, ..., xn, y1, y2, ..., yn] 的格式排列。
//
//请你将数组按[x1, y1, x2, y2, ..., xn, yn] 格式重新排列，返回重排后的数组。
//
//
//
//示例 1：
//
//输入：nums = [2, 5, 1, 3, 4, 7], n = 3
//输出：[2, 3, 5, 4, 1, 7]
//解释：由于 x1 = 2, x2 = 5, x3 = 1, y1 = 3, y2 = 4, y3 = 7 ，所以答案为[2, 3, 5, 4, 1, 7]
//示例 2：
//
//输入：nums = [1, 2, 3, 4, 4, 3, 2, 1], n = 4
//输出：[1, 4, 2, 3, 3, 2, 4, 1]
//示例 3：
//
//输入：nums = [1, 1, 2, 2], n = 2
//输出：[1, 2, 1, 2]
//
//
//提示：
//
//1 <= n <= 500
//nums.length == 2n
//1 <= nums[i] <= 10 ^ 3
#include"LeetCode1470.h"
vector<int> Solution::shuffle(vector<int>& nums, int n) {
	vector<int> result;
	for (size_t i = 0; i < n; i++)
	{
		result.push_back(nums[i]);
		result.push_back(nums[i + n]);
	}
	return result;
};
//方法一：一次遍历
//用 ans\textit{ ans }ans 表示结果数组，数组 nums\textit{ nums }nums 和 ans\textit{ ans }ans 的长度都是 2n2n2n。对于 0≤i < n0 \le i < n0≤i < n，重新排列数组的规则如下：
//
//	nums[i]\textit{ nums }[i]nums[i] 填到 ans[2×i]\textit{ ans }[2 \times i]ans[2×i]；
//
//	nums[i + n]\textit{ nums }[i + n]nums[i + n] 填到 ans[2×i + 1]\textit{ ans }[2 \times i + 1]ans[2×i + 1]。
//
//	根据该规则将原数组 nums\textit{ nums }nums 中的元素依次填入结果数组 ans\textit{ ans }ans 中，即可得到重新排列后的数组。
//class Solution {
//public:
//	vector<int> shuffle(vector<int>& nums, int n) {
//		vector<int> ans(2 * n);
//		for (int i = 0; i < n; i++) {
//			ans[2 * i] = nums[i];
//			ans[2 * i + 1] = nums[i + n];
//		}
//		return ans;
//	}
//};
//复杂度分析
//
//时间复杂度：O(n)O(n)O(n)，其中 nnn 是给定的参数。需要遍历长度为 2n2n2n 的数组 nums\textit{ nums }nums 一次将数组重新排列，每个元素重新排列的时间是 O(1)O(1)O(1)。
//
//空间复杂度：O(1)O(1)O(1)。注意返回值不计入空间复杂度。