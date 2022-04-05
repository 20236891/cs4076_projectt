#include "Player.h"
#include "item.h"
using namespace std;

Player::Player(){
}

Player::Player(string newName, int newHealth, int newHitChance) : Character(newName, newHealth, newHitChance)
{}



Player::~Player(){
    for(unsigned int i = 0; i < itemsInCharacter.size(); i++) {
        delete itemsInCharacter[i];
    }

}

vector <Item*> Player::getItemsInCharacter()const{
    return itemsInCharacter;
}

void Player::addItem(Item *item){
    itemsInCharacter.push_back(item);
}

void Player::setCurrentItem(Item item) {
    currentItem = item;
}


string Player::playerDetails(){
    return "Playe's Name: " + getName() + "\nHealth: " + to_string(getHealth());
}

int Player::getHasAnswered(){
    return this->hasAnswered;
}
void Player::setHasAnswered(int newHasAnswered){
    this->hasAnswered = newHasAnswered;
}

