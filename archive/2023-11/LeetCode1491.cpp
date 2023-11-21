// 1491. 去掉最低工资和最高工资后的工资平均值
// 给你一个整数数组 salary ，数组里每个数都是 唯一 的，其中 salary[i] 是第 i 个员工的工资。

// 请你返回去掉最低工资和最高工资以后，剩下员工工资的平均值。

// 示例 1： 
// 输入：salary = [4000,3000,1000,2000]
// 输出：2500.00000
// 解释：最低工资和最高工资分别是 1000 和 4000 。
// 去掉最低工资和最高工资以后的平均工资是 (2000+3000)/2= 2500
//
// 示例 2： 
// 输入：salary = [1000,2000,3000]
// 输出：2000.00000
// 解释：最低工资和最高工资分别是 1000 和 3000 。
// 去掉最低工资和最高工资以后的平均工资是 (2000)/1= 2000
//
// 示例 3： 
// 输入：salary = [6000,5000,4000,3000,2000,1000]
// 输出：3500.00000
//
// 示例 4： 
// 输入：salary = [8000,9000,2000,3000,6000,1000]
// 输出：4750.00000

// 提示：

// 3 <= salary.length <= 100
// 10^3 <= salary[i] <= 10^6
// salary[i] 是唯一的。
// 与真实值误差在 10^-5 以内的结果都将视为正确答案。
#include "LeetCode1491.h"

double Solution::average(vector<int> &salary)
{
    double result = 0;
    sort(salary.begin(), salary.end());
    for (size_t i = 1; i < salary.size() - 1; i++)
    {
        result += salary[i];
    }
    return result / (salary.size() - 2);
};
// 方法一：模拟
// 思路

// 我们可以按照题意来模拟：

// 找到一个最大值 maxValue；

// 找到一个最小值 minValue；

// 然后对所有元素求和后减去这两个值 sum=(∑isalary[i])−maxValue−minValue；

// 求平均值 sum/[salary.size()−2]。

// 因为这里保证了 salary 数组的长度至少是 3，所以我们不用特殊考虑 maxValue 和 minValu 是同一个的问题，因为如果它们相等的话（假设等于 x），这个序列里面所有元素都应该是 x，不影响计算结果。
// class Solution {
// public:
//     double average(vector<int>& salary) {
//         double maxValue = *max_element(salary.begin(), salary.end());
//         double minValue = *min_element(salary.begin(), salary.end());
//         double sum = accumulate(salary.begin(), salary.end(), - maxValue - minValue);
//         return sum / int(salary.size() - 2);
//     }
// };
// 复杂度

// 时间复杂度：O(n)。选取最大值、最小值和求和的过程的时间代价都是 O(n)，故渐进时间复杂度为 O(n)。

// 空间复杂度：O(1)。这里只用到了常量级别的辅助空间。