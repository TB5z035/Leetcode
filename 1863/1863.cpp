#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
using std::string;
using std::vector;

class Solution
{
    using sset = std::unordered_set<std::string>;
    sset insert(sset &now)
    {
        sset ret;
        for (auto &&i : now)
            for (int j = 0; j < i.size() + 1; j++)
                ret.insert(i.substr(0, j) + "()" + i.substr(j));
        return ret;
    }

public:
    vector<string> generateParenthesis(int n)
    {
        sset current = sset({"()"});
        for (int i = 0; i < n - 1; i++)
            current = insert(current);
        vector<string> ret;
        for (auto &&i : current)
            ret.push_back(i);
        return ret;
    }
};

int main()
{
    Solution s;
    vector<string> ret = s.generateParenthesis(3);
    for (auto &&i : ret)
    {
        std::cout << i << std::endl;
    }

    return 0;
}