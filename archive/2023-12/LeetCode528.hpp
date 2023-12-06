#pragma once
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;
class Solution
{
private:
    vector<int> arr;
    int sum = 0;

public:
    Solution(vector<int> &w)
    {
        for (size_t i = 0; i < w.size(); i++)
        {
            sum += w[i];
            arr.push_back(sum);
        }
        srand(time(0));
    };
    int pickIndex();
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */