// 509. 斐波那契数
// 斐波那契数 （通常用 F(n) 表示）形成的序列称为 斐波那契数列 。该数列由 0 和 1 开始，后面的每一项数字都是前面两项数字的和。也就是：

// F(0) = 0，F(1) = 1
// F(n) = F(n - 1) + F(n - 2)，其中 n > 1
// 给定 n ，请计算 F(n) 。

// 示例 1：
// 输入：n = 2
// 输出：1
// 解释：F(2) = F(1) + F(0) = 1 + 0 = 1
// 示例 2：
// 输入：n = 3
// 输出：2
// 解释：F(3) = F(2) + F(1) = 1 + 1 = 2
// 示例 3：
// 输入：n = 4
// 输出：3
// 解释：F(4) = F(3) + F(2) = 2 + 1 = 3

// 提示：
// 0 <= n <= 30
#include "LeetCode509.hpp"

int fib(int n) {
    int n0 = 0, n1 = 1, temp = 0;
    if (n <= 1) {
        return n;
    }
    for (int i = 0; i < n - 1; i++) {
        temp = n0 + n1;
        n0 = n1;
        n1 = temp;
    }
    return temp;
}

// int Solution::fib(int n) {
//     int f0 = 0, f1 = 1, temp = 0;
//     if (n == 1)
//         return f0;
//     if (n == 2)
//         return f1;
//     for (size_t i = 2; i <= n; i++)
//     {
//         temp = f0 + f1;
//         f0 = f1;
//         f1 = temp;
//     }
//     return f1;
// }
// int Solution::fib(int n)
// {
//     int a = 0, b = 1, result = 0;
//     if (n == 0)
//         return 0;
//     else if (n == 1)
//         return 1;
//     else
//     {
//         for (size_t i = 2; i <= n; i++)
//         {
//             result = a + b;
//             a = b;
//             b = result;
//         }
//     }
//     return result;
// }
// 方法一：动态规划
// 斐波那契数的边界条件是 F(0)=0 和 F(1)=1。当 n>1 时，每一项的和都等于前两项的和，因此有如下递推关系：
// F(n)=F(n−1)+F(n−2)
// 由于斐波那契数存在递推关系，因此可以使用动态规划求解。动态规划的状态转移方程即为上述递推关系，边界条件为 F(0) 和 F(1)。
// 根据状态转移方程和边界条件，可以得到时间复杂度和空间复杂度都是 O(n) 的实现。由于 F(n) 只和 F(n−1) 与 F(n−2) 有关，因此可以使用「滚动数组思想」把空间复杂度优化成 O(1)。如下的代码中给出的就是这种实现。
// class Solution {
// public:
//     int fib(int n) {
//         if (n < 2) {
//             return n;
//         }
//         int p = 0, q = 0, r = 1;
//         for (int i = 2; i <= n; ++i) {
//             p = q;
//             q = r;
//             r = p + q;
//         }
//         return r;
//     }
// };
// 复杂度分析
// 时间复杂度：O(n)。
// 空间复杂度：O(1)。

// 方法二：矩阵快速幂
// 方法一的时间复杂度是 O(n)。使用矩阵快速幂的方法可以降低时间复杂度。
// 首先我们可以构建这样一个递推关系：
// [1110][F(n)F(n−1)]=[F(n)+F(n−1)F(n)]=[F(n+1)F(n)]
// 因此：
// [F(n+1)F(n)]=[1110]^n[F(1)F(0)]
// 令：
// M=[1110]
// 因此只要我们能快速计算矩阵 M 的 n 次幂，就可以得到 F(n) 的值。如果直接求取 M^n ，时间复杂度是 O(n)，可以定义矩阵乘法，然后用快速幂算法来加速这里 M^n 的求取。
// class Solution {
// public:
//     int fib(int n) {
//         if (n < 2) {
//             return n;
//         }
//         vector<vector<int>> q{{1, 1}, {1, 0}};
//         vector<vector<int>> res = matrix_pow(q, n - 1);
//         return res[0][0];
//     }

//     vector<vector<int>> matrix_pow(vector<vector<int>>& a, int n) {
//         vector<vector<int>> ret{{1, 0}, {0, 1}};
//         while (n > 0) {
//             if (n & 1) {
//                 ret = matrix_multiply(ret, a);
//             }
//             n >>= 1;
//             a = matrix_multiply(a, a);
//         }
//         return ret;
//     }

//     vector<vector<int>> matrix_multiply(vector<vector<int>>& a, vector<vector<int>>& b) {
//         vector<vector<int>> c{{0, 0}, {0, 0}};
//         for (int i = 0; i < 2; i++) {
//             for (int j = 0; j < 2; j++) {
//                 c[i][j] = a[i][0] * b[0][j] + a[i][1] * b[1][j];
//             }
//         }
//         return c;
//     }
// };
// 复杂度分析
// 时间复杂度：O(logn)。
// 空间复杂度：O(1)。

// 方法三：通项公式
// 斐波那契数 F(n) 是齐次线性递推，根据递推方程 F(n)=F(n−1)+F(n−2)，可以写出这样的特征方程：
// x^2=x+1
// 求得 x1=(1+√5)/2 ，x2=(1−√5)/2 。设通解为 F(n)=c1x1^n+c2x2^n ，代入初始条件 F(0)=0，F(1)=1，得 c1=1/√5 ，c2=−1/√5 。因此斐波那契数的通项公式如下：
// F(n)=1/√5[((1+√5)/2)^n−((1−√5)/2)^n]
// 得到通项公式之后，就可以通过公式直接求解第 n 项。
// class Solution {
// public:
//     int fib(int n) {
//         double sqrt5 = sqrt(5);
//         double fibN = pow((1 + sqrt5) / 2, n) - pow((1 - sqrt5) / 2, n);
//         return round(fibN / sqrt5);
//     }
// };
// 复杂度分析
// 代码中使用的 pow 函数的时空复杂度与 CPU 支持的指令集相关，这里不深入分析。
