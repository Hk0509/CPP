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

    // Copy Constructor
    Hero(Hero &temp)
    {
        //Manual Copy constructor: Created a new array to make it deep (from shallow(default))
        char *ch = new char[strlen(temp.name) + 1];
        strcpy(ch, temp.name);
        this->name = ch;

        cout << "Copy Constructor called" << endl;
        this->health = temp.health;
        this->level = temp.level;
    }

    void setName(char name[])
    {
        strcpy(this->name, name); // Copy name(parameter wala) to name(upr wala);
    }

    void print() //Print function to print values
    {
        cout << endl;
        cout << "[ Name: " << this->name << ", ";
        cout << "Health: " << this->health << ", ";
        cout << "Level: " << this->level << "]";
        cout << endl
             << endl;
    }

    //Setter
    void setLevel(char a)
    {
        level = a;
    }

    void setHealth(int a)
    {
        health = a;
    }

    //Getter
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
    Hero hero1; //Call Constructor
    hero1.setHealth(12); //Setter (Set value)
    hero1.setLevel('B'); //Setter (Set value)
    char name[7] = "Babbar"; // Input
    hero1.setName(name);

    // hero1.print();

    // Use default copy constructor
    // Shallow copy
    Hero hero2(hero1); // Copy constructor
    // hero2.print();

    hero1.name[0] = 'G'; //Edit a character to see shallowness of default copy constructor i.e., it will change with the main constructor.
    hero1.print();
    hero2.print();

    // Copy Assignment Operator
    hero1 = hero2;
    hero1.print();
    hero2.print();
}