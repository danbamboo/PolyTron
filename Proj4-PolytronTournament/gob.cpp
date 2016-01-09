/************************************************************************************
 Class Name: goblin
 Author: Danny McMurrough
 Date: 8/8/2015
 Description: Derived class of creature, represents Goblin creature
 Input: N/A
 Output: Attacks, Defense, Armor, Strength Points
 ************************************************************************************/

#include "gob.h"
#include <iostream>







gob::gob()
:creature("Goblin", 3, 8)
{
}


/************************************************************************************/
//  Goblin damage function.  Rolls 32six sided die.  Also sets goblin special if damage=12
/************************************************************************************/
int gob::damage ()
{
    int damage=0;
    rolls=2;
    
    for( int x=0; x < rolls; x++)
    {
        
        
        damage+= rollSix();
        
   }
    
    
    
    if (damage==12&&goblin!=2)
    {
        goblin=2;
        std::cout << "Goblin Special Achilles!  Unless oppontent is Goblin, attack is cut in half!\n";
    }
    
    
    
    return damage;
}


/************************************************************************************/
//  Goblin defend function, rolls 1 six sided die.
/************************************************************************************/
int gob::defend()
{
    
    int def=0;
    rolls=1;
    
    for( int x=0; x < rolls; x++)
    {
        
        
        def+= rollSix();
        
    }
    
    
    
    return def;
    
    
    
}

/************************************************************************************/
//  Display's the outcome of damage rolls and Goblin attack phrase.
/************************************************************************************/
void gob::sayItatk()
{
    
    std::cout<< "Goblin  Slither! ";
    std::cout << this->damg;
    std::cout << " damage." << std::endl;
    
}

/************************************************************************************/
//  Display's the outcome of defense rolls and Goblin defense phrase.
/************************************************************************************/
void gob::sayItdef()
{
    std::cout<< "Sneeky me! Block: ";
    std::cout << this->defn;
    std::cout << " damage." << std::endl;
    
    
}



