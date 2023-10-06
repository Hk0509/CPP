// You are using GCC
#include <bits/stdc++.h>
using namespace std;

bool sortbysec(const pair<int, int> &a,
               const pair<int, int> &b)
{
    return (a.second < b.second);
}

int sumOf(int n)
{
    int temp = 0;
    for (int i = 0; i * i <= n; i++)
    {
        if (i * i == n)
        {
            temp += 5;
        }
    }
    if (n % 4 == 0 && n % 6 == 0)
        temp += 4;
    if (n % 2 == 0)
        temp += 3;
    return temp;
}

int main()
{
    vector<pair<int, int>> vect;
    int arr[4];
    for (int i = 0; i < 4; i++)
    {
        cin >> arr[i]; 
    }
    int arr1[4];
    for (int i = 0; i < 4; i++)
    {
        arr1[i] = sumOf(arr[i]); 
    }
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; i++)
        vect.push_back(make_pair(arr[i], arr1[i])); 

    // cout << "before sort: "<<endl ;
    // for (int i=0; i<n; i++)
    // {
    //     cout << vect[i].first << " "
    //          << vect[i].second << endl;

    // }

    // sort by 2nd element of pair
    sort(vect.begin(), vect.end(), sortbysec);

    // cout << "after sort: "<<endl ;
    for (int i = 0; i < n; i++)
    {
        cout << vect[i].first << " ";
    }
    return 0;
}