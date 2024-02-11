#include<bits/stdc++.h>
using namespace std;

int x, y, h, n, m;

void dfs2(vector<vector<int>>& grid, vector<vector<int>>& vis2, int i , int j, int match){
    if(i >= n || i<0 || j>=m || j<0 || vis2[i][j] == 1 || grid[i][j] != match) return;

    vis2[i][j] = 1;

    dfs2(grid, vis2, i+1, j, grid[i][j]);
    dfs2(grid, vis2, i-1, j, grid[i][j]);
    dfs2(grid, vis2, i, j+1, grid[i][j]);
    dfs2(grid, vis2, i, j-1, grid[i][j]);
}



int numIslands(vector<vector<int>>& grid) {

    vector<vector<int>> vis(n, vector<int> (m, 0));
    vector<vector<int>> vis2(n, vector<int> (m, 0));

    int ans = 0;


    queue<pair<int,int>> q;
    q.emplace(x, y);

    while(!q.empty()){
        int x_cor = q.front().first;
        int y_cor = q.front().second;
        q.pop();

        if(!vis2[x_cor][y_cor] && grid[x_cor][y_cor] > 0) {
            ans++;
            dfs2(grid, vis2, x_cor, y_cor, grid[x_cor][y_cor]);
        }
        vis[x_cor][y_cor] = 1;

        if(x_cor+1 < n and !vis[x_cor+1][y_cor] and grid[x_cor+1][y_cor] <= h) q.emplace(x_cor+1, y_cor);
        if(x_cor-1 >= 0 and !vis[x_cor-1][y_cor] and grid[x_cor-1][y_cor] <= h) q.emplace(x_cor-1, y_cor);
        if(y_cor+1 < m and !vis[x_cor][y_cor+1] and grid[x_cor][y_cor+1] <= h) q.emplace(x_cor, y_cor+1);
        if(y_cor-1 >= 0 and !vis[x_cor][y_cor-1] and grid[x_cor][y_cor-1] <= h) q.emplace(x_cor, y_cor-1);
    }

    return ans;
}


int main(){
    cin>>n>>m;

    vector<vector<int>> grid(n, vector<int>(m));


    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin>>grid[i][j];
        }
    }

    cin>>x>>y>>h;

    if(grid[x][y] != 0){
        cout<<"NONE"<<endl;
        return 0;
    }

    cout<<numIslands(grid);
}
