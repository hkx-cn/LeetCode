// 528. 按权重随机选择
// 给你一个 下标从 0 开始 的正整数数组 w ，其中 w[i] 代表第 i 个下标的权重。
// 请你实现一个函数 pickIndex ，它可以 随机地 从范围 [0, w.length - 1] 内（含 0 和 w.length - 1）选出并返回一个下标。选取下标 i 的 概率 为 w[i] / sum(w) 。
// 例如，对于 w = [1, 3]，挑选下标 0 的概率为 1 / (1 + 3) = 0.25 （即，25%），而选取下标 1 的概率为 3 / (1 + 3) = 0.75（即，75%）。

// 示例 1：
// 输入：
// ["Solution","pickIndex"]
// [[[1]],[]]
// 输出：
// [null,0]
// 解释：
// Solution solution = new Solution([1]);
// solution.pickIndex(); // 返回 0，因为数组中只有一个元素，所以唯一的选择是返回下标 0。
//
// 示例 2：
// 输入：
// ["Solution","pickIndex","pickIndex","pickIndex","pickIndex","pickIndex"]
// [[[1,3]],[],[],[],[],[]]
// 输出：
// [null,1,1,1,1,0]
// 解释：
// Solution solution = new Solution([1, 3]);
// solution.pickIndex(); // 返回 1，返回下标 1，返回该下标概率为 3/4 。
// solution.pickIndex(); // 返回 1
// solution.pickIndex(); // 返回 1
// solution.pickIndex(); // 返回 1
// solution.pickIndex(); // 返回 0，返回下标 0，返回该下标概率为 1/4 。
// 由于这是一个随机问题，允许多个答案，因此下列输出都可以被认为是正确的:
// [null,1,1,1,1,0]
// [null,1,1,1,1,1]
// [null,1,1,1,0,0]
// [null,1,1,1,0,1]
// [null,1,0,1,0,0]
// ......
// 诸若此类。

// 提示：
// 1 <= w.length <= 10^4
// 1 <= w[i] <= 10^5
// pickIndex 将被调用不超过 10^4 次
#include "LeetCode528.hpp"
int Solution::pickIndex()
{
    int rand = std::rand() % sum + 1;
    int left = 0, right = arr.size() - 1, mid = -1;
    while (left < right)
    {
        mid = left + (right - left) / 2;
        if (arr[mid] < rand)
            left = mid + 1;
        else
            right = mid;
    }
    return left;
};
// 方法一：前缀和 + 二分查找
// 思路与算法
// 设数组 w 的权重之和为 total。根据题目的要求，我们可以看成将 [1,total] 范围内的所有整数分成 n 个部分（其中 n 是数组 w 的长度），第 i 个部分恰好包含 w[i] 个整数，并且这 n 个部分两两的交集为空。随后我们在 [1,total] 范围内随机选择一个整数 x，如果整数 x 被包含在第 i 个部分内，我们就返回 i。
// 一种较为简单的划分方法是按照从小到大的顺序依次划分每个部分。例如 w=[3,1,2,4] 时，权重之和 total=10，那么我们按照 [1,3],[4,4],[5,6],[7,10] 对 [1,10] 进行划分，使得它们的长度恰好依次为 3,1,2,4。可以发现，每个区间的左边界是在它之前出现的所有元素的和加上 1，右边界是到它为止的所有元素的和。因此，如果我们用 pre[i] 表示数组 w 的前缀和：
// pre[i]=∑k=0iw[k]
// 那么第 i 个区间的左边界就是 pre[i]−w[i]+1，右边界就是 pre[i]。
// 当划分完成后，假设我们随机到了整数 x，我们希望找到满足：
// pre[i]−w[i]+1≤x≤pre[i] 的 i 并将其作为答案返回。由于 pre[i] 是单调递增的，因此我们可以使用二分查找在 O(log⁡n) 的时间内快速找到 i，即找出最小的满足 x≤pre[i] 的下标 i。
// class Solution {
// private:
//     mt19937 gen;
//     uniform_int_distribution<int> dis;
//     vector<int> pre;
// public:
//     Solution(vector<int>& w): gen(random_device{}()), dis(1, accumulate(w.begin(), w.end(), 0)) {
//         partial_sum(w.begin(), w.end(), back_inserter(pre));
//     }
//     int pickIndex() {
//         int x = dis(gen);
//         return lower_bound(pre.begin(), pre.end(), x) - pre.begin();
//     }
// };
// 复杂度分析
// 时间复杂度：初始化的时间复杂度为 O(n)，每次选择的时间复杂度为 O(log⁡n)，其中 n 是数组 w 的长度。
// 空间复杂度：O(n)，即为前缀和数组 pre 需要使用的空间。 