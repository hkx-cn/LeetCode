// 2765. 最长交替子数组
// 给你一个下标从 0 开始的整数数组 nums 。如果 nums 中长度为 m 的子数组 s 满足以下条件，我们称它是一个 交替子数组 ：
// m 大于 1 。
// s1 = s0 + 1 。
// 下标从 0 开始的子数组 s 与数组 [s0, s1, s0, s1,...,s(m-1) % 2] 一样。也就是说，s1 - s0 = 1 ，s2 - s1 = -1 ，s3 - s2 = 1 ，s4 - s3 = -1 ，以此类推，直到 s[m - 1] - s[m - 2] = (-1)m 。
// 请你返回 nums 中所有 交替 子数组中，最长的长度，如果不存在交替子数组，请你返回 -1 。
// 子数组是一个数组中一段连续 非空 的元素序列。

// 示例 1：
// 输入：nums = [2,3,4,3,4]
// 输出：4
// 解释：交替子数组有 [3,4] ，[3,4,3] 和 [3,4,3,4] 。最长的子数组为 [3,4,3,4] ，长度为4 。
// 示例 2：
// 输入：nums = [4,5,6]
// 输出：2
// 解释：[4,5] 和 [5,6] 是仅有的两个交替子数组。它们长度都为 2 。

// 提示：
// 2 <= nums.length <= 100
// 1 <= nums[i] <= 10^4
#include "LeetCode2765.hpp"
int Solution::alternatingSubarray(vector<int> &nums)
{
    int max = -1, dif = 1, len = 1;
    for (int i = 0; i < nums.size() - 1; i++)
    {
        if (nums[i + 1] - nums[i] == dif)
        {
            len++;
            dif *= -1;
            max = max > len ? max : len;
        }
        else
        {
            len = 1;
            dif = 1;
            if (nums[i + 1] - nums[i] == dif)
            {
                len++;
                dif *= -1;
                max = max > len ? max : len;
            }
        }
    }
    return max;
}
// 方法一：双层循环
// 思路
// 题目要求返回所有交替子数组的最长长度，我们可以利用双层循环。外层的循环遍历数组每一个的下标，使其作为交替子数组的第一个下标 firstIndex 。内层循环则从 firstIndex 往后遍历，判断接下来的元素是否满足交替子数组的条件。是的话则更新最长长度，不满足的的话则跳出内层循环，继续外层循环。外层循环遍历完后，返回最长长度。
// class Solution {
// public:
//     int alternatingSubarray(vector<int>& nums) {
//         int res = -1;
//         int n = nums.size();
//         for (int firstIndex = 0; firstIndex < n; firstIndex++) {
//             for (int i = firstIndex + 1; i < n; i++) {
//                 int length = i - firstIndex + 1;
//                 if (nums[i] - nums[firstIndex] == (length - 1) % 2) {
//                     res = max(res, length);
//                 } else {
//                     break;
//                 }
//             }
//         }
//         return res;
//     }
// };
// 复杂度分析
// 时间复杂度：O(n^2)。其中 n 是数组 nums 的长度，我们需要双层循环。
// 空间复杂度：O(1)。

// 方法二：单层循环
// 思路
// 方法一比较直观，但是复杂度比较高。当内层循环判断出当前下标 i 打破了交替子数组的条件后，我们其实不需要回到外层循环的下标 firstIndex，因为通过内层循环，我们已经知道子数组 nums[firstIndex,…,i−1] 是满足交替子数组的条件的。分析以下情况：
// 如果这个子数组的长度大于等于 3，那么我们不需要从 firstIndex+1 开始外层循环，因为子数组 nums[firstIndex+1,firstIndex+2] 必不满足交替子数组。
// 如果这个子数组的长度大于等于 4，那么我们不需要从 firstIndex+2 开始外层循环，因为子数组 nums[firstIndex+2,…,i−1] 虽然满足交替子数组，但是这个交替数组会在 i 被破环，并且长度小于 nums[firstIndex,…,i−1]。
// 通过这样分析，我们可以得出结论，外层的循环可以从 i−1 继续。而这样的话，我们可以丢弃外层循环，在内层循环多做一个 firstIndex 是否可以为 i−1 的判断，而只保留内层循环。如果可以，则将 firstIndex 更新为 i−1，并更新最长长度。如果不可以，则将 firstIndex 更新为 i。两种情况下，内层循环下一个遍历的下标都为 i+1，这样，我们就只用循环一层，即可以在循环结束后返回结果。
// class Solution {
// public:
//     int alternatingSubarray(vector<int>& nums) {
//         int res = -1;
//         int n = nums.size();
//         int firstIndex = 0;
//         for (int i = 1; i < n; i++) {
//             int length = i - firstIndex + 1;
//             if (nums[i] - nums[firstIndex] == (length - 1) % 2) {
//                 res = max(res, length);
//             } else {
//                 if (nums[i] - nums[i - 1] == 1) {
//                     firstIndex = i - 1;
//                     res = max(res, 2);
//                 } else {
//                     firstIndex = i;
//                 }
//             }
//         }
//         return res;
//     }
// };
// 复杂度分析
// 时间复杂度：O(n)。其中 n 是数组 nums 的长度，我们只需要单层循环。
// 空间复杂度：O(1)。