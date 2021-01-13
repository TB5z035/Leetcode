#include <bits/stdc++.h>
// #include <iostream>
// #include <vector>
// #include <set>
// #include <algorithm>
using namespace std;
class Solution
{
public:
    string smallestStringWithSwaps(string s, vector<vector<int>> &pairs)
    {
        vector<set<int>> records;
        unordered_set<int> total;

        map<int, unordered_set<int>> next;
        for (auto &&pair : pairs)
        {
            next[pair.at(0)].insert(pair.at(1));
            next[pair.at(1)].insert(pair.at(0));
        }
        for (int i = 0; i < s.size(); i++)
        {
            if (total.find(i) != total.end())
                continue;
        
            records.push_back(set<int>{});
            auto &toadd = records.back();
            queue<int> todo;
            todo.push(i);
            while (!todo.empty())
            {
                toadd.insert(todo.front());
                total.insert(todo.front());
                for (auto &&j : next[todo.front()])
                    if (toadd.find(j) == toadd.end())
                        todo.push(j);
                todo.pop();
            }
            
        }

        for (auto &&part : records)
        {
            string temp;
            for (auto &&i : part)
            {
                temp += s[i];
            }
            sort(temp.begin(), temp.end());
            auto it = part.begin();
            for (int i = 0; i < temp.size(); i++, it++)
            {
                s[*it] = temp[i];
            }
        }
        return s;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> a = {{2, 4}, {5, 7}, {1, 0}, {0, 0}, {4, 7}, {0, 3}, {4, 1}, {1, 3}};
    cout << s.smallestStringWithSwaps(string("fqtvkfkt"), a) << endl;
    return 0;
}