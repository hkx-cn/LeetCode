//389. 找不同
//给定两个字符串 s 和 t ，它们只包含小写字母。
//
//字符串 t 由字符串 s 随机重排，然后在随机位置添加一个字母。
//
//请找出在 t 中被添加的字母。
//
//
//
//示例 1：
//
//输入：s = "abcd", t = "abcde"
//输出："e"
//解释：'e' 是那个被添加的字母。
//示例 2：
//
//输入：s = "", t = "y"
//输出："y"
//
//
//提示：
//
//0 <= s.length <= 1000
//t.length == s.length + 1
//s 和 t 只包含小写字母

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
//
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