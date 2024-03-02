//1099. 小于 K 的两数之和
//给你一个整数数组 nums 和整数 k ，返回最大和 sum ，满足存在 i < j 使得 nums[i] + nums[j] = sum 且 sum < k 。如果没有满足此等式的 i,j 存在，则返回 -1 。
//
//示例 1：
//输入：nums = [34,23,1,24,75,33,54,8], k = 60
//输出：58
//解释：
//34 和 24 相加得到 58，58 小于 60，满足题意。
//示例 2：
//输入：nums = [10,20,30], k = 15
//输出：-1
//解释：
//我们无法找到和小于 15 的两个元素。
//
//提示：
//1 <= nums.length <= 100
//1 <= nums[i] <= 1000
//1 <= k <= 2000
#include "LeetCode1099.hpp"
//方法一：暴力求解
//int Solution::twoSumLessThanK(vector<int>& nums, int k){
//    int result = 0;
//    for (size_t i = 0; i < nums.size(); i++){
//        for (size_t j = i + 1; j < nums.size(); j++){
//            if (nums[i] + nums[j] < k){
//                result = max(result, nums[i] + nums[j]);
//            }
//        }
//    }
//    return result;
//}
int Solution::twoSumLessThanK(vector<int>& nums, int k){
    sort(nums.begin(), nums.end());
    int left = 0, right = nums.size() - 1;
    int result = -1;
    while (left < right){
        if (nums[left] + nums[right] < k){
            result = max(result, nums[left] + nums[right]);
            left++;
        }
        else{
            right--;
        }
    }
    return result;
}
//解决方案
//这个问题是 两数之和 的一个变种。主要的区别在于我们这里并不是在寻找精确的目标值。相反，我们得到的和与目标值有某种 关系。对于这个问题，我们要找的是一个小于目标值的最大和。
//首先，让我们看看类似问题的解决方案：
//两数之和 使用哈希表来查找补数值，因此其时间复杂度为 O(N)。
//两数之和 II 使用的是双指针，其时间复杂度也为 O(N)，在数组已排序的情况下。对于任何数组，如果我们先对它进行排序，就会将时间复杂度提升至 O(nlog⁡n)。
//由于我们的和可以取小于目标值的任何值，我们不能使用哈希映射。我们不知道该查找哪个值！相反，我们需要对数组进行排序，然后使用二分搜索或者两指针模式，就像在 两数之和 II 中一样。在已排序的数组中，找到接近给定值的元素非常容易。
//
//方法 1：暴力法
//理解输入约束以选择最合适的方法 是非常重要的。对于这个问题，我们的数组大小限制为 100。所以，暴力解法可能是一个合理的选择。它简单且不需要额外的内存。
//算法
//对 nums 中的每个索引 i：
//对每个索引 j > i 在 nums 中：
//如果 nums[i] + nums[j] 小于 k：
//在结果 answer 中跟踪目前最大的 nums[i] + nums[j]
//返回结果 answer。
//class Solution {
//public:
//   int twoSumLessThanK(vector<int>& nums, int k) {
//       int answer = -1;
//       for (int i = 0; i < nums.size(); i++) {
//           for (int j = i + 1; j < nums.size(); j++) {
//               int sum = nums[i] + nums[j];
//               if (sum < k) {
//                   answer = max(answer, sum);
//               }
//           }
//       }
//       return answer;
//   }
//};
//复杂度分析
//时间复杂度：O(n^2)。我们有 2 个嵌套循环。
//空间复杂度：O(1)。
//
//方法 2：双指针
//我们将采用和 两数之和 II 相同的双指针的方法 。它要求数组已排序，所以我们先将数组排序。
//做个快速概述，指针最初设定为第一个元素和最后一个元素。我们将这两个元素的和与目标进行比较。如果它小于目标，我们就将较低的指针 left 做增加。否则，我们将较高的指针 right 进行减小。因此，和总是朝向目标移动，并且我们“删减”了那些会使之远离目标的对。再次，只有在数组已排序的时候，这种方法 才能起作用。有关详细解释，请转到 两数之和 II 的解答部分。
//由于这里的和必须小于目标，我们在找到一对准确的目标和时并不停止。我们减小较高的指针并继续，直到我们的指针重合。每层迭代中，我们都会跟踪最大的和-如果它小于目标的话。
//对数组排序。
//将 left 指针设为 0，right 指针设为最后一个索引。
//当 left 指针小于 right 指针时：
//如果 nums[left] + nums[right] 小于 k：
//在结果 answer 中跟踪目前最大的 nums[left] + nums[right]。
//增加 left。
//否则：
//减小 right。
//返回结果 answer。
//class Solution {
//public:
//   int twoSumLessThanK(vector<int>& nums, int k) {
//       sort(nums.begin(), nums.end());
//       int answer = -1;
//       int left = 0;
//       int right = nums.size() - 1;
//       while (left < right) {
//           int sum = nums[left] + nums[right];
//           if (sum < k) {
//               answer = max(answer, sum);
//               left++;
//           } else {
//               right--;
//           }
//       }
//       return answer;
//   }
//};
//优化
//我们可以在 nums[left] > k / 2 的时候结束循环。在已排序的数组中，nums[left] 是剩余元素中的最小元素，所以对于任何 right，我们有 nums[right] > k / 2。因此，对于剩余的元素，nums[left] + nums[right] 将等于或大于 k。
//复杂度分析
//时间复杂度：排序数组需要 O(nlog⁡n)，两指针的方法 本身为 O(n)，所以如果输入已排序，这个方法 的时间复杂度是线性的。
//空间复杂度：从 O(log⁡n) 到O(n)，取决于排序算法的实现。
//
//方法 3：二分查找
//我们可以将双指针朝向目标移动的方法 ，改为迭代每个元素 nums[i]，并对 k - nums[i] 进行二分查找。这个方法比两指针方法效率稍低，但是，可能会更直观。同上，我们需要先对数组进行排序，这样才能起作用。
//注意，二分查找返回查找值的“插入点”，即将该值插入于保持数组排序的位置。因此，二分查找的结果指向第一个等于或大于补数值的元素。由于我们的和必须小于 k，我们考虑找到元素之前的元素。
//算法
//对数组进行排序。
//对 nums 中的每个索引 i：
//从 i + 1 开始对 k - nums[i] 进行二分查找。
//将 j 设定为找到元素前的位置。
//如果 j 小于 i：
//在结果 answer 中追踪目前最大的 nums[i] + nums[j]。
//返回结果 answer。
//注意，Java 中的二分查找函数有点不同。如果有多个元素与查找值匹配，它并不保证指向第一个。这就是为什么在下面的 Java 解决方案中，我们对 k - nums[i] - 1 进行查找。注意，只有当我们找到的值大于 k - nums[i] - 1 时，我们才减小指针。
//class Solution {
//public:
//   int twoSumLessThanK(vector<int>& nums, int k) {
//       int answer = -1;
//       sort(nums.begin(), nums.end());
//       for (int i = 0; i < nums.size() && nums[i] < k; i++) {
//           auto j = lower_bound(nums.begin() + i + 1, nums.end(), k - nums[i]) - nums.begin() - 1;
//           if (j > i) {
//               answer = max(answer, nums[i] + nums[j]);
//           }
//       }
//       return answer;
//   }
//};
//复杂度分析
//时间复杂度：对数组进行排序并对每个元素进行二分查找，需要 O(nlog⁡n)。
//空间复杂度：从 O(log⁡n) 到 O(n)，取决于排序算法的实现。
//
//方法 4：计数排序
//我们可以利用输入数值的范围限制在 [1..1000] 之间，并使用计数排序。然后，我们可以使用双指针的模式来在 [1..1000] 范围内列举配对。
//注意，结果可以是两个相同数字的和，这意味着 lo 可以等于 hi。在这种情况下，我们需要检查该数字的计数是否大于一。
//算法
//使用数组 count 计数每个元素。
//将 lo 数字设为零，将 hi 数字设为1000。
//当 lo 小于或 等于 hi 的时候：
//如果 lo + hi 大于 k，或 count[hi] == 0：
//减小 hi。
//否则：
//如果 count[lo] 大于 0（当 lo < hi 时）或 1 （当 lo == hi 时）：
//在结果 answer 中追踪目前最大的 lo + hi。
//增加 lo。
//返回结果 answer。
//class Solution {
//public:
//   int twoSumLessThanK(vector<int>& nums, int k) {
//       int answer = -1;
//       int count[1001] = {};
//       for (int num : nums) {
//           count[num]++;
//       }
//       int lo = 1;
//       int hi = 1000;
//       while (lo <= hi) {
//           if (lo + hi >= k || count[hi] == 0) {
//               hi--;
//           } else {
//               if (count[lo] > (lo < hi ? 0 : 1)) {
//                   answer = max(answer, lo + hi);
//               }
//               lo++;
//           }
//       }
//       return answer;
//   }
//};
//优化
//我们可以将 hi 设定为最大数或者 k - 1，两者取小者。
//我们可以忽略大于 k - 1 的数。
//我们可以使用布尔数组（例如 seen）代替 count。在第一个循环中，我们将检查 i 是否为重复数字（seen[i] 已经是 true），并将 answer 设定为最高的 i + i < k。注意两指针的循环将运行，而 lo < hi，而不是 lo <= hi。
//可以在 nums[lo] > k / 2 的情况下打破两指针的循环。
//复杂度分析
//时间复杂度：O(n+m)，其中 m 对应于输入数组中值的范围。
//空间复杂度：O(m) ，计数每个值。
//进阶
//始终在面试中明确问题约束和输入。这将帮助你选择正确的方法。
//当元素数量较大，可能值的范围没有限制时，选择双指针的办法是个好选择。另外，如果输入数组已经排序，这个办法的时间复杂度是线性的，而且不需要额外的内存。
