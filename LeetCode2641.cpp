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
    if (root == nullptr) return root;

    queue<TreeNode*> bfs;
    queue<int> node_sum;
    queue<int> depth;
    int sum = 0, node = 0, idx = 0, count = 2;

    bfs.push(root);
    depth.push(root->val);
    node_sum.push(root->val);

    while(!bfs.empty()){
        node = 0;
        if (bfs.front() != nullptr){
            bfs.push(bfs.front()->left);
            bfs.push(bfs.front()->right);
            if (bfs.front()->left != nullptr){
                sum += bfs.front()->left->val;
                node += bfs.front()->left->val;
            }
            if (bfs.front()->right != nullptr){
                sum += bfs.front()->right->val;
                node += bfs.front()->right->val;
            }
            node_sum.push(node);
            node_sum.push(node);
            idx += 2;
            if (count <= 4 && bfs.front() != nullptr){
                bfs.front()->val = 0;
            }
            else{
                if (!depth.empty() && !node_sum.empty() && bfs.front() != nullptr)
                    bfs.front()->val = depth.front() - node_sum.front();
            }
        }
        else{
            count--;
        }
        bfs.pop();
        node_sum.pop(); 

        if (idx >= count){
            depth.pop();
            depth.push(sum);
            idx = 0;
            sum = 0;
            count *= 2;
        }
    }
    return root;
}
