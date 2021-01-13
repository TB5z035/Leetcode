#include <iostream>
using namespace std;
class Solution
{

    long long width(long long index)
    {
        long long ret = 1;
        for (long long i = 0; i < index - 1; i++)
        {
            ret *= 10;
        }

        return ret * 9 * index;
    }

public:
    long long findNthDigit(long long n)
    {
        if (n == 0)
            return 0;
        long long widthSum = 1;
        long long order = 0;
        while (n >= widthSum)
        {
            order++;
            widthSum += width(order);
        }
        widthSum -= width(order);
        order--;

        long long div = (n - widthSum) / (order + 1);
        long long rem = (n - widthSum) % (order + 1);

        long long base = 1;
        for (long long i = 0; i < order; i++)
        {
            base *= 10;
        }
        long long res = base + div;

        long long index = order - rem;
        for (long long i = 0; i < index; i++)
        {
            res /= 10;
        }
        return res % 10;
    }
};

int main()
{
    long long i;
    cin >> i;
    Solution s;
    cout << s.findNthDigit(i);
    return 0;
}