//702. 搜索长度未知的有序数组
//这是一个交互问题。
//您有一个升序整数数组，其长度未知。您没有访问数组的权限，但是可以使用 ArrayReader 接口访问它。你可以调用 ArrayReader.get(i):
//返回数组第ith个索引(0-indexed)处的值(即secret[i])，或者
//如果 i  超出了数组的边界，则返回 2^31 - 1
//你也会得到一个整数 target。
//如果存在secret[k] == target，请返回索引 k 的值；否则返回 -1
//你必须写一个时间复杂度为 O(log n) 的算法。
//
//示例 1：
//输入: secret = [-1,0,3,5,9,12], target = 9
//输出: 4
//解释: 9 存在在 nums 中，下标为 4
//示例 2：
//输入: secret = [-1,0,3,5,9,12], target = 2
//输出: -1
//解释: 2 不在数组中所以返回 -1
//
//提示：
//1 <= secret.length <= 10^4
//-10^4 <= secret[i], target <= 10^4
//secret 严格递增
#include "LeetCode702.hpp"
int search(const ArrayReader& reader, int target){
    int left = 0, right = 1, mid = 0, result = 0;
    ArrayReader r = reader;
    while (left <= right) {
        mid = left + (right - left) / 2;
        result = r.get(mid);
        if (result == target) {
            return mid;
        } else if (result == INT_MAX) {
            right = mid - 1;
        } else if (result < target) {
            left = mid + 1;
            right *= 2;
        } else if (result > target) {
            right = mid - 1;
        }
    }
    return -1;
}
//方法 1：二分查找
//分为两个子问题
//这个数组是已排序的，因此我们可以试图将时间复杂度控制在对数级别。 这意味着我们需要分解成两个子问题，这两个子问题都应该在对数级别的时间内完成：
//定义搜索限制，即搜索的左右边界。
//在定义的边界内进行二分查找。
//定义搜索边界
//这是一个关键的子问题。
//这个思路很简单。我们选取第一个和第二个索引，即0和1，作为左右边界。如果目标值不在这两个元素之中，那么它就在边界之外，即在右边。
//这意味着左边界可以向右移动，而右边界应该进行扩展。为了保持对数时间复杂度，我们让right = right * 2 来扩展它。
//如果目标值现在小于右边元素，那我们就完成了，边界已经设置了。如果没有，重复以上两步，直到边界确定为止：
//
//将左边界移动到右边：left = right。
//扩大右边界：right = right * 2。
//二分搜索
//二分搜索是一个时间复杂度为对数级别的教科书级别的算法。
//它的思路是将目标值和数组的中间元素进行比较。
//如果目标值等于中间元素——我们就完成了。
//如果目标值更小——继续左边的搜索。
//如果目标值更大——继续右边的搜索。
//定义搜索区域的前提条件: 左移和右移
//为了提高速度，我们在这里可以使用位移运算：
//左移：x << 1。等同于乘以 2：x * 2。
//右移：x >> 1。等同于除以 2：x / 2。
//算法
//定义边界：
//初始化 left = 0 和 right = 1。
//当目标在右边界的右边时：reader.get(right) < target：
//将左边界设置为右边界：left = right。
//扩大右边界：right *= 2。为了提高速度，我们用位移操作代替乘法：right <<= 1。
//现在目标值在左边界和右边界之间。
//二分搜索：
//当 left <= right 时：
//选取中间的轴：pivot = (left + right) / 2。为了避免溢出，我们使用 pivot = left + ((right - left) >> 1) 代替上面的表达式。
//获取这个索引处的元素：num = reader.get(pivot)。
//将中间元素 num 与目标值进行比较。
//如果中间元素就是目标 num == target：返回 pivot。
//如果目标还未找到：
//如果 num > target，继续在左边搜索right = pivot - 1。
//否则继续在右边搜索left = pivot + 1。
//我们到这里来是因为没有找到目标，返回-1。
//实现
//class ArrayReader;
//
//class Solution {
// public:
// int search(const ArrayReader& reader, int target) {
//   if (reader.get(0) == target) return 0;
//
//   // 搜索边界
//   int left = 0, right = 1;
//   while (reader.get(right) < target) {
//     left = right;
//     right <<= 1;
//   }
//
//   // 二分查找
//   int pivot, num;
//   while (left <= right) {
//     pivot = left + ((right - left) >> 1);
//     num = reader.get(pivot);
//
//     if (num == target) return pivot;
//     if (num > target) right = pivot - 1;
//     else left = pivot + 1;
//   }
//
//   // 没有目标元素
//   return -1;
// }
//};
//复杂度分析
//时间复杂度：O(logT)，其中 T 是目标值的索引。
//在这里有两个操作：定义搜索边界和进行二分搜索。
//首先找到设置边界所需的步骤k。在第一步，边界是 2^0..2^0+1 ，在第二步 2^1..2^1+1 ，等等。
//当一切都完成时，边界是 2^k..2^k+1 并且2^k<T≤2^k+1 。这意味着我们需要 k=logT 步来设置边界，所以时间复杂度是 O(logT)。
//现在让我们讨论二分搜索的复杂性。边界内的元素是 2^k+1−2^k=2^k ，即 2^logT=T 个元素。
//二分搜索的复杂性是对数级别的，所以时间复杂度是 O(logT)。
//空间复杂度：O(1)，因为这是一个常数空间解决方案。
