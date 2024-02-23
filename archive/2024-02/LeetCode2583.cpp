//2583. 二叉树中的第 K 大层和
//给你一棵二叉树的根节点 root 和一个正整数 k 。
//树中的 层和 是指 同一层 上节点值的总和。
//返回树中第 k 大的层和（不一定不同）。如果树少于 k 层，则返回 -1 。
//注意，如果两个节点与根节点的距离相同，则认为它们在同一层。
//
//示例 1：
//输入：root = [5,8,9,2,1,3,7,4,6], k = 2
//输出：13
//解释：树中每一层的层和分别是：
//- Level 1: 5
//- Level 2: 8 + 9 = 17
//- Level 3: 2 + 1 + 3 + 7 = 13
//- Level 4: 4 + 6 = 10
//第 2 大的层和等于 13 。
//示例 2：
//输入：root = [1,2,null,3], k = 1
//输出：3
//解释：最大的层和是 3 。
//
//提示：
//树中的节点数为 n
//2 <= n <= 10^5
//1 <= Node.val <= 10^6
//1 <= k <= n
#include "LeetCode2583.hpp"
long long Solution::kthLargestLevelSum(TreeNode* root, int k){
    vector<long long> level;
    queue<pair<TreeNode*, int>> bfs;
    bfs.push({root, 0});
    level.push_back(0);
    while (bfs.size()) {
        if (bfs.front().first) {
            if (bfs.front().second >= level.size()) {
                level.push_back({});
            }
            bfs.push({bfs.front().first->left, bfs.front().second + 1});
            bfs.push({bfs.front().first->right, bfs.front().second + 1});
            level[bfs.front().second] += bfs.front().first->val;
        }
        bfs.pop();
    }
    sort(level.begin(), level.end(), [](long long x, long long y){ return x > y;});
    return level.size() >= k ? level[k - 1] : - 1;
}
//方法一：广度优先搜索 + 排序
//思路
//先使用广度优先搜索计算出树的每一层的节点值的和，保存在数组 levelSumArray 中。然后将数组进行排序，返回第 k 大的值。需要考虑数组长度小于 k 的边界情况。也可以使用快速选择的算法快速定位第 k 大的元素。
//代码
//class Solution {
//public:
//    long long kthLargestLevelSum(TreeNode* root, int k) {
//        queue<TreeNode *> q;
//        q.push(root);
//        vector<long long> levelSumArray;
//        while (!q.empty()) {
//            long long levelSum = 0, size = q.size();
//            for (int i = 0; i < size; i++) {
//                TreeNode *node = q.front();
//                q.pop();
//                levelSum += node->val;
//                if (node->left) {
//                    q.push(node->left);
//                }
//                if (node->right) {
//                    q.push(node->right);
//                }
//            }
//            levelSumArray.push_back(levelSum);
//        }
//        if (levelSumArray.size() < k) {
//            return -1;
//        }
//        sort(levelSumArray.begin(), levelSumArray.end());
//        return *(levelSumArray.end() - k);
//    }
//}
//复杂度分析
//时间复杂度：O(n×logn)，其中 n 是树中的节点数。广度优先搜索消耗 O(n)，一次排序消耗 O(n×logn)。
//空间复杂度：O(n)，其中 n 是树中的节点数。广度优先搜索消耗 O(n)，一次排序消耗 O(logn)。
