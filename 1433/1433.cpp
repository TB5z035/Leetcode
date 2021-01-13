#include <algorithm>
#include <string>
using std::sort;
using std::string;
class Solution
{
public:
    bool checkIfCanBreak(string s1, string s2)
    {
        int len = s1.length(), mode = 0;
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        for (int i = 0; i < len; i++)
        {
            if ((s1[i] < s2[i] && mode == -1) ||
                s1[i] > s2[i] && mode == 1)
                return false;
            else if (mode == 0)
                if (s1[i] < s2[i])
                    mode = 1;
                else if (s1[i] > s2[i])
                    mode = -1;
        }
        return true;
    }
};