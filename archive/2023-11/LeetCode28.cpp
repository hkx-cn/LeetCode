//28. 找出字符串中第一个匹配项的下标
//给你两个字符串 haystack 和 needle ，请你在 haystack 字符串中找出 needle 字符串的第一个匹配项的下标（下标从 0 开始）。如果 needle 不是 haystack 的一部分，则返回 - 1 。
//
//
//
//示例 1：
//
//输入：haystack = "sadbutsad", needle = "sad"
//输出：0
//解释："sad" 在下标 0 和 6 处匹配。
//第一个匹配项的下标是 0 ，所以返回 0 。
//示例 2：
//
//输入：haystack = "leetcode", needle = "leeto"
//输出： - 1
//解释："leeto" 没有在 "leetcode" 中出现，所以返回 - 1 。
//
//
//提示：
//
//1 <= haystack.length, needle.length <= 104
//haystack 和 needle 仅由小写英文字符组成

#include "LeetCode28.h"

int Solution::strStr(string haystack, string needle) { 
	bool isFind = false;
	if (haystack.size() < needle.size()) { return -1; }
	for (size_t i = 0; i < haystack.size() - needle.size(); i++)
	{
		isFind = true;
		for (size_t j = 0; j < needle.size(); j++)
		{
			if (haystack[i + j] != needle[j]) {
				isFind = false; break;
			}
		}
		if (isFind)
		{
			return i;
		}
	}
	return -1;
};

