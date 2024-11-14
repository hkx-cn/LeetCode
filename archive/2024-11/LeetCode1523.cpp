// 1523. 在区间范围内统计奇数数目
// 给你两个非负整数 low 和 high 。请你返回 low 和 high
// 之间（包括二者）奇数的数目。
//
// 示例 1：
// 输入：low = 3, high = 7
// 输出：3
// 解释：3 到 7 之间奇数数字为[3, 5, 7] 。
// 示例 2：
// 输入：low = 8, high = 10
// 输出：1
// 解释：8 到 10 之间奇数数字为[9] 。
//
// 提示：
// 0 <= low <= high <= 10 ^ 9
#include "LeetCode1523.hpp"

int countOdds(int low, int high) {
    int result;
    // 奇、奇  1、5     (5 - 1) / 2 = 2    3
    // 奇、偶  1、6     (6 - 1) / 2 = 2    3
    // 偶、奇  2、5     (5 - 2) / 2 = 1    2
    // 偶、偶  2、6     (6 - 2) / 2 = 2    2
    if ((low % 2 == 0) && (high % 2 == 0)) {
        result = (high - low) / 2;
    } else{
        result = (high - low) / 2 + 1;
    }
    return result;
}

// int Solution::countOdds(int low, int high) {
//     return high / 2 + high % 2 - low / 2;
// }

// int Solution::countOdds(int low, int high) {
//     int result = 0;
//     if ((high - low) % 2 == 0) {
//         result += (high - low) / 2;
//         if (low % 2 == 1) {
//             result += 1;
//         }
//     } else {
//         result += (high + 1 - low) / 2;
//     }
//     return result;
// }

// 方法一：前缀和思想
// 思路与算法
// 如果我们暴力枚举[low, high] 中的所有元素会超出时间限制。
// 我们可以使用前缀和思想来解决这个问题，定义 pre(x) 为区间[0, x]
// 中奇数的个数，很显然： pre(x) = ⌊(x + 1)/2⌋ 故答案为 pre(high)−pre(low−1)。
// class Solution {
// public:
//    int pre(int x) {
//        return (x + 1) >> 1;
//    }
//
//    int countOdds(int low, int high) {
//        return pre(high) - pre(low - 1);
//    }
// };
// 复杂度分析
// 时间复杂度：O(1)。
// 空间复杂度：O(1)。

