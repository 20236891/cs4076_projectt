//Neema Kulimushi

#include <iostream>
#include <vector>
#include "ZorkUL.h"

using namespace std;

ZorkUL::ZorkUL() {
     createRooms();
//     ZorkUL temp;
//     temp.play();

}

void ZorkUL::createRooms() {
    std::map<string,  std::array<string, 2>> extras{
        {"riddle", std::array<string, 2>{"What gets wet while driying?", "towel"}},
        {"key", std::array<string, 2>{"This is the key to open the room where Lion is" ,"take"}},
        {"Hint", std::array<string, 2>{"You need to find the riddle question and then Go find the key for the room where there is a Lion", "jhhgc"}},
                                       };


    Item *key = new Item("key", Type::OBJECT, extras);
    Item *riddle = new Item("riddle", Type::RIDDLE, extras);
    Item *info = new Item("Hint", Type::INFO, extras);


    Room *one, *two, *three, *four, *five, *six, *seven, *eight, *nine;


    one = new Room("one");
    two = new Room("two");
    three = new Room("three");
    four = new Room("four");
    five = new Room("five");
    six = new Room("six");
    seven = new Room("seven");
    eight = new Room("eight");
    nine = new Room("nine");


    roomList.push_back(one);
    roomList.push_back(two);
    roomList.push_back(three);
    roomList.push_back(four);
    roomList.push_back(five);
    roomList.push_back(six);
    roomList.push_back(seven);
    roomList.push_back(eight);
    roomList.push_back(nine);

    six->addItem(info);
    three->addItem(key);
    nine->addItem(riddle);

    // Monster mons("lion",100,50);
    five->addMonster(new Monster("lion",100,50));


    one->addMonster(NULL);
    two->addMonster(NULL);
    three->addMonster(NULL);
    four->addMonster(NULL);
    nine->addMonster(NULL);
    six->addMonster(NULL);
    seven->addMonster(NULL);
    eight->addMonster(NULL);


    //             (N,   E,    S,    W)
    one->setExits(six, three, four, two);
    two->setExits(NULL, NULL, NULL, three);
    three->setExits(NULL, one, NULL, NULL);
    four->setExits(one, five, NULL, nine);
    five->setExits(NULL, NULL, NULL, four);
    six->setExits(NULL, seven, one, eight);
    seven->setExits(NULL, NULL, NULL, six);
    eight->setExits(NULL, six, NULL, NULL);
    nine->setExits(NULL, four, NULL, NULL);


        currentRoom = one;


}

/**
 *  Main play routine.  Loops until end of play.
 */
void ZorkUL::play(){
    printWelcome();


    // Enter the main command loop.  Here we repeatedly read commands and
    // execute them until the ZorkUL game is over.

    bool finished = false;
    while (!finished) {
        // Create pointer to command and give it a command.
        Command* command = parser.getCommand();
        // Pass dereferenced command and check for end of game.
//        finished = processCommand(*command);
        // Free the memory allocated by "parser.getCommand()"
        //   with ("return new Command(...)")
        delete command;
    }
    cout << endl;
    cout << "end" << endl;
}

string ZorkUL::printWelcome() {
//    cout << "start"<< endl;
//    cout << "info for help"<< endl;
//    cout << "\n" << me->playerDetails()<< endl;

//    cout << endl;
//    cout << currentRoom->longDescription() << endl;
    string welcome = "\n";
    welcome += "Start the game.\n";
    welcome += "find the key first And the riddle in one of the room.\n\n";
    welcome += currentRoom->longDescription() + "\n";
    return welcome;

}

/**
 * Given a command, process (that is: execute) the command.
 * If this command ends the ZorkUL game, true is returned, otherwise false is
 * returned.
 */


