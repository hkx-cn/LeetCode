// 283. 移动零
// 给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。

// 请注意 ，必须在不复制数组的情况下原地对数组进行操作。
// 示例 1:
// 输入: nums = [0,1,0,3,12]
// 输出: [1,3,12,0,0]
// 示例 2:
// 输入: nums = [0]
// 输出: [0]

// 提示:
// 1 <= nums.length <= 10^4
// -2^31 <= nums[i] <= 2^31 - 1
#include "LeetCode283.hpp"

void Solution::moveZeroes(vector<int> &nums)
{
	int x = 0, y = 0;
	while (x < nums.size() && y < nums.size())
	{
		if (nums[x] == 0)
		{
			y = y < x ? x : y;
			if (nums[y] != 0)
				swap(nums[x], nums[y]);
			else
				y++;
		}
		else
			x++;
	}
}

void Solution::moveZeroes(vector<int> &nums)
{
	for (size_t i = 0; i < nums.size(); i++)
	{
		if (nums[i] == 0)
		{
			for (size_t j = i + 1; j < nums.size(); j++)
			{
				if (nums[j] != 0)
				{
					swap(nums[i], nums[j]);
					break;
				}
			}
		}
	}
}

// void Solution::moveZeroes(vector<int>& nums) {
// 	if (nums.size() == 1)
// 	{
// 		return;
// 	}
// 	int idxZero = 0, idxNoZero = 0, num = 0;
// 	for (size_t i = 0; i < nums.size(); i++)
// 	{
// 		if (nums[i] != 0) {
// 			idxNoZero = i;
// 		}
// 		else if (nums[i] == 0 & idxZero == -1)
// 		{
// 			idxZero = i;
// 		}
// 		if (idxNoZero > idxZero)
// 		{
// 			nums[idxZero] = nums[idxNoZero];
// 			nums[idxNoZero] = 0;
// 			for (size_t i = idxZero; i < nums.size(); i++)
// 			{
// 				if (nums[i] == 0)
// 				{
// 					idxZero = i; break;
// 				}
// 			}
// 		}
// 	}
// 	return;
// };
// 方法一：双指针
// 思路及解法
// 使用双指针，左指针指向当前已经处理好的序列的尾部，右指针指向待处理序列的头部。
// 右指针不断向右移动，每次右指针指向非零数，则将左右指针对应的数交换，同时左指针右移。
// 注意到以下性质：
// 左指针左边均为非零数；
// 右指针左边直到左指针处均为零。
// 因此每次交换，都是将左指针的零与右指针的非零数交换，且非零数的相对顺序并未改变。
// class Solution {
// public:
//     void moveZeroes(vector<int>& nums) {
//         int n = nums.size(), left = 0, right = 0;
//         while (right < n) {
//             if (nums[right]) {
//                 swap(nums[left], nums[right]);
//                 left++;
//             }
//             right++;
//         }
//     }
// };
// 复杂度分析
// 时间复杂度：O(n)，其中 n 为序列长度。每个位置至多被遍历两次。
// 空间复杂度：O(1)。只需要常数的空间存放若干变量。