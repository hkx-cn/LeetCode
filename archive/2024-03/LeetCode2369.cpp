//2369. 检查数组是否存在有效划分
//给你一个下标从 0 开始的整数数组 nums ，你必须将数组划分为一个或多个 连续 子数组。
//如果获得的这些子数组中每个都能满足下述条件 之一 ，则可以称其为数组的一种 有效 划分：
//子数组 恰 由 2 个相等元素组成，例如，子数组 [2,2] 。
//子数组 恰 由 3 个相等元素组成，例如，子数组 [4,4,4] 。
//子数组 恰 由 3 个连续递增元素组成，并且相邻元素之间的差值为 1 。例如，子数组 [3,4,5] ，但是子数组 [1,3,5] 不符合要求。
//如果数组 至少 存在一种有效划分，返回 true ，否则，返回 false 。
//
//示例 1：
//输入：nums = [4,4,4,5,6]
//输出：true
//解释：数组可以划分成子数组 [4,4] 和 [4,5,6] 。
//这是一种有效划分，所以返回 true 。
//示例 2：
//输入：nums = [1,1,1,2]
//输出：false
//解释：该数组不存在有效划分。
//
//提示：
//2 <= nums.length <= 10^5
//1 <= nums[i] <= 10^6
#include "LeetCode2369.hpp"
bool Solution::validPartition(vector<int>& nums){
    //是否存在有效划分
    //前n - 2个元素有效划分，后2个元素相等
    //前n - 3个元素有效划分，后3个元素相等
    //前n - 3个元素有效划分，后3个元素连续递增且相邻元素差值为1
    //f(n) = f(n - 2) && f(n - 1) == f(n)
    //f(n) = f(n - 3) && f(n - 2) == f(n - 1) && f(n - 1) == f(n)
    //f(n) = f(n - 3) && f(n - 2) == f(n - 1) - 1 && f(n - 1) == f(n) - 1
    if (nums.size() == 1) {
        return false;
    } else if (nums.size() == 2) {
        return nums[0] == nums[1];
    }
    vector<bool> dp(nums.size());
    dp[0] = false;
    dp[1] = nums[0] == nums[1];
    dp[2] = (nums[0] == nums[1] && nums[1] == nums[2]) || (nums[0] + 1 == nums[1] && nums[1] + 1 == nums[2]);
    for (size_t i = 3; i < nums.size(); i++) {
        dp[i] = ((dp[i - 2] && nums[i - 1] == nums[i])
              || (dp[i - 3] && nums[i - 2] + 1 == nums[i - 1] && nums[i - 1] + 1 == nums[i])
              || (dp[i - 3] && nums[i - 2] == nums[i - 1] && nums[i - 1] == nums[i]));
    }
    return dp[nums.size() - 1];
}
//方法一：动态规划
//思路
//设数组 nums 的长度为 n，它至少存在一个有效划分的充要条件为：
//前 (n−2) 个元素组成的数组至少存在一个有效划分，且后两个元素相等。或
//前 (n−3) 个元素组成的数组至少存在一个有效划分，且
//后三个元素相等。或
//后三个元素连续递增，且差值为 1。
//这样的判断可以用动态规划来解决，用一个长度为 (n+1) 的数组来记录 nums 是否存在有效划分，dp[i] 表示前 i 个元素组成的数组是否至少存在一个有效划分。边界情况 dp[0] 恒为 true，而 dp[n] 即为结果。
//同时，定义两个辅助函数，validTwo(num1,nums2) 用来判断长度为 2 的子数组是否满足题目的条件 1。validThree(num1,nums2,nums3) 用来判断长度为 3 的子数组是否满足题目的条件 2 或 3。
//
//这样，动态规划的公式即为
//dp[i]=(dp[i−2]∧validTwo(nums[i−2],nums[i−1]))∨(dp[i−3]∧validThree(nums[i−3],nums[i−2],nums[i−1]))
//。推导的时候需要注意下标是否越界。
//
//代码
//class Solution {
//public:
//    bool validPartition(vector<int>& nums) {
//        int n = nums.size();
//        vector<int> dp(n + 1, false);
//        dp[0] = true;
//        for (int i = 1; i <= n; i++) {
//            if (i >= 2) {
//                dp[i] = dp[i - 2] && validTwo(nums[i - 2], nums[i - 1]);
//            }
//            if (i >= 3) {
//                dp[i] = dp[i] || (dp[i - 3] && validThree(nums[i - 3], nums[i - 2], nums[i - 1]));
//            }
//        }  
//        return dp[n];
//    }
//
//    bool validTwo(int num1, int num2) {
//        return num1 == num2;
//    }
//
//    bool validThree(int num1, int num2, int num3) {
//        return (num1 == num2 && num1 == num3) || (num1 + 1 == num2 && num2 + 1 == num3);
//    }
//};
//复杂度分析
//时间复杂度：O(n)，其中 n 是数组 nums 的长度。我们仅遍历一次 nums。
//时间复杂度：O(n)。数组 dp 消耗 O(n)。
