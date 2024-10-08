// 1281. 整数的各位积和之差
// 给你一个整数
// n，请你帮忙计算并返回该整数「各位数字之积」与「各位数字之和」的差。
//
// 示例 1：
// 输入：n = 234
// 输出：15
// 解释：
// 各位数之积 = 2 * 3 * 4 = 24
// 各位数之和 = 2 + 3 + 4 = 9
// 结果 = 24 - 9 = 15
// 示例 2：
// 输入：n = 4421
// 输出：21
// 解释：
// 各位数之积 = 4 * 4 * 2 * 1 = 32
// 各位数之和 = 4 + 4 + 2 + 1 = 11
// 结果 = 32 - 11 = 21
//
//
// 提示：
// 1 <= n <= 10 ^ 5
#include "LeetCode1281.hpp"
int subtractProductAndSum(int n){
    int mul = 1, add = 0, tmp = 0;
    while(n != 0){
        tmp = n % 10;
        n /= 10;
        mul *= tmp;
        add += tmp;
    }
    return mul - add;
}

// int Solution::subtractProductAndSum(int n) {
//     int a = 0, b = 1, cur = 0;
//     while (n >= 10) {
//         cur = n % 10;
//         n /= 10;
//         a += cur;
//         b *= cur;
//     }
//     a += n;
//     b *= n;
//     return b - a;
// };
// 方法一：模拟
// 思路与算法
// 我们只需要依次取出数字 n 中的各位数字，并计算各个数字的乘积 m 以及数字和
// s，最后返回 m−s 即可。 我们可以依次取出 n 的最低位来得到 n 的各位数字：
// 通过「取模」操作 n mod 10 得到此时 n 的最低位。
// 通过「整除」操作 n = ⌊n/10⌋ 来去掉当前 n 的最低位。
// class Solution {
// public:
//     int subtractProductAndSum(int n) {
//         int m = 1, s = 0;
//         while (n) {
//             int x = n % 10;
//             n /= 10;
//             m *= x;
//             s += x;
//         }
//         return m - s;
//     }
// };
// 复杂度分析
// 时间复杂度：O(log⁡n)，其中 n 为题目给定的数字。
// 空间复杂度：O(1)，仅使用常量空间。
