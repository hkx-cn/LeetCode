//889. 根据前序和后序遍历构造二叉树
//给定两个整数数组，preorder 和 postorder ，其中 preorder 是一个具有 无重复 值的二叉树的前序遍历，postorder 是同一棵树的后序遍历，重构并返回二叉树。
//如果存在多个答案，您可以返回其中 任何 一个。
//
//示例 1：
//输入：preorder = [1,2,4,5,3,6,7], postorder = [4,5,2,6,7,3,1]
//输出：[1,2,3,4,5,6,7]
//示例 2:
//输入: preorder = [1], postorder = [1]
//输出: [1]
//
//提示：
//1 <= preorder.length <= 30
//1 <= preorder[i] <= preorder.length
//preorder 中所有值都 不同
//postorder.length == preorder.length
//1 <= postorder[i] <= postorder.length
//postorder 中所有值都 不同
//保证 preorder 和 postorder 是同一棵二叉树的前序遍历和后序遍历
#include "LeetCode889.hpp"
TreeNode* Solution::constructFromPrePost(vector<int>& preorder, vector<int>& postorder){
    stack<TreeNode*> Preorder;
    stack<int> Postorder;
    TreeNode* left = nullptr, * right = nullptr;
    int index = 0, Left = 0, Right = 0;
    for (size_t i = 0; i < preorder.size(); i++) {
        Preorder.push(new TreeNode(preorder[i]));
        if (preorder[i] == postorder[index]) {
            //压栈
            Postorder.push(postorder[index]);
            index = index + 1 < preorder.size() ? index + 1 : preorder.size() - 1;
            //弹栈
            while (Preorder.size()) {
                right = Preorder.top();
                Right = Postorder.top();
                Preorder.pop();
                Postorder.pop();
                if (Preorder.size() && Preorder.top()->val == postorder[index]) {
                    Preorder.top()->right = right;
                    Postorder.push(postorder[index]);
                    index = index + 1 < preorder.size() ? index + 1 : preorder.size() - 1;
                }
                else if (Preorder.size() && Postorder.size() && Preorder.top()->val == Postorder.top()) {
                    left = Preorder.top();
                    Left = Postorder.top();
                    Preorder.pop();
                    Postorder.pop();
                    if (Preorder.size() && Preorder.top()->val == postorder[index]) {
                        Preorder.top()->left = left;
                        Preorder.top()->right = right;
                        Postorder.push(postorder[index]);
                        index = index + 1 < preorder.size() ? index + 1 : preorder.size() - 1;
                    }
                }
                else {
                    Preorder.push(right);
                    Postorder.push(Right);
                    break;
                }
            }
        }
    }
    return Preorder.top();
}
//方法一：分治
//令 n 为二叉树的节点数目，那么根据前序遍历与后序遍历的定义，preorder[0] 与 postorder[n−1] 都对应二叉树的根节点。获取根节点后，我们需要划分根节点的左子树与右子树，考虑两种情况：
//原二叉树的根节点的左子树不为空，那么 preorder[1] 对应左子树的根节点；
//原二叉树的根节点的左子树为空，那么 preorder[1] 对应右子树的根节点。
//对于以上两种情况，我们无法区分 preorder[1] 到底是哪种情况。但是对于第二种情况，将原二叉树的右子树移到左子树后得到的二叉树的前序遍历数组与后序遍历数组与原二叉树相同，所以我们只需要考虑第一种情况。因为二叉树的值互不相同，我们可以在 postorder 中找到 postorder[k]=preorder[1]，那么左子树的节点数目为 k+1。基于此，我们可以对 preorder 和 postorder 进行分治处理，即将 preorder 划分为根节点、左子树节点和右子树节点三个部分，postorder 也划分为左子树节点、右子树节点和根节点三个部分。那么问题划分为：
//根据左子树节点的前序遍历与后序遍历数组构造二叉树；
//根据右子树节点的前序遍历与后序遍历数组构造二叉树。
//同时当节点数目为 1 时，对应构造的二叉树只有一个节点。我们可以递归地对问题进行求解，就可得到构造的二叉树。
//class Solution {
//public:
//    TreeNode *constructFromPrePost(vector<int> &preorder, vector<int> &postorder) {
//        int n = preorder.size();
//        unordered_map<int, int> postMap;
//        for (int i = 0; i < n; i++) {
//            postMap[postorder[i]] = i;
//        }
//        function<TreeNode *(int, int, int, int)> dfs = [&](int preLeft, int preRight, int postLeft, int postRight) -> TreeNode * {
//            if (preLeft > preRight) {
//                return nullptr;
//            }
//            int leftCount = 0;
//            if (preLeft < preRight) {
//                leftCount = postMap[preorder[preLeft + 1]] - postLeft + 1;
//            }
//            return new TreeNode(preorder[preLeft],
//                dfs(preLeft + 1, preLeft + leftCount, postLeft, postLeft + leftCount - 1),
//                dfs(preLeft + leftCount + 1, preRight, postLeft + leftCount, postRight - 1));
//        };
//        return dfs(0, n - 1, 0, n - 1);
//    }
//};
//复杂度分析
//时间复杂度：O(n)，其中 n 是二叉树的节点数目。深度优先搜索的时间复杂度为 O(n)。
//空间复杂度：O(n)。保存哈希表 postMap 需要 O(n) 的空间，深度优先搜索需要的栈空间也为 O(n)。
