// 1232. 缀点成线
// 给定一个数组 coordinates ，其中 coordinates[i] = [x, y] ， [x, y] 表示横坐标为 x、纵坐标为 y 的点。请你来判断，这些点是否在该坐标系中属于同一条直线上。
// 示例 1：
// 输入：coordinates = [[1,2],[2,3],[3,4],[4,5],[5,6],[6,7]]
// 输出：true
// 示例 2：
// 输入：coordinates = [[1,1],[2,2],[3,4],[4,5],[5,6],[7,7]]
// 输出：false
// 提示：
// 2 <= coordinates.length <= 1000
// coordinates[i].length == 2
// -10^4 <= coordinates[i][0], coordinates[i][1] <= 10^4
// coordinates 中不含重复的点
#include "LeetCode1232.hpp" 

bool Solution::checkStraightLine(vector<vector<int>> &coordinates){
    sort(coordinates.begin(), coordinates.end(), [](vector<int> a, vector <int> b){return a[0] < b[0];});
    int x = coordinates[1][0] - coordinates[0][0], y = coordinates[1][1] - coordinates[0][1];
    for (size_t i = 1; i < coordinates.size() - 1; i++)
    {
        if (x == 0 && coordinates[i + 1][0] - coordinates[i][0] == 0) continue;
        if (y == 0 && coordinates[i + 1][1] - coordinates[i][1] == 0) continue;
        if ((coordinates[i + 1][0] - coordinates[i][0]) * y != x * (coordinates[i + 1][1] - coordinates[i][1]))
        {
            return false;
        }
    }
    return true;
}
//方法一：数学
//思路
//记数组 coordinates\textit{coordinates}coordinates 中的点为 P0,P1,…,Pn−1。为方便后续计算，将所有点向 (−P0x,−P0y) 方向平移。记平移后的点为 P0′,P1′,…,Pn−1′，其中 Pi′=(Pix−P0x,Piy−P0y)，P0′ 位于坐标系原点 O 上。
//由于经过两点的直线有且仅有一条，我们以 P0′ 和 P1′ 来确定这条直线。
//因为 P0′ 位于坐标系原点 O 上，直线过原点，故设其方程为 Ax+By=0，将 P1′ 坐标代入可得 A=P1y′,B=−P1x′.
//然后依次判断 P2′,…,Pn−1′ 是否在这条直线上，将其坐标代入直线方程即可。
//代码
//class Solution {
//public:
//    bool checkStraightLine(vector<vector<int>> &coordinates) {
//        int deltaX = coordinates[0][0], deltaY = coordinates[0][1];
//        int n = coordinates.size();
//        for (int i = 0; i < n; ++i) {
//            coordinates[i][0] -= deltaX;
//            coordinates[i][1] -= deltaY;
//        }
//        int A = coordinates[1][1], B = -coordinates[1][0];
//        for (int i = 2; i < n; ++i) {
//            int x = coordinates[i][0], y = coordinates[i][1];
//            if (A * x + B * y != 0) {
//                return false;
//            }
//        }
//        return true;
//    }
//};
