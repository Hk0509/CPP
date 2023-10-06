#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    int x = 123;
    int y = x;
    int temp = 0;
    int ans = 0;
    int count = 0;
    while (y > 10)
    {
        y = y / 10;
        count++;
    }
    while (x > 0)
    {
        temp = x % 10;
        ans = ans + temp * pow(10, count);
        x = x / 10;
        count--;
        cout << count << " " << x << " " << temp << endl;
    }
    cout << ans << endl;
}