#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<string> v;
    string s;
    while(1){
        getline(cin, s);
        v.push_back(s);
        if(s == "si") break;
    }

    vector<char> charV;
    char a;
    while(cin>>a){
        charV.push_back(a);
    }

    int size = charV.size()/2;

    for(auto it: v){
        if(it == "is A<B"){
           
        }
    }
}