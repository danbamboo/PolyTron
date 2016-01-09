/************************************************************************************
 Class Name: creature
 Author: Danny McMurrough
 Date: 7/15/2015
 Description: Base class for creatures of the world Polytron
 Input: From derived class (initailzation of member variables)
 Output: Attacks, Defense, Armor, Strength Points
 ************************************************************************************/


#include "creature.h"
#include <iostream>
//#include <ctime>
#include <unistd.h>

int creature::damg;

int creature::goblin;

creature::creature(std::string s ,  int a , int str) :
name("Nada"), armor(0), strength(0), attk(0), defn(0)
{
    
    name=s;
    armor=a;
    strength=str;
    goblin=1;
    
}




/************************************************************************************/
            //  Uses static variable damg, calles virtual function attack.
/************************************************************************************/
void creature::attack()
{
    damg=0;
    
    if(name=="Goblin")
    {
        damg=damage();
        
    }
    

    
    else
    {
        damg=(damage())/goblin;
    }
    
    
    sayItatk();
  
}


/************************************************************************************/
        //  Uses static variable damg, calles virtual function defend.  Adjusts strength.
/************************************************************************************/
void creature::defense(){
    
    
    defn=defend();
    
    damg -= defn;  // Attack minus defend stored in static var.
    
    sayItdef();
    
    if(name!="The Shadow")
    {
         std::cout << "Armor:  " << armor << std::endl;
        damg -= armor;
    }
    
    
    
    
  
    
    if (damg <= 0)
    {
        std::cout << "No damage done.\n\n";
        damg=0;
        
    }
    
    if (damg > 0)
    {
        std::cout << "Total damage is:  " << damg << std::endl << std::endl;
        strength -= damg;
        damg=0;
        
    }
  
    
}

/************************************************************************************/
        //  Returns strength value.
/************************************************************************************/
int creature::getStrength (){
    
    return strength;
    
}

/************************************************************************************/
        //  Returns six sided dice random roll.
/************************************************************************************/

int creature::rollSix (){
    
    int roll;
    unsigned int randWait=1;
    
    
   // randWait=rand()%2+1;
   sleep(randWait);
    
    roll=(rand()%6)+1;
    
  
    std::cout << "SIX Sided: " << roll << std::endl;
    
    
    return roll;
    
}

/************************************************************************************/
        //  Returns ten sided dice random roll.
/************************************************************************************/
int creature::rollTen(){
    
    int roll;
   unsigned int randWait=1;
    
    
    // randWait=rand()%2+1;  //Choose a wait time of 1 or two, to mix up numbers.
   sleep(randWait);
    
    roll=(rand()%10)+1;
   
    std::cout << "TEN Sided: " << roll << std::endl;
    
    return roll;
    
}




std::string creature::getName()
{
    
    
    return this->name;
}





































