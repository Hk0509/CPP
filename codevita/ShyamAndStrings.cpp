#include<bits/stdc++.h>
using namespace std;

int dp[1001][1001];

bool check(char c1, char c2, int k){
    int diff = abs(c1 - c2);
    return diff <= k or (26 - (diff%26)) <= k;
}

int lcs(string &s1, string &s2, int m, int n, int k){

    if(m == 0 || n == 0) return 0;

    if(dp[m][n] != -1) return dp[m][n];

    if(check(s1[m-1], s2[n-1], k)) {
        return dp[m][n] = 1 + lcs(s1, s2, m-1, n-1, k);
    }
    else {
        return dp[m][n] = max(lcs(s1, s2, m-1,n, k), lcs(s1, s2, m, n-1, k));
    }
}


int main(){
    string text1, text2;
    cin>>text1>>text2;

    int k; cin>>k;

    int m = text1.size();
    int n = text2.size();

    memset(dp, -1, sizeof(dp));

    cout<< lcs(text1, text2, m, n,  k);
}


