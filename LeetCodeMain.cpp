#include "LeetCodeMain.hpp"
#include "LeetCode4.hpp"

int main() {
    vector<int> nums1 = {2};
    vector<int> nums2 = {1, 3, 4, 5, 6};
    Solution solution;
    double result = solution.findMedianSortedArrays(nums1, nums2);
    std::cout << result << std::endl;
    return 0;
}
