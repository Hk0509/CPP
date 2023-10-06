#include<iostream>
using namespace std;

void printIt(int ind , int i){
    if(ind > i){
        cout<<endl;
        return ;
    }
    cout<<"*"<<" ";
    printIt(ind+1, i);
}

void solve(int i, int n){
    if(i > n) return ;
    printIt(1, i);
    solve(i+1, n);
}

int main(){
    int n = 5;
    solve(1, n);
}