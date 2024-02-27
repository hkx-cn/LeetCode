//163. 缺失的区间
//给你一个闭区间 [lower, upper] 和一个 按从小到大排序 的整数数组 nums ，其中元素的范围在闭区间 [lower, upper] 当中。
//如果一个数字 x 在 [lower, upper] 区间内，并且 x 不在 nums 中，则认为 x 缺失。
//返回 准确涵盖所有缺失数字 的 最小排序 区间列表。也就是说，nums 的任何元素都不在任何区间内，并且每个缺失的数字都在其中一个区间内。
//
//示例 1：
//输入: nums = [0, 1, 3, 50, 75], lower = 0 , upper = 99
//输出: [[2,2],[4,49],[51,74],[76,99]]
//解释：返回的区间是：
//[2,2]
//[4,49]
//[51,74]
//[76,99]
//示例 2：
//输入： nums = [-1], lower = -1, upper = -1
//输出： []
//解释： 没有缺失的区间，因为没有缺失的数字。
//
//提示：
//-10^9 <= lower <= upper <= 10^9
//0 <= nums.length <= 100
//lower <= nums[i] <= upper
//nums 中的所有值 互不相同
#include "LeetCode163.hpp"
vector<vector<int>> Solution::findMissingRanges(vector<int>& nums, int lower, int upper){
    vector<vector<int>> result;
    bool isFind = true;
    for (size_t i = 0; i < nums.size(); i++) {
        if (nums[i] == lower) {
            lower++;
        } else if (i + 1 <= nums.size()) {
            result.push_back({lower, nums[i] - 1});
            lower = nums[i];
            i--;
        } else {
            result.push_back({lower, upper});
        }
    }
    if (lower <= upper) {
        result.push_back({lower, upper});
    }
    return result;
}
