#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int once = 0, twice = 0;
        for (auto &&i : nums)
        {
            once = ~twice & (once ^ i);
            twice = ~once & (twice ^ i);
        }
        return once;
    }
};
