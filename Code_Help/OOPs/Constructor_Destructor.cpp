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

    // Parameterized Constructor
    Hero(int health, char level)
    {
        this->level = level;
        this->health = health;
    }

    // // Copy Constructor
    // Hero(Hero &temp)
    // {
    //     cout << "Copy Constructor called" << endl;
    //     this->health = temp.health;
    //     this->level = temp.level;
    // }

    void setName(char name[])
    {
        strcpy(this->name, name);
    }

    void print()
    {
        cout << endl;
        cout << "Name: " << this->name << endl;
        cout << "Health: " << this->health << endl;
        cout << "Level: " << this->level << endl;
        cout << endl;
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
};

int main()
{
    Hero hero1;
    hero1.setHealth(12);
    hero1.setLevel('B');
    char name[7] = "Babbar";
    hero1.setName(name);

    hero1.print();

    // Use default copy constructor 
    //Shallow copy
    Hero hero2(hero1);
    hero2.print();

    hero1.name[0] = 'G';
    hero1.print();

    hero2.print();

    // Another way to create copy constructor
    //  Hero hero2 = hero1;

    // Hero Suresh(70, 'C');

    // Suresh.print();

    // // Copy Constructor
    // Hero R(Suresh);

    // R.print();
    // Hero rohan(70, 'S');
    // cout << rohan.getHealth() << endl;
    // cout << rohan.getLevel() << endl;
}