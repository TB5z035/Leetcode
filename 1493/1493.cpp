#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int longestSubarray(vector<int> &nums)
    {
        int seg0 = 0;
        int seg1 = 0;
        int max = 0;
        bool zero = false;
        bool one = true;

        auto iter = nums.begin();
        while (iter != nums.end())
        {
            if ((iter + 1) != nums.end() && *iter == 0 && *(iter + 1) == 0)
            {
                max = (seg0 + seg1) > max ? (seg0 + seg1) : max;
                seg0 = 0;
                seg1 = 0;
                zero = false;
                one = false;
                while (iter != nums.end() && *iter != 1)
                    iter++;
            }
            else if (*iter == 0)
            {
                if (zero)
                {
                    max = (seg0 + seg1) > max ? (seg0 + seg1) : max;
                    seg0 = seg1;
                    seg1 = 0;
                }
                zero = true;
                iter++;
                one = false;
            }
            else
            {
                if (!zero)
                    seg0++;
                else
                    seg1++;
                iter++;
            }
        }
        max = (seg0 + seg1) > max ? (seg0 + seg1) : max;
        return one ? nums.size() - 1 : max;
    }
};

int main()
{
    Solution s;
    vector<int> v = {0, 1, 1, 1, 0, 1, 1, 0, 1};
    cout << s.longestSubarray(v);
    return 0;
}