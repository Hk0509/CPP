#include <iostream>
using namespace std;

int sumOfArray(int *arr, int size)
{
    // Base case
    if (size == 0)
        return 0;

    if (size == 1)
        return arr[0];

    // Processing
    int remainingPart = sumOfArray(arr + 1, size - 1);
    int sum = arr[0] + remainingPart;

    return sum;
}

int main()
{
    int size = 5;
    int arr[5] = {2, 4, 9, 9, 9};

    int ans = sumOfArray(arr, size);
    cout << ans << endl;
}