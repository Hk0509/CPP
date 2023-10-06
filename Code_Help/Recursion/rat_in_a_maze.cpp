#include <iostream>
#include <vector>
using namespace std;

bool pathCondition(int x, int y, vector<vector<int>> m, int n, vector<vector<int>> visited)
{
    // Check condition if mouse can move
    if ((x >= 0 && x < n) && (y >= 0 && y < n) && visited[x][y] == 0 && m[x][y] == 1)
        return 1;
    else
        return 0;
}

void solve(int x, int y, vector<vector<int>> m, int n, vector<vector<int>> visited, string path, vector<string> &ans)
{
    // Base case
    if (x == n - 1 && y == n - 1)
    {
        ans.push_back(path);
        return;
    }

    // Marking visited points
    visited[x][y] = 1;

    // Down
    int newx = x + 1;
    int newy = y;
    if (pathCondition(newx, newy, m, n, visited))
    {
        path.push_back('D');
        solve(newx, newy, m, n, visited, path, ans);
        path.pop_back();
    }

    // Left
    newx = x;
    newy = y - 1;
    if (pathCondition(newx, newy, m, n, visited))
    {
        path.push_back('L');
        solve(newx, newy, m, n, visited, path, ans);
        path.pop_back();
    }

    // Right
    newx = x;
    newy = y + 1;
    if (pathCondition(newx, newy, m, n, visited))
    {
        path.push_back('R');
        solve(newx, newy, m, n, visited, path, ans);
        path.pop_back();
    }

    // Up
    newx = x - 1;
    newy = y;
    if (pathCondition(newx, newy, m, n, visited))
    {
        path.push_back('U');
        solve(newx, newy, m, n, visited, path, ans);
        path.pop_back();
    }

    visited[x][y] = 0;
}

int main()
{
    // Input maze 2D vector
    vector<vector<int>> m = {{1, 0, 0, 0},
                             {1, 1, 0, 1},
                             {1, 1, 0, 0},
                             {0, 1, 1, 1}};

    int n = m.size();

    // Visited array = 0
    vector<vector<int>> visited = m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            visited[i][j] = 0;
        }
    }

    // To store strings
    vector<string> ans;

    // String to store path "D,L,R,U"
    string path = "";
    int x = 0;
    int y = 0;

    // // If starting point is blocked(0)
    // if (m[0][0] == 0)
    //     return ans;

    solve(x, y, m, n, visited, path, ans);

    // Print paths
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
}