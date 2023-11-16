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
#include "LeetCode1232.h" 

bool Solution::checkStraightLine(vector<vector<int>> &coordinates){
    int x = coordinates[1][0] - coordinates[0][0], y = coordinates[1][1] - coordinates[0][1];
    for (size_t i = 1; i <= coordinates.size() - 2; i++)
    {
        if (coordinates[i + 1][0] - coordinates[i][0] != x || coordinates[i + 1][1] - coordinates[i][1] != y)
        {
            return false;
        }
    }
    return true;
};