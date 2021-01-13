#include <iostream>
#include <map>
#include <vector>
using std::map;
using std::vector;

class Solution
{
    vector<int> nums;

public:
    Solution(vector<int> &nums) : nums(nums) {}

    int pick(int target)
    {
        int cnt = 0;
        int index = -1;
        for (int i = 0; i < nums.size(); i++)
            if (nums[i] == target)
            {
                cnt++;
                if (rand() % cnt == 0)
                    index = i; // 1/i prob
            }

        return index;
    }
};