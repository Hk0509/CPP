#include <iostream>
using namespace std;

int setbit(int a, int b)
{
    int count = 0;
    while (a > 0)
    {
        if (a & 1 == 1)
            count++;
        if (b & 1 == 1)
            count++;
        a = a >> 1;
        b = b >> 1;
    }
    return count;
}

int main()
{
    int a, b;
    cin >> a >> b;
    cout << setbit(a, b) << endl;
}