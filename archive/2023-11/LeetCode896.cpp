// 896. 单调数列
// 如果数组是单调递增或单调递减的，那么它是 单调 的。
// 如果对于所有 i <= j，nums[i] <= nums[j]，那么数组 nums 是单调递增的。 如果对于所有 i <= j，nums[i]> = nums[j]，那么数组 nums 是单调递减的。
// 当给定的数组 nums 是单调数组时返回 true，否则返回 false。


// 示例 1： 
// 输入：nums = [1,2,2,3]
// 输出：true 
// 示例 2： 
// 输入：nums = [6,5,4,4]
// 输出：true 
// 示例 3： 
// 输入：nums = [1,3,2]
// 输出：false
 

// 提示： 
// 1 <= nums.length <= 10^5
// -10^5 <= nums[i] <= 10^5
#include "LeetCode896.hpp"
bool Solution::isMonotonic(vector<int>& nums) {
	vector<int> v1, v2;
	v1 = nums;
	v2 = nums;
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	reverse(v2.begin(), v2.end()); 
	if (nums == v1 || nums == v2)
	{
		return true;
	}
	return false;
};
// 方法一：两次遍历
// 遍历两次数组，分别判断其是否为单调递增或单调递减。
// class Solution {
// public:
//     bool isMonotonic(vector<int>& nums) {
//         return is_sorted(nums.begin(), nums.end()) || is_sorted(nums.rbegin(), nums.rend());
//     }
// };
// 复杂度分析
// 时间复杂度：O(n)，其中 n 是数组 nums 的长度。
// 空间复杂度：O(1)。

// 方法二：一次遍历
// 遍历数组 nums，若既遇到了 nums[i]>nums[i+1] 又遇到了 nums[i′]<nums[i′+1]，则说明 nums 既不是单调递增的，也不是单调递减的。
// class Solution {
// public:
//     bool isMonotonic(vector<int>& nums) {
//         bool inc = true, dec = true;
//         int n = nums.size();
//         for (int i = 0; i < n - 1; ++i) {
//             if (nums[i] > nums[i + 1]) {
//                 inc = false;
//             }
//             if (nums[i] < nums[i + 1]) {
//                 dec = false;
//             }
//         }
//         return inc || dec;
//     }
// };
// 复杂度分析
// 时间复杂度：O(n)，其中 n 是数组 nums 的长度。
// 空间复杂度：O(1)。 