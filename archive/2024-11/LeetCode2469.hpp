#pragma once

#include <vector>
#include <cstdlib>
using namespace std;

class Solution {
public:
    vector<double> convertTemperature(double celsius);
};

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
double* convertTemperature(double celsius, int* returnSize);
