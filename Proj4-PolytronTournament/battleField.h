/*<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
 The file battleField.h  is the specification file for the battleField.cpp file/class.
 <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>*/

#ifndef __Polytron__battleField__
#define __Polytron__battleField__


#include "creature.h"
#include "blue_men.h"
#include "shadow.h"
#include "gob.h"
#include "barb.h"
#include "reptile.h"
#include "queue.h"
#include "theStack.h"



class battleField
{
    
public:
    battleField();
    
    void mainMenu();
    void cont();
    void getReady(creature*& a, creature*& b);
    void getDeath(creature*& a, creature*& b);
    void onceagain();
    void choose(std::string);
    void how_many();
    void getpoints(creature*& a, creature*& b);
    void reset();
    void displaystats();
    void selectionSort();
    void recuriveStack (creatque );
private:
    
    creature *fighter, *fighter2, *temp1, *temp2;
    creatque team1, team2;
    creatstk loserpile;
    
    bool death,exit,exit2,exit3,again;
    unsigned int choice, points, count,loser, twocount,round;
    int team1p, team2p;
    int rr;  // Random input variable
    std::string t1name,t2name, name;
    std::string cr1, cr2;
    creature** creatarr;
};





#endif /* defined(__Polytron__battleField__) */
