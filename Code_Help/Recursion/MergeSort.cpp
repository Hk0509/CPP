#include <iostream>
using namespace std;

void merge(int *arr, int s, int e)
{
    int m = s + (e - s) / 2;
    int len1 = m - s + 1;
    int len2 = e - m;
    int *left = new int[len1];
    int *right = new int[len2];

    // k = Main Array Index;
    int k = s;

    // Creating half arrays
    for (int i = 0; i < len1; i++)
    {
        left[i] = arr[k];
        k++;
    }

    k = m + 1;
    for (int i = 0; i < len2; i++)
    {
        right[i] = arr[k];
        k++;
    }

    // Merge 2 Sorted Arrays
    int index1 = 0;
    int index2 = 0;
    k = s;

    while (index1 < len1 && index2 < len2)
    {
        if (left[index1] < right[index2])
            arr[k++] = left[index1++];

        else
            arr[k++] = right[index2++];
    }

    while (index1 < len1)
    {
        arr[k++] = left[index1++];
    }

    while (index2 < len2)
    {
        arr[k++] = right[index2++];
    }
}

void mergeSort(int *arr, int s, int e)
{
    // Base case
    if (s >= e)
        return;

    int m = s + (e - s) / 2;

    mergeSort(arr, s, m);

    mergeSort(arr, m + 1, e);

    merge(arr, s, e);
}

int main()
{
    int n = 5;
    int arr[5] = {20, 10, 40, 30, 45};

    mergeSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}