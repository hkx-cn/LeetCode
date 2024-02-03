// 1275. 找出井字棋的获胜者
// A 和 B 在一个 3 x 3 的网格上玩井字棋。
// 井字棋游戏的规则如下：
// 玩家轮流将棋子放在空方格 (" ") 上。
// 第一个玩家 A 总是用 "X" 作为棋子，而第二个玩家 B 总是用 "O" 作为棋子。
// "X" 和 "O" 只能放在空方格中，而不能放在已经被占用的方格上。
// 只要有 3 个相同的（非空）棋子排成一条直线（行、列、对角线）时，游戏结束。
// 如果所有方块都放满棋子（不为空），游戏也会结束。
// 游戏结束后，棋子无法再进行任何移动。
// 给你一个数组 moves，其中每个元素是大小为 2 的另一个数组（元素分别对应网格的行和列），它按照 A 和 B 的行动顺序（先 A 后 B）记录了两人各自的棋子位置。
// 如果游戏存在获胜者（A 或 B），就返回该游戏的获胜者；如果游戏以平局结束，则返回 "Draw"；如果仍会有行动（游戏未结束），则返回 "Pending"。
// 你可以假设 moves 都 有效（遵循井字棋规则），网格最初是空的，A 将先行动。

// 示例 1： 
// 输入：moves = [[0,0],[2,0],[1,1],[2,1],[2,2]]
// 输出："A"
// 解释："A" 获胜，他总是先走。
// "X  "    "X  "    "X  "    "X  "    "X  "
// "   " -> "   " -> " X " -> " X " -> " X "
// "   "    "O  "    "O  "    "OO "    "OOX"
// 示例 2： 
// 输入：moves = [[0,0],[1,1],[0,1],[0,2],[1,0],[2,0]]
// 输出："B"
// 解释："B" 获胜。
// "X  "    "X  "    "XX "    "XXO"    "XXO"    "XXO"
// "   " -> " O " -> " O " -> " O " -> "XO " -> "XO " 
// "   "    "   "    "   "    "   "    "   "    "O  "
// 示例 3： 
// 输入：moves = [[0,0],[1,1],[2,0],[1,0],[1,2],[2,1],[0,1],[0,2],[2,2]]
// 输出："Draw"
// 输出：由于没有办法再行动，游戏以平局结束。
// "XXO"
// "OOX"
// "XOX"
//
// 示例 4： 
// 输入：moves = [[0,0],[1,1]]
// 输出："Pending"
// 解释：游戏还没有结束。
// "X  "
// " O "
// "   "
 
// 提示：
// 1 <= moves.length <= 9
// moves[i].length == 2
// 0 <= moves[i][j] <= 2
// moves 里没有重复的元素。
// moves 遵循井字棋的规则。
#include "LeetCode1275.hpp"
string Solution::tictactoe(vector<vector<int>>& moves) {
    if (moves.size() <= 4) return "Pending";
    vector<vector<int>> a, b;
    for (size_t i = 0; i < moves.size(); i++){
        if (i % 2 == 0){
            a.push_back(moves[i]);
        }
        else{
            b.push_back(moves[i]);
        }
    }
    for (size_t i = 0; i < a.size() - 2; i++){
        for (size_t j = i + 1; j < a.size() - 1; j++){
            for (size_t k = j + 1; k < a.size(); k++){
                if ((a[j][0] - a[i][0] == 0 && a[k][0] - a[j][0] == 0))
                    return "A";
                if ((a[j][1] - a[i][1] == 0 && a[k][1] - a[j][1] == 0))
                    return "A";
                if ((a[j][0] - a[i][0]) * (a[k][1] - a[j][1]) == (a[j][1] - a[i][1]) * (a[k][0] - a[j][0]))
                    return "A";
            }
        }
    }
    for (size_t i = 0; i < b.size() - 2; i++){
        for (size_t j = i + 1; j < b.size() - 1; j++){
            for (size_t k = j + 1; k < b.size(); k++){
                if ((b[j][0] - b[i][0] == 0 && b[k][0] - b[j][0] == 0))
                    return "B";
                if ((b[j][1] - b[i][1] == 0 && b[k][1] - b[j][1] == 0))
                    return "B";
                if ((b[j][0] - b[i][0]) * (b[k][1] - b[j][1]) == (b[j][1] - b[i][1]) * (b[k][0] - b[j][0]))
                    return "B";
            }
        }
    }
    return moves.size() == 9 ? "Pending" : "Draw";
}
//方法一：模拟
//我们可以模拟数组 move 中的每一步落子。我们使用两个集合 A 和 B 存放每位玩家当前已经落子的位置，并用集合 wins 存放棋子排成一条直线的所有情况（排成一行或一列各有 3 种，排成对角线有 2 种，总计 8 种）。当某位玩家落子时，我们枚举 wins 中的每一种情况，并判断该玩家是否将棋子落在了这些位置。如果满足了其中一种情况，则该玩家获胜。
//如果直到落子完毕仍然没有玩家获胜，那么根据数组 move 的长度返回平局 Draw 或游戏未结束 Pending。
//class Solution {
//public:
//    bool checkwin(unordered_set<int>& S, vector<vector<int>>& wins) {
//        for (auto win: wins) {
//            bool flag = true;
//            for (auto pos: win) {
//                if (!S.count(pos)) {
//                    flag = false;
//                    break;
//                }
//            }
//            if (flag) {
//                return true;
//            }
//        }
//        return false;
//    }
//
//    string tictactoe(vector<vector<int>>& moves) {
//        vector<vector<int>> wins = {
//            {0, 1, 2},
//            {3, 4, 5},
//            {6, 7, 8},
//            {0, 3, 6},
//            {1, 4, 7},
//            {2, 5, 8},
//            {0, 4, 8},
//            {2, 4, 6}
//        };
//
//        unordered_set<int> A, B;
//        for (int i = 0; i < moves.size(); ++i) {
//            int pos = moves[i][0] * 3 + moves[i][1];
//            if (i % 2 == 0) {
//                A.insert(pos);
//                if (checkwin(A, wins)) {
//                    return "A";
//                }
//            }
//            else {
//                B.insert(pos);
//                if (checkwin(B, wins)) {
//                    return "B";
//                }
//            }
//        }
//
//        return (moves.size() == 9 ? "Draw" : "Pending");
//    }
//};
//复杂度分析
//时间复杂度：O(N^4)，其中 N 是棋盘的边长，在本题中 N=3。集合 wins 中存放的排成一条直线的所有情况的数量为 O(2N+2)=O(N)，对于每一步落子我们需要遍历所有的情况，而每一种情况有 N 个位置，因此时间复杂度为 O(N^2)。在最坏情况下，落子的数量为 O(N^2)，因此总时间复杂度为 O(N^4)。
//空间复杂度：O(N^2)。集合 wins 占用的空间为 O(N^2)，而集合 A 和 B 在最坏情况下占用的空间也为 O(N^2)。
