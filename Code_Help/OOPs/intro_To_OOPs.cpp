#include <iostream>
using namespace std;

class Hero
{
private:
    int health;

public:
    int level;

    void print()
    {
        cout << "Health: " << health;
    }

    int getHealth()
    {
        return health;
    }

    void setHealth(int h) // Can apply conditions such as only particular person/role can access or applying passwd
    {
        health = h;
    }
};

int main()
{
    // Instantiate
    Hero ramesh;

    // Private, so can't access, use getter/setter to access private objects.
    // cout<<ramesh.health<<endl;

    cout << "Health (before Setter): " << ramesh.getHealth() << endl; // Garbage

    ramesh.setHealth(5);

    cout << "Health (after Setter): " << ramesh.getHealth() << endl; // 5
    cout << ramesh.level << endl;                                    // Garbage
}