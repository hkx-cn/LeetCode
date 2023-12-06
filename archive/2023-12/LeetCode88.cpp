// 88. 合并两个有序数组
// 给你两个按 非递减顺序 排列的整数数组 nums1 和 nums2，另有两个整数 m 和 n ，分别表示 nums1 和 nums2 中的元素数目。
// 请你 合并 nums2 到 nums1 中，使合并后的数组同样按 非递减顺序 排列。
// 注意：最终，合并后数组不应由函数返回，而是存储在数组 nums1 中。为了应对这种情况，nums1 的初始长度为 m + n，其中前 m 个元素表示应合并的元素，后 n 个元素为 0 ，应忽略。nums2 的长度为 n 。

// 示例 1：
// 输入：nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
// 输出：[1,2,2,3,5,6]
// 解释：需要合并 [1,2,3] 和 [2,5,6] 。
// 合并结果是 [1,2,2,3,5,6] ，其中斜体加粗标注的为 nums1 中的元素。
// 示例 2：
// 输入：nums1 = [1], m = 1, nums2 = [], n = 0
// 输出：[1]
// 解释：需要合并 [1] 和 [] 。
// 合并结果是 [1] 。
// 示例 3：
// 输入：nums1 = [0], m = 0, nums2 = [1], n = 1
// 输出：[1]
// 解释：需要合并的数组是 [] 和 [1] 。
// 合并结果是 [1] 。
// 注意，因为 m = 0 ，所以 nums1 中没有元素。nums1 中仅存的 0 仅仅是为了确保合并结果可以顺利存放到 nums1 中。

// 提示：
// nums1.length == m + n
// nums2.length == n
// 0 <= m, n <= 200
// 1 <= m + n <= 200
// -10^9 <= nums1[i], nums2[j] <= 10^9
// 进阶：你可以设计实现一个时间复杂度为 O(m + n) 的算法解决此问题吗？
#include "LeetCode88.hpp"

void Solution::merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int idx1 = 0, idx2 = 0, min1 = 0, min2 = 0;
    bool end1 = m == 0 ? true : false, end2 = n == 0 ? true : false;
    for (size_t i = 0; i < n; i++)
    {
        if (end1 == false && end2 == false)
            break;
        else if (end1 == true)
        {
            nums1[i] = nums2[idx2];
            idx2++;
        }
        else if (end2 == true)
        {
            nums1[i] = nums1[idx1];
            idx1++;
        }
        else if (nums1[idx1] < nums2[idx2])
        {
            nums1[m + i + idx2] = nums1[i];
            nums1[i] = nums1[idx1];
            idx1++;
        }
        else
        {
            nums1[m + i + idx2] = nums1[i];
            nums1[i] = nums2[idx2];
            idx2++;
            idx1 = idx1 < m ? m + idx1 : idx1 + 1;
        }
        end1 = idx1 >= m + n - 1 ? true : false;
        end2 = idx2 >= n ? true : false;
    }
    for (size_t i = n; i < m + n; i++)
    {
        if (end1 == false && end2 == false)
            break;
        else if (end1 == true)
        {
            nums1[i] = nums2[idx2];
            idx2++;
        }
        else if (end2 == true)
        {
            nums1[i] = nums1[idx1];
            idx1++;
        }
        else if (nums1[idx1] < nums2[idx2])
        {
            // 1,2,3,4,5,6,0,0,0
            // -3,-2,-1
            // -3,-2,-1,4,5,6,1,2,3

            // 1,2,3,4,5,6,0,0,0
            // -3,-2,10
            // -3,-2,1,4,5,6,1,2,3
            // -3,-2,10
            // m = 6,n = 3
            // m-n,n1 = 2,n2 = 1
            nums1[m + i + idx2] = nums1[i];
            nums1[i] = nums1[idx1];
            idx1++;
        }
        else
        {
            nums1[m + i + idx2] = nums1[i];
            nums1[i] = nums2[idx2];
            idx2++;
            idx1 = idx1 < m ? m + idx1 : idx1 + 1;
        }
        end1 = idx1 >= m + n - 1 ? true : false;
        end2 = idx2 >= n ? true : false;
    }
};

// // idx1:nums1滑动下标,idx2:nums2滑动下标
// int idx1 = 0, idx2 = 0;
// for (size_t i = 0; i < n; i++)
// {
//     if (m == 0)
//     {
//         nums1[i] = nums2[idx2];
//         idx2++;
//     }
//     // nums2最小值小于nums1最小值插入nums1[i]中
//     else if (nums1[idx1] > nums2[idx2])
//     {
//         // nums1[i]移动到数组末尾
//         nums1[m + i + idx2] = nums1[i];
//         // nums2的最小值放在nums1[i]
//         nums1[i] = nums2[idx2];
//         // nums2最小值下标更新
//         idx2++;
//         // nums1最小值滑动初始化
//         idx1 = idx1 < m ? idx1 + m : idx1;
//     }
//     // nums1最小值小于nums2最小值
//     else
//     {
//         // nums1[i]移动到数组末尾
//         nums1[m + i + idx2] = nums1[i];
//         // nums1的最小值放在nums1[i]
//         nums1[i] = nums1[idx1];
//         // nums1最小值下标更新
//         idx1++;
//     }
// }
// for (size_t i = n; i < m + n; i++)
// {
//     if (idx1 - m == 0 || idx1 >= m + n)
//     {
//         nums1[i] = nums2[idx2];
//         idx2++;
//     }
//     else if (idx2 >= n)
//     {
//         nums1[i] = nums1[idx1];
//         idx1++;
//     }
//     else if (nums1[idx1] < nums2[idx2])
//     {
//         nums1[i] = nums1[idx1];
//         idx1++;
//     }
//     else
//     {
//         nums1[i] = nums2[idx2];
//         idx2++;
//     }
// }