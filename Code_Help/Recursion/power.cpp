#include <iostream>
using namespace std;

int power(int a, int b)
{
    // Base case
    if (b == 0)
        return 1;

    if (b == 1)
        return a;

    // Recursive call
    int ans = power(a, b / 2);

    if (b & 1)
        return a * ans * ans;

    else
        return ans * ans;
}

int main()
{
    int a = 2;
    int b = 10;

    cout << power(a, b) << endl;
}