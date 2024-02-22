#include "LeetCodeMain.hpp"
#include "LeetCode2641.hpp"
int main()
{
    //13,37,null,11,46,null,26,null,null,36,null,null,18
    TreeNode* node1 = new TreeNode(13);
    TreeNode* node2 = new TreeNode(37);
    TreeNode* node3 = new TreeNode(11);
    TreeNode* node4 = new TreeNode(46);
    TreeNode* node5 = new TreeNode(26);
    TreeNode* node6 = new TreeNode(36);
    TreeNode* node7 = new TreeNode(18);
    node1->left = node2;
    node2->left = node3;
    node2->right = node4;
    node3->right = node5;
    node5->left = node6;
    node6->right = node7;
    Solution sol;
    TreeNode* result = sol.replaceValueInTree(node1);
    return 0;
}