//KMP算法
//思路及算法
//
//Knuth - Morris - Pratt\text{ Knuth - Morris - Pratt }Knuth - Morris - Pratt 算法，简称 KMP\text{ KMP }KMP 算法，由 Donald Knuth\text{ Donald Knuth }Donald Knuth、James H.Morris\text{ James H.Morris }James H.Morris 和 Vaughan Pratt\text{ Vaughan Pratt }Vaughan Pratt 三人于 197719771977 年联合发表。
//
//Knuth - Morris - Pratt\text{ Knuth - Morris - Pratt }Knuth - Morris - Pratt 算法的核心为前缀函数，记作 π(i)\pi(i)π(i)，其定义如下：
//
//对于长度为 mmm 的字符串 sss，其前缀函数 π(i)(0≤i < m)\pi(i)(0 \leq i < m)π(i)(0≤i < m) 表示 sss 的子串 s[0:i]s[0:i]s[0:i] 的最长的相等的真前缀与真后缀的长度。特别地，如果不存在符合条件的前后缀，那么 π(i) = 0\pi(i) = 0π(i) = 0。其中真前缀与真后缀的定义为不等于自身的的前缀与后缀。
//
//	我们举个例子说明：字符串 aabaaabaabaaabaabaaab 的前缀函数值依次为 0, 1, 0, 1, 2, 2, 30, 1, 0, 1, 2, 2, 30, 1, 0, 1, 2, 2, 3。
//
//	π(0) = 0\pi(0) = 0π(0) = 0，因为 aaa 没有真前缀和真后缀，根据规定为 000（可以发现对于任意字符串 π(0) = 0\pi(0) = 0π(0) = 0 必定成立）；
//
//	π(1) = 1\pi(1) = 1π(1) = 1，因为 aaaaaa 最长的一对相等的真前后缀为 aaa，长度为 111；
//
//	π(2) = 0\pi(2) = 0π(2) = 0，因为 aabaabaab 没有对应真前缀和真后缀，根据规定为 000；
//
//	π(3) = 1\pi(3) = 1π(3) = 1，因为 aabaaabaaaba 最长的一对相等的真前后缀为 aaa，长度为 111；
//
//	π(4) = 2\pi(4) = 2π(4) = 2，因为 aabaaaabaaaabaa 最长的一对相等的真前后缀为 aaaaaa，长度为 222；
//
//	π(5) = 2\pi(5) = 2π(5) = 2，因为 aabaaaaabaaaaabaaa 最长的一对相等的真前后缀为 aaaaaa，长度为 222；
//
//	π(6) = 3\pi(6) = 3π(6) = 3，因为 aabaaabaabaaabaabaaab 最长的一对相等的真前后缀为 aabaabaab，长度为 333。
//
//	有了前缀函数，我们就可以快速地计算出模式串在主串中的每一次出现。
//
//	如何求解前缀函数
//
//	长度为 mmm 的字符串 sss 的所有前缀函数的求解算法的总时间复杂度是严格 O(m)O(m)O(m) 的，且该求解算法是增量算法，即我们可以一边读入字符串，一边求解当前读入位的前缀函数。
//
//	为了叙述方便，我们接下来将说明几个前缀函数的性质：
//
//	π(i)≤π(i−1) + 1\pi(i) \leq \pi(i - 1) + 1π(i)≤π(i−1) + 1。
//	依据 π(i)\pi(i)π(i) 定义得：s[0:π(i)−1] = s[i−π(i) + 1:i]s[0:\pi(i) - 1] = s[i - \pi(i) + 1:i]s[0:π(i)−1] = s[i−π(i) + 1:i]。
//	将两区间的右端点同时左移，可得：s[0:π(i)−2] = s[i−π(i) + 1:i−1]s[0:\pi(i) - 2] = s[i - \pi(i) + 1:i - 1]s[0:π(i)−2] = s[i−π(i) + 1:i−1]。
//	依据 π(i−1)\pi(i - 1)π(i−1) 定义得：π(i−1)≥π(i)−1\pi(i - 1) \geq \pi(i) - 1π(i−1)≥π(i)−1，即 π(i)≤π(i−1) + 1\pi(i) \leq \pi(i - 1) + 1π(i)≤π(i−1) + 1。
//	如果 s[i] = s[π(i−1)]s[i] = s[\pi(i - 1)]s[i] = s[π(i−1)]，那么 π(i) = π(i−1) + 1\pi(i) = \pi(i - 1) + 1π(i) = π(i−1) + 1。
//	依据 π(i−1)\pi(i - 1)π(i−1) 定义得：s[0:π(i−1)−1] = s[i−π(i−1):i−1]s[0:\pi(i - 1) - 1] = s[i - \pi(i - 1):i - 1]s[0:π(i−1)−1] = s[i−π(i−1):i−1]。
//	因为 s[π(i−1)] = s[i]s[\pi(i - 1)] = s[i]s[π(i−1)] = s[i]，可得 s[0:π(i−1)] = s[i−π(i−1):i]s[0:\pi(i - 1)] = s[i - \pi(i - 1):i]s[0:π(i−1)] = s[i−π(i−1):i]。
//	依据 π(i)\pi(i)π(i) 定义得：π(i)≥π(i−1) + 1\pi(i)\geq\pi(i - 1) + 1π(i)≥π(i−1) + 1，结合第一个性质可得 π(i) = π(i−1) + 1\pi(i) = \pi(i - 1) + 1π(i) = π(i−1) + 1。
//	这样我们可以依据这两个性质提出求解 π(i)\pi(i)π(i) 的方案：找到最大的 jjj，满足 s[0:j−1] = s[i−j:i−1]s[0:j - 1] = s[i - j:i - 1]s[0:j−1] = s[i−j:i−1]，且 s[i] = s[j]s[i] = s[j]s[i] = s[j]（这样就有 s[0:j] = s[i−j:i]s[0:j] = s[i - j:i]s[0:j] = s[i−j:i]，即 π(i) = j + 1\pi(i) = j + 1π(i) = j + 1）。
//
//	注意这里提出了两个要求：
//
//	jjj 要求尽可能大，且满足 s[0:j−1] = s[i−j:i−1]s[0:j - 1] = s[i - j:i - 1]s[0:j−1] = s[i−j:i−1]；
//	jjj 要求满足 s[i] = s[j]s[i] = s[j]s[i] = s[j]。
//	由 π(i−1)\pi(i - 1)π(i−1) 定义可知：
//
//	s[0:π(i−1)−1] = s[i−π(i−1):i−1](1)s[0:\pi(i - 1) - 1] = s[i - \pi(i - 1):i - 1] \tag{ 1 }
//	s[0:π(i−1)−1] = s[i−π(i−1):i−1](1)
//	那么 j = π(i−1)j = \pi(i - 1)j = π(i−1) 符合第一个要求。如果 s[i] = s[π(i−1)]s[i] = s[\pi(i - 1)]s[i] = s[π(i−1)]，我们就可以确定 π(i)\pi(i)π(i)。
//
//	否则如果 s[i]≠s[π(i−1)]s[i]\neq s[\pi(i - 1)]s[i]
//	
//	= s[π(i−1)]，那么 π(i)≤π(i−1)\pi(i) \leq \pi(i - 1)π(i)≤π(i−1)，因为 j = π(i)−1j = \pi(i) - 1j = π(i)−1，所以 j  < π(i−1)j  < \pi(i - 1)j  < π(i−1)，于是可以取 (1)(1)(1) 式两子串的长度为 jjj 的后缀，它们依然是相等的：s[π(i−1)−j:π(i−1)−1] = s[i−j:i−1]s[\pi(i - 1) - j:\pi(i - 1) - 1] = s[i - j:i - 1]s[π(i−1)−j:π(i−1)−1] = s[i−j:i−1]。
//
//	当 s[i]≠s[π(i−1)]s[i]\neq s[\pi(i - 1)]s[i]
//	
//	= s[π(i−1)] 时，我们可以修改我们的方案为：找到最大的 jjj，满足 s[0:j−1] = s[π(i−1)−j:π(i−1)−1]s[0:j - 1] = s[\pi(i - 1) - j:\pi(i - 1) - 1]s[0:j−1] = s[π(i−1)−j:π(i−1)−1]，且 s[i] = s[π(i−1)]s[i] = s[\pi(i - 1)]s[i] = s[π(i−1)]（这样就有 s[0:j] = s[π(i−1)−j:π(i−1)]s[0:j] = s[\pi(i - 1) - j:\pi(i - 1)]s[0:j] = s[π(i−1)−j:π(i−1)]，即 π(i) = π(i−1) + 1\pi(i) = \pi(i - 1) + 1π(i) = π(i−1) + 1）。
//
//	注意这里提出了两个要求：
//
//	jjj 要求尽可能大，且满足 s[0:j−1] = s[π(i−1)−j:π(i−1)−1]s[0:j - 1] = s[\pi(i - 1) - j:\pi(i - 1) - 1]s[0:j−1] = s[π(i−1)−j:π(i−1)−1]；
//	jjj 要求满足 s[i] = s[j]s[i] = s[j]s[i] = s[j]。
//	由 π(π(i−1)−1)\pi(\pi(i - 1) - 1)π(π(i−1)−1) 定义可知 j = π(π(i−1)−1)j = \pi(\pi(i - 1) - 1)j = π(π(i−1)−1) 符合第一个要求。如果 s[i] = s[π(π(i−1)−1)]s[i] = s[\pi(\pi(i - 1) - 1)]s[i] = s[π(π(i−1)−1)]，我们就可以确定 π(i)\pi(i)π(i)。
//
//	此时，我们可以发现 jjj 的取值总是被描述为 π(π(π(…)−1)−1)\pi(\pi(\pi(\ldots) - 1) - 1)π(π(π(…)−1)−1) 的结构（初始为 π(i−1)\pi(i - 1)π(i−1)）。于是我们可以描述我们的算法：设定 π(i) = j + 1\pi(i) = j + 1π(i) = j + 1，jjj 的初始值为 π(i−1)\pi(i - 1)π(i−1)。我们只需要不断迭代 jjj（令 jjj 变为 π(j−1)\pi(j - 1)π(j−1)）直到 s[i] = s[j]s[i] = s[j]s[i] = s[j] 或 j = 0j = 0j = 0 即可，如果最终匹配成功（找到了 jjj 使得 s[i] = s[j]s[i] = s[j]s[i] = s[j]），那么 π(i) = j + 1\pi(i) = j + 1π(i) = j + 1，否则 π(i) = 0\pi(i) = 0π(i) = 0。
//
//	复杂度证明
//
//	时间复杂度部分，注意到 π(i)≤π(i−1) + 1\pi(i)\leq \pi(i - 1) + 1π(i)≤π(i−1) + 1，即每次当前位的前缀函数至多比前一位增加一，每当我们迭代一次，当前位的前缀函数的最大值都会减少。可以发现前缀函数的总减少次数不会超过总增加次数，而总增加次数不会超过 mmm 次，因此总减少次数也不会超过 mmm 次，即总迭代次数不会超过 mmm 次。
//
//	空间复杂度部分，我们只用到了长度为 mmm 的数组保存前缀函数，以及使用了常数的空间保存了若干变量。
//
//	如何解决本题
//
//	记字符串 haystack\textit{ haystack }haystack 的长度为 nnn，字符串 needle\textit{ needle }needle 的长度为 mmm。
//
//	我们记字符串 str = needle + # + haystack\textit{ str } = \textit{ needle } + \# + \textit{ haystack }str = needle + # + haystack，即将字符串 needle\textit{ needle }needle 和 haystack\textit{ haystack }haystack 进行拼接，并用不存在于两串中的特殊字符 #\## 将两串隔开，然后我们对字符串 str\textit{ str }str 求前缀函数。
//
//	因为特殊字符 #\## 的存在，字符串 str\textit{ str }str 中 haystack\textit{ haystack }haystack 部分的前缀函数所对应的真前缀必定落在字符串 needle\textit{ needle }needle 部分，真后缀必定落在字符串 haystack\textit{ haystack }haystack 部分。当 haystack\textit{ haystack }haystack 部分的前缀函数值为 mmm 时，我们就找到了一次字符串 needle\textit{ needle }needle 在字符串 haystack\textit{ haystack }haystack 中的出现（因为此时真前缀恰为字符串 needle\textit{ needle }needle）。
//
//	实现时，我们可以进行一定的优化，包括：
//
//	我们无需显式地创建字符串 str\textit{ str }str。
//	为了节约空间，我们只需要顺次遍历字符串 needle\textit{ needle }needle、特殊字符 #\## 和字符串 haystack\textit{ haystack }haystack 即可。
//	也无需显式地保存所有前缀函数的结果，而只需要保存字符串 needle\textit{ needle }needle 部分的前缀函数即可。
//	特殊字符 #\## 的前缀函数必定为 000，且易知 π(i)≤m\pi(i) \leq mπ(i)≤m（真前缀不可能包含特殊字符 #\##）。
//	这样我们计算 π(i)\pi(i)π(i) 时，j = π(π(π(…)−1)−1)j = \pi(\pi(\pi(\ldots) - 1) - 1)j = π(π(π(…)−1)−1) 的所有的取值中仅有 π(i−1)\pi(i - 1)π(i−1) 的下标可能大于等于 mmm。我们只需要保存前一个位置的前缀函数，其它的 jjj 的取值将全部为字符串 needle\textit{ needle }needle 部分的前缀函数。
//	我们也无需特别处理特殊字符 #\##，只需要注意处理字符串 haystack\textit{ haystack }haystack 的第一个位置对应的前缀函数时，直接设定 jjj 的初值为 000 即可。
//	这样我们可以将代码实现分为两部分：
//
//	第一部分是求 needle\textit{ needle }needle 部分的前缀函数，我们需要保留这部分的前缀函数值。
//	第二部分是求 haystack\textit{ haystack }haystack 部分的前缀函数，我们无需保留这部分的前缀函数值，只需要用一个变量记录上一个位置的前缀函数值即可。当某个位置的前缀函数值等于 mmm 时，说明我们就找到了一次字符串 needle\textit{ needle }needle 在字符串 haystack\textit{ haystack }haystack 中的出现（因为此时真前缀恰为字符串 needle\textit{ needle }needle，真后缀为以当前位置为结束位置的字符串 haystack\textit{ haystack }haystack 的子串），我们计算出起始位置，将其返回即可。

//int Solution::strStr(string haystack, string needle) {
//    int n = haystack.size(), m = needle.size();
//    if (m == 0) {
//        return 0;
//    }
//    vector<int> pi(m);
//    for (int i = 1, j = 0; i < m; i++) {
//        while (j > 0 && needle[i] != needle[j]) {
//            j = pi[j - 1];
//        }
//        if (needle[i] == needle[j]) {
//            j++;
//        }
//        pi[i] = j;
//    }
//    for (int i = 0, j = 0; i < n; i++) {
//        while (j > 0 && haystack[i] != needle[j]) {
//            j = pi[j - 1];
//        }
//        if (haystack[i] == needle[j]) {
//            j++;
//        }
//        if (j == m) {
//            return i - m + 1;
//        }
//    }
//    return -1; 
//}; 