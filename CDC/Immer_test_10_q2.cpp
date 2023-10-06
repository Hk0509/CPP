#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int count = n;
    
    vector<int> s;
    vector<int> e;
    
    for(int i=0; i<n; i++)
    {
        int a,b;
        cin>>a>>b;
        s.push_back(a);
        e.push_back(b);
    }
    // sort(s.begin() , s.end());
    // sort(e.begin() , e.end());
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            if(s[j] <= e[i])
            count--;
        }
    }
    cout<<count<<endl;
}