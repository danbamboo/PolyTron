/************************************************************************************
 Class Name: reptile
 Author: Danny McMurrough
 Date: 7/15/2015
 Description: Derived class of creature, represents reptile creature
 Input: N/A
 Output: Attacks, Defense, Armor, Strength Points
 ************************************************************************************/

#include "reptile.h"
#include <iostream>






reptile::reptile()
:creature("Reptilian", 7, 18)
{
    
}

/************************************************************************************/
//  Reptile damage function.  Rolls 3 six sided die.
/************************************************************************************/

int reptile::damage ()
{
    int damage=0;
    rolls=3;
    
    for( int x=0; x < rolls; x++)
    {
        
        
        damage+= rollSix();
        
    }
    
    return damage;
}




/************************************************************************************/
//  Reptiles defend function, rolls 1 six sided die.
/************************************************************************************/
int reptile::defend()
{
    
    int def=0;
    rolls=1;
    
    for( int x=0; x < rolls; x++)
    {
        
        
        def += rollSix();
        
    }

    return def;
    
    
    
}

/************************************************************************************/
//  Display's the outcome of damage rolls and reptile attack phrase.
/************************************************************************************/
void reptile::sayItatk()
{
    
    std::cout<< "Reptile smack! ";
    std::cout << this->damg;
    std::cout << " damage." << std::endl;
}


/************************************************************************************/
//  Display's the outcome of defense rolls and reptile defense phrase.
/************************************************************************************/

void reptile::sayItdef()
{
    
    
    std::cout<< "Snake Shield! Block: ";
    std::cout << this->defn;
    std::cout << " damage." << std::endl;
    
    
}






