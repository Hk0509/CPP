#include <iostream>
using namespace std;

void insertionSort(int *arr, int s, int n)
{
    if (s == n)
        return;

    int temp = arr[s];
    int i = s - 1;
    for (; i >= 0; i--)
    {
        if (temp < arr[i])
        {
            arr[i + 1] = arr[i];
        }
        else
            break;
    }
    arr[i + 1] = temp;

    insertionSort(arr, s + 1, n);
}

int main()
{
    int n = 5;
    int arr[5] = {30, 10, 40, 35, 32};

    insertionSort(arr, 1, n);

    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
}