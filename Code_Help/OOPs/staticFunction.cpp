//Static functions: same as static keyword this keyword(pointer to current object) ni hota (no object so no this)
// Can only access static members.

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

    static int random() 
    {
        return timeToComplete;
    }    // Constructor


    Hero()
    {
        cout << "Constructor called" << endl;
        name = new char[100];
    }
};

// Static keyword: It is a data member i.e., it belongs to class. For ex - timeToComplete...it is independent of both Hero and Enemy.
// No need to create object.
//Created outside class(globally)
int Hero::timeToComplete = 5;

int main()
{
    cout<<Hero::random()<<endl;
}