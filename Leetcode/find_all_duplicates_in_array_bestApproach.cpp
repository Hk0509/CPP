#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};
    vector<int> ans;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        int index = abs(nums[i]) - 1; // elements upto N and all greater than 0
        if (nums[index] < 0)
            ans.push_back(abs(nums[i]));
        else
            nums[index] *= -1;
    }
    for (auto it : ans)
    {
        cout << it << " ";
    }
}