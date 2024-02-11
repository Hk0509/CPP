#include<bits/stdc++.h>
using namespace std;

int doit(int index,int prior,vector<int> arr,int n,vector<vector<int>>&dp)
{
    if(index==n) return 0;
    if(dp[index][prior]!=-(1e6+1)) return dp[index][prior];
    int pick,notpick;
    pick=(arr[index]*prior)+doit(index+1,prior+1,arr,n,dp);
    notpick=doit(index+1,prior,arr,n,dp);
    return dp[index][prior]=max(pick,notpick);
}


int main(){
    string input;
    getline(cin, input);

    vector<int> arr;

    stringstream ss(input);
    string num;

    while(ss >> num){
        arr.push_back(stoi(num));
    }

    sort(arr.begin(), arr.end());

    int n = arr.size();

    vector<vector<int>>dp(n,vector<int>(n+2,-(1e6+1)));
    int ans= doit(0,1,arr,n,dp);
    if(ans<0) cout<<0;
    else cout<<ans;
}

