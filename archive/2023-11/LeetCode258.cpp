//258. 各位相加
//给定一个非负整数 num，反复将各个位上的数字相加，直到结果为一位数。返回这个结果。
//
//
//
//示例 1:
//
//输入: num = 38
//输出 : 2
//解释 : 各位相加的过程为：
//38 -- > 3 + 8 -- > 11
//11 -- > 1 + 1 -- > 2
//由于 2 是一位数，所以返回 2。
//示例 2:
//
//输入: num = 0
//输出 : 0
//
//
//提示：
//
//0 <= num <= 231 - 1
//
//
//进阶：你可以不使用循环或者递归，在 O(1) 时间复杂度内解决这个问题吗？
#include"LeetCode258.h"
int Solution::addDigits(int num) {
	int a = 0,result = num;
	while (num >= 10)
	{
		a = num;
		result = 0;
		while (a >= 10)
		{
			result += ( a % 10 ); a /= 10;
		}
		result += a;
		num = result;
	}
	return result;
};
//前言
//这道题的本质是计算自然数 num\textit{ num }num 的数根。
//
//数根又称数字根（Digital root\text{ Digital root }Digital root），是自然数的一种性质，每个自然数都有一个数根。对于给定的自然数，反复将各个位上的数字相加，直到结果为一位数，则该一位数即为原自然数的数根。
//
//计算数根的最直观的方法是模拟计算各位相加的过程，直到剩下的数字是一位数。利用自然数的性质，则能在 O(1)O(1)O(1) 的时间内计算数根。
//
//方法一：模拟
//思路和算法
//
//最直观的方法是模拟各位相加的过程，直到剩下的数字是一位数。
//
//计算一个整数的各位相加的做法是，每次计算当前整数除以 101010 的余数得到最低位数，将最低位数加到总和中，然后将当前整数除以 101010。重复上述操作直到当前整数变成 000，此时的总和即为原整数各位相加的结果。
//class Solution {
//public:
//	int addDigits(int num) {
//		while (num >= 10) {
//			int sum = 0;
//			while (num > 0) {
//				sum += num % 10;
//				num /= 10;
//			}
//			num = sum;
//		}
//		return num;
//	}
//};
//复杂度分析
//
//时间复杂度：O(log⁡num)O(\log \textit{ num })O(lognum)，其中 num\textit{ num }num 是给定的整数。对于 num\textit{ num }num 计算一次各位相加需要 O(log⁡num)O(\log \textit{ num })O(lognum) 的时间，由于 num≤231−1\textit{ num } \le 2 ^ {31} - 1num≤2
//31
//−1，因此对于 num\textit{ num }num 计算一次各位相加的最大可能结果是 828282，对于任意两位数最多只需要计算两次各位相加的结果即可得到一位数。
//
//空间复杂度：O(1)O(1)O(1)。
//
//方法二：数学
//思路和算法
//
//假设整数 num\textit{ num }num 的十进制表示有 nnn 位，从最低位到最高位依次是 a0a_0a
//0
//​
//到 an−1a_{ n - 1 }a
//n−1
//​
//，则 num\textit{ num }num 可以写成如下形式：
//
//num = ∑i = 0n−1ai×10i = ∑i = 0n−1ai×(10i−1 + 1) = ∑i = 0n−1ai×(10i−1) + ∑i = 0n−1ai\begin{ aligned } \textit{ num } &= \sum_{ i = 0 }^ {n - 1} a_i \times 10 ^ i \\ &= \sum_{ i = 0 }^ {n - 1} a_i \times(10 ^ i - 1 + 1) \\ &= \sum_{ i = 0 }^ {n - 1} a_i \times(10 ^ i - 1) + \sum_{ i = 0 }^ {n - 1} a_i \end{ aligned }
//num
//​
//
//=
//i = 0
//∑
//n−1
//​
//a
//i
//​
//×10
//i
//
//=
//i = 0
//∑
//n−1
//​
//a
//i
//​
//×(10
//	i
//	−1 + 1)
//	=
//	i = 0
//	∑
//	n−1
//	​
//	a
//	i
//	​
//	×(10
//		i
//		−1) +
//	i = 0
//	∑
//	n−1
//	​
//	a
//	i
//	​
//
//	​
//
//	当 i = 0i = 0i = 0 时，10i−1 = 010 ^ i - 1 = 010
//	i
//	−1 = 0 是 999 的倍数；当 iii 是正整数时，10i−110 ^ i - 110
//	i
//	−1 是由 iii 位 999 组成的整数，也是 999 的倍数。因此对于任意非负整数 iii，10i−110 ^ i - 110
//	i
//	−1 都是 999 的倍数。由此可得 num\textit{ num }num 与其各位相加的结果模 999 同余。重复计算各位相加的结果直到结果为一位数时，该一位数即为 num\textit{ num }num 的数根，num\textit{ num }num 与其数根模 999 同余。
//
//	我们对 num\textit{ num }num 分类讨论：
//
//	num\textit{ num }num 不是 999 的倍数时，其数根即为 num\textit{ num }num 除以 999 的余数。
//
//	num\textit{ num }num 是 999 的倍数时：
//
//	如果 num = 0\textit{ num } = 0num = 0，则其数根是 000；
//
//	如果 num > 0\textit{ num } > 0num > 0，则各位相加的结果大于 000，其数根也大于 000，因此其数根是 999。
//
//	细节
//
//	根据上述分析可知，当 num > 0\textit{ num } > 0num > 0 时，其数根的结果在范围[1, 9][1, 9][1, 9] 内，因此可以想到计算 num−1\textit{ num } - 1num−1 除以 999 的余数然后加 111。由于当 num > 0\textit{ num } > 0num > 0 时，num−1≥0\textit{ num } - 1 \ge 0num−1≥0，非负数除以 999 的余数一定也是非负数，因此计算 num−1\textit{ num } - 1num−1 除以 999 的余数然后加 111 的结果是正确的。
//
//	当 num = 0\textit{ num } = 0num = 0 时，num−1 = −1 < 0\textit{ num } - 1 = -1 < 0num−1 = −1 < 0，负数对 999 取余或取模的结果的正负在不同语言中有所不同。
//
//	对于取余的语言，结果的正负和左操作数相同，则 num−1\textit{ num } - 1num−1 对 999 取余的结果为 −1 - 1−1，加 111 后得到结果 000，可以得到正确的结果；
//
//	对于取模的语言，结果的正负和右操作数相同，则 num−1\textit{ num } - 1num−1 对 999 取模的结果为 888，加 111 后得到结果 999，无法得到正确的结果，此时需要对 num = 0\textit{ num } = 0num = 0 的情况专门做处理。
//class Solution {
//public:
//	int addDigits(int num) {
//		return (num - 1) % 9 + 1;
//	}
//};
//复杂度分析
//
//时间复杂度：O(1)O(1)O(1)。
//
//空间复杂度：O(1)O(1)O(1)。