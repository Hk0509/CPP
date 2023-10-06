#include <iostream>
#include <algorithm>
using namespace std;

void BubbleSort(int arr[], int n)
{
    // Base case
    if (n == 0 || n == 1)
        return;

    // Send largest element to the last position
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
            swap(arr[i], arr[i + 1]);
    }

    // Recursive call
    BubbleSort(arr, n - 1);
}

int main()
{
    int n = 5;
    int arr[5] = {30, 10, 70, 50, 40};
    BubbleSort(arr, 5);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}