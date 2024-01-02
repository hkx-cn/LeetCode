//1422. 分割字符串的最大得分
//给你一个由若干 0 和 1 组成的字符串 s ，请你计算并返回将该字符串分割成两个 非空 子字符串（即 左 子字符串和 右 子字符串）所能获得的最大得分。
//「分割字符串的得分」为 左 子字符串中 0 的数量加上 右 子字符串中 1 的数量。
//
//示例 1： 
//输入：s = "011101"
//输出：5
//解释：
//将字符串 s 划分为两个非空子字符串的可行方案有：
//左子字符串 = "0" 且 右子字符串 = "11101"，得分 = 1 + 4 = 5
//左子字符串 = "01" 且 右子字符串 = "1101"，得分 = 1 + 3 = 4
//左子字符串 = "011" 且 右子字符串 = "101"，得分 = 1 + 2 = 3
//左子字符串 = "0111" 且 右子字符串 = "01"，得分 = 1 + 1 = 2
//左子字符串 = "01110" 且 右子字符串 = "1"，得分 = 2 + 1 = 3
//示例 2： 
//输入：s = "00111"
//输出：5
//解释：当 左子字符串 = "00" 且 右子字符串 = "111" 时，我们得到最大得分 = 2 + 3 = 5
//示例 3： 
//输入：s = "1111"
//输出：3
//
//
//提示：
//2 <= s.length <= 500
//字符串 s 仅由字符 '0' 和 '1' 组成。
#include "LeetCode1422.hpp"
int Solution::maxScore(string s) {
	string left, right;
	int max = 0,tmp = 0;
	for (size_t i = 1; i < s.size() - 1; i++)
	{
		left = s.substr(0, i);
		right = s.substr(i);
		tmp = count(left.begin(), left.end(), '0') + count(right.begin(), right.end(), '1');
		max = max > tmp ? max : tmp;
	}
	return max;
};
//方法一：枚举每个分割点
//用 n 表示字符串 s 的长度。对于每个 1≤i < n，下标 i 是一个分割点，将字符串 s 分割成两个非空子字符串，左子字符串的下标范围是[0, i−1]，右子字符串的下标范围是[i, n−1]，分别计算左子字符串中的 0 的个数和右子字符串中的 1 的个数即可得到分割字符串的得分。遍历所有的分割点，即可得到分割字符串的最大得分。
// class Solution {
// public:
// 	int maxScore(string s) {
// 		int ans = 0;
// 		int n = s.size();
// 		for (int i = 1; i < n; i++) {
// 			int score = 0;
// 			for (int j = 0; j < i; j++) {
// 				if (s[j] == '0') {
// 					score++;
// 				}
// 			}
// 			for (int j = i; j < n; j++) {
// 				if (s[j] == '1') {
// 					score++;
// 				}
// 			}
// 			ans = max(ans, score);
// 		}
// 		return ans;
// 	}
// };
//复杂度分析
//时间复杂度：O(n^2) ，其中 n 是字符串 s 的长度。需要遍历 n−1 个分割点，对于每个分割点需要 O(n) 的时间遍历整个字符串计算分割字符串的得分，因此时间复杂度是 O(n^2)。
//空间复杂度：O(1)。
//
//方法二：两次遍历
//方法一中，对于每个分割点遍历整个字符串计算分割字符串的得分。可以换一个角度思考，如果分割点从左到右移动一位，则位于原分割点处的字符从右子字符串中移除并添加到左子字符串中，根据该字符的值更新分割字符串的得分。
//当 1≤i < n 时，分割点 i 将字符串 s 分割成两个非空子字符串，左子字符串的下标范围是[0, i−1]，右子字符串的下标范围是[i, n−1]。对于 1≤i < n−1，当分割点从 i 移动到 i + 1 时，位于下标 i 处的字符 s[i] 从右子字符串中移除并添加到左子字符串中，分割字符串的得分变化如下：
// 如果 s[i] = 0，则左子字符串的得分加 1，右子字符串的得分不变，因此分割字符串的得分加 1；
// 如果 s[i] = 1，则左子字符串的得分不变，右子字符串的得分减 1，因此分割字符串的得分减 1。
// 由于最左侧的分割点是 i = 1，因此首先计算 i = 1 处的分割字符串的得分，然后从左到右依次遍历每个分割点，遍历过程中更新分割字符串的得分，遍历结束之后即可得到分割字符串的最大得分。
// class Solution {
// public:
// 	int maxScore(string s) {
// 		int score = 0;
// 		int n = s.size();
// 		if (s[0] == '0') {
// 			score++;
// 		}
// 		for (int i = 1; i < n; i++) {
// 			if (s[i] == '1') {
// 				score++;
// 			}
// 		}
// 		int ans = score;
// 		for (int i = 1; i < n - 1; i++) {
// 			if (s[i] == '0') {
// 				score++;
// 			}
// 			else {
// 				score--;
// 			}
// 			ans = max(ans, score);
// 		}
// 		return ans;
// 	}
// };
//复杂度分析
//时间复杂度：O(n)，其中 n 是字符串 s 的长度。需要遍历字符串两次。
//空间复杂度：O(1)。