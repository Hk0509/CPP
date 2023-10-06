#include <iostream>
using namespace std;

bool checkPalin(string str, int i)
{
    int e = str.length() - i - 1;
    if (i > e)
        return true;

    if (str[i] != str[e])
        return false;

    i++;

    return checkPalin(str, i);
}

int main()
{
    string str = "himanshu";
    if (checkPalin(str, 0))
        cout << "Palindrome" << endl;
    else
        cout << "Not Palindrome" << endl;
}