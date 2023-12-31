#include <iostream>
using namespace std;

int fibo(int n)
{
    // Base Case
    if (n == 0)
        return 0;

    if (n == 1)
        return 1;

    // RC
    return fibo(n - 1) + fibo(n - 2);
}

int main()
{
    int n;
    cin >> n;
    cout << fibo(n) << endl;
}