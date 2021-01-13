#include <iostream>
#include <map>
#include <set>
using namespace std;

class StreamRank
{
    map<int, int> records;

public:
    StreamRank()
    {
    }

    void track(int x)
    {
        records[x]++;
    }

    int getRankOfNumber(int x)
    {
        int sum = 0;

        auto iter = records.begin();
        // auto fin = records.upper_bound(x);
        for (; iter != records.end(); iter++)
        {
            if (iter->first > x)
                break;
            sum += iter->second;
        }

        return sum;
    }
};

int main()
{
    StreamRank s;
    s.track(4);
    s.track(3);
    s.track(5);
    cout << s.getRankOfNumber(8) << endl;
    s.track(3);
    cout << s.getRankOfNumber(2) << endl;
    return 0;
}