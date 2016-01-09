/************************************************************************************
 Class Name: barb
 Author: Danny McMurrough
 Date: 7/15/2015
 Description: Derived class of creature, represents barbarian creature
 Input: N/A
 Output: Attacks, Defense, Armor, Strength Points
 ************************************************************************************/

#include "barb.h"
#include <iostream>



barb::barb()
:creature("Barbarian", 0, 12)
{
    
}

/************************************************************************************/
//  Barbarian damage function.  Rolls 2 six sided die.
/************************************************************************************/
int barb::damage ()
{
    int damage=0;
    rolls=2;
    for( int x=0; x < rolls; x++)
    {
        
        
        damage+= rollSix();
        
    }
    
    return damage;
}

/************************************************************************************/
//  Reptiles defend function, rolls 2 six sided die.
/************************************************************************************/
int barb::defend()
{
    
    int def=0;
    rolls=2;
    srand( static_cast<unsigned int>(time(0)));
    for( int x=0; x < rolls; x++)
    {
        
        
        def+= rollSix();
        
    }
    

    return def;
    
    
    
}

/************************************************************************************/
//  Display's the outcome of damage rolls and Barabarian attack phrase.
/************************************************************************************/
void barb::sayItatk()
{
    
    std::cout<< "Barbarian Wrath! ";
    std::cout << this->damg;
    std::cout << " damage." << std::endl;
}

/************************************************************************************/
//  Display's the outcome of defense rolls and Barbarian defense phrase.
/************************************************************************************/
void barb::sayItdef()
{
    std::cout<< "MY BIG SHIELD! Block: ";
    std::cout << this->defn;
    std::cout << " damage." << std::endl;
    
    
}