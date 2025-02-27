// 326. 3 的幂
// 给定一个整数，写一个函数来判断它是否是 3 的幂次方。如果是，返回 true
// ；否则，返回 false 。 整数 n 是 3 的幂次方需满足：存在整数 x 使得 n == 3^x
//
// 示例 1：
// 输入：n = 27
// 输出：true
// 示例 2：
// 输入：n = 0
// 输出：false
// 示例 3：
// 输入：n = 9
// 输出：true
// 示例 4：
// 输入：n = 45
// 输出：false
//
// 提示：
// -2^31 <= n <= 2^31 - 1
// 进阶：你能不使用循环或者递归来完成本题吗？
#include "LeetCode326.hpp"

bool isPowerOfThree(int n) {
    if (n <= 0) {
        return false;
    }
    while (n % 3 == 0) {
        n /= 3;
    }
    return n == 1;
}

// bool Solution::isPowerOfThree(int n) {
//     if (n == 0) {
//         return false;
//     }
//     while (n % 3 == 0) {
//         n /= 3;
//     }
//     if (n == 1) {
//         return true;
//     }
//     return false;
// }

// 方法一：试除法
// 思路与算法
// 我们不断地将 n 除以 3，直到 n = 1。如果此过程中 n 无法被 3 整除，就说明 n
// 不是 3 的幂。 本题中的 n 可以为负数或 0，可以直接提前判断该情况并返回
// False，也可以进行试除，因为负数或 0 也无法通过多次除以 3 得到 1。
// class Solution {
// public:
//     bool isPowerOfThree(int n) {
//         while (n && n % 3 == 0) {
//             n /= 3;
//         }
//         return n == 1;
//     }
// };
// 复杂度分析
// 时间复杂度：O(logn)。当 n 是 3 的幂时，需要除以 3 的次数为 log3 n =
// O(logn)；当 n 不是 3 的幂时，需要除以 3 的次数小于该值。 空间复杂度：O(1)。
//
// 方法二：判断是否为最大 3 的幂的约数
// 思路与算法
// 我们还可以使用一种较为取巧的做法。
// 在题目给定的 32 位有符号整数的范围内，最大的 3 的幂为 3^19 =
// 1162261467。我们只需要判断 n 是否是 3^19 的约数即可。
// 与方法一不同的是，这里需要特殊判断 n 是负数或 0 的情况。
// class Solution {
// public:
//     bool isPowerOfThree(int n) {
//         return n > 0 && 1'162'261'467 % n == 0;
//     }
// };
// 复杂度分析
// 时间复杂度：O(1)。
// 空间复杂度：O(1)。
