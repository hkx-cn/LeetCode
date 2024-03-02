//94. 二叉树的中序遍历
//给定一个二叉树的根节点 root ，返回 它的 中序 遍历 。
//
//示例 1：
//输入：root = [1,null,2,3]
//输出：[1,3,2]
//示例 2：
//输入：root = []
//输出：[]
//示例 3：
//输入：root = [1]
//输出：[1]
//
//提示：
//树中节点数目在范围 [0, 100] 内
//-100 <= Node.val <= 100
//
//进阶: 递归算法很简单，你可以通过迭代算法完成吗？
#include "LeetCode94.hpp"
vector<int> Solution::inorderTraversal(TreeNode* root){
    if (!root) {
        return {};
    }
    vector<int> result;
    stack<pair<TreeNode*, bool>> s;
    s.push({root, true});
    while (s.size()) {
        if (!s.top().first) {
            s.pop();
            while (s.size() && !s.top().second) {
                s.pop();
            }
            if (s.size()) {
                s.top().second = false;
            }
        }
        else if (s.top().second) {
            s.push({s.top().first->left, true});
        }
        else {
            result.push_back(s.top().first->val);
            s.push({s.top().first->right, true});
        }
    }
    return result;
}
//vector<int> Solution::inorderTraversal(TreeNode* root){
//    vector<int> result;
//    inorder(root, result);
//    return result;
//}
////中序遍历 递归
//void Solution::inorder(TreeNode* root, vector<int>& result){
//    if (!root) {
//        return;
//    }
//    inorder(root->left, result);
//    result.push_back(root->val);
//    inorder(root->right, result);
//}
//方法一：递归
//思路与算法
//首先我们需要了解什么是二叉树的中序遍历：按照访问左子树——根节点——右子树的方式遍历这棵树，而在访问左子树或者右子树的时候我们按照同样的方式遍历，直到遍历完整棵树。因此整个遍历过程天然具有递归的性质，我们可以直接用递归函数来模拟这一过程。
//定义 inorder(root) 表示当前遍历到 root 节点的答案，那么按照定义，我们只要递归调用 inorder(root.left) 来遍历 root 节点的左子树，然后将 root 节点的值加入答案，再递归调用inorder(root.right) 来遍历 root 节点的右子树即可，递归终止的条件为碰到空节点。
//代码
//
//class Solution {
//public:
//    void inorder(TreeNode* root, vector<int>& res) {
//        if (!root) {
//            return;
//        }
//        inorder(root->left, res);
//        res.push_back(root->val);
//        inorder(root->right, res);
//    }
//    vector<int> inorderTraversal(TreeNode* root) {
//        vector<int> res;
//        inorder(root, res);
//        return res;
//    }
//};
//复杂度分析
//时间复杂度：O(n)，其中 n 为二叉树节点的个数。二叉树的遍历中每个节点会被访问一次且只会被访问一次。
//空间复杂度：O(n)。空间复杂度取决于递归的栈深度，而栈深度在二叉树为一条链的情况下会达到 O(n) 的级别。
//
//方法二：迭代
//思路与算法
//方法一的递归函数我们也可以用迭代的方式实现，两种方式是等价的，区别在于递归的时候隐式地维护了一个栈，而我们在迭代的时候需要显式地将这个栈模拟出来，其他都相同，具体实现可以看下面的代码。
//
//class Solution {
//public:
//    vector<int> inorderTraversal(TreeNode* root) {
//        vector<int> res;
//        stack<TreeNode*> stk;
//        while (root != nullptr || !stk.empty()) {
//            while (root != nullptr) {
//                stk.push(root);
//                root = root->left;
//            }
//            root = stk.top();
//            stk.pop();
//            res.push_back(root->val);
//            root = root->right;
//        }
//        return res;
//    }
//};
//复杂度分析
//时间复杂度：O(n)，其中 n 为二叉树节点的个数。二叉树的遍历中每个节点会被访问一次且只会被访问一次。
//空间复杂度：O(n)。空间复杂度取决于栈深度，而栈深度在二叉树为一条链的情况下会达到 O(n) 的级别。
//
//方法三：Morris 中序遍历
//思路与算法
//Morris 遍历算法是另一种遍历二叉树的方法，它能将非递归的中序遍历空间复杂度降为 O(1)。
//
//Morris 遍历算法整体步骤如下（假设当前遍历到的节点为 x）：
//如果 x 无左孩子，先将 x 的值加入答案数组，再访问 x 的右孩子，即 x=x.right。
//如果 x 有左孩子，则找到 x 左子树上最右的节点（即左子树中序遍历的最后一个节点，x 在中序遍历中的前驱节点），我们记为 predecessor。根据 predecessor 的右孩子是否为空，进行如下操作。
//如果 predecessor 的右孩子为空，则将其右孩子指向 x，然后访问 x 的左孩子，即 x=x.left。
//如果 predecessor 的右孩子不为空，则此时其右孩子指向 x ，说明我们已经遍历完 x 的左子树，我们将 predecessor 的右孩子置空，将 x 的值加入答案数组，然后访问 x 的右孩子，即 x=x.right。
//重复上述操作，直至访问完整棵树。
//其实整个过程我们就多做一步：假设当前遍历到的节点为 x，将 x 的左子树中最右边的节点的右孩子指向 x，这样在左子树遍历完成后我们通过这个指向走回了 x，且能通过这个指向知晓我们已经遍历完成了左子树，而不用再通过栈来维护，省去了栈的空间复杂度。
//
//代码
//class Solution {
//public:
//    vector<int> inorderTraversal(TreeNode* root) {
//        vector<int> res;
//        TreeNode *predecessor = nullptr;
//
//        while (root != nullptr) {
//            if (root->left != nullptr) {
//                // predecessor 节点就是当前 root 节点向左走一步，然后一直向右走至无法走为止
//                predecessor = root->left;
//                while (predecessor->right != nullptr && predecessor->right != root) {
//                    predecessor = predecessor->right;
//                }
//                
//                // 让 predecessor 的右指针指向 root，继续遍历左子树
//                if (predecessor->right == nullptr) {
//                    predecessor->right = root;
//                    root = root->left;
//                }
//                // 说明左子树已经访问完了，我们需要断开链接
//                else {
//                    res.push_back(root->val);
//                    predecessor->right = nullptr;
//                    root = root->right;
//                }
//            }
//            // 如果没有左孩子，则直接访问右孩子
//            else {
//                res.push_back(root->val);
//                root = root->right;
//            }
//        }
//        return res;
//    }
//};
//复杂度分析
//时间复杂度：O(n)，其中 n 为二叉树的节点个数。Morris 遍历中每个节点会被访问两次，因此总时间复杂度为 O(2n)=O(n)。
//空间复杂度：O(1)。
