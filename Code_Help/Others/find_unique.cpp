#include <iostream>
using namespace std;
int main()
{
    int ans = 0;
    int arr[] = {10, 20, 20, 10, 3, 2, 3};
    int size = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < size; i++)
    {
        ans = ans ^ arr[i];
        cout << i << " " << ans << endl;
    }
    cout << "Ans = " << ans << endl;
}