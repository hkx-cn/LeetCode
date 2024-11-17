// 2586. 统计范围内的元音字符串数
// 给你一个下标从 0 开始的字符串数组 words 和两个整数：left 和 right 。
// 如果字符串以元音字母开头并以元音字母结尾，那么该字符串就是一个 元音字符串
// ，其中元音字母是 'a'、'e'、'i'、'o'、'u' 。 返回 words[i]
// 是元音字符串的数目，其中 i 在闭区间 [left, right] 内。

// 示例 1：
// 输入：words = ["are","amy","u"], left = 0, right = 2
// 输出：2
// 解释：
// - "are" 是一个元音字符串，因为它以 'a' 开头并以 'e' 结尾。
// - "amy" 不是元音字符串，因为它没有以元音字母结尾。
// - "u" 是一个元音字符串，因为它以 'u' 开头并以 'u' 结尾。
// 在上述范围中的元音字符串数目为 2 。
// 示例 2：
// 输入：words = ["hey","aeo","mu","ooo","artro"], left = 1, right = 4
// 输出：3
// 解释：
// - "aeo" 是一个元音字符串，因为它以 'a' 开头并以 'o' 结尾。
// - "mu" 不是元音字符串，因为它没有以元音字母开头。
// - "ooo" 是一个元音字符串，因为它以 'o' 开头并以 'o' 结尾。
// - "artro" 是一个元音字符串，因为它以 'a' 开头并以 'o' 结尾。
// 在上述范围中的元音字符串数目为 3 。

// 提示：
// 1 <= words.length <= 1000
// 1 <= words[i].length <= 10
// words[i] 仅由小写英文字母组成
// 0 <= left <= right < words.length
#include "LeetCode2586.hpp"

int vowelStrings(char **words, int wordsSize, int left, int right) {
    int result = 0;
    for (int i = left; i <= right; i++) {
        wordsSize = strlen(words[i]);
        if ((words[i][0] == 'a' || words[i][0] == 'e' || words[i][0] == 'i' ||
             words[i][0] == 'o' || words[i][0] == 'u') &&
            (words[i][wordsSize - 1] == 'a' || words[i][wordsSize - 1] == 'e' ||
             words[i][wordsSize - 1] == 'i' || words[i][wordsSize - 1] == 'o' ||
             words[i][wordsSize - 1] == 'u')) {
            result++;
        }
    }
    return result;
}

// int Solution::vowelStrings(vector<string> &words, int left, int right) {
//     int result = 0;
//     for (size_t i = left; i <= right; i++) {
//         if (words[i][0] == 'a' || words[i][0] == 'e' || words[i][0] == 'i' ||
//             words[i][0] == 'o' || words[i][0] == 'u') {
//             if (words[i][words[i].size() - 1] == 'a' ||
//                 words[i][words[i].size() - 1] == 'e' ||
//                 words[i][words[i].size() - 1] == 'i' ||
//                 words[i][words[i].size() - 1] == 'o' ||
//                 words[i][words[i].size() - 1] == 'u') {
//                 result++;
//             }
//         }
//     }
//     return result;
// };

// 方法一：枚举范围内的字符串
// 思路与算法
// 我们在 [left,right] 范围内枚举给定字符串数组 words
// 中的字符串，并判断其是否以元音字母开头，并且以元音字母结尾。
// 为了方便判断，我们可以将元音字母 aeiou
// 存入一个哈希集合中。这样一来，我们只需要判断字符串的首字符和尾字符是否均在哈希集合中出现即可。
// class Solution {
// public:
//     int vowelStrings(vector<string>& words, int left, int right) {
//         unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
//         int ans = 0;
//         for (int i = left; i <= right; ++i) {
//             const string& word = words[i];
//             if (vowels.count(word[0]) && vowels.count(word.back())) {
//                 ++ans;
//             }
//         }
//         return ans;
//     }
// };
// 复杂度分析
// 时间复杂度：O(n+∣Σ∣)，其中 n 是数组 words 的长度，Σ 是元音的集合，在本题中
// ∣Σ∣=5。 空间复杂度：O(∣Σ∣)，即为哈希集合需要使用的空间。

