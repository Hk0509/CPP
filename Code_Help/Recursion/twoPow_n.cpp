#include <iostream>
using namespace std;

int two_pow(int n)
{
    if (n == 0)
        return 1;

    return 2 * two_pow(n - 1);
}

int main()
{
    int n;
    cin >> n;
    cout << two_pow(n) << endl;
}