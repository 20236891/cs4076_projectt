#include "Monster.h"
#include <iostream>

using namespace std;

Monster::Monster(){
    name = "";
    health = 0;
    attack = 0;
}

Monster::~Monster(){
    delete attack;
}

Monster::Monster(Monster& mon){
    name = mon.name;
    health = mon.health;
    attack = new int(*mon.attack);
    attack = mon.attack;
}

Monster::Monster(string name, int health, int hitChance) :
    name(name), health(health), attack(new int(hitChance)){ }


string Monster::monsterDetails(){
    return "Name: " + getName();
}
string Monster::getName()const{
    return this->name;
}

int Monster::getHitChance()const{
    return *(this->attack);
}

int Monster::getHealth()const{
   return this->health;
}

void Monster::setHealth(int newHealth){
    this->health = newHealth;
}

