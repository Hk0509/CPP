#include <bits/stdc++.h>
using namespace std;
int main()
{
    string str = "Himanshu";
    stack<char> st;

    for(int i=0; i<str.length(); i++)
    {
        st.push(str[i]);
    }

    for(int i=0; i<str.length(); i++)
    {
        cout<<st.top()<<" ";
        st.pop();
    }

}