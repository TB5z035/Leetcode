#include <bits/stdc++.h>
using namespace std;

class Solution
{
    string result(string &input)
    {
        int cnt = 0;
        string ret;
        for (auto &&i = input.rbegin(); i != input.rend(); i++)
        {
            if (*i == '#')
                cnt++;
            else if (cnt > 0)
                cnt--;
            else
                ret += *i;
        }
        return ret;
    }

public:
    bool backspaceCompare(string S, string T)
    {
        return result(S) == result(T);
    }
};

int main()
{
    Solution s;
    string s1 = "y#fo##f";
    string s2 = "y#f#o##f";
    cout << (s.backspaceCompare(s1, s2) ? "true" : "false") << endl;

    return 0;
}
