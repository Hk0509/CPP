#include <iostream>
#include <vector>
using namespace std;
int main()
{
   int n, m;
   cin>>n>>m;
   vector<int> adj[n+1]; 
   //For edge weight store as pairs: vector<pair<int, int>> adj[n+1]
   for(int i=0; i<m; i++){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        //For directed graph we won't need line 14 as only u--->v and Space Complexity will be O(E) instead of O(2E)
        adj[v].push_back(u);
   }
   return 0;
}