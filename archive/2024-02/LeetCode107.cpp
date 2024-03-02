//107. 二叉树的层序遍历 II
//给你二叉树的根节点 root ，返回其节点值 自底向上的层序遍历 。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）
//
//示例 1：
//输入：root = [3,9,20,null,null,15,7]
//输出：[[15,7],[9,20],[3]]
//示例 2：
//输入：root = [1]
//输出：[[1]]
//示例 3：
//输入：root = []
//输出：[]
//
//提示：
//树中节点数目在范围 [0, 2000] 内
//-1000 <= Node.val <= 1000
#include "LeetCode107.hpp"
vector<vector<int>> Solution::levelOrderBottom(TreeNode* root){
    if (root == nullptr) {
        return {{}};
    }
    vector<vector<int>> result;
    vector<vector<TreeNode*>> tnode;
    int depth = 0;
    result.push_back({root->val});
    tnode.push_back({root});
    while (level(result, tnode, depth)) {
        depth++;
    }
    return result;
}

bool Solution::level(vector<vector<int>> &vec, vector<vector<TreeNode*>> &tnode, int depth){
    vector<TreeNode*> tnode_add;
    vector<int> vec_add;
    for(auto var : tnode[depth]) {
        if (var->left != nullptr) {
            tnode_add.push_back(var->left);
            vec_add.push_back(var->left->val);
        }
        if (var->right != nullptr) {
            tnode_add.push_back(var->right);
            vec_add.push_back(var->right->val);
        }
    }
    if (tnode_add.size() != 0) {
        tnode.push_back(tnode_add);
        vec.insert(vec.begin(), vec_add);
        return true;
    }
    return false;
}
//前言
//这道题和「102. 二叉树的层序遍历」相似，不同之处在于，第 102 题要求从上到下输出每一层的节点值，而这道题要求从下到上输出每一层的节点值。除了输出顺序不同以外，这两道题的思路是相同的，都可以使用广度优先搜索进行层次遍历。
//方法一：广度优先搜索
//树的层次遍历可以使用广度优先搜索实现。从根节点开始搜索，每次遍历同一层的全部节点，使用一个列表存储该层的节点值。
//如果要求从上到下输出每一层的节点值，做法是很直观的，在遍历完一层节点之后，将存储该层节点值的列表添加到结果列表的尾部。这道题要求从下到上输出每一层的节点值，只要对上述操作稍作修改即可：在遍历完一层节点之后，将存储该层节点值的列表添加到结果列表的头部。
//为了降低在结果列表的头部添加一层节点值的列表的时间复杂度，结果列表可以使用链表的结构，在链表头部添加一层节点值的列表的时间复杂度是 O(1)。在 Java 中，由于我们需要返回的 List 是一个接口，这里可以使用链表实现；而 C++ 或 Python 中，我们需要返回一个 vector 或 list，它不方便在头部插入元素（会增加时间开销），所以我们可以先用尾部插入的方法得到从上到下的层次遍历列表，然后再进行反转。
//class Solution {
//public:
//    vector<vector<int>> levelOrderBottom(TreeNode* root) {
//        auto levelOrder = vector<vector<int>>();
//        if (!root) {
//            return levelOrder;
//        }
//        queue<TreeNode*> q;
//        q.push(root);
//        while (!q.empty()) {
//            auto level = vector<int>();
//            int size = q.size();
//            for (int i = 0; i < size; ++i) {
//                auto node = q.front();
//                q.pop();
//                level.push_back(node->val);
//                if (node->left) {
//                    q.push(node->left);
//                }
//                if (node->right) {
//                    q.push(node->right);
//                }
//            }
//            levelOrder.push_back(level);
//        }
//        reverse(levelOrder.begin(), levelOrder.end());
//        return levelOrder;
//    }
//};
//复杂度分析
//时间复杂度：O(n)，其中 n 是二叉树中的节点个数。每个节点访问一次，结果列表使用链表的结构时，在结果列表头部添加一层节点值的列表的时间复杂度是 O(1)，因此总时间复杂度是 O(n)。
//空间复杂度：O(n)，其中 n 是二叉树中的节点个数。空间复杂度取决于队列开销，队列中的节点个数不会超过 n。
