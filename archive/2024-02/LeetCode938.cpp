//938. 二叉搜索树的范围和
//给定二叉搜索树的根结点 root，返回值位于范围 [low, high] 之间的所有结点的值的和。
//
//示例 1：
//输入：root = [10,5,15,3,7,null,18], low = 7, high = 15
//输出：32
//示例 2：
//输入：root = [10,5,15,3,7,13,18,1,null,6], low = 6, high = 10
//输出：23
//
//提示：
//树中节点数目在范围 [1, 2 * 10^4] 内
//1 <= Node.val <= 10^5
//1 <= low <= high <= 10^5
//所有 Node.val 互不相同
#include "LeetCode938.hpp"
int Solution::rangeSumBST(TreeNode* root, int low, int high){
    int result = 0;
    dfs(root, low, high, result);
    return result;
}

void Solution::dfs(TreeNode* root, int low, int high, int& result){
    if (!root) {
        return;
    }
    if (root->val >= low && root->val <= high) {
        result += root->val;
    }
    dfs(root->right, low, high, result);
    dfs(root->left, low, high, result);
}
//方法一：深度优先搜索
//思路
//按深度优先搜索的顺序计算范围和。记当前子树根节点为 root，分以下四种情况讨论：
//root 节点为空
//返回 0。
//root 节点的值大于 high
//由于二叉搜索树右子树上所有节点的值均大于根节点的值，即均大于 high，故无需考虑右子树，返回左子树的范围和。
//root 节点的值小于 low
//由于二叉搜索树左子树上所有节点的值均小于根节点的值，即均小于 low，故无需考虑左子树，返回右子树的范围和。
//root 节点的值在 [low,high] 范围内
//此时应返回 root 节点的值、左子树的范围和、右子树的范围和这三者之和。
//
//代码
//class Solution {
//public:
//    int rangeSumBST(TreeNode *root, int low, int high) {
//        if (root == nullptr) {
//            return 0;
//        }
//        if (root->val > high) {
//            return rangeSumBST(root->left, low, high);
//        }
//        if (root->val < low) {
//            return rangeSumBST(root->right, low, high);
//        }
//        return root->val + rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
//    }
//};
//复杂度分析
//时间复杂度：O(n)，其中 n 是二叉搜索树的节点数。
//空间复杂度：O(n)。空间复杂度主要取决于栈空间的开销。
//
//方法二：广度优先搜索
//思路
//使用广度优先搜索的方法，用一个队列 q 存储需要计算的节点。每次取出队首节点时，若节点为空则跳过该节点，否则按方法一中给出的大小关系来决定加入队列的子节点。
//代码
//class Solution {
//public:
//    int rangeSumBST(TreeNode *root, int low, int high) {
//        int sum = 0;
//        queue<TreeNode*> q({root});
//        while (!q.empty()) {
//            auto node = q.front();
//            q.pop();
//            if (node == nullptr) {
//                continue;
//            }
//            if (node->val > high) {
//                q.push(node->left);
//            } else if (node->val < low) {
//                q.push(node->right);
//            } else {
//                sum += node->val;
//                q.push(node->left);
//                q.push(node->right);
//            }
//        }
//        return sum;
//    }
//};
//复杂度分析
//时间复杂度：O(n)，其中 n 是二叉搜索树的节点数。
//空间复杂度：O(n)。空间复杂度主要取决于队列的空间。
