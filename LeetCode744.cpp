//744. 寻找比目标字母大的最小字母
//给你一个字符数组 letters，该数组按非递减顺序排序，以及一个字符 target。letters 里至少有两个不同的字符。
//
//返回 letters 中大于 target 的最小的字符。如果不存在这样的字符，则返回 letters 的第一个字符。
//
//
//
//示例 1：
//
//输入 : letters = ["c", "f", "j"]，target = "a"
//输出 : "c"
//解释：letters 中字典上比 'a' 大的最小字符是 'c'。
//示例 2 :
//
//	输入 : letters = ["c", "f", "j"], target = "c"
//	输出 : "f"
//	解释：letters 中字典顺序上大于 'c' 的最小字符是 'f'。
//	示例 3 :
//
//	输入 : letters = ["x", "x", "y", "y"], target = "z"
//	输出 : "x"
//	解释：letters 中没有一个字符在字典上大于 'z'，所以我们返回 letters[0]。
//
//
//	提示：
//
//	2 <= letters.length <= 104
//	letters[i] 是一个小写字母
//	letters 按非递减顺序排序
//	letters 最少包含两个不同的字母
//	target 是一个小写字母
#include"LeetCode744.h"
char Solution::nextGreatestLetter(vector<char>& letters, char target) {
	int left = 0, right = letters.size() - 1, mid = 0;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (letters[mid] > target)
		{
			right = mid - 1;
		}
		else if (letters[mid] <= target)
		{
			left = mid + 1;
		}
	}
	if (left == letters.size())
	{
		return letters[0];
	}
	else
		return letters[left];
};
//方法一：线性查找
//由于给定的列表已经按照递增顺序排序，因此可以从左到右遍历列表，找到第一个比目标字母大的字母，即为比目标字母大的最小字母。
//
//如果目标字母小于列表中的最后一个字母，则一定可以在列表中找到比目标字母大的最小字母。如果目标字母大于或等于列表中的最后一个字母，则列表中不存在比目标字母大的字母，根据循环出现的顺序，列表的首个字母是比目标字母大的最小字母。
//class Solution {
//public:
//	char nextGreatestLetter(vector<char>& letters, char target) {
//		for (char letter : letters) {
//			if (letter > target) {
//				return letter;
//			}
//		}
//		return letters[0];
//	}
//};
//复杂度分析
//
//时间复杂度：O(n)O(n)O(n)，其中 nnn 是列表 letters\textit{ letters }letters 的长度。需要遍历列表一次寻找比目标字母大的最小字母。
//
//空间复杂度：O(1)O(1)O(1)。
//
//方法二：二分查找
//利用列表有序的特点，可以使用二分查找降低时间复杂度。
//
//首先比较目标字母和列表中的最后一个字母，当目标字母大于或等于列表中的最后一个字母时，答案是列表的首个字母。当目标字母小于列表中的最后一个字母时，列表中一定存在比目标字母大的字母，可以使用二分查找得到比目标字母大的最小字母。
//
//初始时，二分查找的范围是整个列表的下标范围。每次比较当前下标处的字母和目标字母，如果当前下标处的字母大于目标字母，则在当前下标以及当前下标的左侧继续查找，否则在当前下标的右侧继续查找。
//class Solution {
//public:
//	char nextGreatestLetter(vector<char>& letters, char target) {
//		return target < letters.back() ? *upper_bound(letters.begin(), letters.end() - 1, target) : letters[0];
//	}
//};
//复杂度分析
//
//时间复杂度：O(log⁡n)O(\log n)O(logn)，其中 nnn 是列表 letters\textit{ letters }letters 的长度。二分查找的时间复杂度是 O(log⁡n)O(\log n)O(logn)。
//
//空间复杂度：O(1)O(1)O(1)。 