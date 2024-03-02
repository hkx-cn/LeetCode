// 1137. 第 N 个泰波那契数
// 泰波那契序列 Tn 定义如下：
// T0 = 0, T1 = 1, T2 = 1, 且在 n >= 0 的条件下 Tn+3 = Tn + Tn+1 + Tn+2
// 给你整数 n，请返回第 n 个泰波那契数 Tn 的值。

// 示例 1：
// 输入：n = 4
// 输出：4
// 解释：
// T_3 = 0 + 1 + 1 = 2
// T_4 = 1 + 1 + 2 = 4
// 示例 2：
// 输入：n = 25
// 输出：1389537

// 提示：
// 0 <= n <= 37
// 答案保证是一个 32 位整数，即 answer <= 2^31 - 1。
#include "LeetCode1137.hpp"
int Solution::tribonacci(int n)
{
    int t0 = 0, t1 = 1, t2 = 1, result = 0;
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else if (n == 2)
        return 1;
    else
    {
        for (size_t i = 3; i <= n; i++)
        {
            result = t0 + t1 + t2;
            t0 = t1;
            t1 = t2;
            t2 = result;
        }
    }
    return result;
};
// 方法一：动态规划
// 泰波那契数的边界条件是 T(0)=0,T(1)=1,T(2)=1。当 n>2 时，每一项的和都等于前三项的和，因此有如下递推关系：
// T(n)=T(n−1)+T(n−2)+T(n−3)
// 由于泰波那契数存在递推关系，因此可以使用动态规划求解。动态规划的状态转移方程即为上述递推关系，边界条件为 T(0)、T(1) 和 T(2)。
// 根据状态转移方程和边界条件，可以得到时间复杂度和空间复杂度都是 O(n) 的实现。由于 T(n) 只和前三项有关，因此可以使用「滚动数组思想」将空间复杂度优化成 O(1)。如下的代码中给出的就是这种实现。
// class Solution {
// public:
//     int tribonacci(int n) {
//         if (n == 0) {
//             return 0;
//         }
//         if (n <= 2) {
//             return 1;
//         }
//         int p = 0, q = 0, r = 1, s = 1;
//         for (int i = 3; i <= n; ++i) {
//             p = q;
//             q = r;
//             r = s;
//             s = p + q + r;
//         }
//         return s;
//     }
// };
// 复杂度分析
// 时间复杂度：O(n)。
// 空间复杂度：O(1)。

// 方法二：矩阵快速幂
// 方法一的时间复杂度是 O(n)。使用矩阵快速幂的方法可以降低时间复杂度。
// 首先我们可以构建这样一个递推关系：
// [111100010][T(n)T(n−1)T(n−2)]=[T(n)+T(n−1)+T(n−2)T(n)T(n−1)]=[T(n+1)T(n)T(n−1)]
// 因此：
// [T(n+2)T(n+1)T(n)]=[111100010]n[T(2)T(1)T(0)]
// 令：
// M=[111100010]
// 因此只要我们能快速计算矩阵 M 的 n 次幂，就可以得到 T(n) 的值。如果直接求取 M^n ，时间复杂度是 O(n)，可以定义矩阵乘法，然后用快速幂算法来加速这里 M^n 的求取。
// class Solution {
// public:
//     int tribonacci(int n) {
//         if (n == 0) {
//             return 0;
//         }
//         if (n <= 2) {
//             return 1;
//         }
//         vector<vector<long>> q = {{1, 1, 1}, {1, 0, 0}, {0, 1, 0}};
//         vector<vector<long>> res = pow(q, n);
//         return res[0][2];
//     }

//     vector<vector<long>> pow(vector<vector<long>>& a, long n) {
//         vector<vector<long>> ret = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
//         while (n > 0) {
//             if ((n & 1) == 1) {
//                 ret = multiply(ret, a);
//             }
//             n >>= 1;
//             a = multiply(a, a);
//         }
//         return ret;
//     }

//     vector<vector<long>> multiply(vector<vector<long>>& a, vector<vector<long>>& b) {
//         vector<vector<long>> c(3, vector<long>(3));
//         for (int i = 0; i < 3; i++) {
//             for (int j = 0; j < 3; j++) {
//                 c[i][j] = a[i][0] * b[0][j] + a[i][1] * b[1][j] + a[i][2] * b[2][j];
//             }
//         }
//         return c;
//     }
// };
// 复杂度分析 
// 时间复杂度：O(log⁡n)。 
// 空间复杂度：O(1)。