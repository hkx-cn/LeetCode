﻿//1672. 最富有客户的资产总量
//给你一个 m x n 的整数网格 accounts ，其中 accounts[i][j] 是第 i​​​​​​​​​​​​ 位客户在第 j 家银行托管的资产数量。返回最富有客户所拥有的 资产总量 。
//
//客户的 资产总量 就是他们在各家银行托管的资产数量之和。最富有客户就是 资产总量 最大的客户。
// 
//示例 1： 
//输入：accounts = [[1, 2, 3], [3, 2, 1]]
//输出：6
//解释：
//第 1 位客户的资产总量 = 1 + 2 + 3 = 6
//第 2 位客户的资产总量 = 3 + 2 + 1 = 6
//两位客户都是最富有的，资产总量都是 6 ，所以返回 6 。 
//示例 2： 
//输入：accounts = [[1, 5], [7, 3], [3, 5]]
//输出：10
//解释：
//第 1 位客户的资产总量 = 6
//第 2 位客户的资产总量 = 10
//第 3 位客户的资产总量 = 8
//第 2 位客户是最富有的，资产总量是 10 
//示例 3： 
//输入：accounts = [[2, 8, 7], [7, 1, 3], [1, 9, 5]]
//输出：17
//
//
//提示： 
//m == accounts.length
//n == accounts[i].length
//1 <= m, n <= 50
//1 <= accounts[i][j] <= 100
#include "LeetCode1672.hpp"
int Solution::maximumWealth(vector<vector<int>>& accounts) {
	int max = 0, tmp = 0;
	for (size_t i = 0; i < accounts.size(); i++)
	{
		tmp = 0;
		for (size_t j = 0; j < accounts[i].size(); j++)
		{
			tmp += accounts[i][j];
		}
		if (tmp > max)
		{
			max = tmp;
		}
	}
	return max;
};
//方法一：遍历
//思路与算法 
//分别计算每位客户在各家银行托管的资产数量之和，返回这些资产总量的最大值。
//class Solution {
//public:
//	int maximumWealth(vector<vector<int>>& accounts) {
//		int maxWealth = INT_MIN;
//		for (auto& account : accounts) {
//			maxWealth = max(maxWealth, accumulate(account.begin(), account.end(), 0));
//		}
//		return maxWealth;
//	}
//};
//复杂度分析 
//时间复杂度：O(mn)，其中 m 和 n 分别是网格 accounts 的行数和列数。 
//空间复杂度：O(1)。