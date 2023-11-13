//13. 罗马数字转整数
//罗马数字包含以下七种字符 : I， V， X， L，C，D 和 M。
//
//字符          数值
//I             1
//V             5
//X             10
//L             50
//C             100
//D             500
//M             1000
//例如， 罗马数字 2 写做 II ，即为两个并列的 1 。12 写做 XII ，即为 X + II 。 27 写做  XXVII, 即为 XX + V + II 。
//
//通常情况下，罗马数字中小的数字在大的数字的右边。但也存在特例，例如 4 不写做 IIII，而是 IV。数字 1 在数字 5 的左边，所表示的数等于大数 5 减小数 1 得到的数值 4 。同样地，数字 9 表示为 IX。这个特殊的规则只适用于以下六种情况：
//
//IV(5) 和 X(10) 的左边，来表示 4 和 9。
//XL(50) 和 C(100) 的左边，来表示 40 和 90。
//CD(500) 和 M(1000) 的左边，来表示 400 和 900。
//给定一个罗马数字，将其转换成整数。
//
//
//
//示例 1:
//
//输入: s = "III"
//输出 : 3
//示例 2 :
//
//	输入 : s = "IV"
//	输出 : 4
//	示例 3 :
//
//	输入 : s = "IX"
//	输出 : 9
//	示例 4 :
//
//	输入 : s = "LVIII"
//	输出 : 58
//	解释 : L = 50, V = 5, III = 3.
//	示例 5 :
//
//	输入 : s = "MCMXCIV"
//	输出 : 1994
//	解释 : M = 1000, CM = 900, XC = 90, IV = 4.
//
//
//	提示：
//
//	1 <= s.length <= 15
//	s 仅含字符('I', 'V', 'X', 'L', 'C', 'D', 'M')
//	题目数据保证 s 是一个有效的罗马数字，且表示整数在范围[1, 3999] 内
//	题目所给测试用例皆符合罗马数字书写规则，不会出现跨位等情况。
//	IL 和 IM 这样的例子并不符合题目要求，49 应该写作 XLIX，999 应该写作 CMXCIX 。
//	关于罗马数字的详尽书写规则，可以参考 罗马数字 - Mathematics 。
#include "LeetCode13.h"
int Solution::romanToInt(string s) {
	//I             1
	//V             5
	//X             10
	//L             50
	//C             100
	//D             500
	//M             1000
	//IV            4
	//IX            9
	//XL            40 
	//XC            90
	//CD            400
	//CM            900
	int result = 0;
	string tmp;
	for (size_t i = 0; i < s.size(); i++)
	{
		tmp = s.substr(i, 2);
		if (tmp == "IV" || tmp == "IX" || tmp == "XL" || tmp == "XC" || tmp == "CD" || tmp == "CM")
		{
			if (tmp == "IV")
			{
				result += 4;
			}
			else if (tmp == "IX")
			{
				result += 9;
			}
			else if (tmp == "XL")
			{
				result += 40;
			}
			else if (tmp == "XC")
			{
				result += 90;
			}
			else if (tmp == "CD")
			{
				result += 400;
			}
			else if (tmp == "CM")
			{
				result += 900;
			}
			i++;
		}
		else
		{
			tmp = s.substr(i, 1);
			if (tmp == "I")
			{
				result += 1;
			}
			else if (tmp == "V")
			{
				result += 5;
			}
			else if (tmp == "X")
			{
				result += 10;
			}
			else if (tmp == "L")
			{
				result += 50;
			}
			else if (tmp == "C")
			{
				result += 100;
			}
			else if (tmp == "D")
			{
				result += 500;
			}
			else if (tmp == "M")
			{
				result += 1000;
			} 
		}
	}
	return result;
};
//方法一：模拟
//思路
//
//通常情况下，罗马数字中小的数字在大的数字的右边。若输入的字符串满足该情况，那么可以将每个字符视作一个单独的值，累加每个字符对应的数值即可。
//
//例如 XXVII\texttt{ XXVII }XXVII 可视作 X + X + V + I + I = 10 + 10 + 5 + 1 + 1 = 27\texttt{ X } + \texttt{ X } + \texttt{ V } + \texttt{ I } + \texttt{ I } = 10 + 10 + 5 + 1 + 1 = 27X + X + V + I + I = 10 + 10 + 5 + 1 + 1 = 27。
//
//若存在小的数字在大的数字的左边的情况，根据规则需要减去小的数字。对于这种情况，我们也可以将每个字符视作一个单独的值，若一个数字右侧的数字比它大，则将该数字的符号取反。
//
//例如 XIV\texttt{ XIV }XIV 可视作 X−I + V = 10−1 + 5 = 14\texttt{ X } - \texttt{ I } + \texttt{ V } = 10 - 1 + 5 = 14X−I + V = 10−1 + 5 = 14。
//class Solution {
//private:
//	unordered_map<char, int> symbolValues = {
//		{'I', 1},
//		{'V', 5},
//		{'X', 10},
//		{'L', 50},
//		{'C', 100},
//		{'D', 500},
//		{'M', 1000},
//	};
//
//public:
//	int romanToInt(string s) {
//		int ans = 0;
//		int n = s.length();
//		for (int i = 0; i < n; ++i) {
//			int value = symbolValues[s[i]];
//			if (i < n - 1 && value < symbolValues[s[i + 1]]) {
//				ans -= value;
//			}
//			else {
//				ans += value;
//			}
//		}
//		return ans;
//	}
//};
//复杂度分析
//
//时间复杂度：O(n)O(n)O(n)，其中 nnn 是字符串 sss 的长度。
//
//空间复杂度：O(1)O(1)O(1)。