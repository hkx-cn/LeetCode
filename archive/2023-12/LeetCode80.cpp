// 80. 删除有序数组中的重复项 II
// 给你一个有序数组 nums ，请你 原地 删除重复出现的元素，使得出现次数超过两次的元素只出现两次 ，返回删除后数组的新长度。
// 不要使用额外的数组空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。

// 说明：
// 为什么返回数值是整数，但输出的答案是数组呢？
// 请注意，输入数组是以「引用」方式传递的，这意味着在函数里修改输入数组对于调用者是可见的。
// 你可以想象内部操作如下:
// // nums 是以“引用”方式传递的。也就是说，不对实参做任何拷贝
// int len = removeDuplicates(nums);
// // 在函数里修改输入数组对于调用者是可见的。
// // 根据你的函数返回的长度, 它会打印出数组中 该长度范围内 的所有元素。
// for (int i = 0; i < len; i++) {
//     print(nums[i]);
// }

// 示例 1：
// 输入：nums = [1,1,1,2,2,3]
// 输出：5, nums = [1,1,2,2,3]
// 解释：函数应返回新长度 length = 5, 并且原数组的前五个元素被修改为 1, 1, 2, 2, 3。 不需要考虑数组中超出新长度后面的元素。
// 示例 2：
// 输入：nums = [0,0,1,1,1,1,2,3,3]
// 输出：7, nums = [0,0,1,1,2,3,3]
// 解释：函数应返回新长度 length = 7, 并且原数组的前七个元素被修改为 0, 0, 1, 1, 2, 3, 3。不需要考虑数组中超出新长度后面的元素。

// 提示：
// 1 <= nums.length <= 3 * 10^4
// -10^4 <= nums[i] <= 10^4
// nums 已按升序排列
#include "LeetCode80.hpp"

int Solution::removeDuplicates(vector<int> &nums)
{
    int idx = 0, temp = nums[0] - 1, count = 0;
    for (size_t i = 0; i < nums.size(); i++)
    {
        if (nums[i] == temp)
        {
            count++;
            if (count <= 2) 
            {
                swap(nums[i], nums[idx]);
                idx++;
            }
        }
        else
        {
            temp = nums[i];
            swap(nums[i], nums[idx]);
            count = 1;
            idx++;
        }
    }
    return idx;
}
// int Solution::removeDuplicates(vector<int> &nums)
// {
//     int tmp = nums[0], count = 1, len = 1;
//     for (size_t i = 1; i < nums.size(); i++)
//     {
//         if (nums[i] == tmp)
//         {
//             count++;
//             if (count > 2)
//             {
//                 nums.erase(nums.begin() + i, nums.begin() + i + 1);
//                 i--;
//             }
//             else
//                 len++;
//         }
//         else
//         {
//             tmp = nums[i];
//             count = 1;
//             len++;
//         }
//     }
//     return len;
// }
// 方法一：双指针
// 思路及解法
// 在阅读本题前，读者们可以先尝试解决「26. 删除有序数组中的重复项」。
// 因为给定数组是有序的，所以相同元素必然连续。我们可以使用双指针解决本题，遍历数组检查每一个元素是否应该被保留，如果应该被保留，就将其移动到指定位置。具体地，我们定义两个指针 idx 和 fast 分别为慢指针和快指针，其中慢指针表示处理出的数组的长度，快指针表示已经检查过的数组的长度，即 nums[fast] 表示待检查的第一个元素，nums[idx−1] 为上一个应该被保留的元素所移动到的指定位置。
// 因为本题要求相同元素最多出现两次而非一次，所以我们需要检查上上个应该被保留的元素 nums[idx−2] 是否和当前待检查元素 nums[fast] 相同。当且仅当 nums[idx−2]=nums[fast] 时，当前待检查元素 nums[fast] 不应该被保留（因为此时必然有 nums[idx−2]=nums[idx−1]=nums[fast]）。最后，idx 即为处理好的数组的长度。
// 特别地，数组的前两个数必然可以被保留，因此对于长度不超过 2 的数组，我们无需进行任何处理，对于长度超过 2 的数组，我们直接将双指针的初始值设为 2 即可。
// class Solution {
// public:
//     int removeDuplicates(vector<int>& nums) {
//         int n = nums.size();
//         if (n <= 2) {
//             return n;
//         }
//         int idx = 2, fast = 2;
//         while (fast < n) {
//             if (nums[idx - 2] != nums[fast]) {
//                 nums[idx] = nums[fast];
//                 ++idx;
//             }
//             ++fast;
//         }
//         return idx;
//     }
// };
// 复杂度分析
// 时间复杂度：O(n)，其中 n 是数组的长度。我们最多遍历该数组一次。
// 空间复杂度：O(1)。我们只需要常数的空间存储若干变量。