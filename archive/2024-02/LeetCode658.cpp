//658. 找到 K 个最接近的元素
//给定一个 排序好 的数组 arr ，两个整数 k 和 x ，从数组中找到最靠近 x（两数之差最小）的 k 个数。返回的结果必须要是按升序排好的。
//整数 a 比整数 b 更接近 x 需要满足：
//|a - x| < |b - x| 或者
//|a - x| == |b - x| 且 a < b
//
//示例 1：
//输入：arr = [1,2,3,4,5], k = 4, x = 3
//输出：[1,2,3,4]
//示例 2：
//输入：arr = [1,2,3,4,5], k = 4, x = -1
//输出：[1,2,3,4]
//
//提示：
//1 <= k <= arr.length
//1 <= arr.length <= 10^4
//arr 按 升序 排列
//-10^4 <= arr[i], x <= 10^4
#include "LeetCode658.hpp"
vector<int> Solution::findClosestElements(vector<int>& arr, int k, int x){
    vector<int> result;
    int left = 0, right = arr.size() - 1, mid = 0, targetIndex = 0, minDiff = 1000000;
    while (left <= right) {
        mid = left + (right - left) / 2;
        if (arr[mid] == x) {
            targetIndex = mid;
            break;
        }
        else if (arr[mid] > x) {
            right = mid - 1;
            if (minDiff > abs(arr[mid] - x)) {
                targetIndex = mid;
                minDiff = abs(arr[mid] - x);
            };
        }
        else if (arr[mid] < x) {
            left = mid + 1;
            if (minDiff >= abs(arr[mid] - x)) {
                targetIndex = mid;
                minDiff = abs(arr[mid] - x);
            };
        }
    }
    left = targetIndex;
    right = targetIndex;
    result.push_back(arr[targetIndex]);
    for (size_t i = 1; i < k; i++) {
        if (left > 0 && right < arr.size() - 1) {
            if (abs(arr[left - 1] - x) <= abs(arr[right + 1] - x)) {
                left--;
                result.push_back(arr[left]);
            }
            else {
                right++;
                result.push_back(arr[right]);
            }
        }
        else if (left <= 0) {
            right++;
            result.push_back(arr[right]);
        }
        else if (right >= arr.size() - 1) {
            left--;
            result.push_back(arr[left]);
        }
    }
    sort(result.begin(), result.end());
    return result;
}
//方法一：排序
//首先将数组 arr 按照「更接近」的定义进行排序，如果 a 比 b 更接近 x，那么 a 将排在 b 前面。排序完成之后，k 个最接近的元素就是数组 arr 的前 k 个元素，将这 k 个元素从小到大进行排序后，直接返回。
//
//class Solution {
//public:
//    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
//        sort(arr.begin(), arr.end(), [x](int a, int b) -> bool {
//            return abs(a - x) < abs(b - x) || abs(a - x) == abs(b - x) && a < b;
//        });
//        sort(arr.begin(), arr.begin() + k);
//        return vector<int>(arr.begin(), arr.begin() + k);
//    }
//};
//复杂度分析
//时间复杂度：O(nlogn)，其中 n 是数组 arr 的长度。排序需要 O(nlogn)。
//空间复杂度：O(logn)。返回值不计算时间复杂度。排序需要 O(logn) 的栈空间。
//
//方法二：二分查找 + 双指针
//假设数组长度为 n，注意到数组 arr 已经按照升序排序，我们可以将数组 arr 分成两部分，前一部分所有元素 [0,left] 都小于 x，后一部分所有元素 [right,n−1] 都大于等于 x，left 与 right 都可以通过二分查找获得。
//left 和 right 指向的元素都是各自部分最接近 x 的元素，因此我们可以通过比较 left 和 right 指向的元素获取整体最接近 x 的元素。如果 x−arr[left]≤arr[right]−x，那么将 left 减一，否则将 right 加一。相应地，如果 left 或 right 已经越界，那么不考虑对应部分的元素。
//最后，区间 [left+1,right−1] 的元素就是我们所要获得的结果，返回答案既可。
//class Solution {
//public:
//    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
//        int right = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
//        int left = right - 1;
//        while (k--) {
//            if (left < 0) {
//                right++;
//            } else if (right >= arr.size()) {
//                left--;
//            } else if (x - arr[left] <= arr[right] - x) {
//                left--;
//            } else {
//                right++;
//            }
//        }
//        return vector<int>(arr.begin() + left + 1, arr.begin() + right);
//    }
//};
//复杂度分析
//时间复杂度：O(logn+k)，其中 n 是数组 arr 的长度。二分查找需要 O(logn)，双指针查找需要 O(k)。
//空间复杂度：O(1)。返回值不计入空间复杂度。
