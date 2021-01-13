
#include <cstring>
#include <iostream>
using namespace std;

class bitset
{
    int width;
    unsigned int *container;

public:
    bitset(int size) : width(size), container(new unsigned int[(size >> 5) + 1]) {}
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
    char *marks;
    int *bucket;
    int size;
    int capacity;
    void atomicAdd(int key, char *m, int *b, int capa, int *size)
    {
        for (int i = 0; i < (capa + 1) / 2; i++)
        {
            if (m[validIndex(key + i * i, capa)] == 0)
            {
                m[validIndex(key + i * i, capa)] = 1;
                b[validIndex(key + i * i, capa)] = key;
                break;
            }
            else if (m[validIndex(key - i * i, capa)] == 0)
            {
                m[validIndex(key - i * i, capa)] = 1;
                b[validIndex(key - i * i, capa)] = key;
                break;
            }
        }
        *size += 1;
    }
    inline int validIndex(int key, int capa)
    {
        return (capa + (key) % capa) % capa;
    }

public:
    /** Initialize your data structure here. */
    MyHashSet()
    {
        capacity = 103;
        size = 0;
        bucket = new int[capacity];
        marks = new char[capacity];
        memset(marks, 0, capacity * sizeof(char));
    }

    void add(int key)
    {
        if (contains(key))
            return;
        if (3 * size > 2 * capacity)
        {
            int newCapa = 2 * capacity - 3;
            int *newBucket = new int[newCapa];
            char *newMarks = new char[newCapa];
            memset(newMarks, 0, newCapa * sizeof(char));
            int newSize = 0;
            for (int i = 0; i < capacity; i++)
            {
                if (marks[i] == 1)
                {
                    atomicAdd(bucket[i], newMarks, newBucket, newCapa, &newSize);
                }
            }
            delete[] bucket;
            delete[] marks;
            marks = newMarks;
            bucket = newBucket;
            capacity = newCapa;
            size = newSize;
        }
        atomicAdd(key, marks, bucket, capacity, &size);
    }

    void remove(int key)
    {
        for (int i = 0; i < (capacity + 1) / 2; i++)
        {
            if (marks[validIndex(key + i * i, capacity)] == 1 && bucket[validIndex(key + i * i, capacity)] == key)
            {
                marks[validIndex(key + i * i, capacity)] = 0;
                break;
            }
            else if (marks[validIndex(key - i * i, capacity)] == 1 && bucket[validIndex(key - i * i, capacity)] == key)
            {
                marks[validIndex(key - i * i, capacity)] = 0;
                break;
            }
        }
        size--;
    }

    /** Returns true if this set contains the specified element */
    bool contains(int key)
    {
        for (int i = 0; i < (capacity + 1) / 2; i++)
        {
            if (marks[validIndex(key + i * i, capacity)] == 1 && bucket[validIndex(key + i * i, capacity)] == key)
            {
                return true;
            }
            else if (marks[validIndex(key - i * i, capacity)] == 1 && bucket[validIndex(key - i * i, capacity)] == key)
            {
                return true;
            }
        }
        return false;
    }
    ~MyHashSet()
    {
        delete[] bucket;
        delete[] marks;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */

int main()
{
    MyHashSet *obj = new MyHashSet();
    obj->add(1);
    obj->add(2);
    cout << obj->contains(1) << endl;
    cout << obj->contains(3) << endl;
    obj->add(2);
    cout << obj->contains(2) << endl;
    obj->remove(2);
    cout << obj->contains(2) << endl;

    return 0;
}