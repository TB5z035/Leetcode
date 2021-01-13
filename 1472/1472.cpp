#include <string>
#include <vector>
using std::string;

class BrowserHistory
{
    struct page
    {
        page *prev;
        page *next;
        string name;
        page(string name) : prev(nullptr), next(nullptr), name(name) {}
    };

    page start;
    page *now;

public:
    BrowserHistory(string homepage) : start(homepage)
    {
        now = &start;
    }

    void visit(string url)
    {
        if (now->next)
        {
            page *tmp = now->next;
            page *bak = now->next;
            now->next = nullptr;
            while (tmp)
            {
                bak = tmp;
                tmp = tmp->next;
                delete bak;
            }
        }
        now->next = new page(url);
        now = now->next;
    }

    string back(int steps)
    {
        for (int i = 0; i < steps && now->prev; i++)
            now = now->prev;
    }

    string forward(int steps)
    {
        for (int i = 0; i < steps && now->next; i++)
            now = now->next;
    }
};