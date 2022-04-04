//19258879 FISTON KULIMUSHI
//20296568 VALENTIN FORITE
// LEVEL 2

#ifndef ZORKUL_H_
#define ZORKUL_H_

#include "Command.h"
#include "Parser.h"
#include "Room.h"
#include "item.h"
#include "Character.h"
#include <vector>
#include "Player.h"
#include "Monster.h"
#include <iostream>
#include <string>
#include<QPushButton>
#include<QPushButton>
#include<QObject>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


using namespace std;
class Room;

class ZorkUL: public QObject {

    Q_OBJECT


private:

    Parser parser;
	Room *currentRoom;
    vector <Room*> roomList;
    void createItems();
    void displayItems();
    void printHelp();
    void goRoom(Command command);

    Monster dragon;
    Player me;
    QString text;



public:
	ZorkUL();
    void play();
    friend class MainWindow;
    string processCommand(Command command);



    ~ZorkUL();
    Room* getCurrentRoom() const;
    Player getPlayer() const;
    void createRooms();
    string printWelcome();
     void createPlayer();
    int getPlayerHealth();
    int getPlayerHitchance();
    int getDragonHealth();
    int getDragonHitchance();
    string map();
    string Inventory;
    int itemsGot=0;
    string go(string direction);
    string fight();
    string solveRiddle();
    void setText(QString);
    QString getText();
    bool flag = false;
    bool getPlayerAnswer();
    string quitFucntion();





};

#endif /*ZORKUL_H_*/
