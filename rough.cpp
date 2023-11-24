#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>>bag;
    vector<pair<int,int>>cust;
    
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        cust.push_back({y,x});
    }
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        bag.push_back({y,x});
    }

    sort(bag.begin(),bag.end(), greater<int>()); 
    sort(cust.begin(),cust.end(), greater<int>()); 
    
    int i=n-1,j=m-1;
    int ans=0;
    //price quantity
    while(i>=0 && j>=0)
    {
        if(cust[i].first >= bag[j].first)
        {
            if(cust[i].second < bag[j].second)
            {
                ans++;
                i--;
                j--;
            }
            else
            {
                j--;
            }       
        }
        else
        {
            i--;
        }     
    }
    cout<<ans;
    return 0;
}