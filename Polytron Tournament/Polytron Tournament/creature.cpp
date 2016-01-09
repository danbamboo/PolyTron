/************************************************************************************
 Class Name: creature
 Author: Danny McMurrough
 Date: 8/8/2015
 Description: Base class for creatures of the world Polytron
 Input: From derived class (initailzation of member variables)
 Output: Attacks, Defense, Armor, Strength Points
 ************************************************************************************/


#include "creature.h"
#include <iostream>
#include <unistd.h>

int creature::damg;

int creature::goblin;

creature::creature( std::string s ,  int a , int str) :
name("Nada"), armor(0), strength(0), attk(0), points(0), tag(false),  defn(0)
{
    
    name=s;
    armor=a;
    strength=str;
    initstr=str;
    goblin=1;
    this->person=person;
    this->team=team;
    
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
        if(goblin==2)
        {
            std::cout << " Goblin achilles is activiated, damage cut in half!\n";
        }
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
    
    std::cout << "Total block: " << armor+defn << std::endl;
    
    
  
    
    if (damg <= 0)
    {
        std::cout << "==========================================\n";
        std::cout << "No damage done.\n";
        std::cout << "==========================================\n";
        damg=0;
        
    }
    
    if (damg > 0)
    {
        std::cout << "==========================================\n";
        std::cout << "Total damage is:  " << damg << std::endl;
        std::cout << "==========================================\n";
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
    //unsigned int randWait=1;
   //sleep(randWait);
    
    roll=(rand()%6)+1;
    
  
    std::cout << "SIX Sided: " << roll << std::endl;
    
    
    return roll;
    
}

/************************************************************************************/
        //  Returns ten sided dice random roll.
/************************************************************************************/
int creature::rollTen(){
    
    int roll;
  // unsigned int randWait=1;
   //sleep(randWait);
    
    roll=(rand()%10)+1;
   
    std::cout << "TEN Sided: " << roll << std::endl;
    
    return roll;
    
}



/************************************************************************************/
//  Returns name.
/************************************************************************************/
std::string creature::getName()
{
    
    
    return this->name;
}


/************************************************************************************/
//  Sets recovery amount (20% increase)
/************************************************************************************/
void creature::setrestore()
{
    
    std::cout << "++RESTORE++ ";
    
    if (strength < (initstr*.8))
    {
        
        std::cout << this->person << "'s strength restored!    ";
        std::cout << "From " << strength << " S.P. ";
        strength += initstr*.2;
        
        if (strength > initstr)
        {
            strength=initstr;
        }
        
        std::cout << "to " << strength << " S.P. \n\n";
    }
    else{
        
        std::cout << "No strength restored for " << person << ".  Put back in line with "
                    << strength << " strength (of total " << initstr << ")\n\n";
    }
    
    
}


/************************************************************************************/
//  Returns name.
/************************************************************************************/
std::string creature::getPerson()
{
    return this->person;
    
}

/************************************************************************************/
//  Returns team.
/************************************************************************************/
std::string creature::getTeam()
{
    return this->team;
    
}


/************************************************************************************/
//  Set team and name.
/************************************************************************************/
void creature::setnameteam(std::string p, std::string t)
{
    person=p;
    team=t;
    
    
}




/************************************************************************************/
//  Sets points.
/************************************************************************************/
void creature::setpoints(int p)
{
    points+=p;
    
    
}



/************************************************************************************/
//  Returns points.
/************************************************************************************/
int creature::getpoints()
{
    return points;
    
    
}


void creature::reSetGoblin()
{
    
    goblin=1;
    
    
}



















