#ifndef CHARACTER_H_
#define CHARACTER_H_

#include <vector>
#include <string>

class Character {
public:
    Character();
    Character(std::string name, int health, int hitChance);

    virtual std::string getName()const;
    virtual int getHitChance()const;
    virtual int getHealth()const;
    virtual void setHealth(int newHealth);
    virtual ~Character();

protected:

    std::string name;
    int health;
    int hitChance;
};

#endif /*CHARACTER_H_*/
