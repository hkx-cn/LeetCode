// 2744. 最大字符串配对数目
// 给你一个下标从 0 开始的数组 words ，数组中包含 互不相同 的字符串。
// 如果字符串 words[i] 与字符串 words[j] 满足以下条件，我们称它们可以匹配：
// 字符串 words[i] 等于 words[j] 的反转字符串。
// 0 <= i < j < words.length
// 请你返回数组 words 中的 最大 匹配数目。
// 注意，每个字符串最多匹配一次。

// 示例 1：
// 输入：words = ["cd","ac","dc","ca","zz"]
// 输出：2
// 解释：在此示例中，我们可以通过以下方式匹配 2 对字符串：
// - 我们将第 0 个字符串与第 2 个字符串匹配，因为 word[0] 的反转字符串是 "dc" 并且等于 words[2]。
// - 我们将第 1 个字符串与第 3 个字符串匹配，因为 word[1] 的反转字符串是 "ca" 并且等于 words[3]。
// 可以证明最多匹配数目是 2 。
// 示例 2：
// 输入：words = ["ab","ba","cc"]
// 输出：1
// 解释：在此示例中，我们可以通过以下方式匹配 1 对字符串：
// - 我们将第 0 个字符串与第 1 个字符串匹配，因为 words[1] 的反转字符串 "ab" 与 words[0] 相等。
// 可以证明最多匹配数目是 1 。
// 示例 3：
// 输入：words = ["aa","ab"]
// 输出：0
// 解释：这个例子中，无法匹配任何字符串。
#include "LeetCode2744.hpp"
int Solution::maximumNumberOfStringPairs(vector<string> &words)
{
    int count = 0;
    string temp;
    for (size_t i = 0; i < words.size() - 1; i++)
    {
        for (size_t j = i + 1; j < words.size(); j++)
        {
            temp = words[i];
            reverse(temp.begin(), temp.end());
            if (temp == words[j])
            {
                count++;
            }
        }
    }
    return count;
}
// 方法一：两重循环枚举
// 思路与算法
// 我们可以直接使用二重循环，枚举给定的数组 words 中的 words[i] 和 words[j] 是否可以匹配。
// 由于题目规定了数组 words 中包含的字符串互不相同，因此在枚举时，只要保证 i<j，那么每个字符串最多匹配一次。
// 代码
// class Solution {
// public:
//     int maximumNumberOfStringPairs(vector<string>& words) {
//         int n = words.size();
//         int ans = 0;
//         for (int i = 0; i < n; ++i) {
//             for (int j = i + 1; j < n; ++j) {
//                 if (words[i][0] == words[j][1] && words[i][1] == words[j][0]) {
//                     ++ans;
//                 }
//             }
//         }
//         return ans;
//     }
// }; 
// 复杂度分析
// 时间复杂度：O(n^2)，其中 n 是数组 words 的长度。
// 空间复杂度：O(1)。

// 方法二：哈希表
// 思路与算法
// 我们也可以借助哈希集合，只进行一次遍历。
// 当我们枚举到 words[i] 时，我们将之前的所有字符串 words[0..i−1] 放入哈希集合中。如果 words[i] 的反转字符串在哈希集合中存在，那么匹配的数量增加 1。
// 对于比较方便得到反转字符串的语言，我们可以在哈希集合中存储字符串本身；对于其它语言，我们可以存储字符串的哈希值，改为判断 words[i] 的反转字符串的哈希值是否存在。哈希值需要保证不会冲突，本题中字符串的长度为 2 并且只包含小写字母，因此可以使用 100a+b 作为哈希值，其中 a 和 b 分别是两个字符的 ASCII 值。
// 代码
// class Solution {
// public:
//     int maximumNumberOfStringPairs(vector<string>& words) {
//         int n = words.size();
//         int ans = 0;
//         unordered_set<int> seen;
//         for (int i = 0; i < n; ++i) {
//             if (seen.count(words[i][1] * 100 + words[i][0])) {
//                 ++ans;
//             }
//             seen.insert(words[i][0] * 100 + words[i][1]);
//         }
//         return ans;
//     }
// };
// 复杂度分析
// 时间复杂度：O(n)，其中 n 是数组 words 的长度。
// 空间复杂度：O(n)，即为哈希表需要使用的空间。