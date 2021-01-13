#include <iostream>
#include <unordered_set>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *nowA = headA;
        ListNode *nowB = headB;
        bool flagA = true;
        bool flagB = true;
        while (nowA && nowB)
        {
            if (nowA == nowB)
                return nowA;
            if (!flagA || nowA->next)
                nowA = nowA->next;
            else
            {
                flagA = false;
                nowA = headB;
            }
            if (!flagB || nowB->next)
                nowB = nowB->next;
            else
            {
                flagB = false;
                nowB = headA;
            }
        }

        return nullptr;
    }
};