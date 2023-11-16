//242. 有效的字母异位词
//给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。
//
//注意：若 s 和 t 中每个字符出现的次数都相同，则称 s 和 t 互为字母异位词。
//
//
//
//示例 1:
//
//输入: s = "anagram", t = "nagaram"
//输出 : true
//示例 2 :
//
//	输入 : s = "rat", t = "car"
//	输出 : false
//
//
//	提示 :
//
//	1 <= s.length, t.length <= 5 * 104
//	s 和 t 仅包含小写字母
//
//
//	进阶 : 如果输入字符串包含 unicode 字符怎么办？你能否调整你的解法来应对这种情况？
#include "LeetCode242.h"

bool Solution::isAnagram(string s, string t) {
	int a1[26] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
	int a2[26] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
	for (size_t i = 0; i < s.size(); i++)
	{
		a1[s[i] - 97]++;
	}
	for (size_t i = 0; i < t.size(); i++)
	{
		a2[t[i] - 97]++;
	}
	for (size_t i = 0; i < 26; i++)
	{
		if (a1[i] != a2[i])
		{
			return false;
		}
	}
	return true;
};

//t 是 sss 的异位词等价于「两个字符串排序后相等」。因此我们可以对字符串 sss 和 ttt 分别排序，看排序后的字符串是否相等即可判断。此外，如果 sss 和 ttt 的长度不同，ttt 必然不是 sss 的异位词。
//class Solution {
//public:
//	bool isAnagram(string s, string t) {
//		if (s.length() != t.length()) {
//			return false;
//		}
//		sort(s.begin(), s.end());
//		sort(t.begin(), t.end());
//		return s == t;
//	}
//}; 
//复杂度分析
//
//时间复杂度：O(nlog⁡n)O(n \log n)O(nlogn)，其中 nnn 为 sss 的长度。排序的时间复杂度为 O(nlog⁡n)O(n\log n)O(nlogn)，比较两个字符串是否相等时间复杂度为 O(n)O(n)O(n)，因此总体时间复杂度为 O(nlog⁡n + n) = O(nlog⁡n)O(n \log n + n) = O(n\log n)O(nlogn + n) = O(nlogn)。
//
//空间复杂度：O(log⁡n)O(\log n)O(logn)。排序需要 O(log⁡n)O(\log n)O(logn) 的空间复杂度。注意，在某些语言（比如 Java & JavaScript）中字符串是不可变的，因此我们需要额外的 O(n)O(n)O(n) 的空间来拷贝字符串。但是我们忽略这一复杂度分析，因为：
//
//这依赖于语言的细节；
//这取决于函数的设计方式，例如，可以将函数参数类型更改为 char[]。 