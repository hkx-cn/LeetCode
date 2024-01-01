// 611. 有效三角形的个数
// 给定一个包含非负整数的数组 nums ，返回其中可以组成三角形三条边的三元组个数。

// 示例 1:
// 输入: nums = [2,2,3,4]
// 输出: 3
// 解释:有效的组合是:
// 2,3,4 (使用第一个 2)
// 2,3,4 (使用第二个 2)
// 2,2,3
// 示例 2:
// 输入: nums = [4,2,3,4]
// 输出: 4

// 提示:
// 1 <= nums.length <= 1000
// 0 <= nums[i] <= 1000
#include "LeetCode611.hpp"
int Solution::triangleNumber(vector<int> &nums)
{
    int left, right, mid, ans = 0;
    sort(nums.begin(), nums.end());
    if (nums.size() < 3)
        return 0;
    for (size_t i = 0; i < nums.size() - 2; i++)
    {
        for (size_t j = i + 1; j < nums.size() - 1; j++)
        {
            left = j + 1;
            right = nums.size() - 1;
            while (left <= right)
            {
                mid = left + (right - left + 1) / 2;
                if (nums[i] + nums[j] <= nums[mid])
                    right = mid - 1;
                else
                    left = mid + 1;
            }
            ans = ans + right - j;
        }
    }
    return ans;
}
// int Solution::triangleNumber(vector<int> &nums)
// {
//     sort(nums.begin(), nums.end());
//     int left = 0, right = nums.size() - 1, i, j, mid = -1, target, result = 0;
//     if (nums.size() < 3)
//         return 0;
//     for (size_t i = 0; i < nums.size() - 2; i++)
//     {
//         for (size_t j = i + 1; j < nums.size() - 1; j++)
//         {
//             left = j + 1;
//             right = nums.size() - 1;
//             target = nums[i] + nums[j];
//             while (left < right)
//             {
//                 mid = left + (right - left + 1) / 2;
//                 if (nums[mid] < target)
//                     left = mid;
//                 else
//                     right = mid - 1;
//             }
//             if (nums[right] < target)
//                 result += right - j;
//         }
//     }
//     return result;
// };
// 方法一：排序 + 二分查找
// 思路与算法
// 对于正整数 a,b,c，它们可以作为三角形的三条边，当且仅当：

// {a+b>c
// ⎩a+c>b
// ⎨b+c>a
// ⎧
// 均成立。如果我们将三条边进行升序排序，使它们满足 a≤b≤c，那么 a+c>b 和 b+c>a 使一定成立的，我们只需要保证 a+b>c。

// 因此，我们可以将数组 nums 进行升序排序，随后使用二重循环枚举 a 和 b。设 a=nums[i],b=nums[j]，为了防止重复统计答案，我们需要保证 i<j。剩余的边 c 需要满足 c<nums[i]+nums[j]，我们可以在 [j+1,n−1] 的下标范围内使用二分查找（其中 n 是数组 nums 的长度），找出最大的满足 nums[k]<nums[i]+nums[j] 的下标 k，这样一来，在 [j+1,k] 范围内的下标都可以作为边 c 的下标，我们将该范围的长度 k−j 累加入答案。

// 当枚举完成后，我们返回累加的答案即可。
// 细节
// 注意到题目描述中 nums 包含的元素为非负整数，即除了正整数以外，nums 还会包含 0。但如果我们将 nums 进行升序排序，那么在枚举 a 和 b 时出现了 0，那么 nums[i] 一定为 0。此时，边 c 需要满足 c<nums[i]+nums[j]=nums[j]，而下标在 [j+1,n−1] 范围内的元素一定都是大于等于 nums[j] 的，因此二分查找会失败。若二分查找失败，我们可以令 k=j，此时对应的范围长度 k−j=0，我们也就保证了答案的正确性。
// class Solution {
// public:
//     int triangleNumber(vector<int>& nums) {
//         int n = nums.size();
//         sort(nums.begin(), nums.end());
//         int ans = 0;
//         for (int i = 0; i < n; ++i) {
//             for (int j = i + 1; j < n; ++j) {
//                 int left = j + 1, right = n - 1, k = j;
//                 while (left <= right) {
//                     int mid = (left + right) / 2;
//                     if (nums[mid] < nums[i] + nums[j]) {
//                         k = mid;
//                         left = mid + 1;
//                     }
//                     else {
//                         right = mid - 1;
//                     }
//                 }
//                 ans += k - j;
//             }
//         }
//         return ans;
//     }
// };
// 复杂度分析
// 时间复杂度：O(n^2log⁡n)，其中 n 是数组 nums 的长度。我们需要 O(nlog⁡n) 的时间对数组 nums 进行排序，随后需要 O(n^2log⁡n) 的时间使用二重循环枚举 a,b 的下标以及使用二分查找得到 c 的下标范围。
// 空间复杂度：O(log⁡n)，即为排序需要的栈空间。

// 方法二：排序 + 双指针
// 思路与算法
// 我们可以对方法一进行优化。
// 我们将当 a=nums[i],b=nums[j] 时，最大的满足 nums[k]<nums[i]+nums[j] 的下标 k 记为 ki,j 。可以发现，如果我们固定 i，那么随着 j 的递增，不等式右侧 nums[i]+nums[j] 也是递增的，因此 ki,j 也是递增的。
// 这样一来，我们就可以将 j 和 k 看成两个同向（递增）移动的指针，将方法一进行如下的优化：
// 我们使用一重循环枚举 i。当 i 固定时，我们使用双指针同时维护 j 和 k，它们的初始值均为 i；
// 我们每一次将 j 向右移动一个位置，即 j←j+1，并尝试不断向右移动 k，使得 k 是最大的满足 nums[k]<nums[i]+nums[j] 的下标。我们将 max⁡(k−j,0) 累加入答案。
// 当枚举完成后，我们返回累加的答案即可。
// 细节
// 与方法一中「二分查找的失败」类似，方法二的双指针中，也会出现不存在满足 nums[k]<nums[i]+nums[j] 的下标的情况。此时，指针 k 不会出现在指针 j 的右侧，即 k−j≤0，因此我们需要将 k−j 与 0 中的较大值累加入答案，防止错误的负数出现。
// class Solution {
// public:
//     int triangleNumber(vector<int>& nums) {
//         int n = nums.size();
//         sort(nums.begin(), nums.end());
//         int ans = 0;
//         for (int i = 0; i < n; ++i) {
//             int k = i;
//             for (int j = i + 1; j < n; ++j) {
//                 while (k + 1 < n && nums[k + 1] < nums[i] + nums[j]) {
//                     ++k;
//                 }
//                 ans += max(k - j, 0);
//             }
//         }
//         return ans;
//     }
// };
// 复杂度分析
// 时间复杂度：O(n2)，其中 n 是数组 nums 的长度。我们需要 O(nlog⁡n) 的时间对数组 nums 进行排序，随后需要 O(n2) 的时间使用一重循环枚举 a 的下标以及使用双指针维护 b,c 的下标。
// 空间复杂度：O(log⁡n)，即为排序需要的栈空间。