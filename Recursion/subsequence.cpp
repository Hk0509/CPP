#include <iostream>
#include <vector>
using namespace std;

void rec(int i, int arr[], int n, vector<int> &ans)
{
    if (i == n)
    {
        for (auto it : ans)
        {
            cout << it << " ";
        }
        cout << endl;
        return;
    }
    // Take condition (adds elements into subsequence )
    ans.push_back(arr[i]);
    rec(i + 1, arr, n, ans);

    // Not take condition (removes unwanted element)
    ans.pop_back();
    rec(i + 1, arr, n, ans);
}
int main()
{
    int arr[] = {3, 1, 2};
    int n = 3;
    vector<int> ans;
    int i = 0;
    rec(i, arr, n, ans);
    return 0;
}