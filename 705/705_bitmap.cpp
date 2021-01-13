#include <cstring>
class MyBitset
{
    int width;
    unsigned int *container;

public:
    MyBitset(int size) : width(size), container(new unsigned int[(size >> 5) + 1]) {
        memset(container, 0, ((size >> 5) + 1) * sizeof(unsigned int));
    }
    void set(int key)
    {
        container[key >> 5] |= (1 << (31 - (key & 31)));
    }
    void clear(int key)
    {
        container[key >> 5] &= ~(1 << (31 - (key & 31)));
    }
    bool get(int key)
    {
        return container[key >> 5] & (1 << (31 - (key & 31)));
    }
};

class MyHashSet
{
    MyBitset *records;

public:
    /** Initialize your data structure here. */
    MyHashSet() : records(new MyBitset(1048576))
    {
    }

    void add(int key)
    {
        records->set(key);
    }

    void remove(int key)
    {
        records->clear(key);
    }

    /** Returns true if this set contains the specified element */
    bool contains(int key)
    {
        return records->get(key);
    }
};