#include "LeetCodeMain.hpp"
#include "LeetCode102.hpp"
int main()
{
    Solution solution;
    TreeNode* node1 = new TreeNode(3);
    TreeNode* node2 = new TreeNode(9);
    TreeNode* node3 = new TreeNode(20);
    TreeNode* node4 = new TreeNode(15);
    TreeNode* node5 = new TreeNode(7);
    node1->left = node2;
    node1->right = node3;
    node3->left = node4;
    node3->right = node5;
    // vector<vector<int>> nums = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
    solution.levelOrder(node1);
//    vector<vector<int>> nums = {{1, 2}};
//    std::cin.get();
    return 0;
}
