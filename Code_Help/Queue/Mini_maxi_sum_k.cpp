#include<iostream>
#include<queue>
using namespace std;

int solve(int arr[], int k, int n)
{
    deque<int> maxi;
    deque<int> mini;

    for(int i=0; i<k; i++)
    {
        while(!maxi.empty() && arr[i]>=arr[maxi.back()])
        maxi.pop_back();

        maxi.push_back(i);

        while(!mini.empty() && arr[i]<=arr[mini.back()])
        mini.pop_back();

        mini.push_back(i);

    }

    int ans = 0;
    ans = arr[maxi.front()] + arr[mini.front()];
    
    for(int i=k; i<n; i++)
    {
        if(!maxi.empty() && i-maxi.front() > k)
        maxi.pop_front();

        if(!mini.empty() && i-mini.front() > k)
        mini.pop_front();

        while(!maxi.empty() && arr[i]>=arr[maxi.back()])
        maxi.pop_back();

        maxi.push_back(i);

        while(!mini.empty() && arr[i]<=arr[mini.back()])
        mini.pop_back();

        mini.push_back(i);

        ans += arr[maxi.front()] + arr[mini.front()];
    }
    return ans;
}

int main()
{
    int arr[7] = {2, 5, -1, 7, -3, -1, -2};
    int k = 4, n = 7;
    int ans = solve(arr, k, n);
    cout<<ans<<endl;
}
