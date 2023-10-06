#include <iostream>
using namespace std;

int main()
{

    uint32_t c;
    cin >> c;

    int count = 0;

    while (c > 0)
    {
        if (c % 10 == 1)
        {
            count++;
        }
        c = c / 10;
    }

    cout << count << endl;
    return 0;
}