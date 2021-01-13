#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string decodeString(string s)
    {
        stack<int> repeat;
        stack<string> before;
        string now;
        int times = 0;
        // string inside;
        for (auto &&i : s)
        {
            if ('0' <= i && i <= '9')
            {
                times = 10 * times + (i - '0');
            }
            else if (i == '[')
            {
                repeat.push(times);
                before.push(now);
                times = 0;
                now.clear();
            }
            else if ('a' <= i && i <= 'z')
            {
                now += i;
            }
            else if (i == ']')
            {
                string tmp;
                for (int i = 0; i < repeat.top(); i++)
                    tmp += now;
                now = before.top() + tmp;
                repeat.pop();
                before.pop();
            }
        }
        return now;
    }
};

int main()
{
    Solution s;
    cout << s.decodeString("100[leetcode]") << endl;
    return 0;
}
