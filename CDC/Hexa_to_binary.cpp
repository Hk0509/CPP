#include <bits/stdc++.h>
using namespace std;

int to_decimal(string hexa, int n)
{
    int dec = 0;
    for (int i = 0; i < n; i++)
    {
        int dig = 0;
        if (hexa[i] - '0' <= 9)
            dig = hexa[i] - '0';
        else
            dig = int(hexa[i]) - 55;
        dec += dig * pow(16, n - i - 1);
    }
    return dec;
}

string to_binary(int dec)
{
    string bin = "";
    while (dec > 0)
    {
        int dig = dec % 2;
        bin += to_string(dig);
        dec = dec / 2;
    }
    return bin;
}

void rev(string &bin, int n)
{
    int s = 0;
    int e = n-1;
    while(s<e)
    {
        swap(bin[s++], bin[e--]);
    }
    return;
}

int main()
{
    string hexa;
    cin >> hexa;
    int n = hexa.length();
    int dec = to_decimal(hexa, n);
    string bin = to_binary(dec);
    rev(bin, bin.length());
    cout << bin << endl;
}