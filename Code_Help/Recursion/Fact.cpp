#include <iostream>
using namespace std;

int facto(int n)
{
    // base case
    if (n == 0)
        return 1;

    // recursive condition
    return n * facto(n - 1);
}

int main()
{
    cout << facto(5) << endl;
}