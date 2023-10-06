#include <bits/stdc++.h>
using namespace std;

class Hero
{
private:
    char level;

public:
    //Initialization
    int health;
    char *name;
    static int timeToComplete;

    // Constructor
    Hero()
    {
        cout << "Constructor called" << endl;
        name = new char[100];
    }
};

// Static keyword: It is a data member i.e., it belongs to class. For ex - timeToComplete...it is independent of both Hero and Enemy.
// No need to create object.
//Created outside class(globally)
int Hero::timeToComplete = 5; // DataType(int), fir class Name(Hero), fir Scope Resolution Operator(::), fir field name(timeToComplete), fir =,fir value(5); 

int main()
{
    // cout<<Hero::timeToComplete<<endl; // Recommended

    // Hero a;
    // cout<<a.timeToComplete<<endl; // Not recommended

    // Hero b;
    // b.timeToComplete = 10; // Updated static in b
    // cout<<a.timeToComplete<<endl;
    // cout<<b.timeToComplete<<endl;



}