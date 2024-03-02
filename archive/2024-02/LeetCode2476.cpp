//2476. 二叉搜索树最近节点查询
//给你一个 二叉搜索树 的根节点 root ，和一个由正整数组成、长度为 n 的数组 queries 。
//请你找出一个长度为 n 的 二维 答案数组 answer ，其中 answer[i] = [mini, maxi] ：
//mini 是树中小于等于 queries[i] 的 最大值 。如果不存在这样的值，则使用 -1 代替。
//maxi 是树中大于等于 queries[i] 的 最小值 。如果不存在这样的值，则使用 -1 代替。
//返回数组 answer 。
//
//示例 1 ：
//输入：root = [6,2,13,1,4,9,15,null,null,null,null,null,null,14], queries = [2,5,16]
//输出：[[2,2],[4,6],[15,-1]]
//解释：按下面的描述找出并返回查询的答案：
//- 树中小于等于 2 的最大值是 2 ，且大于等于 2 的最小值也是 2 。所以第一个查询的答案是 [2,2] 。
//- 树中小于等于 5 的最大值是 4 ，且大于等于 5 的最小值是 6 。所以第二个查询的答案是 [4,6] 。
//- 树中小于等于 16 的最大值是 15 ，且大于等于 16 的最小值不存在。所以第三个查询的答案是 [15,-1] 。
//示例 2 ：
//输入：root = [4,null,9], queries = [3]
//输出：[[-1,4]]
//解释：树中不存在小于等于 3 的最大值，且大于等于 3 的最小值是 4 。所以查询的答案是 [-1,4] 。
//
//提示：
//树中节点的数目在范围 [2, 10^5] 内
//1 <= Node.val <= 10^6
//n == queries.length
//1 <= n <= 10^5
//1 <= queries[i] <= 10^6
#include "LeetCode2476.hpp"
vector<vector<int>> Solution::closestNodes(TreeNode* root, vector<int>& queries){
    vector<vector<int>> result(queries.size());
    vector<int> nums;
    dfs(root, nums);
    for (size_t i = 0; i < queries.size(); i++) {
        result[i] = {-1, -1};
        binarySearch(nums, queries[i], result[i]);
    }
    return result;
}

void Solution::dfs(TreeNode* root, vector<int>& nums){
    if (!root) {
        return;
    }
    dfs(root->left, nums);
    nums.push_back(root->val);
    dfs(root->right, nums);
}

void Solution::binarySearch(const vector<int>& nums, int target, vector<int>& result){
    int left = 0, right = nums.size() - 1, mid = -1;
    while (left <= right) {
        mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            result = {target, target};
            break;
        }
        else if (nums[mid] < target) {
            result[0] = result[0] > nums[mid] ? result[0] : nums[mid];
            left = mid + 1;
        }
        else if (nums[mid] > target) {
            if (result[1] == -1) {
                result[1] = nums[mid];
            }
            else {
                result[1] = result[1] < nums[mid] ? result[1] : nums[mid];
            }
            right = mid - 1;
        }
    }
    return;
}

//二叉搜索树不平衡导致超时
void Solution::query(TreeNode* root, int target, vector<int>& result){
    if (!root) {
        return;
    }
    if (root->val == target) {
        result = {target, target};
        return;
    }
    if (root->val > target) {
        if (result[1] == -1) {
            result[1] = root->val;
        }
        else {
            result[1] = root->val < result[1] ? root->val : result[1];
        }
        query(root->left, target, result);
    }
    if (root->val < target) {
        result[0] = root->val > result[0] ? root->val : result[1];
        query(root->right, target, result);
    }
}
//方法一：二分查找
//思路与算法
//根据题意要求给定查询的值 queriesi ，需要在二叉搜索中找到 mini,maxi：
//mini 是树中小于等于 queriesi 的最大值。如果不存在这样的值，则使用 −1 代替。
//maxi 是树中大于等于 queriesi 的最小值。如果不存在这样的值，则使用 −1 代替。
//由于该二叉搜索树并不是平衡的，则最坏情况该树可能形成一条链，直接在树上查找可能存在超时。我们可以保存树中所有的节点值，并将其排序，每次给定查询值 val 时，利用二分查找直接在树中找到大于等于 val 的最小值与小于等于 val 的最小值。由于给定的二叉树为二叉搜索树，因此按照中序遍历该树的结果即为升序，我们直接用数组 arr 保存二叉树的中序遍历结果，并使用二分查找在索引中找到大于等于 val 最左侧的索引 index，此时分析如下：
//
//如果索引 index 合法存在，则此时大于等于 val 的最小元素即为 arr[index]，否则则为 −1，如果此时 arr[index]=val，则小于等于 val 的最大元素也为 arr[index]。
//如果索引 index 大于 0，则此时小于等于 val 的最大元素即为 arr[index−1]，否则则为 −1。
//我们按照题目要求返回查询结果即可。
//代码
//class Solution {
//public:
//    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
//        vector<int> arr;
//        function<void(TreeNode*)> dfs = [&](TreeNode *root) {
//            if (!root) {
//                return;
//            }    
//            dfs(root->left);
//            arr.emplace_back(root->val);
//            dfs(root->right);
//        };
//        dfs(root);
//
//        vector<vector<int>> res;
//        for (int val : queries) {
//            int maxVal = -1, minVal = -1;
//            auto it = lower_bound(arr.begin(), arr.end(), val);
//            if (it != arr.end()) {
//                maxVal = *it;
//                if (*it == val) {
//                    minVal = *it;
//                    res.push_back({minVal, maxVal});
//                    continue;
//                }
//            }
//            if (it != arr.begin()) {
//                minVal = *(--it);
//            }
//            res.push_back({minVal, maxVal});
//        }
//        return res;
//    }
//};
//复杂度分析
//时间复杂度：O(n+qlogn)，其中 n 表示给定二叉搜索树中节点的数目，q 表示给定的查询数组的长度。遍历整个二叉树需要的时间为 O(n)，每次查询时二分查找需要的时间为 O(logn)，一共需要 q 次二分查找，因此总的时间复杂度为 O(n+qlogn)。
//空间复杂度：O(n)，其中 n 表示给定二叉搜索树中节点的数目。查询时，需要用数组保存二叉树中所有节点的值，需要的空间为 O(n)。
