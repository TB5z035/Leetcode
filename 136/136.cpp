#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int mask = 0;
        for (auto &&i : nums)
            mask ^= i;
        return mask;
    }
};