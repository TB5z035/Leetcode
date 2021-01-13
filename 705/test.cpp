#include <iostream>
using namespace std;

int main()
{
    int a = 2001;
    int b = 3;
    cout << (b + (a % b)) % b << endl;

    return 0;
}