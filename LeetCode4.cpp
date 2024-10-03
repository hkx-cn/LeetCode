// 4. 寻找两个正序数组的中位数
// 给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1 和
// nums2。请你找出并返回这两个正序数组的 中位数 。 算法的时间复杂度应该为 O(log
// (m+n)) 。
//
// 示例 1：
// 输入：nums1 = [1,3], nums2 = [2]
// 输出：2.00000
// 解释：合并数组 = [1,2,3] ，中位数 2
// 示例 2：
// 输入：nums1 = [1,2], nums2 = [3,4]
// 输出：2.50000
// 解释：合并数组 = [1,2,3,4] ，中位数 (2 + 3) / 2 = 2.5
//
// 提示：
// nums1.length == m
// nums2.length == n
// 0 <= m <= 1000
// 0 <= n <= 1000
// 1 <= m + n <= 2000
//-10^6 <= nums1[i], nums2[i] <= 10^6
#include "LeetCode4.hpp"

double Solution::findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    double num1 = -10000000.0, num2 = -10000000.0, result = 0.0;
    int index1 = 0, index2 = 0, mid = (nums1.size() + nums2.size()) / 2;
    for (int i = 0; i <= mid; i++) {
        // 中位数都不在数组1中
        if (index1 >= nums1.size()) {
            if (mid - nums1.size() >= index2 + 1) {
                num1 = nums2[mid - nums1.size() - 1];
            } else if (nums1.size() > 0) {
                num1 = nums1[nums1.size() - 1];
            }
            num2 = nums2[mid - nums1.size()];
            break;
        }
        // 中位数不在数组2中
        else if (index2 >= nums2.size()) {
            if (mid - nums2.size() >= index1 + 1) {
                num1 = nums1[mid - nums2.size() - 1];
            } else if (nums2.size() > 0) {
                num1 = nums2[nums2.size() - 1];
            }
            num2 = nums1[mid - nums2.size()];
            break;
        } else if (nums1[index1] <= nums2[index2]) {
            num1 = num2;
            num2 = nums1[index1];
            index1++;
        } else if (nums1[index1] > nums2[index2]) {
            num1 = num2;
            num2 = nums2[index2];
            index2++;
        }
    }
    if ((nums1.size() + nums2.size()) % 2 == 1) {
        result = num2;
    } else {
        result = (num1 + num2) / 2;
    }
    return result;
}
