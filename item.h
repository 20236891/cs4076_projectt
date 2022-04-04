#ifndef ITEM_H_
#define ITEM_H_

#include <string>
#include "Type.h"
#include <vector>
#include <map>
using namespace std;
using std::vector;


class Item {

private:
    std::string name;
    Type type;
    std::map<string, std::array<string, 2>> extras;


public:
    Item ();
    ~Item();
    Item (string newName, Type newtype, map<string, std::array<string, 2>> theExtras);


    string getName() const;
    string getLongDescription();
    Type getType();
    void setType(Type type);
    string * getExtras(string name);
    bool operator==(const std::string& itemName);


};

#endif /*ITEM_H_*/
