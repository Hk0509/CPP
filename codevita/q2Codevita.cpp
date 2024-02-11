#include <bits/stdc++.h>
using namespace std;

float distance(int x1, int y1, int x2, int y2)
{
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2) * 1.0);
}

float getArea(int r)
{
    return 3.14 * float(r * r);
}

int main()
{
    int r1 = 2, r2 = 5, x1 = 11, x2 = 13, y1 = 13, y2 = 11;
    // int r1 = 3, r2 = 4, x1 = 12, x2 = 14, y1 = 14 , y2 = 15;
    // cin>>r1>>r2>>x1>>x2>>y1>>y2;

    int actRadius = ceil(distance(r1, r2, x1, x2));
    int wrongDis = ceil(distance(r1, r2, y1, y2));
    // cout<<"WrongDis: "<<wrongDis<<" ActRadius: "<<actRadius<<endl;

    int actualArea = ceil(getArea(actRadius));
    int calculatedArea = ceil(getArea(wrongDis));
    // cout<<"actualArea: "<<actualArea<<" calculatedArea: "<<calculatedArea<<endl;
    int ans = -1;

    // Took more area
    if (actualArea < calculatedArea)
    {
        int extraOccupiedArea = calculatedArea - actualArea;
        // cout<<"extraOccupiedArea: "<<extraOccupiedArea<<endl;
        int upVal = ceil(sqrt(extraOccupiedArea));
        int lowVal = floor(sqrt(extraOccupiedArea));
        // cout<<"upVal: "<<upVal<<" lowVal: "<<lowVal<<endl;
        int upValSquare = upVal * upVal, lowValSquare = lowVal * lowVal;
        // cout<<"upValSquare: "<<upValSquare<<" lowValSquare: "<<lowValSquare<<endl;
        if (abs(upValSquare - extraOccupiedArea) < abs(extraOccupiedArea - lowValSquare))
        {
            // upar waala
            ans = (upValSquare - extraOccupiedArea) * 20;
            cout << "Krishna " << ans << endl;
        }
        else if (abs(upValSquare - extraOccupiedArea) > abs(extraOccupiedArea - lowValSquare))
        {
            // niche waala
            ans = (extraOccupiedArea - lowValSquare) * 20;
            cout << "Shiva " << ans << endl;
        }
    } // fence occupied less land than original
    else if (actualArea > calculatedArea)
    {
        // cout<<"Else if";
        ans = abs(calculatedArea - actualArea) * 20;
        cout << "Krishna " << ans << endl;
    }
    else
        cout << ans << endl;
}