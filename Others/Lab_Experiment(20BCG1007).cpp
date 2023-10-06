
#include <bits/stdc++.h>
using namespace std;

// Helper functions

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void createGraph(vector<int> adj[], vector<pair<int, int>> nodes)
{
    for (auto node : nodes)
    {
        addEdge(adj, node.first, node.second);
    }
}

//******** Unit-1 ***********************

// Euclidean Algorithm - Used for gcd(a,b)
int euclideanAlgo(int a, int b)
{
    if (b == 0)
        return a;
    return euclideanAlgo(b, a % b);
}

// ExtendedEuclid
void extendedEuclid(int a, int b, int &x, int &y, int &d)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        d = a;
        return;
    }                                  // base case
    extendedEuclid(b, a % b, x, y, d); // similar as the original gcd
    int x1 = y;
    int y1 = x - (a / b) * y;
    x = x1;
    y = y1;
}

// Sieve of Eratosthenes
void sieve(int n)
{
    vector<int> sieveArr(n, 0);
    for (int i = 2; i <= n; i++)
    {
        if (sieveArr[i] != 0)
            continue;
        for (int j = 2 * i; j <= n; j += i)
            sieveArr[j] = i;
    }

    for (int i = 2; i <= n; i++)
    {
        if (sieveArr[i] == 0)
        {
            cout << i << " ";
        }
    }
    cout << endl;
}

//******** Unit-2 ***********************

// __INSERTION SORT __
void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int value = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > value)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = value;
    }
}

// __MERGE SORT__

void merge(int arr[], int p, int q, int r)
{

    // Create L ← A[p..q] and M ← A[q+1..r]
    int n1 = q - p + 1;
    int n2 = r - q;

    int L[n1], M[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[p + i];
    for (int j = 0; j < n2; j++)
        M[j] = arr[q + 1 + j];

    // Maintain current index of sub-arrays and main array
    int i, j, k;
    i = 0;
    j = 0;
    k = p;

    // Until we reach either end of either L or M, pick larger among
    // elements L and M and place them in the correct position at A[p..r]
    while (i < n1 && j < n2)
    {
        if (L[i] <= M[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = M[j];
            j++;
        }
        k++;
    }

    // When we run out of elements in either L or M,
    // pick up the remaining elements and put in A[p..r]
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = M[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        // m is the point where the array is divided into two subarrays
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        // Merge the sorted subarrays
        merge(arr, l, m, r);
    }
}

// __SELECTION SORT__
void selectionSort(int array[], int size)
{
    for (int step = 0; step < size - 1; step++)
    {
        int min_idx = step;
        for (int i = step + 1; i < size; i++)
        {
            if (array[i] < array[min_idx])
                min_idx = i;
        }

        swap(&array[min_idx], &array[step]);
    }
}

//******** Unit-4 ***********************

// Graph DFS

void dfs(int node, vector<int> &vis, vector<int> adj[], vector<int> &storeDfs)
{
    storeDfs.push_back(node);
    vis[node] = 1;
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            dfs(it, vis, adj, storeDfs);
        }
    }
}

vector<int> dfsOfGraph(int V, vector<int> adj[])
{
    vector<int> storeDfs;
    vector<int> vis(V + 1, 0);
    for (int i = 1; i <= V; i++)
    {
        if (!vis[i])
            dfs(i, vis, adj, storeDfs);
    }
    return storeDfs;
}

// Graph BFS
vector<int> bfsOfGraph(int V, vector<int> adj[])
{
    vector<int> bfs;
    vector<int> vis(V, 0);
    queue<int> q;
    q.push(0);
    vis[0] = 1;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        bfs.push_back(node);

        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                q.push(it);
                vis[it] = 1;
            }
        }
    }

    return bfs;
}

// Topological Sort (Using BFS)
vector<int> topo(int N, vector<int> adj[])
{
    queue<int> q;
    vector<int> indegree(N, 0);
    for (int i = 0; i < N; i++)
    {
        for (auto it : adj[i])
        {
            indegree[it]++;
        }
    }

    for (int i = 0; i < N; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }
    vector<int> topo;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        topo.push_back(node);
        for (auto it : adj[node])
        {
            indegree[it]--;
            if (indegree[it] == 0)
            {
                q.push(it);
            }
        }
    }
    return topo;
}

//******** Unit-5 ***********************

