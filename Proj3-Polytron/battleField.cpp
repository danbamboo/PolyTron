/************************************************************************************
 Class Name: Battle Field
 Author: Danny McMurrough
 Date: 7/17/2015
 Description: Composition of 5 creaturs.
 Input: User set up who battles whom.
 Output: Winner and loser of battle.
 ************************************************************************************/

#include "battleField.h"
#include <iostream>
#include <ctime>
#include <cstddef>




battleField::battleField()
{
    
    mainMenu();
    
    
}



/************************************************************************************/
//  Acts as main menu for the program.  Will loop as long as user wants to keep playing
/************************************************************************************/
void battleField::mainMenu()
{
    
    std::cout << "»»»»»»»»»»»»»»»»»»»»»»»»»»»»»» ± ««««««««««««««««««««««««««««««««\n";
    std::cout << "\t±±±±±  ±±±±±  ±      ±   ±  ±±±±±  ±±±±±   ±±±±±  ±     ± \n";
    std::cout << "\t±   ±  ±   ±  ±      ±   ±    ±    ±   ±   ±   ±  ± ±   ± \n";
    std::cout << "\t±±±±±  ±   ±  ±      ±±±±±    ±    ±±±±±   ±   ±  ±  ±  ± \n";
    std::cout << "\t±      ±   ±  ±          ±    ±    ± ±     ±   ±  ±   ± ± \n";
    std::cout << "\t±      ±   ±  ±          ±    ±    ±  ±    ±   ±  ±    ±± \n";
    std::cout << "\t±      ±±±±±  ±±±±±  ±±±±±    ±    ±   ±   ±±±±±  ±     ± \n";
    std::cout << "»»»»»»»»»»»»»»»»»»»»»»»»»»»»»» ± ««««««««««««««««««««««««««««««««\n\n\n";
    
    std::cout << "\tWelcome to the world of PolyTron!\n";
    std::cout << "\tEvil has found it's way into the hearts of all races.\n";
    std::cout << "\tYou will select two creatures to fight one another.\n";
    std::cout << "\tMay the best creature win.\n\n";
    
    
    count=0;
    
   
    do{
         count=0;
    do{
        
        
        
        
        std::cout << "Choose Creature# " << count+1 << "\n\n";
        
        
        std::cout << "1. Reptilian\n";
        std::cout << "2. Barbarian\n";
        std::cout << "3. Goblin\n";
        std::cout << "4. The Shadow\n";
        std::cout << "5. Blue Man\n";
        
        
        
        /************************************************************************************/
        //  Here we cast creatures into the base class dynamically based on user input
        /************************************************************************************/
        
        do{
            std::cout << "Selction:";
            std::cin >> choice;
            
            if (std::cin.fail()|| (choice < 1 || choice > 5))
            {
                std::cout << "Please enter a number 1-5\n";
                exit=false;
                std::cin.clear();
                std::cin.ignore(100, '\n');
            }
            else{
                exit=true;
            }
        }while(exit==false);
        
        
        std::cout << std::endl;
        
        
        if (choice==1)  //Add New Item
        {
            fighter[count]= new reptile;
            
            
        }
        if (choice==2)  //Add New Item
        {
            fighter[count]= new barb;
            
            
        }
        if (choice==3)  //Add New Item
        {
            
            fighter[count]= new gob;
            
        }
        if (choice==4)  //Add New Item
        {
            fighter[count]= new shadow;
            
            
        }
        if (choice==5)  //Add New Item
        {
            
            fighter[count]= new blue_men;
            
        }
    
        
        count++;
    }while(count <2);
    
    
    
    random();
    
    exit2=false;
    
    
    
    //Sets who fights first by passing pointer variables by reference into function.
    
    if(rr==0)
    {
        
        getReady(fighter[0], fighter[1]);   //Runs the fighting program, passing in by reference.
        
       
    }
    
    
    
    
    
    
    if (rr==1)
    {
        getReady(fighter[1], fighter[0]);   //Runs the fighting program, passing in by reference.
        
        
    }
    
        getDeath(fighter[0], fighter[1]);
    
        
        
        
        
        
        for (int x=0; x < 2; x++)
        {
        delete fighter[x];
        }
        
    }while(again==true);
  
    
    
 
    
}









