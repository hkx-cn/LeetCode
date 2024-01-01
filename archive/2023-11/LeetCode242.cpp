//242. 有效的字母异位词
//给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。
//注意：若 s 和 t 中每个字符出现的次数都相同，则称 s 和 t 互为字母异位词。
//
// 
//示例 1:
//输入: s = "anagram", t = "nagaram"
//输出 : true
//示例 2 : 
//输入 : s = "rat", t = "car"
//输出 : false


//提示 :
//1 <= s.length, t.length <= 5 * 10^4
//s 和 t 仅包含小写字母

//进阶 : 如果输入字符串包含 unicode 字符怎么办？你能否调整你的解法来应对这种情况？
#include "LeetCode242.hpp"

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
}
// 方法一：排序
//t 是 s 的异位词等价于「两个字符串排序后相等」。因此我们可以对字符串 s 和 t 分别排序，看排序后的字符串是否相等即可判断。此外，如果 s 和 t 的长度不同，t 必然不是 s 的异位词。
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
//时间复杂度：O(nlog⁡n)，其中 n 为 s 的长度。排序的时间复杂度为 O(nlog⁡n)，比较两个字符串是否相等时间复杂度为 O(n)，因此总体时间复杂度为 O(nlog⁡n + n) = O(nlog⁡n)。
//空间复杂度：O(log⁡n)。排序需要 O(log⁡n) 的空间复杂度。注意，在某些语言（比如 Java & JavaScript）中字符串是不可变的，因此我们需要额外的 O(n) 的空间来拷贝字符串。但是我们忽略这一复杂度分析，因为：
//
//这依赖于语言的细节；
//这取决于函数的设计方式，例如，可以将函数参数类型更改为 char[]。 
//方法二：哈希表
//从另一个角度考虑，t 是 s 的异位词等价于「两个字符串中字符出现的种类和次数均相等」。由于字符串只包含 26 个小写字母，因此我们可以维护一个长度为 26 的频次数组 table，先遍历记录字符串 s 中字符出现的频次，然后遍历字符串 t，减去 table 中对应的频次，如果出现 table[i]<0，则说明 t 包含一个不在 s 中的额外字符，返回 false 即可。
// class Solution {
// public:
//     bool isAnagram(string s, string t) {
//         if (s.length() != t.length()) {
//             return false;
//         }
//         vector<int> table(26, 0);
//         for (auto& ch: s) {
//             table[ch - 'a']++;
//         }
//         for (auto& ch: t) {
//             table[ch - 'a']--;
//             if (table[ch - 'a'] < 0) {
//                 return false;
//             }
//         }
//         return true;
//     }
// };
// 对于进阶问题，Unicode 是为了解决传统字符编码的局限性而产生的方案，它为每个语言中的字符规定了一个唯一的二进制编码。而 Unicode 中可能存在一个字符对应多个字节的问题，为了让计算机知道多少字节表示一个字符，面向传输的编码方式的 UTF−8 和 UTF−16 也随之诞生逐渐广泛使用，具体相关的知识读者可以继续查阅相关资料拓展视野，这里不再展开。
// 回到本题，进阶问题的核心点在于「字符是离散未知的」，因此我们用哈希表维护对应字符的频次即可。同时读者需要注意 Unicode 一个字符可能对应多个字节的问题，不同语言对于字符串读取处理的方式是不同的。
// 复杂度分析
// 时间复杂度：O(n)，其中 n 为 s 的长度。
// 空间复杂度：O(S)，其中 S 为字符集大小，此处 S=26。