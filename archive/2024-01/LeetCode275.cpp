// 275. H 指数 II
// 给你一个整数数组 citations ，其中 citations[i] 表示研究者的第 i 篇论文被引用的次数，citations 已经按照 升序排列 。计算并返回该研究者的 h 指数。
// h 指数的定义：h 代表“高引用次数”（high citations），一名科研人员的 h 指数是指他（她）的 （n 篇论文中）至少 有 h 篇论文分别被引用了至少 h 次。
// 请你设计并实现对数时间复杂度的算法解决此问题。

// 示例 1：
// 输入：citations = [0,1,3,5,6]
// 输出：3
// 解释：给定数组表示研究者总共有 5 篇论文，每篇论文相应的被引用了 0, 1, 3, 5, 6 次。
//      由于研究者有3篇论文每篇 至少 被引用了 3 次，其余两篇论文每篇被引用 不多于 3 次，所以她的 h 指数是 3 。
// 示例 2：
// 输入：citations = [1,2,100]
// 输出：2

// 提示：
// n == citations.length
// 1 <= n <= 10^5
// 0 <= citations[i] <= 1000
// citations 按 升序排列
#include "LeetCode275.hpp"
int Solution::hIndex(vector<int> &citations)
{ 
    int left = 0, right = citations.size() - 1, mid = -1, ans = citations.size() - 1;
    while (left <= right)
    {
        mid = left + (right - left) / 2;
        if (citations[mid] < citations.size() - mid)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
            ans = mid;
        }
    }
    return citations[ans] < citations.size() - ans ? citations[ans] : citations.size() - ans;
}
// int Solution::hIndex(vector<int> &citations)
// {
//     int left = 0, right = citations.size() - 1, mid = -1, ans = -1;
//     // 从右往左二分
//     // 下标边界值[0,citations.size()-1]
//     while (left <= right)
//     {
//         mid = left + (right - left) / 2;
//         if (citations.size() - mid <= citations[mid])
//         {
//             right = mid;
//             ans = citations.size() - right;
//         }
//         else
//         {
//             left = mid + 1;
//         }
//     }
//     return ans;
// }
// int Solution::hIndex(vector<int> &citations)
// {
//     int left = 0, right = citations.size() - 1, mid = -1;
//     while (left < right)
//     {
//         mid = left + (right - left) / 2;
//         if (citations[mid] >= citations.size() - mid)
//             right = mid;
//         else
//             left = mid + 1;
//     }
//     return citations.size() - right < citations[citations.size() - 1] ? citations.size() - right : citations[citations.size() - 1];
// };
// 这道题是「274. H 指数」的延伸，和第 274 题相比，这道题中的输入数组 citations 已经按照升序排序。

// 除了使用第 274 题的方法以外（见「274. H 指数的官方题解」），这道题可以利用数组 citations 有序的特点，使用二分查找的方法求解，时间复杂度为 O(log⁡n)，其中 n 为数组 citations 的长度。

// 方法一：二分查找
// 由于数组 citations 已经按照升序排序，因此可以使用二分查找。
// 设查找范围的初始左边界 left 为 0, 初始右边界 right 为 n−1，其中 n 为数组 citations 的长度。每次在查找范围内取中点 mid，则有 n−mid 篇论文被引用了至少 citations[mid] 次。如果在查找过程中满足 citations[mid]≥n−mid，则移动右边界 right，否则移动左边界 left。
// class Solution {
// public:
//     int hIndex(vector<int>& citations) {
//         int n = citations.size();
//         int left = 0, right = n - 1;
//         while (left <= right) {
//             int mid = left + (right - left) / 2;
//             if (citations[mid] >= n - mid) {
//                 right = mid - 1;
//             } else {
//                 left = mid + 1;
//             }
//         }
//         return n - left;
//     }
// };
// 复杂度分析

// 时间复杂度：O(log⁡n)，其中 n 为数组 citations 的长度。二分查找的时间复杂度为 O(log⁡n)。

// 空间复杂度：O(1)。