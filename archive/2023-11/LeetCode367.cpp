// 367. 有效的完全平方数
// 给你一个正整数 num 。如果 num 是一个完全平方数，则返回 true ，否则返回 false 。
// 完全平方数 是一个可以写成某个整数的平方的整数。换句话说，它可以写成某个整数和自身的乘积。
// 不能使用任何内置的库函数，如  sqrt 。
//
// 示例 1：
// 输入：num = 16
// 输出：true
// 解释：返回 true ，因为 4 * 4 = 16 且 4 是一个整数。
// 示例 2：
// 输入：num = 14
// 输出：false
// 解释：返回 false ，因为 3.742 * 3.742 = 14 但 3.742 不是一个整数。
//
// 提示：
// 1 <= num <= 2^31 - 1
#include "LeetCode367.hpp"
bool Solution::isPerfectSquare(int num)
{
	// 二分查找
	// 值范围[1,46340]
	int left = 1, right = num > 46340 ? 46340 : num, mid = -1;
	while (left <= right)
	{
		mid = left + (right - left) / 2;
		if (mid * mid < num)
		{
			left = mid + 1;
		}
		else if (mid * mid > num)
		{
			right = mid - 1;
		}
		else if (mid * mid == num)
		{
			return true;
		}
	}
	return false;
};

// bool Solution::isPerfectSquare(int num) {
// 	int left = 1, right = num, mid = -1;
// 	while (left <= right)
// 	{
// 		mid = left + (right - left) / 2;
// 		if (mid > 46340)
// 		{
// 			right = mid - 1; continue;
// 		}
// 		if (mid * mid == num)
// 		{
// 			return true;
// 		}
// 		else if (mid * mid < num)
// 		{
// 			left = mid + 1;
// 		}
// 		else if (mid * mid > num)
// 		{
// 			right = mid - 1;
// 		}
// 	}
// 	return false;
// };
// 前言
// 在方法一中，我们使用内置的库函数来解决问题。
// 在方法二、方法三和方法四中，我们不使用库函数来解决进阶问题。注意，因为不能使用任何内置的库函数，所以也不能使用类似 √x = x^1/2 = (e^ln⁡x)^1/2 = e^1/2^ln⁡x 的公式来通过其他库函数计算平方根。

