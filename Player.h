#ifndef PLAYER_H
#define PLAYER_H
#include <vector>
#include "item.h"
#include "Character.h"
#include "Monster.h"


class Player : public Character
{


public:
    void addItem(Item *item);
    Player(std::string name, int health, int hitChance);
    Player();
    std::vector <Item*> getItemsInCharacter()const;
    void setCurrentItem(Item item);
    template <class T>
    bool checkItemExistence(T const* n);
    string playerDetails();
    int getHasAnswered();
    void setHasAnswered(int newHasAnswered);


    ~Player();

private:
    std::vector <Item*> itemsInCharacter;
    Item currentItem;
    Monster monster;
    int hasAnswered;


};

template <class T>
bool Player::checkItemExistence(T const* n)
{
    int sizeItems = itemsInCharacter.size();

    for(int i= 0; sizeItems; i++){
        if(itemsInCharacter[i]->getName() == n){
            return true;
        }
    }
    return false;
}

#endif // Player_H

