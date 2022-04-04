#include "item.h"
#include "Type.h"

using namespace std;

bool Item::operator==(const string& itemName){
    return this->getName().compare(itemName) == 0;
}

Item::Item() { }

Item::~Item() {

}

Item::Item(string newName, Type newType, map<string, std::array<string, 2>> theExtras):
    name(newName),type(newType), extras(theExtras){}


string Item::getName() const {
    return name;
}

string Item::getLongDescription()

{
    return " item(s), " + name + ".\n";
}

Type Item::getType(){
    return type;
}

void Item::setType(Type type){
    Item::type = type;
}


string * Item::getExtras(string name) {

    static string extra [2];

    map<string, std::array<string, 2>>::iterator next = extras.find(name);

    if (next != extras.end()){

        for (int i = 0; i < 2; i++) {
            extra[i] = next->second[i];
        }
}

    return extra;
}


