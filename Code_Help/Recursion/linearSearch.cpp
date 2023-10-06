#include <iostream>
using namespace std;

bool linearSearch(int *arr, int size, int key)
{
    if (size == 0)
        return false;

    if (arr[0] == key)
        return true;

    return linearSearch(arr + 1, size - 1, key);
}

int main()
{
    int size = 5;
    int arr[5] = {10, 20, 30, 40, 50};
    int key = 5;

    bool ans = linearSearch(arr, size, key);

    if (ans)
        cout << "Found" << endl;
    else
        cout << "Not Found" << endl;
}