#include<bits/stdc++.h>
using namespace std;

int main()
{
    int z1,z2,x1,x2,y1,y2;
    cin>>z1>>z2>>x1>>x2>>y1>>y2;

    int ar = ceil(sqrt(pow(x1 - z1, 2) + pow(x2 - z2, 2))); 
    int wd = ceil(sqrt(pow(y1 - z1, 2) + pow(y2 - z2, 2)));

    int aa = ceil(3.14*(ar*ar));
    int ca = ceil(3.14*(wd*wd));

    int ans = -1;
    if(aa < ca)
    {
        int ea = ca - aa;
        int uV = ceil(sqrt(ea));
        int lV = floor(sqrt(ea));
        int us = uV*uV, ls = lV*lV;
        if(abs(us - ea) < abs(ea - ls))
        {
            ans = (us - ea)*20;
            cout<<"Krishna "<<ans<<endl;
        }
        else if(abs(us - ea) > abs(ea - ls))
        {
            ans = (ea - ls)*20;
            cout<<"Shiva "<<ans<<endl;
        }
    }
    else if(aa > ca)
    {
        ans = abs(ca - aa)*20;
        cout<<"Krishna "<<ans<<endl;
    }
    else
    cout<<ans<<endl;
}