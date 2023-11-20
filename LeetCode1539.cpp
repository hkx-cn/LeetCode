// 1539. 第 k 个缺失的正整数
// 给你一个 严格升序排列 的正整数数组 arr 和一个整数 k 。

// 请你找到这个数组里第 k 个缺失的正整数。

// 示例 1：
// 输入：arr = [2,3,4,7,11], k = 5
// 输出：9
// 解释：缺失的正整数包括 [1,5,6,8,9,10,12,13,...] 。第 5 个缺失的正整数为 9 。

// 示例 2：
// 输入：arr = [1,2,3,4], k = 2
// 输出：6
// 解释：缺失的正整数包括 [5,6,7,...] 。第 2 个缺失的正整数为 6 。

// 提示：
// 1 <= arr.length <= 1000
// 1 <= arr[i] <= 1000
// 1 <= k <= 1000
// 对于所有 1 <= i < j <= arr.length 的 i 和 j 满足 arr[i] < arr[j]
// 进阶：
// 你可以设计一个时间复杂度小于 O(n) 的算法解决此问题吗？

#include "LeetCode1539.h"
int Solution::findKthPositive(vector<int> &arr, int k)
{
    // 数组            arr= [2,3,4,7,11]
    // 缺失的正整数个数      [1,1,1,3,6]
    // 下标                 [0,1,2,3,4]
    // 第k个正整数           [1,5,6,8,9,10,12,13,14,15]
    // k                    [1,2,3,4,5,6 ,7 ,8 ,9 ,10]
    // 计算                 [0,3,3,4,4,4 ,5 ,5 ,5 ,5]
    int left = 0, right = arr.size() - 1, mid = -1;
    while (left < right)
    {
        mid = left + (right - left + 1) / 2;
        if (arr[mid] - mid - 1 < k)
            left = mid + 1;
        else
            right = mid;
    }
    return left + k;
    // 下标对应的数组值arr[left]
    // 缺失的正整数个数arr[left]-left-1
    // 个数与K比较arr[left]-left-1 == k ->arr[left] - 1
    // 个数与K比较arr[left]-left-1 > k  ->left + k
};

// 第一版
// int Solution::findKthPositive(vector<int> &arr, int k)
// {
//     int leftDif = arr[0] - 1, rightDif = arr[arr.size() - 1] - arr.size(), left = 0, right = arr.size() - 1, mid = -1;
//     if (k > rightDif)
//     {
//         return arr[arr.size() - 1] + k - rightDif;
//     }
//     else if (k == rightDif)
//     {
//         return arr[arr.size() - 1] - 1;
//     }
//     else if (k <= leftDif)
//     {
//         return k;
//     }
//     while (left < right)
//     {
//         mid = left + (right - left) / 2;
//         if (arr[mid] - mid - 1 >= k)
//             right = mid;
//         else
//             left = mid + 1;
//     }
//     return right + k;
// };

// 方法一：枚举
// 思路与算法

// 我们可以顺序枚举。

// 用一个变量 current\textit{current}current 表示当前应该出现的数，从 111 开始，每次循环都让该变量递增。用一个指针 ptr\textit{ptr}ptr 指向数组中没有匹配的第一个元素，每轮循环中将该元素和 current\textit{current}current 进行比较，如果相等，则指针后移，否则指针留在原地不动，说明缺失正整数 current\textit{current}current。我们用 missCount\textit{missCount}missCount 变量记录缺失的正整数的个数，每次发现有正整数缺失的时候，该变量自增，并且记录这个缺失的正整数，直到我们找到第 kkk 个缺失的正整数。
// class Solution {
// public:
//     int findKthPositive(vector<int>& arr, int k) {
//         int missCount = 0, lastMiss = -1, current = 1, ptr = 0;
//         for (missCount = 0; missCount < k; ++current) {
//             if (current == arr[ptr]) {
//                 ptr = (ptr + 1 < arr.size()) ? ptr + 1 : ptr;
//             } else {
//                 ++missCount;
//                 lastMiss = current;
//             }
//         }
//         return lastMiss;
//     }
// };
// 复杂度分析

// 时间复杂度：O(n+k)O(n + k)O(n+k)，其中 nnn 是数组 arr\textit{arr}arr 的长度，kkk 是给定的整数。最坏情况下遍历完整个数组都没有缺失正整数，还要再将 current\textit{current}current 递增 kkk 次，才能找到最终的答案。

// 空间复杂度：O(1)O(1)O(1)。

// 方法二：二分查找
// 思路与算法

// 对于每个元素 aia_ia
// i
// ​
//  ，我们都可以唯一确定到第 iii 个元素为止缺失的元素数量为 ai−i−1a_i - i - 1a
// i
// ​
//  −i−1，例如：

// 第 iii 个元素	aia_ia
// i
// ​
//   的值	到第 iii 个元素为止缺失的元素数量 pip_ip
// i
// ​

// a0a_0a
// 0
// ​
//  	222	111
// a1a_1a
// 1
// ​
//  	333	111
// a2a_2a
// 2
// ​
//  	444	111
// a3a_3a
// 3
// ​
//  	777	333
// a4a_4a
// 4
// ​
//  	111111	666
// 我们发现 pip_ip
// i
// ​
//   是随 iii 非严格递增的，于是可以使用二分查找解决这个问题。我们只要找到一个 iii 使得 pi−1<k≤pip_{i - 1} < k \leq p_{i}p
// i−1
// ​
//  <k≤p
// i
// ​
//  ，就可以确定缺失的第 kkk 个数为 k−pi−1+ai−1k - p_{i - 1} + a_{i - 1}k−p
// i−1
// ​
//  +a
// i−1
// ​
//  。也就是说，我们要找到第一个大于等于 kkk 的 pip_ip
// i
// ​
//  。

// 在实现的时候，我们要注意两个边界的处理：

// 当 a0>ka_0 > ka
// 0
// ​
//  >k 时，最终 i=0i = 0i=0，找不到 i−1i - 1i−1，所以提前判断是否 a0>ka_0 > ka
// 0
// ​
//  >k，如果是，则直接返回 kkk。
// 当最后一个元素对应的缺失个数 pn−1<kp_{n - 1} < kp
// n−1
// ​
//  <k 时，我们并不能找到第一个大于等于 kkk 的 pip_ip
// i
// ​
//  ，为了解决这个问题，可以在 aaa 序列的最后加入一个虚拟的值，这个值的大小为一个不会出现的非常大的数，这样就可以保证一定能找到一个大于等于 kkk 的 pip_ip
// i
// ​
//  。
// class Solution {
// public:
//     int findKthPositive(vector<int>& arr, int k) {
//         if (arr[0] > k) {
//             return k;
//         }

//         int l = 0, r = arr.size();
//         while (l < r) {
//             int mid = (l + r) >> 1;
//             int x = mid < arr.size() ? arr[mid] : INT_MAX;
//             if (x - mid - 1 >= k) {
//                 r = mid;
//             } else {
//                 l = mid + 1;
//             }
//         }

//         return k - (arr[l - 1] - (l - 1) - 1) + arr[l - 1];
//     }
// };
// 复杂度分析

// 时间复杂度：O(log⁡n)O(\log n)O(logn)，其中 nnn 是数组 arr\textit{arr}arr 的长度。即二分查找的时间复杂度。

// 空间复杂度：O(1)O(1)O(1)。