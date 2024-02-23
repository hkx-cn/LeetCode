//2641. 二叉树的堂兄弟节点 II
//给你一棵二叉树的根 root ，请你将每个节点的值替换成该节点的所有 堂兄弟节点值的和 。
//如果两个节点在树中有相同的深度且它们的父节点不同，那么它们互为 堂兄弟 。
//请你返回修改值之后，树的根 root 。
//注意，一个节点的深度指的是从树根节点到这个节点经过的边数。
//
//示例 1：
//输入：root = [5,4,9,1,10,null,7]
//输出：[0,0,0,7,7,null,11]
//解释：上图展示了初始的二叉树和修改每个节点的值之后的二叉树。
//- 值为 5 的节点没有堂兄弟，所以值修改为 0 。
//- 值为 4 的节点没有堂兄弟，所以值修改为 0 。
//- 值为 9 的节点没有堂兄弟，所以值修改为 0 。
//- 值为 1 的节点有一个堂兄弟，值为 7 ，所以值修改为 7 。
//- 值为 10 的节点有一个堂兄弟，值为 7 ，所以值修改为 7 。
//- 值为 7 的节点有两个堂兄弟，值分别为 1 和 10 ，所以值修改为 11 。
//示例 2：
//输入：root = [3,1,2]
//输出：[0,0,0]
//解释：上图展示了初始的二叉树和修改每个节点的值之后的二叉树。
//- 值为 3 的节点没有堂兄弟，所以值修改为 0 。
//- 值为 1 的节点没有堂兄弟，所以值修改为 0 。
//- 值为 2 的节点没有堂兄弟，所以值修改为 0 。
//
//提示：
//树中节点数目的范围是 [1, 10^5] 。
//1 <= Node.val <= 10^4
#include "LeetCode2641.hpp"
TreeNode* Solution::replaceValueInTree(TreeNode* root){
    queue<TreeNode*> bfs;
    queue<int> node;
    vector<int> level;
    bfs.push(root);
    node.push(root->val);
    level.push_back(root->val);
    int size = 0, depth = 0;
    //广度优先搜索
    while (bfs.size()) {
        //一层一层的搜索
        size = bfs.size();
        depth++;
        level.push_back(0);
        for (size_t i = 0; i < size; i++) {
            if (bfs.front()) {
                int temp = 0;
                if (bfs.front()->left) {
                    temp += bfs.front()->left->val;
                }
                if (bfs.front()->right) {
                    temp += bfs.front()->right->val;
                }
                //记录下一层的每个节点的父节点的左右节点和
                bfs.push(bfs.front()->left);
                bfs.push(bfs.front()->right);
                node.push(temp);
                node.push(temp);
                //遍历一层的时候，计算下一层的所有节点的左右节点和
                level[depth] += temp;
                //堂兄弟节点的值 = 本层所有节点的和 - 父节点的左右节点和
                bfs.front()->val = level[depth - 1] - node.front();
            }
            bfs.pop();
            node.pop();
        }
    }
    return root;
}
//方法一：广度优先搜索
//思路与算法
//题目要求将二叉树中每个节点的值替换为所有堂兄弟节点的和，而堂兄弟节点就是指那些和当前节点深度相同但父节点不同的节点。例如下图中，x 的堂兄弟节点是第 n 层除去 x 和 y 的其他所有节点。假设第 n 层所有节点的和为 sum，那么 x 的值应该被替换为 sum−x−y。
//在广度优先搜索的过程中，通过第 n−1 层去遍历第 n 层的节点时，可以顺便统计第 n 层节点的和 sum。由于更新 x 的值时需要知道 y 的值（有可能不存在），因此需要通过 n−1 层对第 n 层进行第二次遍历，这时就可以使用 sum−x−y 更新 x 的值了。
//在代码实现时，我们需要遍历每一层的节点两次，因此使用动态数组或链表表示的队列会更方便。
//代码
//class Solution {
//public:
//    TreeNode* replaceValueInTree(TreeNode* root) {
//        vector<TreeNode*> q = {root};
//        root->val = 0;
//        while (!q.empty()) {
//            vector<TreeNode*> q2;
//            int sum = 0;
//            for (auto fa : q) {
//                if (fa->left) {
//                    q2.push_back(fa->left);
//                    sum += fa->left->val;
//                }
//                if (fa->right) {
//                    q2.push_back(fa->right);
//                    sum += fa->right->val;
//                }
//            }
//            for (auto fa : q) {
//                int child_sum = (fa->left ? fa->left->val : 0) + 
//                                (fa->right ? fa->right->val : 0);
//                if (fa->left) {
//                    fa->left->val = sum - child_sum;
//                }
//                if (fa->right) {
//                    fa->right->val = sum - child_sum;
//                }
//            }
//            q = move(q2);
//        }
//        return root;
//    }
//};
//复杂度分析
//时间复杂度：O(n)，其中 n 为二叉树中节点的个数。
//空间复杂度：O(n)。
