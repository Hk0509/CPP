#include <iostream>
using namespace std;

bool binarySearch(int *arr, int s, int e, int key)
{
    // Initialization
    int m = s + (e - s) / 2;

    // Base Condition
    if (s > e)
        return false;

    // Processing
    if (arr[m] == key)
        return true;

    // Recursive condition
    if (arr[m] < key)
        return binarySearch(arr, m + 1, e, key);

    if (arr[m] > key)
        return binarySearch(arr, s, m - 1, key);
}

int main()
{
    int arr[] = {10, 20, 30, 40, 50};
    int size = 5;
    int key = 25;
    int s = 0;
    int e = size - 1;

    bool ans = binarySearch(arr, s, e, key);

    if (ans)
        cout << "Found" << endl;
    else
        cout << "Not Found" << endl;
}