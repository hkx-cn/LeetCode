// 746. 使用最小花费爬楼梯
// 给你一个整数数组 cost ，其中 cost[i] 是从楼梯第 i 个台阶向上爬需要支付的费用。一旦你支付此费用，即可选择向上爬一个或者两个台阶。
// 你可以选择从下标为 0 或下标为 1 的台阶开始爬楼梯。
// 请你计算并返回达到楼梯顶部的最低花费。

// 示例 1：
// 输入：cost = [10,15,20]
// 输出：15
// 解释：你将从下标为 1 的台阶开始。
// - 支付 15 ，向上爬两个台阶，到达楼梯顶部。
// 总花费为 15 。
// 示例 2：
// 输入：cost = [1,100,1,1,1,100,1,1,100,1]
              // 0, 0,1,1,2,  2,3,4,4,  5,6
// 输出：6
// 解释：你将从下标为 0 的台阶开始。
// - 支付 1 ，向上爬两个台阶，到达下标为 2 的台阶。
// - 支付 1 ，向上爬两个台阶，到达下标为 4 的台阶。
// - 支付 1 ，向上爬两个台阶，到达下标为 6 的台阶。
// - 支付 1 ，向上爬一个台阶，到达下标为 7 的台阶。
// - 支付 1 ，向上爬两个台阶，到达下标为 9 的台阶。
// - 支付 1 ，向上爬一个台阶，到达楼梯顶部。
// 总花费为 6 。

// 提示：
// 2 <= cost.length <= 1000
// 0 <= cost[i] <= 999
#include "LeetCode746.hpp"
int Solution::minCostClimbingStairs(vector<int> &cost)
{
    int c0 = 0, c1 = 0, temp = 0;
    if (cost.size() < 2)
        return 0;
    for (size_t i = 2; i <= cost.size(); i++)
    {
        temp = c0 + cost[i - 2] < c1 + cost[i - 1] ? c0 + cost[i - 2] : c1 + cost[i - 1];
        c0 = c1;
        c1 = temp;
    }
    return c1;
}
// int Solution::minCostClimbingStairs(vector<int> &cost)
// {
//     int t0 = cost[0], t1 = cost[1], result;
//     for (size_t i = 2; i < cost.size(); i++)
//     {
//         result = t0 < t1 ? t0 : t1;
//         t0 = t1;
//         t1 = result + cost[i];
//     }
//     return t0 < t1 ? t0 : t1;
// }
// 方法一：动态规划
// 假设数组 cost 的长度为 n，则 n 个阶梯分别对应下标 0 到 n−1，楼层顶部对应下标 n，问题等价于计算达到下标 n 的最小花费。可以通过动态规划求解。
// 创建长度为 n+1 的数组 dp，其中 dp[i] 表示达到下标 i 的最小花费。
// 由于可以选择下标 0 或 1 作为初始阶梯，因此有 dp[0]=dp[1]=0。
// 当 2≤i≤n 时，可以从下标 i−1 使用 cost[i−1] 的花费达到下标 i，或者从下标 i−2 使用 cost[i−2] 的花费达到下标 i。为了使总花费最小，dp[i] 应取上述两项的最小值，因此状态转移方程如下：

// dp[i]=min⁡(dp[i−1]+cost[i−1],dp[i−2]+cost[i−2])
// 依次计算 dp 中的每一项的值，最终得到的 dp[n] 即为达到楼层顶部的最小花费。
// class Solution {
// public:
//     int minCostClimbingStairs(vector<int>& cost) {
//         int n = cost.size();
//         vector<int> dp(n + 1);
//         dp[0] = dp[1] = 0;
//         for (int i = 2; i <= n; i++) {
//             dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
//         }
//         return dp[n];
//     }
// };
// 上述代码的时间复杂度和空间复杂度都是 O(n)。注意到当 i≥2 时，dp[i] 只和 dp[i−1] 与 dp[i−2] 有关，因此可以使用滚动数组的思想，将空间复杂度优化到 O(1)。
// class Solution {
// public:
//     int minCostClimbingStairs(vector<int>& cost) {
//         int n = cost.size();
//         int prev = 0, curr = 0;
//         for (int i = 2; i <= n; i++) {
//             int next = min(curr + cost[i - 1], prev + cost[i - 2]);
//             prev = curr;
//             curr = next;
//         }
//         return curr;
//     }
// };
// 复杂度分析
// 时间复杂度：O(n)，其中 n 是数组 cost 的长度。需要依次计算每个 dp 值，每个值的计算需要常数时间，因此总时间复杂度是 O(n)。
// 空间复杂度：O(1)。使用滚动数组的思想，只需要使用有限的额外空间。