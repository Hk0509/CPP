#include<iostream>
#include<vector>
using namespace std;

int correctPivot(int l, int h, vector<int>& v){
    int i = l, j = h, pivot = l;
    while(i < j){
        while(v[i] <= v[pivot] && i<= h-1){
            i++;
        }
        while(v[j] >= v[pivot] && j>= l+1){
            j--;
        }
        if(i<j)
        swap(v[i], v[j]);
    }
    swap(v[l], v[j]);
    return j;
}

void quickSort(int l, int h, vector<int>& v){
    if(l >= h) return ;

    int pivotInd = correctPivot(l, h, v);

    quickSort(l, pivotInd - 1, v);
    quickSort(pivotInd + 1, h, v);
}

int main(){
    int n;
    cin>>n;

    vector<int> v(n);
    for(int i=0; i<n; i++) cin>>v[i]; //6 4 5 1 6 3 2

    quickSort(0, n-1, v);

    for(auto it: v) cout<<it<<" ";
}