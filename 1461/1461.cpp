#include <iostream>
#include <unordered_set>
using namespace std;
class Solution
{
public:
    string transform(int n, int k)
    {
        string ret;
        for (int i = k - 1; i >= 0; i--)
            ret.append((n & (1 << i)) ? "1" : "0");

        return ret;
    }

    bool hasAllCodes(string s, int k)
    {
        if (k > s.size())
            return false;
        unordered_set<string> records;
        for (int i = 0; i < s.size() - k + 1; i++)
            records.insert(s.substr(i, k));

        for (int i = 0; i < (1 << k); i++)
        {
            string s = transform(i, k);
            if (records.find(transform(i, k)) == records.end())
                return false;
        }
        return true;
    }
};

int main()
{
    Solution s;
    cout << s.hasAllCodes("00110", 2) << endl;
    return 0;
}