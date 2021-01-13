#include <iostream>

class Solution
{
public:
    bool checkPerfectNumber(int num)
    {
        int sum = 0;
        for (int i = 1; i * i < num; i++)
            if (i * i == num)
                sum += i;
            else if (num % i == 0)
                sum += i + num / i;
        sum -= num;
        return sum == num;
    }
};

int main()
{
    Solution s;
    std::cout
        << ((s.checkPerfectNumber(28))
                ? "true"
                : "false")
        << std::endl;

    return 0;
}