// Rabin Karp Algo
void rabinKarpSearch(string S, string P)
{
    int Ns = S.length();
    int Np = P.length();

    int prime = 31;
    int mod = 1e9 + 9;

    vector<long long> p_pow(Ns);
    p_pow[0] = 1;
    for (int i = 1; i < Ns; i++)
    {
        p_pow[i] = (p_pow[i - 1] * prime) % mod;
    }

    vector<long long> h(Ns + 1, 0);
    for (int i = 0; i < Ns; i++)
    {
        h[i + 1] = (h[i] + (S[i] - 'a' + 1) * p_pow[i]) % mod;
    }

    long long hash_P = 0;
    for (int i = 0; i < Np; i++)
    {
        hash_P = (hash_P + (P[i] - 'a' + 1) * p_pow[i]) % mod;
    }

    for (int i = 0; i + Np - 1 < Ns; i++)
    {
        long long curr_hash = (h[i + Np] + mod - h[i]) % mod;
        if (curr_hash == hash_P * p_pow[i] % mod)
            cout << i << " ";
    }
}

// KMP Algo
void lps_func(string txt, vector<int> &Lps)
{
    Lps[0] = 0;
    int len = 0;
    int i = 1;
    while (i < txt.length())
    {
        if (txt[i] == txt[len])
        {
            len++;
            Lps[i] = len;
            i++;
            continue;
        }
        else
        {
            if (len == 0)
            {
                Lps[i] = 0;
                i++;
                continue;
            }
            else
            {
                len = Lps[len - 1];
                continue;
            }
        }
    }
}

void KMP(string pattern, string text)
{
    int n = text.length();
    int m = pattern.length();
    vector<int> Lps(m);

    lps_func(pattern, Lps);

    int i = 0, j = 0;
    while (i < n)
    {
        if (pattern[j] == text[i])
        {
            i++;
            j++;
        }
        if (j == m)
        {
            cout << i - m << ' ';
            j = Lps[j - 1];
        }
        else if (i < n && pattern[j] != text[i])
        {
            if (j == 0)
                i++;
            else
                j = Lps[j - 1];
        }
    }
}

// Manacher's Algo to find longest Palindromic Substring
void printSubstring(string str, int left, int right)
{
    for (int i = left; i <= right; i++)
        cout << str[i];
}
void longestPalSubstring(string str)
{
    // Getting length of the input string
    int n = str.size();

    // All substrings of length 1 are palindromes
    int maxLength = 1;

    int start = 0;

    // Checking all the substrings
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int flag = 1;

            // Checking for a palindromic subtring
            for (int k = 0; k < (j - i + 1) / 2; k++)
                if (str[i + k] != str[j - k])
                    flag = 0;

            // If substring is palindromic
            if (flag && (j - i + 1) > maxLength)
            {
                start = i;
                maxLength = j - i + 1;
            }
        }
    }

    // Printing the longest Palindromic substring
    cout << "The Longest Palindromic Substring is: ";
    printSubstring(str, start, start + maxLength - 1);
}

int main()
{
    // cout<<euclideanAlgo(24, 36); // output = 12

    // int x = 0, y = 0, d = 0;
    // extendedEuclid(25, 18, x, y, d);
    // cout<<x<<" "<<y<<" "<<d<<endl;

    // sieve(20);

    // int arr[5] = {3, 1, 2, 5, 4};
    // insertionSort(arr, 5);
    // mergeSort(arr, 0, 4);
    // selectionSort(arr, 5);
    // printArray(arr, 5);

    // vector<int> adj[5];
    // vector<pair<int,int>> nodes = {{0,1}, {0,2}, {0, 3}, {2, 4}};
    // createGraph(adj, nodes);
    // vector<int> ans;
    // ans = dfsOfGraph(4, adj);
    // ans = bfsOfGraph(5, adj);
    // for(auto it : ans) cout<<it<<" ";

    // vector<int> adj[6];
    // vector<pair<int,int>> nodes = {{5,2}, {5,0}, {4, 0}, {4, 1}, {3, 1}, {2, 3}};
    // for(auto node : nodes) adj[node.first].push_back(node.second);
    // vector<int> ans = topo(6, adj);
    // for(auto it : ans) cout<<it<<" ";

    // string S = "cxyzghxyzvjkxyz";
    // string P = "xyz";
    // cout<<"Pattern Occur at indexes: ";
    // rabinKarpSearch(S, P);
    // KMP(P, S);

    string str = "daabddfddbegtd";
    longestPalSubstring(str);

    return 0;
}
