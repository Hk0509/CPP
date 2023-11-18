#include<iostream>
#include<vector>
using namespace std;

void merge(int s, int m, int e, vector<int>& v){
   vector<int> temp;

    int i = s, j = m+1;
    while(i <= m && j <= e){
        if(v[i] <= v[j]) temp.push_back(v[i++]);
        else
        temp.push_back(v[j++]);
    }

    while(i<=m) 
    temp.push_back(v[i++]);

    while(j<=e)
    temp.push_back(v[j++]);

    for(int i=s; i<=e; i++){
        v[i] = temp[i-s];
    }
}

void mergeSort(int s, int e, vector<int>& v){
    if(s>=e) return ;
    int m = (s+e)/2;
    mergeSort(s, m, v);
    mergeSort(m+1, e, v);
    merge(s, m, e, v); 
}

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++) cin>>v[i]; //6 3 4 5 1 4 6 2

    mergeSort(0, n-1, v);

    for(auto it: v) cout<<it<<" ";
}