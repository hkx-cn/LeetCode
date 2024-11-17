// 2235. 两整数相加
// 给你两个整数 num1 和 num2，返回这两个整数的和。

// 示例 1：
// 输入：num1 = 12, num2 = 5
// 输出：17
// 解释：num1 是 12，num2 是 5 ，它们的和是 12 + 5 = 17 ，因此返回 17 。
// 示例 2：
// 输入：num1 = -10, num2 = 4
// 输出：-6
// 解释：num1 + num2 = -6 ，因此返回 -6 。

// 提示：
// -100 <= num1, num2 <= 100
#include "LeetCode2235.hpp"

int sum(int num1, int num2) {
    return num1 + num2;
}

// int Solution::sum(int num1, int num2) {
//     return num1 + num2;
// };

// 方法一：直接计算
// 计算整数 num1 与 num2 之和，返回 num1+num2 即可。
// class Solution {
// public:
//     int sum(int num1, int num2) {
//         return num1 + num2;
//     }
// };
// 复杂度分析
// 时间复杂度：O(1)。
// 空间复杂度：O(1)。
