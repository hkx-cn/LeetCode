#include "LeetCodeMain.hpp"
// #include "LeetCode670.hpp"
#include <vector>
using namespace std;
class Solution {
public:
    int alternatingSubarray(vector<int>& nums) {
        int max = -1, dif = 1, len = 1;
        for (int i = 0; i < nums.size() - 1; i++){
            if (nums[i + 1] - nums[i] == dif){
                len++;
                dif *= -1;
                max = max > len ? max : len;
            }
            else{
                len = 1;
                dif = 1;
				if (nums[i + 1] - nums[i] == dif){
					len++;
					dif *= -1;
					max = max > len ? max : len;
				}
            }
        }
        return max;
    }
};

int main()
{
	Solution solution;
	vector<int> nums = {2,3,4,3,4};
	solution.alternatingSubarray(nums);
	// std::cin.get();
	return 0;
}