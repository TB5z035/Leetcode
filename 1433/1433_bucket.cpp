#include <algorithm>
#include <string>
using std::sort;
using std::string;
class Solution
{
public:
    bool checkIfCanBreak(string s1, string s2)
    {
        short count[26] = {0};
        for (auto &&i : s1)
            count[i - 'a']++;
        for (auto &&i : s2)
            count[i - 'a']--;

        int sum = 0;
        bool left = false, right = false;
        for (int i = 26 - 1; i >= 0; i--)
        {
            sum += count[i];
            if (!left && !right && sum > 0)
                left = true;
            else if (!left && !right && sum < 0)
                right = true;
            else if (left && sum < 0)
                return false;
            else if (right && sum > 0)
                return false;
        }
        return true;
    }
};