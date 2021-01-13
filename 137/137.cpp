#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        unordered_set<int> once;
        unordered_set<int> more;
        for (auto &&i : nums)
        {
            bool found1 = once.find(i) != once.end();
            bool found2 = more.find(i) != more.end();
            if (!found2)
            {
                if (!found1)
                    once.insert(i);
                else
                {
                    once.erase(i);
                    more.insert(i);
                }
            }
        }
        return *once.begin();
    }
};
