#include "LeetCodeMain.hpp"
#include "LeetCode658.hpp"
int main()
{
    std::vector<int> nums = {1, 2, 3, 4, 5};
    Solution sol;
    std::vector<int> result = sol.findClosestElements(nums, 4, -1);
    return 0;
}
