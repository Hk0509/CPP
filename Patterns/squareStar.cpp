#include<iostream>
using namespace std;

int main(){
    int n = 4;
    int cnt = 1;
    for(int i=0; i<n; i++){
       for(int j = 0; j<n-i-1; j++){
        cout<<" ";
       }
       for(int j = 0; j<cnt; j++){
        cout<<"*";
       }
       cnt+=2;
       cout<<endl;
    }
}