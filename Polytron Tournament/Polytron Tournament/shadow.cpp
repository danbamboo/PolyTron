/************************************************************************************
 Class Name: shadow
 Author: Danny McMurrough
 Date: 8/8/2015
 Description: Derived class of creature, represents shadow creature
 Input: N/A
 Output: Attacks, Defense(Armor Special), Strength Points
 ************************************************************************************/
#include "shadow.h"
#include <iostream>
#include <ctime>





shadow::shadow()
:creature("The Shadow", 0, 12)
{
    
}

/************************************************************************************/
//  The Shadow damage function.  Rolls 2 ten sided die.
/************************************************************************************/
int shadow::damage ()
{
    int damage=0;
    rolls=2;
    
    for( int x=0; x < rolls; x++)
    {
        
        
        damage+= rollTen();
        
    }
    

    
    return damage;
}

/************************************************************************************/
//  The Shadow defend function, rolls 1 six sided die.
/************************************************************************************/

int shadow::defend()        //We include The Shadows special armor in the defense function.
{
    
    int def=0;
    rolls=1;
    
    for( int x=0; x < rolls; x++)
    {
        
        
        def+= rollSix();
        
    }
    
    
    rolls=rand()%2 + 1;
    
    
    if(rolls==1)
    {
        
        def += 20;    // Max damage could be after defent is 19 Max attack (20) - min defend (1)
                            // We will round to 20 for simplicity
        
    }
    
    

    
    return def;
    
    
    
}






/************************************************************************************/
//  Display's the outcome of damage rolls and The Shadow attack phrase.
/************************************************************************************/

void shadow::sayItatk()
{
    
    std::cout<< "Feel the wrath! ";
    std::cout << this->damg;
    std::cout << " damage." << std::endl;
    
}



/************************************************************************************/
//  Display's the outcome of defense rolls and The Shadow defense phrase (including special)
/************************************************************************************/
void shadow::sayItdef()
{
    if(defn>20)
    {
    std::cout<< "SPECIAL: Teleport!  Block all damage!\n";
    }
    
    else
    {
        std::cout<< "I hide in the Shadows! Block: ";
        std::cout << this->defn;
        std::cout << " damage." << std::endl;
    }
    
}






