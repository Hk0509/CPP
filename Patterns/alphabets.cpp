#include <iostream>
using namespace std;
int main()
{
    char c = 'a';
    for(int i=0; i<5 ; i++)
    {
        for(int j=0; j<5; j++)
        {
            cout<<c;
        }
        c++;
        cout<<endl;
    }
}