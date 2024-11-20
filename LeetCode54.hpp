#pragma once

#include <vector>
#include <cstdlib>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix);
};

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize);
