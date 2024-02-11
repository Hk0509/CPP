#include<bits/stdc++.h>
using namespace std;

float distance(int x1, int y1, int x2, int y2) 
{ 
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2) * 1.0); 
} 

float getArea(int r)
{
    return 3.14*float(r*r);
}

int main()
{
    int r1,r2,x1,x2,y1,y2;
    cin>>r1>>r2>>x1>>x2>>y1>>y2;

    float radius = distance(r1,r2,x1,x2);
    int actRadius = ceil(radius);
    float aDis = distance(r1,r2,y1,y2);
    int wrongDis = ceil(aDis);

    float correctArea = getArea(actRadius); 
    int cArea = ceil(correctArea);
    float wrongArea = getArea(wrongDis); 
    int wArea = ceil(wrongArea);
    int ans = -1;

    if(cArea < wArea)
    {
        int leftArea = wArea - cArea;
        float num = sqrt(leftArea);
        int upVal = ceil(num);
        int lowVal = floor(num);
        int upValSquare = upVal*upVal, lowValSquare = lowVal*lowVal;
        if(abs(upValSquare - cArea) < abs(cArea - lowValSquare))
        {
            ans = (upValSquare - leftArea)*20;
            cout<<"Krishna "<<ans<<endl;
        }
        else if(abs(upValSquare - cArea) > abs(cArea - lowValSquare))
        {
            ans = (leftArea - lowValSquare)*20;
            cout<<"Shiva "<<ans<<endl;
        }
    }
    else if(cArea > wArea){
        ans = (cArea - wArea)*20;
        cout<<"Krishna "<<ans<<endl;
    }
    else
    cout<<ans<<endl;
}