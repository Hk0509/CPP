#include <iostream>
using namespace std;

void SayNumbers(int n, string arr[])
{

    // Base case
    if (n == 0)
        return;

    // Processing
    int digit = n % 10;
    n = n / 10;
    cout << arr[digit] << " ";

    // Recursive call
    SayNumbers(n, arr);
}

int main()
{
    int n;
    cin >> n;

    string arr[10] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};

    SayNumbers(n, arr);
}