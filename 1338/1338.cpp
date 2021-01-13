#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

bool cmp(int i, int j) { return i > j; }

class Solution
{
public:
    int minSetSize(vector<int> &arr)
    {
        unordered_map<int, int> records;
        for (auto &&i : arr)
            records[i]++;

        vector<int> stats;
        for (auto &&i : records)
            stats.push_back(i.second);

        sort(stats.begin(), stats.end(), cmp);

        int num = 0;w
        int sum = 0;
        for (auto &&i : stats)
        {
            num += 1;
            sum += i;
            if (2 * sum >= arr.size())
                break;
        }
        return num;
    }
};

int main()
{
    Solution s;
    vector<int> a = {1, 1, 1, 1, 2, 2, 3, 3};
    cout << s.minSetSize(a) << endl;

    return 0;
}