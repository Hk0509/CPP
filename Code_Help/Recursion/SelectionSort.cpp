#include <iostream>
using namespace std;

void SelectionSort(int *arr, int s, int n)
{
    if (s == n)
        return;

    int smallestIndex = s;

    for (int i = s + 1; i < n; i++)
    {
        if (arr[smallestIndex] > arr[i])
            smallestIndex = i;
    }

    swap(arr[smallestIndex], arr[s]);

    SelectionSort(arr, s + 1, n);
}

int main()
{
    int n = 6;
    int arr[6] = {30, 10, 50, 30, 40, 80};

    SelectionSort(arr, 0, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}