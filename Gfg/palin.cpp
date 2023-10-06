#include <iostream>
using namespace std;

int main()
{
    string s;
    int aCost, bCost;
    cin >> s >> aCost >> bCost;
    int n = s.length();
    int cost = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '/')
        {
            if (s[i] == s[n - i - 1])
            {
                if (aCost < bCost)
                {
                    cost += aCost;
                }
                else
                    cost += bCost;
            }
            else
            {
                s[i] = s[n - i - 1];
                if (s[i] == 'a')
                    cost += aCost;
                else
                    cost += bCost;
            }
        }
    }
    cout << cost << endl;
    return 0;
}
