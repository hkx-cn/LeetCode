// 704. 二分查找
// 给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target  ，写一个函数搜索 nums 中的 target，如果目标值存在返回下标，否则返回 - 1。
//
// 示例 1:
// 输入: nums = [-1, 0, 3, 5, 9, 12], target = 9
// 输出 : 4
// 解释 : 9 出现在 nums 中并且下标为 4
// 示例 2 :
//  输入 : nums = [-1, 0, 3, 5, 9, 12], target = 2
//  输出 : -1
//  解释 : 2 不存在 nums 中因此返回 - 1

// 提示：
// 你可以假设 nums 中的所有元素是不重复的。
// n 将在[1, 10000]之间。
// nums 的每个元素都将在[-9999, 9999]之间。
#include "LeetCode704.hpp"
int Solution::search(vector<int> &nums, int target)
{
    int left = 0, right = nums.size() - 1, mid = -1, ans = -1;
    // 二分查找
    while (left <= right)
    {
        // 值范围[-1,nums.size()-1]
        // -> 返回右指针，右指针 = 中指针 - 1，可达到-1下标
        // -> 二分下标指向右侧
        // -> 跳出循环left <= right，此时left = right
        // 1、right - 1
        // 2、left = mid = right
        // nums[mid]和target
        // >:mid右侧舍弃 right = mid - 1;
        // <:mid左侧舍弃 left = mid;
        // =:此时left = mid或right = mid - 1;

        // 值范围[-1,nums.size()-1]
        // 循环跳出 left <= right,nums[mid] == target时返回mid
        // nums[mid] < target left = mid + 1
        // nums[mid] > target right = mid - 1
        mid = left + (right - left) / 2;
        if (nums[mid] < target)
            left = mid + 1;
        else if (nums[mid] > target)
            right = mid - 1;
        else
            return mid;
    }
    return ans;
}
// int Solution::search(vector<int>& nums, int target) {
// 	int left = 0, right = nums.size() - 1;
// 	while (left <= right)
// 	{
// 		if (nums[(left + right) / 2] == target)
// 		{
// 			return (left + right) / 2;
// 		}
// 		else if (nums[(left + right) / 2] > target)
// 		{
// 			right = (left + right) / 2 - 1;
// 		}
// 		else if (nums[(left + right) / 2] < target)
// 		{
// 			left = (left + right) / 2 + 1;
// 		}
// 	}
// 	return -1;
// };
// 方法一：二分查找
// 在升序数组 nums 中寻找目标值 target，对于特定下标 i，比较 nums[i] 和 target 的大小：
// 如果 nums[i] = target，则下标 i 即为要寻找的下标；
// 如果 nums[i] > target，则 target 只可能在下标 i 的左侧；
// 如果 nums[i] < target，则 target 只可能在下标 i 的右侧。
// 基于上述事实，可以在有序数组中使用二分查找寻找目标值。
// 二分查找的做法是，定义查找的范围[left, right]，初始查找范围是整个数组。每次取查找范围的中点 mid，比较 nums[mid] 和 target 的大小，如果相等则 mid 即为要寻找的下标，如果不相等则根据 nums[mid] 和 target 的大小关系将查找范围缩小一半。
// 由于每次查找都会将查找范围缩小一半，因此二分查找的时间复杂度是 O(log⁡n)，其中 n 是数组的长度。
// 二分查找的条件是查找范围不为空，即 left≤right。如果 target 在数组中，二分查找可以保证找到 target，返回 target 在数组中的下标。如果 target 不在数组中，则当 left > right 时结束查找，返回 −1 。
// class Solution {
// public:
//	int search(vector<int>& nums, int target) {
//		int left = 0, right = nums.size() - 1;
//		while (left <= right) {
//			int mid = (right - left) / 2 + left;
//			int num = nums[mid];
//			if (num == target) {
//				return mid;
//			}
//			else if (num > target) {
//				right = mid - 1;
//			}
//			else {
//				left = mid + 1;
//			}
//		}
//		return -1;
//	}
// };
// 复杂度分析
// 时间复杂度：O(log⁡n)，其中 n 是数组的长度。
// 空间复杂度：O(1)。