// 1486. 数组异或操作
// 给你两个整数，n 和 start 。
// 数组 nums 定义为：nums[i] = start + 2 * i（下标从 0 开始）且 n == nums.length
// 。 请返回 nums 中所有元素按位异或（XOR）后得到的结果。
//
// 示例 1：
// 输入：n = 5, start = 0
// 输出：8
// 解释：数组 nums 为[0, 2, 4, 6, 8]，其中(0 ^ 2 ^ 4 ^ 6 ^ 8) = 8 。
//"^" 为按位异或 XOR 运算符。
// 示例 2：
// 输入：n = 4, start = 3
// 输出：8
// 解释：数组 nums 为[3, 5, 7, 9]，其中(3 ^ 5 ^ 7 ^ 9) = 8.
// 示例 3：
// 输入：n = 1, start = 7
// 输出：7
// 示例 4：
// 输入：n = 10, start = 5
// 输出：2
//
//
// 提示：
// 1 <= n <= 1000
// 0 <= start <= 1000
// n == nums.length
#include "LeetCode1486.hpp"

int xorOperation(int n, int start) {
    int result = 0;
    for (int i = 0; i < n; i++) {
        result ^= start + 2 * i;
    }
    return result;
}

// int Solution::xorOperation(int n, int start) {
//     int cur = 0, result = 0;
//     for (int i = 0; i < n; i++) {
//         cur = start + 2 * i;
//         result = result ^ cur;
//     }
//     return result;
// };

// 方法一：模拟
// 思路
// 按照题意模拟即可：
// 1.初始化 ans = 0；
// 2.遍历区间[0, n−1] 中的每一个整数 i，令 ans 与每一个 start + 2×i 做异或运算；
// 3.最终返回 ans，即我们需要的答案。
// class Solution {
// public:
//     int xorOperation(int n, int start) {
//         int ans = 0;
//         for (int i = 0; i < n; ++i) {
//             ans ^= (start + i * 2);
//         }
//         return ans;
//     }
// };
// 复杂度分析
// 时间复杂度：O(n)。这里用一重循环对 n 个数字进行异或。
// 空间复杂度：O(1)。这里只是用了常量级别的辅助空间。
//
// 方法二：数学
// 记 ⊕ 为异或运算，异或运算满足以下性质：
// x⊕x = 0；
// x⊕y = y⊕x（交换律）；
// (x⊕y)⊕z = x⊕(y⊕z)（结合律）；
// x⊕y⊕y = x（自反性）；
// ∀i∈Z，有 4i⊕(4i + 1)⊕(4i + 2)⊕(4i + 3) = 0。
// 在本题中，我们需要计算 start⊕(start + 2i)⊕(start + 4i)⊕⋯⊕(start + 2(n−1))。
// 观察公式可以知道，这些数的奇偶性质相同，因此它们的二进制表示中的最低位或者均为
// 1，或者均为
// 0。于是我们可以把参与运算的数的二进制位的最低位提取出来单独处理。当且仅当
// start 为奇数，且 n 也为奇数时，结果的二进制位的最低位才为 1。
// 此时我们可以将公式转化为(s⊕(s + 1)⊕(s + 2)⊕⋯⊕(s + n−1))×2 + e，其中 s =
// ⌊start/2⌋，e
// 表示运算结果的最低位。即我们单独处理最低位，而舍去最低位后的数列恰成为一串连续的整数。
// 这样我们可以描述一个函数 sumXor(x)，表示 0⊕1⊕2⊕⋯⊕x。利用异或运算的性质
// 5，我们可以将计算该函数的复杂度降低到 O(1)，因为以 4i
// 为开头的连续四个整数异或的结果为 0，所以 sumXor(x) 可以被表示为： sumXor(x) =
// { x,x = 4k,k∈Z               (x−1)⊕x,x = 4k + 1,k∈Z
// (x−2)⊕(x−1)⊕x,x = 4k + 2,k∈Z
// (x−3)⊕(x−2)⊕(x−1)⊕x,x = 4k + 3,k∈Z
// 我们可以进一步化简该式：
// sumXor(x) = {x,x = 4k,k∈Z
//              1,x = 4k + 1,k∈Z
//              x + 1,x = 4k + 2,k∈Z
//              0,x = 4k + 3,k∈Z
// 这样最后的结果即可表示为(sumXor(s−1)⊕sumXor(s + n−1))×2 + e。
// class Solution {
// public:
//     int sumXor(int x) {
//         if (x % 4 == 0) {
//             return x;
//         }
//         if (x % 4 == 1) {
//             return 1;
//         }
//         if (x % 4 == 2) {
//             return x + 1;
//         }
//         return 0;
//     }
//
//     int xorOperation(int n, int start) {
//         int s = start >> 1, e = n & start & 1;
//         int ret = sumXor(s - 1) ^ sumXor(s + n - 1);
//         return ret << 1 | e;
//     }
// };
// 复杂度分析
// 时间复杂度：O(1)。我们只需要常数的时间计算出结果。
// 空间复杂度：O(1)。我们只需要常数的空间保存若干变量。
