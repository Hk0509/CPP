#include<bits/stdc++.h>
using namespace std;

int main()
{
    string a,b;
    cin>>a>>b;
    int ans = 0;
    
    for(int i=0; i<b.length(); i++)
    {
        int tempI = i;
        int j=0;
        if(b[i] == a[j])
        {
            int count = 0;
            while(b[tempI]==a[j])
            {
                count++;
                tempI++;
                if(j<a.length())
                j++;
            }
            if(count == a.length())
            {
            ans++;
            i = tempI-1;
            }
            // i--;
        }
    }
    cout<<"The no of occurences: "<<ans;
}