#include<bits/stdc++.h> 
using namespace std;
int main()
{
    int n;
    cin>>n;
    
    vector<int> m;
    vector<int> f;
    
    for(int i=0; i<n; i++)
    {
        int a,b;
        cin>>a>>b;
        
        if(a==0)
        f.push_back(b);
        
        else
        m.push_back(b);
    }
    int fSize = f.size();
    int mSize = m.size();
    
    sort(f.begin(), f.end());
    sort(m.begin(), m.end());
    
    for(int i = fSize-1; i>=0; i--)
    {
        cout<<f[i]<<" ";
    }
    
    for(int i = mSize-1; i>=0; i--)
    {
        cout<<m[i]<<" ";
    }
    
}