string ZorkUL::processCommand(Command command) {

    string output ="";

    if (command.isUnknown()) {
        cout << "invalid input"<< endl;
        return output;
    }

    string commandWord = command.getCommandWord();
    if (commandWord.compare("info") == 0)
        printHelp();



    else if (commandWord.compare("map") == 0)
        {
        map();
        }


    else if (commandWord.compare("fight") == 0)
        {
        fight();
        }

    else if (commandWord.compare("quit") == 0)
        {
        quitFucntion();
        }

    else if (commandWord.compare("go") == 0){
    //        cout << command.getCommandWord() << endl;
        goRoom(command);
    }
    else if (commandWord.compare("nothing") == 0){
    //        cout << command.getCommandWord() << endl;
        output+= "correct";
    }



    else if (commandWord.compare("take") == 0)
    {
        if (!command.hasSecondWord()) {

            output = "incomplete input";
                    return output;

        }
        else if (command.hasSecondWord()) {
//        cout << "you're trying to take " + command.getSecondWord() << endl;
        int location = currentRoom->isItemInRoom(command.getSecondWord());
        if (location  < 0 ){
                   output+= "\n\nitem is not in room" ;
               return output;
                }else{
                   output = "\nItem " + command.getSecondWord()+" has been added to your Inventory";
                   this->me.addItem(currentRoom->getItem());

                   output+="\n";
                   this->Inventory += "\n"+command.getSecondWord();
                   itemsGot++;


                   output+= currentRoom->longDescription() +"\n\n";
               }
         }
//        return output;

    }
    return output;


}


string ZorkUL::map(){
    string map;
    map+= "\n";
    map +="[eight] --- [six] --- [seven]\n";
    map +="            |         \n";
    map +="            |         \n";
    map +="[three] --- [one] --- [two]\n" ;
    map +="            |         \n";
    map +="            |         \n";
    map +="[nine] --- [four] --- [five]\n";


    return map;
}

string ZorkUL::quitFucntion(){
    string quit = "\n\n\n\n\n                          End of Game";

    return quit;


}


/** COMMANDS **/
void ZorkUL::printHelp() {
    cout << "valid inputs are; " << endl;
    parser.showCommands();

}

void ZorkUL::goRoom(Command command) {
    if (!command.hasSecondWord()) {
        cout << "incomplete input"<< endl;
        return;
    }

    string direction = command.getSecondWord();

    // Try to leave current room.
    Room* nextRoom = currentRoom->nextRoom(direction);

    if (nextRoom == NULL)
        cout << "underdefined input"<< endl;
    else
     {
        currentRoom = nextRoom;
        cout << currentRoom->longDescription() << endl;

    }
}
string ZorkUL::go(string direction) {
    //Make the direction lowercase
    //transform(direction.begin(), direction.end(), direction.begin(),:: tolower);
    //Move to the next room
    Room* nextRoom = currentRoom->nextRoom(direction);
    if (nextRoom == NULL)
        return("\n\nNo room in that Direction. \n");
    else
    {
        string go;
        currentRoom = nextRoom;
        go="\n\n"+ currentRoom->longDescription()+"\n\n";
       //go+= ""+ this->getPlayer().setStamina(Player1->getStamina()-10);


        return go;
    }
}


Room* ZorkUL::getCurrentRoom() const{
    return this->currentRoom;
}




void ZorkUL::createPlayer(){
  Player player ("King", 100, 30);
  me = player;

    me.getHealth();
    me.getHitChance();
    me.getName();

    Monster mon("lion",80,50);
    lion = mon;
    lion.getHealth();
    lion.getHitChance();
    lion.getName();

}

int ZorkUL::getPlayerHealth(){
    return this->me.getHealth();
}

int ZorkUL::getPlayerHitchance(){
    return this->me.getHitChance();
}
bool ZorkUL::getPlayerAnswer(){
    return this->me.getHasAnswered();
}

int ZorkUL::getLionHealth(){
    return this->lion.getHealth();
}

int ZorkUL::getDragonHitchance(){
    return this->me.getHitChance();
}


string ZorkUL::fight(){

    string output ="\nYou are about to fight the Lion.\n";


    while (me.getHealth() > 0 && lion.getHealth() > 0){
        int hitchance = 1 + rand() % 10;


    if (flag){

        lion.setHealth(me.getHealth() - hitchance);
        flag = false;
}
  else{

        me.setHealth(me.getHealth() - hitchance);
        flag = true;

    }

    }

    if (me.getHealth() > 0){
         output += "\nYou win";

    }
    else{
        output += "\nYou lose \n " ;

    }

    return output;
}



QString ZorkUL::getText(){
    return this->text;
}

void ZorkUL::setText(QString newText){
    this->text=newText;
}

ZorkUL::~ZorkUL(){
    delete currentRoom;

    for(unsigned int i = 0; i < roomList.size(); i++) {
        delete roomList[i];
    }
}
