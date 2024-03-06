//2917. 找出数组中的 K-or 值
//给你一个下标从 0 开始的整数数组 nums 和一个整数 k 。
//nums 中的 K-or 是一个满足以下条件的非负整数：
//只有在 nums 中，至少存在 k 个元素的第 i 位值为 1 ，那么 K-or 中的第 i 位的值才是 1 。
//返回 nums 的 K-or 值。
//注意 ：对于整数 x ，如果 (2i AND x) == 2i ，则 x 中的第 i 位值为 1 ，其中 AND 为按位与运算符。
//
//示例 1：
//输入：nums = [7,12,9,8,9,15], k = 4
//输出：9
//解释：nums[0]、nums[2]、nums[4] 和 nums[5] 的第 0 位的值为 1 。
//nums[0] 和 nums[5] 的第 1 位的值为 1 。
//nums[0]、nums[1] 和 nums[5] 的第 2 位的值为 1 。
//nums[1]、nums[2]、nums[3]、nums[4] 和 nums[5] 的第 3 位的值为 1 。
//只有第 0 位和第 3 位满足数组中至少存在 k 个元素在对应位上的值为 1 。因此，答案为 2^0 + 2^3 = 9 。
//示例 2：
//输入：nums = [2,12,1,11,4,5], k = 6
//输出：0
//解释：因为 k == 6 == nums.length ，所以数组的 6-or 等于其中所有元素按位与运算的结果。因此，答案为 2 AND 12 AND 1 AND 11 AND 4 AND 5 = 0 。
//示例 3：
//输入：nums = [10,8,5,9,11,6,8], k = 1
//输出：15
//解释：因为 k == 1 ，数组的 1-or 等于其中所有元素按位或运算的结果。因此，答案为 10 OR 8 OR 5 OR 9 OR 11 OR 6 OR 8 = 15 。
//
//提示：
//1 <= nums.length <= 50
//0 <= nums[i] < 2^31
//1 <= k <= nums.length
#include "LeetCode2917.hpp"
int Solution::findKOr(vector<int>& nums, int k){
    long long result = 0, temp = 0, mark = 1;
    sort(nums.begin(), nums.end());
    while (true) {
        temp = 0;
        for (size_t i = 0; i < nums.size(); i++) {
            if ((nums[i] & mark) == mark) {
                temp += 1;
            }
            if (temp >= k) {
                result += mark;
                break;
            }
        }
        if (nums[nums.size() - 1] < mark) {
            break;
        }
        mark *= 2;
    }
    return result;
}
//方法一：枚举每一个二进制位
//思路与算法
//我们直接按照题目描述进行枚举即可。
//具体地，我们在外层循环枚举 i，内层循环枚举数组 nums 中元素 nums[j]。我们可以通过：
//(nums[j] >> i) & 1
//得到 nums[j] 的第 i 位。如果至少有 k 个 1，就将最终的答案加上 2^i ，位运算表示即为 1 << i。
//本题中数组 nums 中的元素不超过 2^31 ，因此 i 的枚举范围是 [0,31)。
//
//代码
//class Solution {
//public:
//    int findKOr(vector<int>& nums, int k) {
//        int ans = 0;
//        for (int i = 0; i < 31; ++i) {
//            int cnt = 0;
//            for (int num: nums) {
//                if ((num >> i) & 1) {
//                    ++cnt;
//                }
//            }
//            if (cnt >= k) {
//                ans |= 1 << i;
//            }
//        }
//        return ans;
//    }
//};
//复杂度分析
//时间复杂度：O(nlogC)，其中 n 是数组 nums 的长度，C 是数组 nums 中元素的范围。
//空间复杂度：O(1)。
