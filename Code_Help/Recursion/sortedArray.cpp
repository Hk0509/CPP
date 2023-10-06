#include <iostream>
using namespace std;

bool isSorted(int arr[], int size)
{
    // Base Case
    if (size == 0 || size == 1)
        return true;

    if (arr[0] > arr[1])
        return false;

    else
    {
        bool remainingPart = isSorted(arr + 1, size - 1);
        return remainingPart;
    }
}

int main()
{
    int size = 5;
    int arr[5] = {10, 20, 80, 40, 50};

    bool ans = isSorted(arr, size);

    if (ans)
        cout << "Array is sorted." << endl;
    else
        cout << "Array is not sorted." << endl;
}