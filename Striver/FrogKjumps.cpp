#include <iostream>
#include <vector>
using namespace std;

int solve(int n, vector<int> &arr, int k, int mini, vector<int>& dp){
    if (n == 0) return 0;

    if(dp[n] != -1) return dp[n];

    for (int i = 1; i <= k; i++){
        if (n - i < 0)
            break;
        int left = solve(n - i, arr, k, mini, dp) + abs(arr[n] - arr[n - i]);
        mini = min(mini, left);
    }
    dp[n] = mini;
    return dp[n];
}

int main(){
    int n, k, mini = INT_MAX;
    cin >> n >> k;
    vector<int> arr(n, 0);
    vector<int> dp(n, -1);
    for (int i = 0; i < n; i++) cin>>arr[i];
    cout << solve(n - 1, arr, k, mini, dp) << endl;
}