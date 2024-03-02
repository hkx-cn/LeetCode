//104. 二叉树的最大深度
//给定一个二叉树 root ，返回其最大深度。
//二叉树的 最大深度 是指从根节点到最远叶子节点的最长路径上的节点数。
//
//示例 1：
//输入：root = [3,9,20,null,null,15,7]
//输出：3
//示例 2：
//输入：root = [1,null,2]
//输出：2
//
//提示：
//树中节点的数量在 [0, 10^4] 区间内。
//-100 <= Node.val <= 100
#include "LeetCode104.hpp"
int maxDepth(TreeNode* root){
    if (!root) {
        return 0;
    }
    int depth = 0, size = 0;
    queue<TreeNode*> que;
    que.push(root);
    while (que.size()) {
        size = que.size();
        for (size_t i = 0; i < size; i++) {
            if (que.front()) {
                if (que.front()->left) {
                    que.push(que.front()->left);
                }
                if (que.front()->right) {
                    que.push(que.front()->right);
                }
            }
            que.pop();
        }
        depth++;
    }
    return depth;
}
//方法一：深度优先搜索
//思路与算法
//如果我们知道了左子树和右子树的最大深度 l 和 r，那么该二叉树的最大深度即为
//max(l,r)+1
//而左子树和右子树的最大深度又可以以同样的方式进行计算。因此我们可以用「深度优先搜索」的方法来计算二叉树的最大深度。具体而言，在计算当前二叉树的最大深度时，可以先递归计算出其左子树和右子树的最大深度，然后在 O(1) 时间内计算出当前二叉树的最大深度。递归在访问到空节点时退出。
//class Solution {
//public:
//    int maxDepth(TreeNode* root) {
//        if (root == nullptr) return 0;
//        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
//    }
//};
//复杂度分析
//时间复杂度：O(n)，其中 n 为二叉树节点的个数。每个节点在递归中只被遍历一次。
//空间复杂度：O(height)，其中 height 表示二叉树的高度。递归函数需要栈空间，而栈空间取决于递归的深度，因此空间复杂度等价于二叉树的高度。
//
//方法二：广度优先搜索
//思路与算法
//我们也可以用「广度优先搜索」的方法来解决这道题目，但我们需要对其进行一些修改，此时我们广度优先搜索的队列里存放的是「当前层的所有节点」。每次拓展下一层的时候，不同于广度优先搜索的每次只从队列里拿出一个节点，我们需要将队列里的所有节点都拿出来进行拓展，这样能保证每次拓展完的时候队列里存放的是当前层的所有节点，即我们是一层一层地进行拓展，最后我们用一个变量 ans 来维护拓展的次数，该二叉树的最大深度即为 ans。
//class Solution {
//public:
//    int maxDepth(TreeNode* root) {
//        if (root == nullptr) return 0;
//        queue<TreeNode*> Q;
//        Q.push(root);
//        int ans = 0;
//        while (!Q.empty()) {
//            int sz = Q.size();
//            while (sz > 0) {
//                TreeNode* node = Q.front();Q.pop();
//                if (node->left) Q.push(node->left);
//                if (node->right) Q.push(node->right);
//                sz -= 1;
//            }
//            ans += 1;
//        } 
//        return ans;
//    }
//};
//复杂度分析
//时间复杂度：O(n)，其中 n 为二叉树的节点个数。与方法一同样的分析，每个节点只会被访问一次。
//空间复杂度：此方法空间的消耗取决于队列存储的元素数量，其在最坏情况下会达到 O(n)。
