#pragma once

#include <vector>
#include <cstdlib>
using namespace std;

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n);
};

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* shuffle(int* nums, int numsSize, int n, int* returnSize);
