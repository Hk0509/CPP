#include <iostream>
using namespace std;

void reverseString(string &str, int s)
{
    // Base case
    if (s > str.length() - s - 1)
    {
        return;
    }
    swap(str[s], str[str.length() - s - 1]);
    s++;
    reverseString(str, s);
}

int main()
{
    string str = "abcdef";
    int s = 0;

    reverseString(str, s);

    cout << str << endl;
}