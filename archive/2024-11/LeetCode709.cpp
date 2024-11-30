// 709. 转换成小写字母
// 给你一个字符串 s
// ，将该字符串中的大写字母转换成相同的小写字母，返回新的字符串。

// 示例 1：
// 输入：s = "Hello"
// 输出："hello"
// 示例 2：
// 输入：s = "here"
// 输出："here"
// 示例 3：
// 输入：s = "LOVELY"
// 输出："lovely"

// 提示：
// 1 <= s.length <= 100
// s 由 ASCII 字符集中的可打印字符组成
#include "LeetCode709.hpp"

char* toLowerCase(char* s) {
    int index = 0;
    while (s[index] != '\0') {
        if (s[index] >= 'A' && s[index] <= 'Z') {
            s[index] = s[index] - 'A' + 'a';
        }
        index++;
    }
    return s;
}

// string Solution::toLowerCase(string s) {
//     for (size_t i = 0; i < s.size(); i++) {
//         if (s[i] >= 'A' && s[i] <= 'Z') {
//             s[i] += 32;
//         }
//     }
//     return s;
// };

// 方法一：使用语言 API
// 思路与算法
// 我们可以使用语言自带的大写字母转小写字母的 API。
// class Solution {
// public:
//     string toLowerCase(string s) {
//         for (char& ch: s) {
//             ch = tolower(ch);
//         }
//         return s;
//     }
// };
// 复杂度分析
// 时间复杂度：O(n)，其中 n 是字符串 s 的长度。
// 空间复杂度：O(1)，不考虑返回值的空间占用。

// 方法二：自行实现该 API
// 思路与算法
// 方法二的主要目的是，带领读者一步一步设计一个高效的大写字母转小写字母的 API。
// 我们可以想到的最简单的方法是使用一个哈希映射，哈希映射中包含 26 个键值对
// (A,a),(B,b),⋯ ,(Z,z)。对于每个待转换的字符 ch，如果它出现在是哈希映射中（即
// ch 是哈希映射中的一个键），那么 ch 是大写字母，我们获取 ch
// 在哈希映射中的值即可得到对应的小写字母；如果它没有出现在哈希映射中，那么 ch
// 是其它字符，我们无需进行转换。
// 然而这种方法需要一定量的辅助空间，不够简洁。一种更好的方法是观察小写字母和大写字母的
// ASCII 码表示： 大写字母 A - Z 码范围为 [65,90]： 小写字母 a - z 的 ASCII
// 码范围为 [97,122]。 因此，如果我们发现 ch 的 ASCII 码在 [65,90]
// 的范围内，那么我们将它的 ASCII 码增加 32，即可得到对应的小写字母。
// 近而我们可以发现，由于 [65,90] 对应的二进制表示为
// [(01000001)2,(01011010)2]，32 对应的二进制表示为 (00100000)2，而对于
// [(01000001)2,(01011010)2] 内的所有数，表示 32 的那个二进制位都是
// 0，因此可以对 ch 的 ASCII 码与 32 做按位或运算，替代与 32 的加法运算。
// class Solution {
// public:
//     string toLowerCase(string s) {
//         for (char& ch: s) {
//             if (ch >= 65 && ch <= 90) {
//                 ch |= 32;
//             }
//         }
//         return s;
//     }
// };
// 复杂度分析
// 时间复杂度：O(n)，其中 n 是字符串 s 的长度。
// 空间复杂度：O(1)，不考虑返回值的空间占用。