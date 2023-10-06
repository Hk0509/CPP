class Hero
{
private:
    char level;

public:
    int health;

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