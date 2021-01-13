#include <bits/stdc++.h>
using namespace std;

class Solution {
    stack<int>* result(string &input)
    {
        stack<int> *record = new stack<int>;
        for(auto &&i : input)
        {
            if (i == '#' && !record->empty())
            {
                record->pop();
            }
            else
            {
                record->push(i);
            }
        }
        return record;
    }
public:
    bool backspaceCompare(string S, string T) {
        auto* s_ptr = result(S);
        auto* t_ptr = result(T);
        while(true)
        {
            if (s_ptr->empty() && t_ptr->empty())
            {
                delete s_ptr;
                delete t_ptr;
                return true;
            }
            else if (s_ptr->empty() || t_ptr->empty() || s_ptr->top() != t_ptr->top())
            {
                delete s_ptr;
                delete t_ptr;
                return false;
            }
            s_ptr->pop();
            t_ptr->pop();
        }
        return false;
    }
};

int main()
{
    Solution s;
    string s1 = "y#fo##f";
    string s2 = "y#f#o##f";
    cout << (s.backspaceCompare(s1, s2) ? "true" : "false") << endl;
    
    return 0;
}
