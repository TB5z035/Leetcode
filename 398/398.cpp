#include <iostream>
#include <map>
#include <vector>
using std::map;
using std::vector;

class Solution
{
    map<int, vector<int>> indices;

public:
    Solution(vector<int> &nums)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            if (indices.find(nums[i]) == indices.end())
            {
                vector<int> a = {i};
                indices[nums[i]] = a;
            }
            else
            {
                indices[nums[i]].push_back(i);
            }
        }
    }

    int pick(int target)
    {
        int i = rand() % indices[target].size();
        return indices[target][i];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */

int main()
{
    vector<int> nums = {1, 2, 3, 3, 3, 1, 1, 1, 4, 4, 5};
    Solution *obj = new Solution(nums);
    int param_1 = obj->pick(5);
    std::cout << param_1 << std::endl;
    return 0;
}