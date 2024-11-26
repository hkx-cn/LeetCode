#pragma once 

#include <vector>
#include <cstdlib>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits);
}; 

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize);
