// 682. 棒球比赛
// 你现在是一场采用特殊赛制棒球比赛的记录员。这场比赛由若干回合组成，过去几回合的得分可能会影响以后几回合的得分。
// 比赛开始时，记录是空白的。你会得到一个记录操作的字符串列表 ops，其中 ops[i]
// 是你需要记录的第 i 项操作，ops 遵循下述规则： 整数 x - 表示本回合新获得分数 x
// "+" -
// 表示本回合新获得的得分是前两次得分的总和。题目数据保证记录此操作时前面总是存在两个有效的分数。
// "D" -
// 表示本回合新获得的得分是前一次得分的两倍。题目数据保证记录此操作时前面总是存在一个有效的分数。
// "C" -
// 表示前一次得分无效，将其从记录中移除。题目数据保证记录此操作时前面总是存在一个有效的分数。
// 请你返回记录中所有得分的总和。

// 示例 1：
// 输入：ops = ["5","2","C","D","+"]
// 输出：30
// 解释：
// "5" - 记录加 5 ，记录现在是 [5]
// "2" - 记录加 2 ，记录现在是 [5, 2]
// "C" - 使前一次得分的记录无效并将其移除，记录现在是 [5].
// "D" - 记录加 2 * 5 = 10 ，记录现在是 [5, 10].
// "+" - 记录加 5 + 10 = 15 ，记录现在是 [5, 10, 15].
// 所有得分的总和 5 + 10 + 15 = 30
// 示例 2：
// 输入：ops = ["5","-2","4","C","D","9","+","+"]
// 输出：27
// 解释：
// "5" - 记录加 5 ，记录现在是 [5]
// "-2" - 记录加 -2 ，记录现在是 [5, -2]
// "4" - 记录加 4 ，记录现在是 [5, -2, 4]
// "C" - 使前一次得分的记录无效并将其移除，记录现在是 [5, -2]
// "D" - 记录加 2 * -2 = -4 ，记录现在是 [5, -2, -4]
// "9" - 记录加 9 ，记录现在是 [5, -2, -4, 9]
// "+" - 记录加 -4 + 9 = 5 ，记录现在是 [5, -2, -4, 9, 5]
// "+" - 记录加 9 + 5 = 14 ，记录现在是 [5, -2, -4, 9, 5, 14]
// 所有得分的总和 5 + -2 + -4 + 9 + 5 + 14 = 27
// 示例 3：
// 输入：ops = ["1"]
// 输出：1

// 提示：
// 1 <= ops.length <= 1000
// ops[i] 为 "C"、"D"、"+"，或者一个表示整数的字符串。整数范围是 [-3 * 10^4, 3 *
// 10^4] 对于 "+" 操作，题目数据保证记录此操作时前面总是存在两个有效的分数 对于
// "C" 和 "D" 操作，题目数据保证记录此操作时前面总是存在一个有效的分数
#include "LeetCode682.hpp"

int calPoints(char** operations, int operationsSize) {
    int records[operationsSize], recordIndex = 0, operationsIndex = 0, result = 0;
    for (int i = 0; i < operationsSize; i++) {
        if (operations[i][0] == 'C') {
            recordIndex--;
        } else if (operations[i][0] == 'D') {
            records[recordIndex] = records[recordIndex - 1] * 2;
            recordIndex++;
        } else if (operations[i][0] == '+') {
            records[recordIndex] =
                records[recordIndex - 1] + records[recordIndex - 2];
            recordIndex++;
        } else {
            if (operations[i][0] == '-') {
                operationsIndex = 1;
            } else {
                operationsIndex = 0;
            }
            records[recordIndex] = 0;
            while (operations[i][operationsIndex] != '\0') {
                records[recordIndex] *= 10;
                records[recordIndex] += operations[i][operationsIndex] - '0';
                operationsIndex++;
            }
            if (operations[i][0] == '-') {
                records[recordIndex] *= -1;
            }
            recordIndex++;
        }
    }
    for (int i = 0; i < recordIndex; i++) {
        result += records[i];
    }
    return result;
}

// int Solution::calPoints(vector<string>& operations) {
//     vector<int> result;
//     int ans = 0;
//     for (size_t i = 0; i < operations.size(); i++) {
//         if (operations[i] == "C") {
//             result.pop_back();
//         } else if (operations[i] == "D") {
//             result.push_back(result[result.size() - 1] * 2);
//         } else if (operations[i] == "+") {
//             result.push_back(result[result.size() - 2] +
//                              result[result.size() - 1]);
//         } else {
//             result.push_back(stoi(operations[i]));
//         }
//     }
//     for (size_t i = 0; i < result.size(); i++) {
//         ans += result[i];
//     }
//     return ans;
// };

// 方法一：模拟
// 思路与算法
// 使用变长数组对栈进行模拟。
// 如果操作是
// +，那么访问数组的后两个得分，将两个得分之和加到总得分，并且将两个得分之和入栈。
// 如果操作是 D，那么访问数组的最后一个得分，将得分乘以 2
// 加到总得分，并且将得分乘以 2 入栈。 如果操作是
// C，那么访问数组的最后一个得分，将总得分减去该得分，并且将该得分出栈。
// 如果操作是整数，那么将该整数加到总得分，并且将该整数入栈。
// class Solution {
// public:
//     int calPoints(vector<string>& ops) {
//         int ret = 0;
//         vector<int> points;
//         for (auto &op : ops) {
//             int n = points.size();
//             switch (op[0]) {
//                 case '+':
//                     ret += points[n - 1] + points[n - 2];
//                     points.push_back(points[n - 1] + points[n - 2]);
//                     break;
//                 case 'D':
//                     ret += 2 * points[n - 1];
//                     points.push_back(2 * points[n - 1]);
//                     break;
//                 case 'C':
//                     ret -= points[n - 1];
//                     points.pop_back();
//                     break;
//                 default:
//                     ret += stoi(op);
//                     points.push_back(stoi(op));
//                     break;
//             }
//         }
//         return ret;
//     }
// };
// 复杂度分析
// 时间复杂度：O(n)，其中 n 为数组 ops 的大小。遍历整个 ops 需要 O(n)。
// 空间复杂度：O(n)。变长数组最多保存 O(n) 个元素。

