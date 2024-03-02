// 154. 寻找旋转排序数组中的最小值 II
// 已知一个长度为 n 的数组，预先按照升序排列，经由 1 到 n 次 旋转 后，得到输入数组。例如，原数组 nums = [0,1,4,4,5,6,7] 在变化后可能得到：
// 若旋转 4 次，则可以得到 [4,5,6,7,0,1,4]
// 若旋转 7 次，则可以得到 [0,1,4,4,5,6,7]
// 注意，数组 [a[0], a[1], a[2], ..., a[n-1]] 旋转一次 的结果为数组 [a[n-1], a[0], a[1], a[2], ..., a[n-2]] 。
// 给你一个可能存在 重复 元素值的数组 nums ，它原来是一个升序排列的数组，并按上述情形进行了多次旋转。请你找出并返回数组中的 最小元素 。
// 你必须尽可能减少整个过程的操作步骤。

// 示例 1：
// 输入：nums = [1,3,5]
// 输出：1
// 示例 2：
// 输入：nums = [2,2,2,0,1]
// 输出：0

// 提示：
// n == nums.length
// 1 <= n <= 5000
// -5000 <= nums[i] <= 5000
// nums 原来是一个升序排序的数组，并进行了 1 至 n 次旋转

// 进阶：这道题与 寻找旋转排序数组中的最小值 类似，但 nums 可能包含重复元素。允许重复会影响算法的时间复杂度吗？会如何影响，为什么？
#include "LeetCode154.hpp"
int Solution::findMin(vector<int> &nums)
{
    int left = 0, right = nums.size() - 1, mid = -1;
    while (left < right)
    {
        mid = left + (right - left) / 2;
        if (nums[mid] < nums[right])
        {
            right = mid;
        }
        else if (nums[mid] > nums[right])
        {
            left = mid + 1;
        }
        else if (nums[mid] == nums[right])
        {
            right--;
        }
    }
    return nums[left];
}
// int Solution::findMin(vector<int> &nums)
// {
//     int left = 0, right = nums.size() - 1, mid = -1, min = 50000;
//     // 二分查找，结果范围[0,nums.size()-1]
//     while (left <= right)
//     {
//         mid = left + (right - left) / 2;
//         if (nums[mid] > nums[right])
//         {
//             min = min < nums[left] ? min : nums[left];
//             left = mid + 1;
//         }
//         else if (nums[left] > nums[mid])
//         {
//             min = min < nums[right] ? min : nums[right];
//             right = mid;
//         }
//         else if (nums[mid] < nums[right])
//         {
//             min = min < nums[mid] ? min : nums[mid];
//             right = mid - 1;
//         }
//         else if (nums[left] < nums[mid])
//         {
//             min = min < nums[left] ? min : nums[left];
//             left = mid + 1;
//         }
//         else if (nums[mid] == nums[right])
//         {
//             min = min < nums[right] ? min : nums[right];
//             right--;
//         }
//         else if (nums[left] == nums[mid])
//         {
//             min = min < nums[left] ? min : nums[left];
//             left++;
//         }
//     }
//     return min;
// }
// int Solution::findMin(vector<int> &nums)
// {
//     int left = 0, right = nums.size() - 1, mid = -1;
//     return Solution::equalFindMin(nums, 0, nums.size() - 1);
//     // 二分查找，每次将区间对半切分
//     // nums[left] < nums[mid] < nums[right]，此时最小元素在[nums[left],nums[mid])
//     // nums[left] < nums[mid] = nums[right]，此时最小元素在[nums[left],nums[mid])
//     // nums[left] < nums[mid] > nums[right]，此时最小元素在(nums[mid],nums[right]]
//     // nums[left] = nums[mid] < nums[right]，此时最小元素是[nums[left]
//     // nums[left] = nums[mid] = nums[right]，此时最小元素在[nums[left],nums[mid]]和[nums[mid],nums[right]]任意区间内都有可能
//     // nums[left] = nums[mid] > nums[right]，此时最小元素在(nums[mid],nums[right]]
//     // nums[left] > nums[mid] < nums[right]，此时最小元素在[nums[left],nums[mid]]
//     // nums[left] > nums[mid] = nums[right]，此时最小元素在[nums[left],nums[mid]]
//     // nums[left] > nums[mid] > nums[right]，不存在这种情况

//     // nums[left] < nums[mid] < nums[right]，此时最小元素在[nums[left],nums[mid])
//     // nums[left] > nums[mid] < nums[right]，此时最小元素在[nums[left],nums[mid]]
//     // nums[left] = nums[mid] < nums[right]，此时最小元素是[nums[left]

//     // nums[left] < nums[mid] > nums[right]，此时最小元素在(nums[mid],nums[right]]
//     // nums[left] = nums[mid] > nums[right]，此时最小元素在(nums[mid],nums[right]]

