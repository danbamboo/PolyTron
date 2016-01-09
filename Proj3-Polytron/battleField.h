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



class battleField
{
    
public:
    battleField();
    
    void mainMenu();
    void random();
    void cont();
    void getReady(creature*& a, creature*& b);
    void getDeath(creature*& a, creature*& b);
    
    
    
private:
    
    creature *fighter[2];
    
    bool death,loser,exit,exit2,again;
    int choice, count;
    int rr;  // Random input variable
    
};





#endif /* defined(__Polytron__battleField__) */
