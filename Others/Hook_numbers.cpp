#include <iostream>
using namespace std;

int sumOfDigits(int n)
{
    int sum = 0;
    while (n > 0)
    {
        int dig = n % 10;
        sum += dig;
        n = n / 10;
    }
    return sum;
}

int factors(int n)
{
    int factor = 2;
    int sum = 0;

    while (n > 1)
    {
        if (n % factor == 0)
        {
            sum += sumOfDigits(factor);
            n = n / factor;
        }
        else
        {
            factor++;
        }
    }
    return sum;
}

bool isComposite(int n)
{
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            return true;
            break;
        }
    }
    return false;
}

int main()
{
    int n;
    cin >> n;

    for (int i = 4; i < n; i++)
    {
        if ((sumOfDigits(i) == factors(i)) && isComposite(i))
            cout << i << " ";
    }
}