//     // nums[left] < nums[mid] = nums[right]，此时最小元素在[nums[left],nums[mid])
//     // nums[left] > nums[mid] = nums[right]，此时最小元素在[nums[left],nums[mid]]
//     // nums[left] = nums[mid] = nums[right]，此时最小元素在[nums[left],nums[mid]]和[nums[mid],nums[right]]任意区间内都有可能

//     // nums[left] > nums[mid] > nums[right]，不存在这种情况
//     // 如果右半区间是升序排列，舍弃右半区间（左端点保留）
//     // 否则左半区间舍弃（右端点不保留）
//     // 如果左右端点相等的区间需单独计算最小元素
//     // while (left < right)
//     // {
//     //     mid = left + (right - left) / 2;
//     //     if (nums[mid] < nums[right])
//     //     {
//     //         if (nums[left] == nums[mid])
//     //             return nums[left];
//     //         else
//     //             right = mid;
//     //     }
//     //     else if (nums[mid] > nums[right])
//     //     {
//     //         if (nums[left] == nums[mid])
//     //             return nums[right];
//     //         else
//     //             left = mid + 1;
//     //     }
//     //     else if (nums[left] != nums[mid])
//     //         right = mid;
//     //     else if (nums[left] == nums[mid])
//     // }
//     // return nums[left];
// }
// int Solution::equalFindMin(vector<int> &nums, int left, int right)
// {
//     int mid = -1;
//     while (left < right)
//     {
//         mid = left + (right - left) / 2;
//         if (left == mid || mid == right)
//             return nums[left] < nums[right] ? nums[left] : nums[right];
//         else if (nums[left] == nums[mid] && nums[mid] == nums[right])
//         {
//             int result1 = equalFindMin(nums, left, mid);
//             int result2 = equalFindMin(nums, mid, right);
//             return result1 < result2 ? result1 : result2;
//         }
//         else if (nums[mid] < nums[right])
//         {
//             if (nums[left] == nums[mid])
//                 return nums[left];
//             else
//                 right = mid;
//         }
//         else if (nums[mid] > nums[right])
//             left = mid + 1;
//         else if (nums[left] != nums[mid])
//             right = mid;
//     }
//     return nums[left];
// };
// 前言
// 本题是「153. 寻找旋转排序数组中的最小值」的延伸。读者可以先尝试第 153 题，体会在旋转数组中进行二分查找的思路，再来尝试解决本题。
// 方法一：二分查找
// 思路与算法
// 一个包含重复元素的升序数组在经过旋转之后，可以得到下面可视化的折线图：
// 其中横轴表示数组元素的下标，纵轴表示数组元素的值。图中标出了最小值的位置，是我们需要查找的目标。
// 我们考虑数组中的最后一个元素 x：在最小值右侧的元素，它们的值一定都小于等于 x；而在最小值左侧的元素，它们的值一定都大于等于 x。因此，我们可以根据这一条性质，通过二分查找的方法找出最小值
// 在二分查找的每一步中，左边界为 low，右边界为 high，区间的中点为 pivot，最小值就在该区间内。我们将中轴元素 nums[pivot] 与右边界元素 nums[high] 进行比较，可能会有以下的三种情况：

// 第一种情况是 nums[pivot]<nums[high]。如下图所示，这说明 nums[pivot] 是最小值右侧的元素，因此我们可以忽略二分查找区间的右半部分。
// 第二种情况是 nums[pivot]>nums[high]。如下图所示，这说明 nums[pivot] 是最小值左侧的元素，因此我们可以忽略二分查找区间的左半部分。
// 第三种情况是 nums[pivot]==nums[high]。如下图所示，由于重复元素的存在，我们并不能确定 nums[pivot] 究竟在最小值的左侧还是右侧，因此我们不能莽撞地忽略某一部分的元素。我们唯一可以知道的是，由于它们的值相同，所以无论 nums[high] 是不是最小值，都有一个它的「替代品」nums[pivot]，因此我们可以忽略二分查找区间的右端点。
// 当二分查找结束时，我们就得到了最小值所在的位置。
// class Solution {
// public:
//     int findMin(vector<int>& nums) {
//         int low = 0;
//         int high = nums.size() - 1;
//         while (low < high) {
//             int pivot = low + (high - low) / 2;
//             if (nums[pivot] < nums[high]) {
//                 high = pivot;
//             }
//             else if (nums[pivot] > nums[high]) {
//                 low = pivot + 1;
//             }
//             else {
//                 high -= 1;
//             }
//         }
//         return nums[low];
//     }
// };
// 复杂度分析
// 时间复杂度：平均时间复杂度为 O(log⁡n)，其中 n 是数组 nums 的长度。如果数组是随机生成的，那么数组中包含相同元素的概率很低，在二分查找的过程中，大部分情况都会忽略一半的区间。而在最坏情况下，如果数组中的元素完全相同，那么 while 循环就需要执行 n 次，每次忽略区间的右端点，时间复杂度为 O(n)。
// 空间复杂度：O(1)。