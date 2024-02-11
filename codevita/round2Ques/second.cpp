#include<bits/stdc++.h>
using namespace std;

int solve(int i, int h, int n, vector<int>& v){
    if(h == 0) return 0;
    if(i == n) return -1;

    int take = -1e9, notTake = -1e9;
    if(h - v[i] >= 0){
        take = 1 + solve(i, h-v[i], n, v);
    }
    notTake = solve(i+1, h, n, v);

    return min(take, notTake);
}

int main(){
   int h;
   cin>>h;
    
   vector<int> v;
   int x;
   while(cin>>x){
       v.push_back(x);   
       if(x == -1) break;  
   }
    sort(v.begin(), v.end());
   int n = v.size();

   return solve(0, h, n, v);

}