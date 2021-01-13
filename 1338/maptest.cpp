#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;
//the first call to operator[] initialized the value with zero
int main()
{
    map<int, int> map1;
    map1[2]++;
    cout << map1[2] << endl;
    return 0;
}