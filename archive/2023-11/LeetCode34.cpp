// 34. 在排序数组中查找元素的第一个和最后一个位置
// 给你一个按照非递减顺序排列的整数数组 nums，和一个目标值 target。请你找出给定目标值在数组中的开始位置和结束位置。
// 如果数组中不存在目标值 target，返回[-1, -1]。
// 你必须设计并实现时间复杂度为 O(log n) 的算法解决此问题。
//
// 示例 1：
// 输入：nums = [5, 7, 7, 8, 8, 10], target = 8
// 输出：[3, 4]
// 示例 2：
// 输入：nums = [5, 7, 7, 8, 8, 10], target = 6
// 输出：[-1, -1]
// 示例 3：
// 输入：nums = [], target = 0
// 输出：[-1, -1]
//
// 提示：
// 0 <= nums.length <= 10^5
//- 10^9 <= nums[i] <= 10^9
// nums 是一个非递减数组
//- 10^9 <= target <= 10^9
#include "LeetCode34.hpp"
vector<int> Solution::searchRange(vector<int> &nums, int target)
{
	vector<int> result = {-1, -1};
	int left = 0, right = nums.size() - 1, mid = -1;
	while (left < right)
	{
		mid = left + (right - left) / 2;
		if (nums[mid] < target)
			left = mid + 1;
		else if (nums[mid] > target)
			right = mid - 1;
		else
		{
			left = mid;
			break;
		}
	}
	if (nums[left] != target)
	{
		return result;
	}
	else
	{
		right = left;
		while (left >= 0)
		{
			if (nums[left] )
			{
				
			}
		}
		while (right < nums.size())
		{
			
		}
	}
}

// vector<int> Solution::searchRange(vector<int>& nums, int target) {
// 	vector<int> result{ -1,-1 };
// 	int left = 0, right = nums.size() - 1, mid = -1;
// 	while (left <= right)
// 	{
// 		mid = (left + right) / 2;
// 		if (nums[mid] == target)
// 		{
// 			break;
// 		}
// 		else if (nums[mid] > target)
// 		{
// 			right = mid - 1;
// 		}
// 		else if (nums[mid] < target)
// 		{
// 			left = mid + 1;
// 		}
// 	}
// 	if (left > right)
// 	{
// 		return result;
// 	}
// 	else
// 	{
// 		left = mid;
// 		right = mid;
// 		while (left >= 0)
// 		{
// 			if (nums[left] == target)
// 			{
// 				left--;
// 			}
// 			else
// 			{
// 				break;
// 			}
// 		}
// 		while (right <= nums.size() - 1)
// 		{
// 			if (nums[right] == target)
// 			{
// 				right++;
// 			}
// 			else
// 			{
// 				break;
// 			}
// 		}
// 		result = { left - 1,right + 1 };
// 	}
// 	return result;
// };
// 方法一：二分查找
// 直观的思路肯定是从前往后遍历一遍。用两个变量记录第一次和最后一次遇见 target 的下标，但这个方法的时间复杂度为 O(n)，没有利用到数组升序排列的条件。
// 由于数组已经排序，因此整个数组是单调递增的，我们可以利用二分法来加速查找的过程。
// 考虑 target 开始和结束位置，其实我们要找的就是数组中「第一个等于 target 的位置」（记为 leftIdx）和「第一个大于 target 的位置减一」（记为 rightIdx）。
// 二分查找中，寻找 leftIdx 即为在数组中寻找第一个大于等于 target 的下标，寻找 rightIdx 即为在数组中寻找第一个大于 target 的下标，然后将下标减一。两者的判断条件不同，为了代码的复用，我们定义 binarySearch(nums, target, lower) 表示在 nums 数组中二分查找 target 的位置，如果 lower 为 true，则查找第一个大于等于 target 的下标，否则查找第一个大于 target 的下标。
// 最后，因为 target 可能不存在数组中，因此我们需要重新校验我们得到的两个下标 leftIdx 和 rightIdx，看是否符合条件，如果符合条件就返回[leftIdx, rightIdx]，不符合就返回[−1, −1]。
// class Solution {
// public:
//	int binarySearch(vector<int>& nums, int target, bool lower) {
//		int left = 0, right = (int)nums.size() - 1, ans = (int)nums.size();
//		while (left <= right) {
//			int mid = (left + right) / 2;
//			if (nums[mid] > target || (lower && nums[mid] >= target)) {
//				right = mid - 1;
//				ans = mid;
//			}
//			else {
//				left = mid + 1;
//			}
//		}
//		return ans;
//	}
//
//	vector<int> searchRange(vector<int>& nums, int target) {
//		int leftIdx = binarySearch(nums, target, true);
//		int rightIdx = binarySearch(nums, target, false) - 1;
//		if (leftIdx <= rightIdx && rightIdx < nums.size() && nums[leftIdx] == target && nums[rightIdx] == target) {
//			return vector<int>{leftIdx, rightIdx};
//		}
//		return vector<int>{-1, -1};
//	}
//};
// 复杂度分析
// 时间复杂度：O(log⁡n) ，其中 n 为数组的长度。二分查找的时间复杂度为 O(log⁡n)，一共会执行两次，因此总时间复杂度为 O(log⁡n)。
// 空间复杂度：O(1) 。只需要常数空间存放若干变量。