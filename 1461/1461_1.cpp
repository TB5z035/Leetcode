#include <iostream>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    bool hasAllCodes(string s, int k)
    {
        unsigned int window = 0;
        unsigned int mask = (1 << k) - 1;
        unordered_set<int> records;

        for (int i = 0; i < s.size(); i++)
        {
            window <<= 1;
            if (s[i] == '1')
                window += 1;
            if (i >= k - 1)
                records.insert(window & mask);
        }

        for (int i = 0; i < (1 << k); i++)
            if (records.find(i) == records.end())
                return false;
        return true;
    }
};

int main()
{
    Solution s;
    cout << s.hasAllCodes("0110", 2) << endl;
    return 0;
}