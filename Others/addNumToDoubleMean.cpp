#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    int n = 5;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    int avg = ceil(sum / n);
    int ans = (2*avg)*(n+1) - sum;
    cout<<ans<<endl;
}