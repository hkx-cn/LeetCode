//               90. 子集 II
//     中等 │ 1286  │ 63.9% 的 667.3K
//
// 给你一个整数数组 nums ，其中可能包含重复元素，请你返回该数组所有可能的 子集（幂集）。
// 解集 不能 包含重复的子集。返回的解集中，子集可以按 任意顺序 排列。
//
// 󰛨 示例 1：
// 	│ 输入：nums = [1,2,2]
// 	│ 输出：[[],[1],[1,2],[1,2,2],[2],[2,2]]
//
// 󰛨 示例 2：
// 	│ 输入：nums = [0]
// 	│ 输出：[[],[0]]
//
//  提示：
// 	* 1 <= nums.length <= 10
// 	* -10 <= nums[i] <= 10
#include "LeetCode90.hpp"

void backtrack(const vector<int> &nums, int index, const vector<int> &path, vector<vector<int>> &result) {
    int num = -100;
    for (size_t i = index; i < nums.size(); i++) {
        if (num == nums[i]) {
            continue;
        } else {
            num = nums[i];
        }
        vector<int> temp = path;
        temp.push_back(nums[i]);
        result.push_back(temp);
        backtrack(nums, i + 1, temp, result);
    }
}

vector<vector<int>> Solution::subsetsWithDup(vector<int>& nums) {
    vector<vector<int>> result = {{}};
    std::sort(nums.begin(), nums.end());
    backtrack(nums, 0, {}, result);
    return result;
}
