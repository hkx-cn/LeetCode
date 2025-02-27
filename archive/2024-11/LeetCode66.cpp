// 66. 加一
// 给定一个由 整数 组成的 非空 数组所表示的非负整数，在该数的基础上加一。
// 最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。
// 你可以假设除了整数 0 之外，这个整数不会以零开头。
// 示例 1：
// 输入：digits = [1,2,3]
// 输出：[1,2,4]
// 解释：输入数组表示数字 123。
// 示例 2：
// 输入：digits = [4,3,2,1]
// 输出：[4,3,2,2]
// 解释：输入数组表示数字 4321。
// 示例 3：
// 输入：digits = [0]
// 输出：[1]

// 提示：
// 1 <= digits.length <= 100
// 0 <= digits[i] <= 9
#include "LeetCode66.hpp"

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *plusOne(int *digits, int digitsSize, int *returnSize) {
    int count = 0, carry = 1;
    for (int i = 0; i < digitsSize; i++) {
        if (digits[i] == 9) {
            count++;
        }
    }
    if (count == digitsSize) {
        *returnSize = digitsSize + 1;
    } else {
        *returnSize = digitsSize;
    }
    int *result = (int *)malloc(sizeof(int) * *returnSize);
    count = digitsSize;
    for (int i = *returnSize - 1; i >= 1; i--) {
        result[i] = (digits[count - 1] + carry) % 10;
        if (digits[count - 1] + carry == 10) {
            carry = 1;
        } else {
            carry = 0;
        }
        count--;
    }
    if (*returnSize == digitsSize) {
        result[0] = digits[0] + carry;
    } else {
        result[0] = 1;
    }
    return result;
}

// vector<int> Solution::plusOne(vector<int> &digits) {
//     bool add = true;
//     for (int i = digits.size() - 1; i >= 0; i--) {
//         if (digits[i] == 9) {
//             digits[i] = 0;
//         } else {
//             digits[i]++;
//             add = false;
//             break;
//         }
//     }
//     if (add) {
//         digits.insert(digits.begin(), 1);
//     }
//     return digits;
// }

// 方法一：找出最长的后缀 9
// 思路
// 当我们对数组 digits 加一时，我们只需要关注 digits 的末尾出现了多少个 9
// 即可。我们可以考虑如下的三种情况： 如果 digits 的末尾没有 9，例如
// [1,2,3]，那么我们直接将末尾的数加一，得到 [1,2,4] 并返回； 如果 digits
// 的末尾有若干个 9，例如 [1,2,3,9,9]，那么我们只需要找出从末尾开始的第一个不为
// 9 的元素，即 3，将该元素加一，得到 [1,2,4,9,9]。随后将末尾的 9 全部置零，得到
// [1,2,4,0,0] 并返回。 如果 digits 的所有元素都是 9，例如
// [9,9,9,9,9]，那么答案为 [1,0,0,0,0,0]。我们只需要构造一个长度比 digits 多 1
// 的新数组，将首元素置为 1，其余元素置为 0 即可。 算法 们只需要对数组 digits
// 进行一次逆序遍历，找出第一个不为 9
// 的元素，将其加一并将后续所有元素置零即可。如果 digits 中所有的元素均为
// 9，那么对应着「思路」部分的第三种情况，我们需要返回一个新的数组。
// class Solution {
// public:
//     vector<int> plusOne(vector<int> &digits) {
//         int n = digits.size();
//         for (int i = n - 1; i >= 0; --i) {
//             if (digits[i] != 9) {
//                 ++digits[i];
//                 for (int j = i + 1; j < n; ++j) {
//                     digits[j] = 0;
//                 }
//                 return digits;
//             }
//         }
//
//         // digits 中所有的元素均为 9
//         vector<int> ans(n + 1);
//         ans[0] = 1;
//         return ans;
//     }
// };
// 复杂度分析
// 时间复杂度：O(n)，其中 n 是数组 digits 的长度。
// 空间复杂度：O(1)。返回值不计入空间复杂度。