// 方法一：使用内置的库函数
// 思路和算法
// 根据完全平方数的性质，我们只需要直接判断 num 的平方根 x 是否为整数即可。对于不能判断浮点数的值是否等于整数的语言，则可以通过以下规则判断：
// 若 √num  为正整数，则有 ⌊xi⌋^2 = (√num)^2 = num，其中符号 ⌊x⌋ 表示 x 的向下取整。
// class Solution {
// public:
//     bool isPerfectSquare(int num) {
//         int x = (int)sqrt(num);
//         return x * x == num;
//     }
// };
// 复杂度分析
// 代码中使用的 pow 函数的时空复杂度与 CPU 支持的指令集相关，这里不深入分析。
//
// 方法二：暴力
// 思路和算法
// 如果 num 为完全平方数，那么一定存在正整数 x 满足 x×x = num。于是我们可以从 1 开始，从小到大遍历所有正整数，寻找是否存在满足 x×x = num 的正整数 x。在遍历中，如果出现正整数 x 使 x×x > num，那么更大的正整数也不可能满足 x×x = num，不需要继续遍历了。
// class Solution {
// public:
//     bool isPerfectSquare(int num) {
//         long x = 1, square = 1;
//         while (square <= num) {
//             if (square == num) {
//                 return true;
//             }
//             ++x;
//             square = x * x;
//         }
//         return false;
//     }
// };
// 复杂度分析
// 时间复杂度：O(√n)，其中 n 为正整数 num 的最大值。我们最多需要遍历 √n + 1 个正整数。
// 空间复杂度：O(1)。
//
// 方法三：二分查找
// 思路和算法
// 考虑使用二分查找来优化方法二中的搜索过程。因为 num 是正整数，所以若正整数 x 满足 x×x = num，则 x 一定满足 1≤x≤num。于是我们可以将 1 和 num 作为二分查找搜索区间的初始边界。
// 细节
// 因为我们在移动左侧边界 left 和右侧边界 right 时，新的搜索区间都不会包含被检查的下标 mid，所以搜索区间的边界始终是我们没有检查过的。因此，当left = right 时，我们仍需要检查 mid = (left + right) / 2。
// class Solution {
// public:
//     bool isPerfectSquare(int num) {
//         int left = 0, right = num;
//         while (left <= right) {
//             int mid = (right - left) / 2 + left;
//             long square = (long)mid * mid;
//             if (square < num) {
//                 left = mid + 1;
//             }
//             else if (square > num) {
//                 right = mid - 1;
//             }
//             else {
//                 return true;
//             }
//         }
//         return false;
//     }
// };
// 复杂度分析
// 时间复杂度：O(log⁡n)，其中 n 为正整数 num 的最大值。
// 空间复杂度：O(1)。
//
// 方法四：牛顿迭代法
// 前置知识
// 牛顿迭代法。牛顿迭代法是一种近似求解方程（近似求解函数零点）的方法。其本质是借助泰勒级数，从初始值开始快速向函数零点逼近。
// 对于函数 f(x)，我们任取 x0 作为初始值。在每一次迭代中，我们根据当前值 xi 找到函数图像上的点(xi, f(xi)) ，过该点做一条斜率为该点导数 f′(x0) 的直线，该直线与横轴（X 轴）的交点记作(xi + 1, 0)。xi+1 相较于 xi 而言，距离函数零点更近。在经过多次迭代后，我们就可以得到距离函数零点非常近的交点。
// 思路
// 如果 num 为完全平方数，那么一定存在正整数 x 满足 x×x = num。于是我们写出如下方程：
// y = f(x) = x^2−num
// 如果方程能够取得整数解，则说明存在满足 x×x = num 的正整数 x。这个方程可以通过牛顿迭代法求解。
// 算法
// 在算法实现中，我们需要解决以下四个问题：
// 如何选取初始值？
// 因为 num 是正整数，所以 y = x^2−num 有两个零点 −√num  和 √num ，其中 1≤√num≤num 。我们只需要判断 √num 是否为正整数即可。又因为 y = x^2−num 是凸函数，所以只要我们选取的初始值大于等于 √num ，那么每次迭代得到的结果也都会大于等于 √num 。
// 因此，我们可以选择 num 作为初始值。
// 如何进行迭代？
// 对 f(x) 求导，得到
// f′(x) = 2x
// 假设当前值为 xi ，将 xi 代入 f(x) 得到函数图像上的点(xi, xi^2−num)，过该点做一条斜率为 f′(xi) = 2xi 的直线，则直线的方程为
// y−(xi^2−num) = 2xi(x−xi) 直线与横轴（X 轴）交点的横坐标为上式中的 y = 0 时 x 的解。于是令上式中 y = 0，得到
// 2xix−xi^2−num = 0
// 整理上式即可得到下一次迭代的值：
// xi+1 = (xi^2 + num)/2*xi = 1/2*(xi + num/xi) (1)
// 如何判断迭代是否可以结束？
// 每一次迭代后，我们都会距离零点更近一步，所以当相邻两次迭代的结果非常接近时，我们就可以断定，此时的结果已经足够我们得到答案了。一般来说，可以判断相邻两次迭代的结果的差值是否小于一个极小的非负数 ϵ，其中 ϵ 一般可以取 10^−6 或 10^−7 。
// 如何通过迭代得到的近似零点得到最终的答案？
// 因为初始值的选择以及 y = x^2−num 凸函数的性质，我们通过迭代得到的 xi 一定是 √num 的近似零点，且满足 xi≥√numx 。
// 当 num 是完全平方数时，√num 为正整数，则有 ⌊xi⌋^2 = (√num)^2 = num ，其中符号 ⌊x⌋ 表示 x 的向下取整。
//
// class Solution {
// public:
//    bool isPerfectSquare(int num) {
//        double x0 = num;
//        while (true) {
//            double x1 = (x0 + num / x0) / 2;
//            if (x0 - x1 < 1e-6) {
//                break;
//            }
//            x0 = x1;
//        }
//        int x = (int)x0;
//        return x * x == num;
//    }
//};
// 复杂度分析
// 时间复杂度：O(log⁡n)，其中 n 为正整数 num 的最大值。具体计算如下：
// 不妨设当前值为 xi ，误差为 ϵi = xi^2−num ；根据式(1) 解得下一次迭代的值为 xi+1，误差为
// ϵi+1 = xi+1^2−num = ((xi^2 + num)/2*xi)2−num = (xi^2−num)2/4*xi^2 = ϵi^2/4*xi^2
// 因为 num 是正整数，所以有
// ϵi+1/ϵi = ϵi/4*xi^2 = (xi^2−num)/4*xi^2 < 1/4
// 因为每一次迭代都可以将误差缩小到原来的 1/4 以下，所以只需要最多 log⁡4 m 次迭代即可将误差缩小到阈值范围内，其中 m 为初始值的误差与阈值的比。根据大 O 符号表示法，其量级可以表示为 O(log⁡n)。
// 空间复杂度：O(1)。