#include <iostream>
#include <vector>
using namespace std;

class Solution
{
    int find(vector<int> &nums, int start, int end)
    {
        int mid = (start + end) / 2;
        if ((mid == 0 || nums[mid] != nums[mid - 1]) && (mid == nums.size() - 1 || nums[mid] != nums[mid + 1]))
            return mid;
        else if (end - start == 1)
            return -1;
        else
        {
            int tmp;

            tmp = find(nums, start, mid);
            if (tmp != -1)
                return tmp;
            tmp = find(nums, mid, end);
            if (tmp != -1)
                return tmp;
            return -1;
        }
    }

    int find2(vector<int> &nums, int start, int end)
    {
        int mid = (start + end) >> 1;
        if (start + 1 == end)
            return start;
        else if (mid < nums.size() - 1 && nums[mid] == nums[mid + 1])
        {
            if (mid % 2)
                return find2(nums, 0, mid);
            else
                return find2(nums, mid + 2, end);
        }
        else if (mid > 0 && nums[mid] == nums[mid - 1])
        {
            if ((mid - 1) % 2)
                return find2(nums, 0, mid - 1);
            else
                return find2(nums, mid + 1, end);
        }
        else
            return mid;
    }

public:
    int singleNonDuplicate(vector<int> &nums)
    {
        return nums[find2(nums, 0, nums.size())];
    }
};

int main()
{
    vector<int> a = {3, 3, 7, 7, 10, 11, 11};
    Solution s;
    cout << s.singleNonDuplicate(a);
    return 0;
}