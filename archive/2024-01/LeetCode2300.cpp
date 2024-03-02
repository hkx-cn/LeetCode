// 2300. 咒语和药水的成功对数
// 给你两个正整数数组 spells 和 potions ，长度分别为 n 和 m ，其中 spells[i] 表示第 i 个咒语的能量强度，potions[j] 表示第 j 瓶药水的能量强度。
// 同时给你一个整数 success 。一个咒语和药水的能量强度 相乘 如果 大于等于 success ，那么它们视为一对 成功 的组合。
// 请你返回一个长度为 n 的整数数组 pairs，其中 pairs[i] 是能跟第 i 个咒语成功组合的 药水 数目。

// 示例 1：
// 输入：spells = [5,1,3], potions = [1,2,3,4,5], success = 7
// 输出：[4,0,3]
// 解释：
// - 第 0 个咒语：5 * [1,2,3,4,5] = [5,10,15,20,25] 。总共 4 个成功组合。
// - 第 1 个咒语：1 * [1,2,3,4,5] = [1,2,3,4,5] 。总共 0 个成功组合。
// - 第 2 个咒语：3 * [1,2,3,4,5] = [3,6,9,12,15] 。总共 3 个成功组合。
// 所以返回 [4,0,3] 。
// 示例 2：
// 输入：spells = [3,1,2], potions = [8,5,8], success = 16
// 输出：[2,0,2]
// 解释：
// - 第 0 个咒语：3 * [8,5,8] = [24,15,24] 。总共 2 个成功组合。
// - 第 1 个咒语：1 * [8,5,8] = [8,5,8] 。总共 0 个成功组合。
// - 第 2 个咒语：2 * [8,5,8] = [16,10,16] 。总共 2 个成功组合。
// 所以返回 [2,0,2] 。

// 提示：
// n == spells.length
// m == potions.length
// 1 <= n, m <= 10^5
// 1 <= spells[i], potions[i] <= 10^5
// 1 <= success <= 10^10
#include "LeetCode2300.hpp"
vector<int> Solution::successfulPairs(vector<int> &spells, vector<int> &potions, long long success)
{
    vector<int> result(spells.size());
    sort(potions.begin(), potions.end());
    for (size_t i = 0; i < spells.size(); i++)
    {
        int left = 0, right = potions.size() - 1, mid = -1, ans = 0;
        // 二分查找，最小下标
        // 值范围[0,potions.size()]
        // 从左往右二分
        while (left <= right)
        {
            mid = left + (right - left) / 2;
            if ((long long)spells[i] * (long long)potions[mid] >= success)
            {
                right = mid - 1;
                ans = potions.size() - mid;
            }
            else
            {
                left = mid + 1;
            }
        }
        result[i] = ans;
    }
    return result;
}
// vector<int> Solution::successfulPairs(vector<int> &spells, vector<int> &potions, long long success)
// {
//     int left = 0, right = potions.size() - 1, mid = -1;
//     vector<int> result;
//     sort(potions.begin(), potions.end());
//     for (size_t i = 0; i < spells.size(); i++)
//     {
//         left = 0;
//         right = potions.size() - 1;
//         while (left < right)
//         {
//             mid = left + (right - left) / 2;
//             if (spells[i] * potions[mid] >= success)
//                 right = mid;
//             else
//                 left = mid + 1;
//         }
//         result.push_back(potions.size() - left);
//     }
//     return result;
// }
// 方法一：二分查找
// 思路与算法
// 对于某一个咒语的能量，我们可以采用二分查找的方法来高效地找到符合条件的药水数量。首先，我们将 potions 数组进行排序，以便能够利用有序性进行二分查找。然后，对于每个咒语 spells[i]，0≤i<n，其中 n 为数组 spells 的长度，我们计算出目标值
// target=⌈success/spells[i]⌉
// 其中 ⌈x⌉ 表示不小于 x 的最小整数。target 代表了在当前咒语强度下，药水需要达到的最低强度。接下来，我们使用「二分查找」来在数组 potions 中找到第一个大于等于 target 的元素的索引 idx，进一步可以得到此时表示成功组合的药水数量为 m−idx，其中 m 表示数组 potions 的长度。
// class Solution {
// public:
//     vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
//         sort(potions.begin(), potions.end());
//         vector<int> res;
//         for (auto& i : spells) {
//             long long t = (success + i - 1) / i - 1;
//             res.push_back(potions.size() - (upper_bound(potions.begin(), potions.end(), t) - potions.begin()));
//         }
//         return res;
//     }
// };
// 复杂度分析
// 时间复杂度：O(m×log⁡m+n×log⁡m)，其中 n 为数组 spells 的长度，m 是数组 postion 的长度，主要为对数组 potions 排序和对数组 spells 中每一个元素对数组 potions 进行「二分查找」的时间开销。
// 空间复杂度：O(log⁡m)，主要为对 potions 排序的空间开销，其中返回的答案不计入空间复杂度。

// 方法二：双指针
// 思路与算法
// 同样我们也可以通过「双指针」来解决这个问题：
// 首先我们对数组 spells 下标按照其位置上的能量强度进行 升序排序，假设其排序后的数组为 idx，对数组 potions 按照能量强度进行 降序排序。并初始化一个结果数组 res，长度为 n，n 为数组 spells 的长度，用于记录每个咒语成功组合的药水数目。
// 我们使用两个指针 i 和 j 分别指向数组 idx 和 potions 的起始位置，用指针 i 遍历数组 idx，对于当前 i 指向的咒语 spells[idx[i]]，若有
// spells[idx[i]]×potions[j]≥sucess (1)
// 成立，则对于任意 i<k<n，都有
// spells[idx[k]]×potions[j]≥sucess (2)
// 成立。对于每一个 i，指针 j 不断右移直至 j 不满足条件 (1)（其中右移前需要满足 j<m 成立，m 为 potions 的长度）。对于指针 i，指针 j 移动操作结束后，那么此时能成功组合的药水数量 res[idx[i]]=j。并且由于随着指针 i 位置不断增大，指针 j 的位置单调不减，所以指针 i 不断右移的整个过程时间复杂度为 O(n)。
// class Solution {
// public:
//     vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
//         vector<int> res(spells.size());
//         vector<int> idx(spells.size());
//         iota(idx.begin(), idx.end(), 0);
//         sort(idx.begin(), idx.end(), [&](int a, int b) {
//             return spells[a] < spells[b];
//         });
//         sort(potions.begin(), potions.end(), [](int a, int b) {
//             return a > b;
//         });
//         for (int i = 0, j = 0; i < spells.size(); ++i) {
//             int p = idx[i];
//             int v = spells[p];
//             while (j < potions.size() && (long long) potions[j] * v >= success) {
//                 ++j;
//             }
//             res[p] = j;
//         }
//         return res;
//     }
// };
// 复杂度分析
// 时间复杂度：O(n×log⁡n+m×log⁡m)，其中 n 为数组 spells 的长度，m 是数组 postion 的长度，主要为对数组 potions 和 idx 排序的时间开销。
// 空间复杂度：O(n+log⁡n+log⁡m)，主要为数组 idx 的空间开销和对数组 potions 排序的空间开销，其中返回的答案不计入空间复杂度。