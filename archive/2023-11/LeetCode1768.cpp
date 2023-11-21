// 1768. 交替合并字符串
// 给你两个字符串 word1 和 word2 。请你从 word1 开始，通过交替添加字母来合并字符串。如果一个字符串比另一个字符串长，就将多出来的字母追加到合并后字符串的末尾。

// 返回 合并后的字符串 。


// 示例 1： 
// 输入：word1 = "abc", word2 = "pqr"
// 输出："apbqcr"
// 解释：字符串合并情况如下所示：
// word1：  a   b   c
// word2：    p   q   r
// 合并后：  a p b q c r
//
// 示例 2： 
// 输入：word1 = "ab", word2 = "pqrs"
// 输出："apbqrs"
// 解释：注意，word2 比 word1 长，"rs" 需要追加到合并后字符串的末尾。
// word1：  a   b 
// word2：    p   q   r   s
// 合并后：  a p b q   r   s
//
// 示例 3： 
// 输入：word1 = "abcd", word2 = "pq"
// 输出："apbqcd"
// 解释：注意，word1 比 word2 长，"cd" 需要追加到合并后字符串的末尾。
// word1：  a   b   c   d
// word2：    p   q 
// 合并后：  a p b q c   d
 

// 提示：

// 1 <= word1.length, word2.length <= 100
// word1 和 word2 由小写英文字母组成 
#include "LeetCode1768.h"

string Solution::mergeAlternately(string word1, string word2) {
	string result;
	while (word1.size() != 0)
	{
		result += word1[0];
		word1.erase(0, 1);
		if (word2.size() != 0)
		{
			result += word2[0];
			word2.erase(0, 1);
		}
	}
	if (word2.size() != 0)
	{
		result += word2;
	}
	return result;
};  
// 方法一：双指针
// 思路与算法

// 我们直接按照题目的要求模拟即可。我们使用两个指针 i 和 j，初始时分别指向两个字符串的首个位置。随后的每次循环中，依次进行如下的两步操作：

// 如果 i 没有超出 word1 的范围，就将 word1[i] 加入答案，并且将 i 移动一个位置；

// 如果 j 没有超出 word2 的范围，就将 word2[j] 加入答案，并且将 j 移动一个位置。

// 当 i 和 j 都超出对应的范围后，结束循环并返回答案即可。
// class Solution {
// public:
//     string mergeAlternately(string word1, string word2) {
//         int m = word1.size(), n = word2.size();
//         int i = 0, j = 0;
        
//         string ans;
//         ans.reserve(m + n);
//         while (i < m || j < n) {
//             if (i < m) {
//                 ans.push_back(word1[i]);
//                 ++i;
//             }
//             if (j < n) {
//                 ans.push_back(word2[j]);
//                 ++j;
//             }
//         }
//         return ans;
//     }
// };
// 复杂度分析 
// 时间复杂度：O(m+n)，其中 m 和 n 分别是字符串 word1 和 word2 的长度。 
// 空间复杂度：O(1) 或 O(m+n)。如果使用的语言支持可修改的字符串，那么空间复杂度为 O(1)，否则为 O(m+n)。注意这里不计入返回值需要的空间。