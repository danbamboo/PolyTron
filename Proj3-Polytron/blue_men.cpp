/************************************************************************************
 Class Name: blue_men
 Author: Danny McMurrough
 Date: 7/17/2015
 Description: Derived class of creature, represents Blue Man creature
 Input: N/A
 Output: Attacks, Defense, Armor, Strength Points
 ************************************************************************************/

#include "blue_men.h"

#include <iostream>





blue_men::blue_men()
:creature("Blue Man", 3, 12)
{
    
}

/************************************************************************************/
//  Blue Men damage function.  Rolls 2 ten sided die.
/************************************************************************************/
int blue_men::damage ()
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
//  Reptiles defend function, rolls 3 six sided die.
/************************************************************************************/
int blue_men::defend()
{
    
    int def=0;
    rolls=3;
    
    for( int x=0; x < rolls; x++)
    {
        
        
        def += rollSix();
        
    }
    
    
    
    return def;
    
    
    
}


/************************************************************************************/
//  Display's the outcome of damage rolls and Blue Men attack phrase.
/************************************************************************************/
void blue_men::sayItatk()
{
    
    std::cout<< "Bow to me! ";
    std::cout << this->damg;
    std::cout << " damage." << std::endl;
    
}


/************************************************************************************/
//  Display's the outcome of defense rolls and Blue Men defense phrase.
/************************************************************************************/

void blue_men::sayItdef()
{
    std::cout<< "Blue Ink! Block: ";
    std::cout << this->defn;
    std::cout << " damage." << std::endl;
    
    
}



