// 102. 二叉树的层序遍历
// 给你二叉树的根节点 root ，返回其节点值的 层序遍历 。 （即逐层地，从左到右访问所有节点）。

// 示例 1：
// 输入：root = [3,9,20,null,null,15,7]
// 输出：[[3],[9,20],[15,7]]
// 示例 2：
// 输入：root = [1]
// 输出：[[1]]
// 示例 3：
// 输入：root = []
// 输出：[]

// 提示：
// 树中节点数目在范围 [0, 2000] 内
// -1000 <= Node.val <= 1000
#include "LeetCode102.hpp"
vector<vector<int>> Solution::levelOrder(TreeNode *root){
    vector<vector<int>> result;
    vector<vector<TreeNode *>> node;
    if (root == nullptr)
        return result;

    result.push_back({root->val});
    node.push_back({root});

    int depth = 0;
    while(level(node, result, depth)){
        depth++; 
    }
    return result;
}

bool Solution::level(vector<vector<TreeNode*>> &node, vector<vector<int>> &vec, int depth){
    vector<int> node_add;
    vector<TreeNode*> tnode_add;
    for (auto &&tnode : node[depth]){
        if (tnode->left != nullptr){
            tnode_add.push_back(tnode->left);
            node_add.push_back(tnode->left->val);
        }
        if (tnode->right != nullptr){ 
            tnode_add.push_back(tnode->right);
            node_add.push_back(tnode->right->val);
        }       
    }
    if (node_add.size() != 0){
        node.push_back(tnode_add);
        vec.push_back(node_add);
        return true;
    }
    return false;
}
// 方法一：广度优先搜索
// 思路和算法
// 我们可以用广度优先搜索解决这个问题。
// 我们可以想到最朴素的方法是用一个二元组 (node, level) 来表示状态，它表示某个节点和它所在的层数，每个新进队列的节点的 level 值都是父亲节点的 level 值加一。最后根据每个点的 level 对点进行分类，分类的时候我们可以利用哈希表，维护一个以 level 为键，对应节点值组成的数组为值，广度优先搜索结束以后按键 level 从小到大取出所有值，组成答案返回即可。
// 考虑如何优化空间开销：如何不用哈希映射，并且只用一个变量 node 表示状态，实现这个功能呢？
// 我们可以用一种巧妙的方法修改广度优先搜索：
// 首先根元素入队
// 当队列不为空的时候
// 求当前队列的长度 si 依次从队列中取 si 个元素进行拓展，然后进入下一次迭代
// 它和普通广度优先搜索的区别在于，普通广度优先搜索每次只取一个元素拓展，而这里每次取 si 个元素。在上述过程中的第 i 次迭代就得到了二叉树的第 i 层的 si 个元素。
// 为什么这么做是对的呢？我们观察这个算法，可以归纳出这样的循环不变式：第 i 次迭代前，队列中的所有元素就是第 i 层的所有元素，并且按照从左向右的顺序排列。证明它的三条性质（你也可以把它理解成数学归纳法）：
// 初始化：i=1 的时候，队列里面只有 root，是唯一的层数为 1 的元素，因为只有一个元素，所以也显然满足「从左向右排列」；
// 保持：如果 i=k 时性质成立，即第 k 轮中出队 sk 的元素是第 k 层的所有元素，并且顺序从左到右。因为对树进行广度优先搜索的时候由低 k 层的点拓展出的点一定也只能是 k+1 层的点，并且 k+1 层的点只能由第 k 层的点拓展到，所以由这 sk 个点能拓展到下一层所有的 sk+1 个点。又因为队列的先进先出（FIFO）特性，既然第 k 层的点的出队顺序是从左向右，那么第 k+1 层也一定是从左向右。至此，我们已经可以通过数学归纳法证明循环不变式的正确性。
// 终止：因为该循环不变式是正确的，所以按照这个方法迭代之后每次迭代得到的也就是当前层的层次遍历结果。至此，我们证明了算法是正确的。
// 代码
// class Solution {
// public:
//     vector<vector<int>> levelOrder(TreeNode* root) {
//         vector <vector <int>> ret;
//         if (!root) {
//             return ret;
//         }

//         queue <TreeNode*> q;
//         q.push(root);
//         while (!q.empty()) {
//             int currentLevelSize = q.size();
//             ret.push_back(vector <int> ());
//             for (int i = 1; i <= currentLevelSize; ++i) {
//                 auto node = q.front(); q.pop();
//                 ret.back().push_back(node->val);
//                 if (node->left) q.push(node->left);
//                 if (node->right) q.push(node->right);
//             }
//         }
        
//         return ret;
//     }
// };
// 复杂度分析
// 记树上所有节点的个数为 n。
// 时间复杂度：每个点进队出队各一次，故渐进时间复杂度为 O(n)。
// 空间复杂度：队列中元素的个数不超过 n 个，故渐进空间复杂度为 O(n)。