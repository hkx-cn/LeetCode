// 389. 找不同
// 给定两个字符串 s 和 t ，它们只包含小写字母。

// 字符串 t 由字符串 s 随机重排，然后在随机位置添加一个字母。

// 请找出在 t 中被添加的字母。

 

// 示例 1：
// 输入：s = "abcd", t = "abcde"
// 输出："e"
// 解释：'e' 是那个被添加的字母。

// 示例 2：
// 输入：s = "", t = "y"
// 输出："y"
 

// 提示： 
// 0 <= s.length <= 1000
// t.length == s.length + 1
// s 和 t 只包含小写字母

#include "LeetCode389.h"

char Solution::findTheDifference(string s, string t) {

	int map[26] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
	for (size_t i = 0; i < s.size(); i++)
	{
		map[s[i] - 65]++;
	}
	for (size_t i = 0; i < t.size(); i++)
	{
		map[t[i] - 65]--;
	}
	for (size_t i = 0; i < 26; i++)
	{
		if (map[i] == -1) {
			return i + 65;
		}
	}
};
//方法一：计数
//首先遍历字符串 s，对其中的每个字符都将计数值加 1；然后遍历字符串 t，对其中的每个字符都将计数值减 1。当发现某个字符计数值为负数时，说明该字符在字符串 t 中出现的次数大于在字符串 s 中出现的次数，因此该字符为被添加的字符。
//char Solution::findTheDifference(string s, string t) {
//	int as = 0, at = 0;
//	for (char ch : s) {
//		as += ch;
//	}
//	for (char ch : t) {
//		at += ch;
//	}
//	return at - as;
//};
//复杂度分析

//时间复杂度：O(N)，其中 N 为字符串的长度。

//空间复杂度：O(∣Σ∣)，其中 Σ 是字符集，这道题中字符串只包含小写字母，∣Σ∣=26|。需要使用数组对每个字符计数。
//方法二：求和
//将字符串 s 中每个字符的 ASCII 码的值求和，得到 As ；对字符串 t 同样的方法得到 At 。两者的差值 At−As 即代表了被添加的字符。 
//char  Solution::findTheDifference(string s, string t) {
//	int ret = 0;
//	for (char ch : s) {
//		ret ^= ch;
//	}
//	for (char ch : t) {
//		ret ^= ch;
//	}
//	return ret;
//};
// 复杂度分析

// 时间复杂度：O(N)。

// 空间复杂度：O(1)。

// 方法三：位运算
// 如果将两个字符串拼接成一个字符串，则问题转换成求字符串中出现奇数次的字符。类似于「136. 只出现一次的数字」，我们使用位运算的技巧解决本题。
// class Solution {
// public:
//     char findTheDifference(string s, string t) {
//         int ret = 0;
//         for (char ch: s) {
//             ret ^= ch;
//         }
//         for (char ch: t) {
//             ret ^= ch;
//         }
//         return ret;
//     }
// };
// 复杂度分析

// 时间复杂度：O(N)。

// 空间复杂度：O(1)。