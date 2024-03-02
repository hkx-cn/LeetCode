//859. 亲密字符串
//给你两个字符串 s 和 goal ，只要我们可以通过交换 s 中的两个字母得到与 goal 相等的结果，就返回 true ；否则返回 false 。
//交换字母的定义是：取两个下标 i 和 j （下标从 0 开始）且满足 i != j ，接着交换 s[i] 和 s[j] 处的字符。
//例如，在 "abcd" 中交换下标 0 和下标 2 的元素可以生成 "cbad" 。
// 
//示例 1：
//输入：s = "ab", goal = "ba"
//输出：true
//解释：你可以交换 s[0] = 'a' 和 s[1] = 'b' 生成 "ba"，此时 s 和 goal 相等。
//示例 2：
//输入：s = "ab", goal = "ab"
//输出：false
//解释：你只能交换 s[0] = 'a' 和 s[1] = 'b' 生成 "ba"，此时 s 和 goal 不相等。
//示例 3：
//输入：s = "aa", goal = "aa"
//输出：true
//解释：你可以交换 s[0] = 'a' 和 s[1] = 'a' 生成 "aa"，此时 s 和 goal 相等。
// 
//提示：
//1 <= s.length, goal.length <= 2 * 10^4
//s 和 goal 由小写英文字母组成
#include "LeetCode859.hpp"
bool buddyStrings(string s, string goal){
    if (s.size() != goal.size()) {
        return false;
    }
    vector<int> map(26);
    int count = 0, max = 0;
    for (size_t i = 0; i < s.size(); i++) {
        map[s[i] - 'a']++;
        max = max > map[s[i] - 'a'] ? max : map[s[i] - 'a'];
        if (s[i] != goal[i]) {
            count++;
        }
    }
    sort(s.begin(), s.end());
    sort(goal.begin(), goal.end());
    if (count == 2 && s == goal) {
        return true;
    } else if (count == 0 && max >= 2 && s == goal) {
        return true;
    }
    return false;
}
//方法一：枚举
//思路与算法
//设两个字符串分别为 s 和 goal，其中 s[i] 表示 s 的第 i 个字符，其中 goal[i] 表示 goal 的第 i 个字符。如果 s[i]=goal[i]，我们就说 i 是匹配的，否则称 i 是不匹配的。亲密字符串定义为：需要交换 s 中的第 i 个字符 s[i] 与 s 中第 j 个字符且满足 i≠j，交换后 s 与 goal 相等。亲密字符串的两个字符串需要交换一次索引不相等的两个字符后相等。
//如果满足交换 s[i] 和 s[j] 后两个字符串相等，那么需要满足以下几个条件使得 s 和 goal 为亲密字符串：
//字符串 s 的长度与字符串 goal 的长度相等；
//存在 i≠j 且满足 s[i]=goal[j] 以及 s[j]=goal[i]，实际在 s[i],s[j],goal[i],goal[j] 这四个自由变量中，只存在两种情况：
//满足 s[i]=s[j]：则此时必然满足 s[i]=s[j]=goal[i]=goal[j]，字符串 s 与 goal 相等，我们应当能够在 s 中找到两个不同的索引 i,j，且满足 s[i]=s[j]，如果能够找到两个索引不同但值相等的字符则满足 s 与 goal 为亲密字符串；否则不为亲密字符串。
//满足 s[i]≠s[j]：满足 s[i]=goal[j],s[j]=goal[i],s[i]≠s[j] 的情况下，两个字符串 s 与 goal 除了索引 i,j 以外的字符都是匹配的。
//class Solution {
//public:
//    bool buddyStrings(string s, string goal) {
//        if (s.size() != goal.size()) {
//            return false;
//        }
//        
//        if (s == goal) {
//            vector<int> count(26);
//            for (int i = 0; i < s.size(); i++) {
//                count[s[i] - 'a']++;
//                if (count[s[i] - 'a'] > 1) {
//                    return true;
//                }
//            }
//            return false;
//        } else {
//            int first = -1, second = -1;
//            for (int i = 0; i < s.size(); i++) {
//                if (s[i] != goal[i]) {
//                    if (first == -1)
//                        first = i;
//                    else if (second == -1)
//                        second = i;
//                    else
//                        return false;
//                }
//            }
//
//            return (second != -1 && s[first] == goal[second] && s[second] == goal[first]);
//        }
//    }
//};
//复杂度分析
//时间复杂度：O(N)，其中 N 为字符串的长度。我们至多遍历字符串两遍。
//空间复杂度：O(C)。需要常数个空间保存字符串的字符统计次数，我们统计所有小写字母的个数，因此 C=26。
