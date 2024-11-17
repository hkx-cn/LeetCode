// 2469. 温度转换
// 给你一个四舍五入到两位小数的非负浮点数 celsius 来表示温度，以
// 摄氏度（Celsius）为单位。 你需要将摄氏度转换为 开氏度（Kelvin）和
// 华氏度（Fahrenheit），并以数组 ans = [kelvin, fahrenheit] 的形式返回结果。
// 返回数组 ans 。与实际答案误差不超过 10^-5 的会视为正确答案。
// 注意：
// 开氏度 = 摄氏度 + 273.15
// 华氏度 = 摄氏度 * 1.80 + 32.00

// 示例 1 ：
// 输入：celsius = 36.50
// 输出：[309.65000,97.70000]
// 解释：36.50 摄氏度：转换为开氏度是 309.65 ，转换为华氏度是 97.70 。
// 示例 2 ：
// 输入：celsius = 122.11
// 输出：[395.26000,251.79800]
// 解释：122.11 摄氏度：转换为开氏度是 395.26 ，转换为华氏度是 251.798 。

// 提示：
// 0 <= celsius <= 1000
#include "LeetCode2469.hpp"

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
double *convertTemperature(double celsius, int *returnSize) {
    double *result = (double *)malloc(sizeof(double) * 2);
    result[0] = celsius + 273.15;
    result[1] = celsius * 1.8 + 32;
    *returnSize = 2;
    return result;
}

// vector<double> Solution::convertTemperature(double celsius) {
//     vector<double> result;
//     result.push_back(celsius + 273.15);
//     result.push_back(celsius * 1.8 + 32);
//     return result;
// };

// 方法一：模拟
// 思路与算法
// 题目要求将给定摄氏度 celsius
// 转换为开氏度和华氏度，我们根据题目给定的计算公式直接计算即可，其中计算公式如下:
// 开氏度：Kelvin=Celsius+237.15；
// 华氏度：Fahrenheit=Celsius×1.80+32.00；
// class Solution {
// public:
//     vector<double> convertTemperature(double celsius) {
//         return {celsius + 273.15, celsius * 1.80 + 32.00};
//     }
// };
// 复杂度分析
// 时间复杂度：O(1)。
// 空间复杂度：O(1)。

