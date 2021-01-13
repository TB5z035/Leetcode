#include <iostream>
#include <vector>
using std::vector;

class Solution
{
public:
    int numSubarraysWithSum(vector<int> &A, int S)
    {
        if (S == 0)
        {
            auto iter = A.begin();
            int stat = 0;
            while (iter != A.end())
            {
                int cnt = 0;
                while (iter != A.end() && *iter != 0)
                {
                    iter++;
                }
                while (iter != A.end() && *iter != 1)
                {
                    iter++;
                    cnt++;
                }
                stat += cnt * (cnt + 1) / 2;
            }
            return stat;
        }
        int sum = 0, space = 0, cnt = 0;
        vector<int> spaces;
        auto iter = A.begin();
        while (true)
        {
            while (iter != A.end() && *iter != 1)
            {
                space++;
                iter++;
            }
            spaces.push_back(space);
            space = 0;
            if (iter == A.end())
                break;
            sum += *iter;
            iter++;
        }
        for (int i = 0; i + S < spaces.size(); i++)
            cnt += (spaces[i] + 1) * (spaces[i + S] + 1);
        return cnt;
    }
};

int main()
{
    Solution s;
    vector<int> a = {0, 0, 0, 0, 0};
    int res = s.numSubarraysWithSum(a, 0);
    std::cout << res;
}