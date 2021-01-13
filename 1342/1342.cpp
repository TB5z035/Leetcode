#include <iostream>
using namespace std;
class Solution
{
public:
    int numberOfSteps(int num)
    {
        if (num == 0)
            return 0;
        int cnt = 0;
        for (; num != 0; num >>= 1)
            cnt += (1 + (num & 1));
        return cnt - 1;
    }
};

int main()
{
    Solution s;
    cout << s.numberOfSteps(123);
    return 0;
}