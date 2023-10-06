#include <iostream>
#include "Hero.cpp"
using namespace std;

// class Hero
// {

// private:
//     char level;

// public:
//     int health;

//     void setLevel(char a)
//     {
//         level = a;
//     }

//     void setHealth(int a)
//     {
//         health = a;
//     }

//     char getLevel()
//     {
//         return level;
//     }

//     int getHealth()
//     {
//         return health;
//     }
// };

int main()
{
    Hero *rohan = new Hero;

    (*rohan).setLevel('S');
    cout << rohan->getLevel() << endl;
    (*rohan).setHealth(80);
    cout << rohan->getHealth();
}