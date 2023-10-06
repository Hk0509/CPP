#include<iostream>
using namespace std;

void fibo(int n)
{
    // if(n == 1) cout<<0<<" ";

    // if(n == 2) cout<<1<<" ";

    int prev = 0, curr = 1;
    int fibo = 0;

    while(n > 2)
    {
        int temp = 0;
        temp = prev;
        prev = curr;
        curr = curr + temp;
        cout<<curr<<" ";
        n--;

    }
    return;
}

int main()
{
    int n;
    cin>>n;
    cout<<0<<" "<<1<<" ";
    fibo(n);



    return 0;
}