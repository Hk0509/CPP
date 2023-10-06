#include <iostream>
#include <map>
using namespace std;
int main()
{
    int arr[] = {1, 2, 2, 1, 1, 3};
    int size = 6;
    map<int, int> mpp;
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n; i++)
    {
        mpp[arr[i]]++;
    }
    for (auto i : mpp)
    {
        int count = 0;
        for (auto j : mpp)
        {
            if (i.second == j.second)
                count++;
            if (count > 1)
                cout << 0;
        }
    }
    cout << 1;
}