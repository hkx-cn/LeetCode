//103. 二叉树的锯齿形层序遍历
//给你二叉树的根节点 root ，返回其节点值的 锯齿形层序遍历 。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。
//
//示例 1：
//输入：root = [3,9,20,null,null,15,7]
//输出：[[3],[20,9],[15,7]]
//示例 2：
//输入：root = [1]
//输出：[[1]]
//示例 3：
//输入：root = []
//输出：[]
//
//提示：
//树中节点数目在范围 [0, 2000] 内
//-100 <= Node.val <= 100
#include "LeetCode103.hpp"
#include <algorithm>
vector<vector<int>> Solution::zigzagLevelOrder(TreeNode* root){
    if (root == nullptr) {
        return {};
    }
    vector<vector<int>> result;
    vector<vector<TreeNode*>> tnode;
    int depth = 0;
    bool zigzag = true;
    result.push_back({root->val});
    tnode.push_back({root});
    while (zigzagLevel(tnode, result, depth, zigzag)) {
        depth++;
        if (zigzag) {
            zigzag = false;
        }
        else{
            zigzag = true;
        }
    }
    return result;
}
bool Solution::zigzagLevel(vector<vector<TreeNode*>> &tnode, vector<vector<int>> &vec, int depth, bool zigzag){
    vector<int> vec_add;
    vector<TreeNode*> tnode_add;
    if (zigzag) {
        for (int i = tnode[depth].size() - 1; i >= 0; i--) {
            if (tnode[depth][i]->right != nullptr) {
                tnode_add.push_back(tnode[depth][i]->right);
                vec_add.push_back(tnode[depth][i]->right->val);
            }
            if (tnode[depth][i]->left != nullptr) {
                tnode_add.push_back(tnode[depth][i]->left);
                vec_add.push_back(tnode[depth][i]->left->val);
            }
        }
        if (tnode_add.size() != 0) {
            reverse(tnode_add.begin(), tnode_add.end());
            vec.push_back(vec_add);
            tnode.push_back(tnode_add);
            return true;
        }
    }
    else{
        for (size_t i = 0; i < tnode[depth].size(); i++) {
            if (tnode[depth][i]->left != nullptr) {
                tnode_add.push_back(tnode[depth][i]->left);
                vec_add.push_back(tnode[depth][i]->left->val);
            }
            if (tnode[depth][i]->right != nullptr) {
                tnode_add.push_back(tnode[depth][i]->right);
                vec_add.push_back(tnode[depth][i]->right->val);
            }
        }
        if (tnode_add.size() != 0) {
            vec.push_back(vec_add);
            tnode.push_back(tnode_add);
            return true;
        }
    }

    return false;
}
//方法一：广度优先遍历
//此题是「102. 二叉树的层序遍历」的变种，最后输出的要求有所变化，要求我们按层数的奇偶来决定每一层的输出顺序。规定二叉树的根节点为第 0 层，如果当前层数是偶数，从左至右输出当前层的节点值，否则，从右至左输出当前层的节点值。
//我们依然可以沿用第 102 题的思想，修改广度优先搜索，对树进行逐层遍历，用队列维护当前层的所有元素，当队列不为空的时候，求得当前队列的长度 size，每次从队列中取出 size 个元素进行拓展，然后进行下一次迭代。
//为了满足题目要求的返回值为「先从左往右，再从右往左」交替输出的锯齿形，我们可以利用「双端队列」的数据结构来维护当前层节点值输出的顺序。
//双端队列是一个可以在队列任意一端插入元素的队列。在广度优先搜索遍历当前层节点拓展下一层节点的时候我们仍然从左往右按顺序拓展，但是对当前层节点的存储我们维护一个变量 isOrderLeft 记录是从左至右还是从右至左的：
//如果从左至右，我们每次将被遍历到的元素插入至双端队列的末尾。
//如果从右至左，我们每次将被遍历到的元素插入至双端队列的头部。
//当遍历结束的时候我们就得到了答案数组。
//class Solution {
//public:
//    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
//        vector<vector<int>> ans;
//        if (!root) {
//            return ans;
//        }
//
//        queue<TreeNode*> nodeQueue;
//        nodeQueue.push(root);
//        bool isOrderLeft = true;
//
//        while (!nodeQueue.empty()) {
//            deque<int> levelList;
//            int size = nodeQueue.size();
//            for (int i = 0; i < size; ++i) {
//                auto node = nodeQueue.front();
//                nodeQueue.pop();
//                if (isOrderLeft) {
//                    levelList.push_back(node->val);
//                } else {
//                    levelList.push_front(node->val);
//                }
//                if (node->left) {
//                    nodeQueue.push(node->left);
//                }
//                if (node->right) {
//                    nodeQueue.push(node->right);
//                }
//            }
//            ans.emplace_back(vector<int>{levelList.begin(), levelList.end()});
//            isOrderLeft = !isOrderLeft;
//        }
//
//        return ans;
//    }
//};
//复杂度分析
//时间复杂度：O(N)，其中 N 为二叉树的节点数。每个节点会且仅会被遍历一次。
//空间复杂度：O(N)。我们需要维护存储节点的队列和存储节点值的双端队列，空间复杂度为 O(N)。
