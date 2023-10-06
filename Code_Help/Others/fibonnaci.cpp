#include <iostream>
using namespace std;

int fibo(int n)
{
    int fib = 0;
    int x = 1;
    for (int i = 0; i < n; i++)
    {
        fib = fib + x;
        x = fib - x;
    }
    return fib;
}

int main()
{
    int n;
    cin >> n;
    cout << fibo(n);
}