// 436. 寻找右区间
// 给你一个区间数组 intervals ，其中 intervals[i] = [starti, endi] ，且每个 starti 都 不同 。
// 区间 i 的 右侧区间 可以记作区间 j ，并满足 startj >= endi ，且 startj 最小化 。注意 i 可能等于 j 。
// 返回一个由每个区间 i 的 右侧区间 在 intervals 中对应下标组成的数组。如果某个区间 i 不存在对应的 右侧区间 ，则下标 i 处的值设为 -1 。

// 示例 1：
// 输入：intervals = [[1,2]]
// 输出：[-1]
// 解释：集合中只有一个区间，所以输出-1。
// 示例 2：
// 输入：intervals = [[3,4],[2,3],[1,2]]
// 输出：[-1,0,1]
// 解释：对于 [3,4] ，没有满足条件的“右侧”区间。
// 对于 [2,3] ，区间[3,4]具有最小的“右”起点;
// 对于 [1,2] ，区间[2,3]具有最小的“右”起点。
// 示例 3：
// 输入：intervals = [[1,4],[2,3],[3,4]]
// 输出：[-1,2,-1]
// 解释：对于区间 [1,4] 和 [3,4] ，没有满足条件的“右侧”区间。
// 对于 [2,3] ，区间 [3,4] 有最小的“右”起点。

// 提示：
// 1 <= intervals.length <= 2 * 10^4
// intervals[i].length == 2
// -10^6 <= starti <= endi <= 10^6
// 每个间隔的起点都 不相同
#include "LeetCode436.hpp"
vector<int> Solution::findRightInterval(vector<vector<int>> &intervals)
{
    vector<vector<int>> map;
    vector<int> result(intervals.size());
    int left = 0, right = intervals.size() - 1, mid = -1, ans = -1;
    for (int i = 0; i < intervals.size(); i++){
        map.push_back({intervals[i][0], i});
    }
    sort(map.begin(), map.end());
    for (int i = 0; i < intervals.size(); i++){
        left = 0;
        right = intervals.size() - 1;
        ans = -1;
        while(left <= right){
            mid = left + (right - left) / 2;
            if (map[mid][0] >= intervals[i][1]){
                right = mid - 1;
                ans = map[mid][1];
            }
            else{
                left = mid + 1;
            }
        }
        result[i] = ans;
    }
    return result;
}
//方法一：二分查找
//思路与算法
//最简单的解决方案是对于集合中的每个区间，我们扫描所有区间找到其起点大于当前区间的终点的区间（具有最小差值），时间复杂度为 O(n^2)，在此我们不详细描述。
//首先我们可以对区间 intervals 的起始位置进行排序，并将每个起始位置 intervals[i][0] 对应的索引 i 存储在数组 startIntervals 中，然后枚举每个区间 i 的右端点 intervals[i][1]，利用二分查找来找到大于等于 intervals[i][1] 的最小值 val 即可，此时区间 i 对应的右侧区间即为右端点 val 对应的索引。
//代码
//class Solution {
//public:
//    vector<int> findRightInterval(vector<vector<int>>& intervals) {
//        vector<pair<int, int>> startIntervals;
//        int n = intervals.size();
//        for (int i = 0; i < n; i++) {
//            startIntervals.emplace_back(intervals[i][0], i);
//        }
//        sort(startIntervals.begin(), startIntervals.end());
//
//        vector<int> ans(n, -1);
//        for (int i = 0; i < n; i++) {
//            auto it = lower_bound(startIntervals.begin(), startIntervals.end(), make_pair(intervals[i][1], 0));
//            if (it != startIntervals.end()) {
//                ans[i] = it->second;
//            }
//        }
//        return ans;
//    }
//};
//复杂度分析
//时间复杂度：O(nlogn)，其中 n 为区间数组的长度。排序的时间为 O(nlogn)，每次进行二分查找花费的时间为 O(logn)，一共需要进行 n 次二分查找，因此总的时间复杂度为 O(nlogn)。
//空间复杂度：O(n)，其中 n 为区间数组的长度。startIntervals 一共存储了 n 个元素，因此空间复杂度为 O(n)。

//方法二：双指针
//思路与算法
//我们可以开辟两个新的数组：
//startIntervals，基于所有区间的起始点从小到大排序。
//endIntervals，基于所有区间的结束点从小到大排序。
//我们从 endIntervals 数组中取出第 i 个区间，就可以从左到右扫描 startIntervals 数组中的区间起点来找到满足右区间条件的区间。设 endIntervals 数组中第 i 个元素的右区间为 startIntervals 数组中的第 j 个元素，此时可以知道 startIntervals[j−1][0]<endIntervals[i][0],startIntervals[j][0]≥endIntervals[i][0]。当我们遍历 endIntervals 数组中第 i+1 个元素时，我们不需要从第一个索引开始扫描 startIntervals 数组，可以直接从第 j 个元素开始扫描 startIntervals 数组。由于数组中所有的元素都是已排序，因此可以知道 startIntervals[j−1][0]<endIntervals[i][0]≤endIntervals[i+1][0]，所以数组 startIntervals 的前 j−1 的元素的起始点都小于 endIntervals[i+1][0]，因此可以直接跳过前 j−1 个元素，只需要从 j 开始搜索即可。
//代码
//class Solution {
//public:
//    vector<int> findRightInterval(vector<vector<int>>& intervals) {
//        vector<pair<int, int>> startIntervals;
//        vector<pair<int, int>> endIntervals;
//        int n = intervals.size();
//        for (int i = 0; i < n; i++) {
//            startIntervals.emplace_back(intervals[i][0], i);
//            endIntervals.emplace_back(intervals[i][1], i);
//        }
//        sort(startIntervals.begin(), startIntervals.end());
//        sort(endIntervals.begin(), endIntervals.end());
//
//        vector<int> ans(n, -1);
//        for (int i = 0, j = 0; i < n && j < n; i++) {
//            while (j < n && endIntervals[i].first > startIntervals[j].first) {
//                j++;
//            }
//            if (j < n) {
//                ans[endIntervals[i].second] = startIntervals[j].second;
//            }
//        }
//        return ans;
//    }
//};
//复杂度分析
//时间复杂度：O(nlogn)，其中 n 为区间数组的长度。两个数组的排序时间一共为 O(nlogn)，查找每个区间的右侧区间的时间复杂度为 O(n)，因此总的时间复杂度为 O(nlogn)。
//空间复杂度：O(n)，其中 n 为区间数组的长度。startIntervals,endIntervals 均存储了 n 个元素，因此空间复杂度为 O(n)。
