#pragma once
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target);
};

bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target);
