#include <iostream>
using namespace std;

int binary_search(int arr[], int n, int key)
{
    int s = 0;
    int e = n - 1;
    while (s <= e)
    {
        int m = s + (e - s) / 2;
        if (arr[m] == key)
        {
            return m;
            break;
        }
        else if (arr[m] < key)
        {
            s = m + 1;
        }
        else
            e = m - 1;
    }
    return -1;
}

int main()
{
    int arr[7] = {1, 3, 5, 6, 7, 10, 13};
    cout << binary_search(arr, 7, 10);
}