/************************************************************************************/
//  Genters random value to see who goes first.
/************************************************************************************/

void battleField::random()
{
    
    srand( static_cast<unsigned int>(time(NULL)));   //Explicitly casts the time into an unsigned int var.
    
    
    rr=rand()%2;
    
}







/************************************************************************************/
//  getReady....Fight:  This function loops between attack and defense of two creatuers
//untill one creature is out of strength points
/************************************************************************************/

void battleField::getReady(creature*& a, creature*& b)
{
  
    
    std::cout << "Initital Strength of #1" << a->getName() << " is " << a->getStrength() <<std::endl;
    std::cout << "Initital Strength of #2" << b->getName() << " is " << b->getStrength() <<std::endl;
    
    std::cout << a->getName();
    std::cout << " was quick, and is the first to attack!\n\n";
    death=false;
    
    
    do
    {
        std::cin.clear();
        std::cin.ignore(100, '\n');
        
        a->attack();
        b->defense();
        
        std::cout << b->getName()<< "#1 has " << b->getStrength();
        std::cout<< " strength remaining!\n\n";
        
        if(b->getStrength() <= 0)
        {
            death=true;
            loser=0;
        }
        
        if(death!=true)  // Will stop for death or exit with cont() placement here outside of next if statement
        {
        cont();
        }
        
        if(death!=true&&exit2!=true) //Stops from executing if death occured
        {
            
            
            
            
            b->attack();
            a->defense();
            
            std::cout << a->getName()<< "#2 has " << a->getStrength();
            std::cout<< " strength remaining!\n\n";
            
            
            
            
            if(a->getStrength() <= 0)
            {
                death=true;
                loser=1;
            }
            
            if(death!=true)
            {
                std::cin.clear();
                std::cin.ignore(100, '\n');
            cont();
            }
        }
        
        
    }while(death==false&&exit2==false);
    
    
    
    
    
}






/************************************************************************************/
//  Asks user if they wish to continue, takes input from user
/************************************************************************************/

void battleField::cont()
{
    std::cout<< "Next move?";
    std::cout << "   1. Yes";
    std::cout << "   2. Exit";
    
    
    
    do{
        std::cout << "      Selction:";
        std::cin >> choice;
        
        if (std::cin.fail()|| (choice < 1 || choice > 2))
        {
            std::cout << "Please enter a number 1 or 2\n";
            exit=false;
            std::cin.clear();
            std::cin.ignore(100, '\n');
        }
        
        else{
            exit=true;
        }
    }while(exit==false);
    
    
    
    
    std::cout << std::endl;
    
    
    if (choice==2)  //Add New Item
    {
        exit2=true;
        again=false;
        
    }
    
    
    
}


/************************************************************************************/
// Discovers if someone has died (note user may exit battle without someone dying first)
// Then displays who has died  Also, asks user if they wish to play again.
/************************************************************************************/

void battleField::getDeath(creature *&a, creature *&b)
{
    
    
    if(death==true&&a->getStrength()<=0)
    {
        
        std::cout<<  a->getName() << " has Fallen!\n";
        
    }
    
    if(death==true&&b->getStrength()<=0)
    {
        
        std::cout<<  b->getName() << " has Fallen!\n";
        
    }
    
    
    
    
    std::cout<< "Play again?";
    std::cout << "   1. Yes";
    std::cout << "   2. Exit";
    
    
    
    do{
        std::cout << "      Selction:";
        std::cin >> choice;
        
        if (std::cin.fail()|| (choice < 1 || choice > 2))
        {
            std::cout << "Please enter a number 1 or 2\n";
            exit=false;
            std::cin.clear();
            std::cin.ignore(100, '\n');
        }
        
        else{
            exit=true;
        }
    }while(exit==false);
    
    
    
    
    std::cout << std::endl;
    
    
    if (choice==1)  //Add New Item
    {
        again=true;
        
    }

    
    if (choice==2)  //Add New Item
    {
        again=false;
        
    }
    
    
    
}

























