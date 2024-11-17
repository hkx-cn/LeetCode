#pragma once
#include <vector>
#include <string>
#include <cstring>

using namespace std;
class Solution {
public:
    int vowelStrings(vector<string>& words, int left, int right);
};

int vowelStrings(char** words, int wordsSize, int left, int right);
