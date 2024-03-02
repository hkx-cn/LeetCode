#include "LeetCode670.hpp"
int Solution::maximumSwap(int num)
{
    std::vector<size_t> idx;
    std::vector<size_t> sorted;
    size_t max = 0, temp = num;
    while (temp >= 10)
    {
        idx.push_back(temp % 10);
        temp /= 10;
    }
    idx.push_back(temp);
    sorted = idx;
    sort(sorted.begin(), sorted.end());
    for (size_t i = idx.size() - 1; i > 0; i--)
    {
        if (idx[i] != sorted[i])
        {
            for (size_t j = 0; j < idx.size(); j++)
            {
                if (idx[j] == sorted[i])
                {
                    max = j;
                    break;
                }
            }
            temp = idx[max] - idx[i];
            for (size_t j = 0; j < max; j++)
            {
                temp *= 10;
            }
            num -= temp;
            temp = idx[max] - idx[i];
            for (size_t j = 0; j < i; j++)
            {
                temp *= 10;
            }
            num += temp;
            break;
        }
    }
    return num;
}