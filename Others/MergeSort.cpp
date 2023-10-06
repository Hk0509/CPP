#include <iostream>
using namespace std;

void merge(int *arr, int s, int e)
{
    int m = s + (e - s) / 2;
    int len1 = m - s + 1;
    int len2 = e - m;

    int *left = new int[len1];
    int *right = new int[len2];

    int k = s;

    // Arrays
    for (int i = 0; i < len1; i++)
    {
        left[i] = arr[k++];
    }

    for (int i = 0; i < len2; i++)
    {
        right[i] = arr[k++];
    }

    // Merge
    k = s;
    int index1 = 0;
    int index2 = 0;
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

    delete []left;
    delete []right;
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
    int arr[5] = {30, 10, 20, 50, 40};
    int size = 5;

    mergeSort(arr, 0, size - 1);

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}