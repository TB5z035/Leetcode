#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        auto iter1 = nums.begin();
        auto iter2 = nums.begin();
        while (true)
        {
            while (iter2 != nums.end() && *iter2 == 0)
                iter2++;
            if (iter2 == nums.end())
                break;
            *iter1 = *iter2;
            iter1++;
            iter2++;
        }
        while (iter1 != nums.end())
        {
            *iter1 = 0;
            iter1++;
        }
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
