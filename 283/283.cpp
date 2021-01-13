#include <bits/stdc++.h>
using namespace std;

bool cmp(int a, int b)
{
    return b==0;
}

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        stable_sort(nums.begin(), nums.end(), cmp);
    }
};

int main()
{
    vector<int> test = {1, 0, 2, 4, 5, 7, 6};
    Solution s;
    s.moveZeroes(test);
    for (auto &&i : test)
    {
        cout << i << " " << endl;
    }
    
    return 0;
}
