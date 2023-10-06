#include <bits/stdc++.h>
using namespace std;
int main()
{
   int n = 5678; // 5 6 78 56 67 78 567 678 
   string s = to_string(n);
   vector<string> v;
   int size = s.size();
   for(int i = 0 ; i < size ; i++)
   {
      string temp;
      int j;
      for(j=0; j<i; j++)
      {
         temp += s[j];
      }
      cout<<temp<<" ";
      for(int k=j; k<size; k++)
      {
         temp+=s[k];
         if(temp.size() >= i) temp.erase(temp.begin());
         cout<<temp<<" ";
      }
   }
}