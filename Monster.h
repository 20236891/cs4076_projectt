#ifndef MONSTER_H
#define MONSTER_H
#include "Character.h"



struct Monster
{

private:

  std::string name;
  int health;
  int* attack;

public:

    Monster();

    Monster(std::string name, int health, int attack);
    Monster(Monster& mon);

    ~Monster();

    std::string monsterDetails();
    std::string getName()const;
     int getHitChance()const;
    int getHealth()const;
     void setHealth(int newHealth);




};

#endif // MONSTER_H
