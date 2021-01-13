// #include <bits/stdc++.h>
#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    vector<int> singleNumber(vector<int> &nums)
    {
        long long mask = 0;
        for (auto &&i : nums)
            mask ^= i;
        long long diff = mask & (-mask);
        long long mask2 = 0;
    
        for (auto &&i : nums)
            if ((i & diff) != 0)
                mask2 ^= i;
        return vector<int>{int(mask2), int(mask ^ mask2)};
    }
};

int main()
{
    vector<int> input = {1, 2, 1, 3, 2, 5};
    Solution s;
    auto output = s.singleNumber(input);
    for (auto &&i : output)
    {
        cout << i << endl;
    }
    

    return 0;
}