// 657. 机器人能否返回原点
// 在二维平面上，有一个机器人从原点 (0, 0)
// 开始。给出它的移动顺序，判断这个机器人在完成移动后是否在 (0, 0) 处结束。
// 移动顺序由字符串 moves 表示。字符 move[i] 表示其第 i
// 次移动。机器人的有效动作有 R（右），L（左），U（上）和 D（下）。
// 如果机器人在完成所有动作后返回原点，则返回 true。否则，返回 false。
// 注意：机器人“面朝”的方向无关紧要。 “R” 将始终使机器人向右移动一次，“L”
// 将始终向左移动等。此外，假设每次移动机器人的移动幅度相同。

// 示例 1:
// 输入: moves = "UD"
// 输出: true
// 解释：机器人向上移动一次，然后向下移动一次。所有动作都具有相同的幅度，因此它最终回到它开始的原点。因此，我们返回
// true。 示例 2: 输入: moves = "LL" 输出: false
// 解释：机器人向左移动两次。它最终位于原点的左侧，距原点有两次 “移动”
// 的距离。我们返回 false，因为它在移动结束时没有返回原点。

// 提示:
// 1 <= moves.length <= 2 * 10^4
// moves 只包含字符 'U', 'D', 'L' 和 'R'
#include "LeetCode657.hpp"

bool judgeCircle(char* moves) {
    int index = 0, x = 0, y = 0;
    while (moves[index] != '\0') {
        if (moves[index] == 'U') {
            y++;
        } else if (moves[index] == 'D') {
            y--;
        } else if (moves[index] == 'L') {
            x--;
        } else if (moves[index] == 'R') {
            x++;
        }
        index++;
    }
    return x == 0 && y == 0;
}


// bool Solution::judgeCircle(string moves) {
//     int x = 0, y = 0;
//     for (size_t i = 0; i < moves.size(); i++) {
//         if (moves[i] == 'U') {
//             y += 1;
//         } else if (moves[i] == 'D') {
//             y -= 1;
//         } else if (moves[i] == 'L') {
//             x -= 1;
//         } else if (moves[i] == 'R') {
//             x += 1;
//         }
//     }
//     return x == 0 && y == 0;
// };

// 方法一： 模拟
// 思路与算法
// 我们只需按指令模拟机器人移动的坐标即可。起始时机器人的坐标为
// (0,0)，在遍历完所有指令并对机器人进行移动之后，判断机器人的坐标是否为 (0,0)
// 即可。 具体来说，我们用两个变量 x 和 y 来表示机器人当前所在的坐标为
// (x,y)，起始时 x=0，y=0。接下来我们遍历指令并更新机器人的坐标： 如果指令是
// U，则令 y=y−1 如果指令是 D，则令 y=y+1 如果指令是 L，则令 x=x−1 如果指令是
// R，则令 x=x+1 最后判断 (x,y) 是否为 (0,0) 即可。
// class Solution {
// public:
//     bool judgeCircle(string moves) {
//         int x = 0, y = 0;
//         for (auto const &move: moves) {
//             if (move == 'U') {
//                 y--;
//             } else if (move == 'D') {
//                 y++;
//             } else if (move == 'L') {
//                 x--;
//             } else if (move == 'R') {
//                 x++;
//             }
//         }
//         return x == 0 && y == 0;
//     }
// };
// 复杂度分析
// 时间复杂度： O(N)，其中 N 表示 moves
// 指令串的长度。我们只需要遍历一遍字符串即可。 空间复杂度：
// O(1)。我们只需要常数的空间来存放若干变量。
