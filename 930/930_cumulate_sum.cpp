#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int numSubarraysWithSum(vector<int> &A, int S)
    {
        vector<int> sum;
        sum.push_back(0);
        for (auto &&i : A)
            sum.push_back(sum.back() + i);

        int cnt = 0;
        int *stat = new int[sum.back() + S + 1];
        for (int i = 0; i < sum.back() + S + 1; i++)
            stat[i] = 0;

        for (auto &&i : sum)
        {
            cnt += stat[i];
            stat[i + S]++;
        }

        delete[] stat;
        return cnt;
    }
};

int main()
{
    Solution s;
    vector<int> a = {1, 0, 1, 0, 1};
    int S = 2;
    cout << s.numSubarraysWithSum(a, S) << endl;
    return 0;
}