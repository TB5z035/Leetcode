#include <algorithm>
#include <iostream>
#include <list>
#include <map>
using namespace std;

class LRUCache
{
    int capacity;
    map<int, int> content;
    list<int> keys;

public:
    LRUCache(int capacity) : capacity(capacity)
    {
    }

    int get(int key)
    {
        auto iter = find(keys.begin(), keys.end(), key);
        if (iter == keys.end())
        {
            return -1;
        }
        else
        {
            int tmp = *iter;
            keys.erase(iter);
            keys.emplace_front(tmp);
            return content[key];
        }
    }

    void put(int key, int value)
    {
        content[key] = value;
        auto iter = find(keys.begin(), keys.end(), key);
        if (iter == keys.end())
        {
            if (keys.size() == capacity)
            {
                auto end = keys.end();
                end--;
                keys.erase(end);
            }
            keys.emplace_front(key);
        }
        else
        {
            int tmp = *iter;
            keys.erase(iter);
            keys.emplace_front(tmp);
        }
    }
};

int main()
{

    LRUCache cache(3);
    cache.put(1, 1);
    cache.put(3, 3);
    cache.put(5, 5);

    cout << cache.get(1) << endl;
    cout << cache.get(5) << endl;
    cache.put(2, 2);
    cout << cache.get(1) << endl;
    cout << cache.get(3) << endl;
    cout << cache.get(5) << endl;
    return 0;
}