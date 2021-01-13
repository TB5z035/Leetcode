#include <vector>
using std::vector;

class Solution
{
public:
    bool validSquare(vector<int> &p1, vector<int> &p2, vector<int> &p3, vector<int> &p4)
    {
        if (p1 == p2 || p2 == p3 || p3 == p4 || p1 == p3 || p2 == p4 || p1 == p4)
            return false;
        bool a = p1[0] + p3[0] == p2[0] + p4[0] &&
                 p1[1] + p3[1] == p2[1] + p4[1] &&
                 ((p1[0] - p3[0] == p4[1] - p2[1] &&
                   p1[1] - p3[1] == p2[0] - p4[0]) ||
                  (p1[0] - p3[0] == p2[1] - p4[1] &&
                   p1[1] - p3[1] == p4[0] - p2[0]));
        bool b = p1[0] + p4[0] == p2[0] + p3[0] &&
                 p1[1] + p4[1] == p2[1] + p3[1] &&
                 ((p1[0] - p4[0] == p3[1] - p2[1] &&
                   p1[1] - p4[1] == p2[0] - p3[0]) ||
                  (p1[0] - p4[0] == p2[1] - p3[1] &&
                   p1[1] - p4[1] == p3[0] - p2[0]));
        bool c = p1[0] + p2[0] == p3[0] + p4[0] &&
                 p1[1] + p2[1] == p3[1] + p4[1] &&
                 ((p1[0] - p2[0] == p4[1] - p3[1] &&
                   p1[1] - p2[1] == p3[0] - p4[0]) ||
                  (p1[0] - p2[0] == p3[1] - p4[1] &&
                   p1[1] - p2[1] == p4[0] - p3[0]));

        return a || b || c;
    }
};