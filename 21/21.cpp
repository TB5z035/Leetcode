
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode start;
        ListNode *now = &start;
        while (l1 || l2)
        {
            if (l1 && (!l2 || l1->val <= l2->val))
            {
                now->next = new ListNode(l1->val);
                l1 = l1->next;
                now = now->next;
            }
            else if (l2 && (!l1 || l2->val < l1->val))
            {
                now->next = new ListNode(l2->val);
                l2 = l2->next;
                now = now->next;
            }
            else
            {
                std::cout << "not possible";
            }
        }
        return start.next;
    }
};