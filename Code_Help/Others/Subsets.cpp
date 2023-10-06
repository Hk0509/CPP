#include <iostream>
#include <vector>
using namespace std;

void subsets(vector<int> arr, int index, vector<int> output, vector<vector<int>> &ans)
{
    // Base Case
    if (index >= arr.size())
    {
        ans.push_back(output);
        return;
    }

    // Exclude
    subsets(arr, index + 1, output, ans);

    // Include
    output.push_back(arr[index]);
    subsets(arr, index + 1, output, ans);
}

int main()
{
    vector<int> arr = {1, 2, 3};
    int index = 0;
    vector<int> output;
    vector<vector<int>> ans;
    subsets(arr, index, output, ans);
    for (auto it : ans)
    {
        for (auto it2 : it)
        {
            cout << it2 << " ";
        }
        cout << endl;
    }
}