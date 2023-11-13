#include "LeetCodeMain.h" 
#include "LeetCode54.h"

int main()
{
	Solution solution;
	//vector<vector<int>> matrix = { {1,2,3,4}, {5,6,7,8}, {9,10,11,12} };
	vector<vector<int>> matrix = { {3} ,{2} };
	vector<int> result = solution.spiralOrder(matrix);
	cin.get();
}