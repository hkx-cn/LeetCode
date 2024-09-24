#pragma once

#include <vector>
using namespace std;

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid);
};

int countNegatives(int** grid, int gridSize, int* gridColSize);
