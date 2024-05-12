#pragma once
#include <stdlib.h>
// #include <vector>
// using namespace std;

// class Solution {
// public:
//     vector<int> searchRange(vector<int>& nums, int target);
// };

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize);