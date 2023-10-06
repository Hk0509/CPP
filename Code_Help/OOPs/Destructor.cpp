#include <bits/stdc++.h>
using namespace std;

class Hero
{
private:
    char level;

public:
    int health;
    char *name;

    // Constructor
    Hero()
    {
        cout << "Constructor called" << endl;
        name = new char[100];
    }
    
    void print()
    {
        cout << endl;
        cout << "[ Name: " << this->name << ", ";
        cout << "Health: " << this->health << ", ";
        cout << "Level: " << this->level << "]";
        cout << endl
             << endl;
    }

    void setLevel(char a)
    {
        level = a;
    }

    void setHealth(int a)
    {
        health = a;
    }

    char getLevel()
    {
        return level;
    }

    int getHealth()
    {
        return health;
    }

    ~Hero()
    {
        cout<<"Destructor called"<<endl;
    }
};

int main()
{
    //Static, Destructor will be called automatically
    Hero a;

    //Dynamic, Call destructor manually
    Hero *b = new Hero();
    delete b; // Now it will call destructor
}