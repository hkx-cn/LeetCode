// 976.三角形的最大周长
// 给定由一些正数（代表长度）组成的数组 nums ，返回
// 由其中三个长度组成的、面积不为零的三角形的最大周长
// 。如果不能形成任何面积不为零的三角形，返回 0。

// 示例 1：
// 输入：nums = [2,1,2]
// 输出：5
// 解释：你可以用三个边长组成一个三角形:1 2 2。
// 示例 2：
// 输入：nums = [1,2,1,10]
// 输出：0
// 解释：
// 你不能用边长 1,1,2 来组成三角形。
// 不能用边长 1,1,10 来构成三角形。
// 不能用边长 1、2 和 10 来构成三角形。
// 因为我们不能用任何三条边长来构成一个非零面积的三角形，所以我们返回 0。

// 提示：
// 3 <= nums.length <= 10^4
// 1 <= nums[i] <= 10^6
#include "LeetCode976.hpp"

int cmp(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int largestPerimeter(int* nums, int numsSize) {
    int result = 0;
    qsort(nums, numsSize, sizeof(int), cmp);
    for (int i = 0; i < numsSize - 2; i++) {
        for (int j = i; j < numsSize - 2; j++) {
            if (nums[j] > nums[j + 1] + nums[j + 2]) {
                result = nums[j] + nums[j + 1] + nums[j + 2];
                return result;
            }
        }
    }
    return result;
}

// int Solution::largestPerimeter(vector<int>& nums) {
//     sort(nums.begin(), nums.end());
//     for (size_t i = nums.size() - 1; i >= 2; i--) {
//         if (nums[i] < nums[i - 1] + nums[i - 2]) {
//             return nums[i] + nums[i - 1] + nums[i - 2];
//         }
//     }
//     return 0;
// };

// 方法一：贪心 + 排序
// 不失一般性，我们假设三角形的边长 a,b,c 满足
// a≤b≤c，那么这三条边组成面积不为零的三角形的充分必要条件为 a+b>c。
// 基于此，我们可以选择枚举三角形的最长边
// c，而从贪心的角度考虑，我们一定是选「小于 c 的最大的两个数」作为边长 a 和
// b，此时最有可能满足
// a+b>c，使得三条边能够组成一个三角形，且此时的三角形的周长是最大的。
// 因此，我们先对整个数组排序，倒序枚举第 i
// 个数作为最长边，那么我们只要看其前两个数 A[i−2] 和 A[i−1]，判断 A[i−2]+A[i−1]
// 是否大于 A[i] 即可，如果能组成三角形我们就找到了最大周长的三角形，返回答案
// A[i−2]+A[i−1]+A[i]
// 即可。如果对于任何数作为最长边都不存在面积不为零的三角形，则返回答案 0。
// class Solution {
// public:
//     int largestPerimeter(vector<int>& A) {
//         sort(A.begin(), A.end());
//         for (int i = (int)A.size() - 1; i >= 2; --i) {
//             if (A[i - 2] + A[i - 1] > A[i]) {
//                 return A[i - 2] + A[i - 1] + A[i];
//             }
//         }
//         return 0;
//     }
// };
// 复杂度分析
// 时间复杂度：O(NlogN)，其中 N 是数组 A 的长度。
// 空间复杂度：Ω(logN)。
