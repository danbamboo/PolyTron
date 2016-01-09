/************************************************************************************
 Class Name: Battle Field
 Author: Danny McMurrough
 Date: 8/8/2015
 Description: Composition of 5 creaturs.
 Input: User set up who battles whom.
 Output: Winner and loser of battle.
 ************************************************************************************/

#include "battleField.h"
#include <iostream>
#include <ctime>
#include <cstddef>




battleField::battleField():
exit2(false), exit3(false), points(0), count(0), round(0), team1p(0), team2p(0)
{
    
    mainMenu();
    
    
}



/************************************************************************************/
//  Acts as main menu for the program.  Will loop as long as user wants to keep playing
/************************************************************************************/
void battleField::mainMenu()
{
    std::srand( static_cast<unsigned int>(time(NULL)));  //Gives random feed
    std::cout << "»»»»»»»»»»»»»»»»»»»»»»»»»»»»»» ± ««««««««««««««««««««««««««««««««\n";
    std::cout << "\t±±±±±  ±±±±±  ±      ±   ±  ±±±±±  ±±±±±   ±±±±±  ±     ± \n";
    std::cout << "\t±   ±  ±   ±  ±      ±   ±    ±    ±   ±   ±   ±  ± ±   ± \n";
    std::cout << "\t±±±±±  ±   ±  ±      ±±±±±    ±    ±±±±±   ±   ±  ±  ±  ± \n";
    std::cout << "\t±      ±   ±  ±          ±    ±    ± ±     ±   ±  ±   ± ± \n";
    std::cout << "\t±      ±   ±  ±          ±    ±    ±  ±    ±   ±  ±    ±± \n";
    std::cout << "\t±      ±±±±±  ±±±±±  ±±±±±    ±    ±   ±   ±±±±±  ±     ± \n";
    std::cout << "»»»»»»»»»»»»»»»»»»»»»»»»»»»»»» ± ««««««««««««««««««««««««««««««««\n\n\n";
    
    std::cout << "\tWelcome to the world of PolyTron!\n";
    std::cout << "\tYou have signed up for the tournament, where champions are born.\n";
    std::cout << "\tTwo teams will select a certain number of creatures, and battle tournament style.\n";
    
    t1name="Team 1";
    t2name="Team 2";
    int randomstart=0;
    
    
    
    
    do{
        std::cout << "\tHow many creatures do you wish to allow in you're lineup (1-15)\n\n";
        
        how_many();         //  Choose how many in lineup.
        choose(t1name);     // Team one creature selections
        choose(t2name);     // Team two creature selections
        
        
        
        do{
            
            randomstart=rand()%2+1;
            
            if(randomstart==1)
            {
            fighter=team1.getFront();         // Get the front of the queue for team 1
            fighter2=team2.getFront();        //  Get the front of the queue for team 2
            }
            
            else if(randomstart==2)
            {
                fighter2=team1.getFront();         // Get the front of the queue for team 1
                fighter=team2.getFront();        //  Get the front of the queue for team 2
            }
            
            getReady(fighter, fighter2);      //  Fight
            getDeath(fighter, fighter2);      // Round results ++Recovery++ -- winner?
            
            
            
        }while (exit3==false);
        
        displaystats();   // Game is over, what are the stats?
        onceagain();      // Do you want to play again?
        reset();         // Reset variables for new round.
        
    }while(again==true);
}



/************************************************************************************/
// Allows user to select, from 1 to 15, how many creatures will be allowed in a lineup.
/************************************************************************************/


void battleField::how_many()
{
    
    do{
        std::cout << "Selction:";
        std::cin >> count;
        
        if (std::cin.fail()|| (count < 1 || count > 15))
        {
            std::cout << "Please enter a number 1-15\n";
            exit=false;
            std::cin.clear();
            std::cin.ignore(100, '\n');
        }
        else{
            exit=true;
        }
    }while(exit==false);
    
    twocount=count*2;  // twocount allows us to determine how many total creatures there are.
                        // Allows for dynamic array creatarr
    
}



/************************************************************************************/
// Choose all creatures in the lineup, give um' a name too.
/************************************************************************************/
void battleField::choose(std::string s)
{
    std::cout<< "Now " << s << " will select their creatures.\n";
    std::cout<< "Please give each creature a name, they have feelings!\n\n";
    for(unsigned int x=0; x < count; x++)
    {
        
        std::cout << "Choose Creature# " << x+1 << "\n\n";
        
        std::cout << "1. Reptilian\n";
        std::cout << "2. Barbarian\n";
        std::cout << "3. Goblin\n";
        std::cout << "4. The Shadow\n";
        std::cout << "5. Blue Man\n";
        
        
        
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
        
        
        std::cin.clear();
        std::cin.ignore(100, '\n');
        
        do{
            std::cout << "Creature's name? ";
            std::getline(std::cin,name);
            
            if (std::cin.fail())
            {
                std::cout << "Please enter a valid name.";
                exit=false;
                std::cin.clear();
                std::cin.ignore(100, '\n');
            }
            else{
                exit=true;
            }
        }while(exit==false);
        
        
        
        /************************************************************************************/
        //  Here we cast creatures into the base class dynamically based on user input
        /************************************************************************************/
        std::cout << std::endl;
        
        if (choice==1)  //Add New Item
        {
            fighter= new reptile;
            
            
        }
        if (choice==2)  //Add New Item
        {
            fighter= new barb;
            
            
        }
        if (choice==3)  //Add New Item
        {
            
            fighter= new gob;
            
        }
        if (choice==4)  //Add New Item
        {
            fighter= new shadow;
            
            
        }
        if (choice==5)  //Add New Item
        {
            
            fighter= new blue_men;
            
        }
        
        
        
        fighter->setnameteam(name, s);
        
        if(s=="Team 1")  //Decides which queue to store creatures in.
        {
            team1.addBack(fighter);
            
            
        }
        if(s=="Team 2")
        {
            team2.addBack(fighter);
            
            
        }
        
        
        
        
    }
    
}



/************************************************************************************/
//  getReady....Fight:  This function loops between attack and defense of two creatuers
//untill one creature is out of strength points
/************************************************************************************/

void battleField::getReady(creature*& a, creature*& b)
{
    
    
    if(exit2!=true)
    {
    
    
    round++;
    std::cout << "»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»  Round "<< round
                << " ««««««««««««««««««««««««««««««««\n\n";
    
        
    std::cout << a->getTeam() << " was quick and is the first to attack!!\n\n";
        
    std::cout << "                     " << a->getTeam();
    std::cout << ": Initital Strength of " << a->getPerson() << " the " << a->getName()    //Displays starting strength of both creatures.
    << " is " << a->getStrength() <<std::endl;
    std::cout << "                     " << b->getTeam();
    std::cout << ": Initital Strength of " << b->getPerson() << " the " << b->getName()
        << " is " << b->getStrength() <<std::endl<<std::endl;
    
    death=false;
    
    do
    {
        std::cout << "»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»   "<<  a->getPerson() << " the "
                    <<  a->getName() << " ATTACKS..\n";
        
        
        a->attack();
        
        std::cout << "»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»   "<<  b->getPerson() << " the "
        <<  b->getName() << " DEFENDS..\n";
        
        
        b->defense();
        
        
        
        std::cout << b->getPerson()<< " the " << b->getName()<<" for " << b->getTeam()<< " has "
        << b->getStrength();
        std::cout<< " strength remaining!\n";
        std::cout << "==========================================\n\n";
        
        
    
        
        
        
        
        if(b->getStrength() <= 0)
        {
            death=true;
            
            
            loser=1;
            
        }
        
        if(death!=true)  // Will stop for death or exit with cont() placement here outside of next if statement
        {
            cont();
            
        }
        
        if(death!=true&&exit2!=true) //Stops from executing if death occured
        {
            
            
            std::cout << "»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»   "<<  b->getPerson() << " the "
                     <<  b->getName() << " ATTACKS..\n";
            
            b->attack();
            
            std::cout << "»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»   "<<  a->getPerson() << " the "
            <<  a->getName() << " DEFENDS..\n";
            
            a->defense();
            
            std::cout << a->getPerson()<< " the " << a->getName()<<" for " << a->getTeam()<< " has "
            << a->getStrength();
            std::cout<< " strength remaining!\n";
            std::cout << "==========================================\n\n";
            

            
            
            if(a->getStrength() <= 0)
            {
                death=true;
                loser=2;
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
    
    
    if (choice==2)
    {
        exit2=true;
        again=false;
        
    }
    
    
    
}


/************************************************************************************/
// Discovers if someone has died (note user may exit battle without someone dying first)
/************************************************************************************/

void battleField::getDeath(creature *&a, creature *&b)
{
    
    
    death=false;
    
    if (exit2==false)  // Will bypass if user wants to end session.
    {
        
        
        
        
        if(loser==1)
        {
            a->reSetGoblin();
            std::cout << "MATCH OVER: " << b->getPerson() << " the " << b->getName() << " from "
            << b->getTeam()<< " has been defeated by ";
            
            std::cout <<  a->getPerson() << " the " << a->getName() << " from "
            << a->getTeam()<< "\n";
            
            
            
            getpoints(a, b);        //Gets the pointer for winner a
            std::cout << "**" << points << "**" << " points earned for " << a->getTeam() << " and player "
                    << a->getPerson()
            << std::endl << std::endl;
            
            
            a->setpoints(points);  //Sets points for player
            a->setrestore();       //Preforms restore function of winner a
            
            
            if(a->getTeam()=="Team 1")
            {
            team1p+=points;         //Sets points for team1
            team1.addBack(a);   //adds winner to the back of a
            team1.removeFront();  //removes (old)a from the front.
            team2.removeFront();
            }
            
            if(a->getTeam()=="Team 2")
            {
                team2p+=points;         //Sets points for team1
                team2.addBack(a);   //adds winner to the back of a
                team2.removeFront();  //removes (old)a from the front.
                team1.removeFront();
            }
            
            
            
            loserpile.push(b); // the loser b is added to loser pile!
            
            
            
            
        }
        
        if(loser==2)
        {
            a->reSetGoblin();
            
            std::cout << "MATCH OVER: " << a->getPerson() << " the " << a->getName() << " from "
            << a->getTeam()<< " has been defeated by ";
            
            std::cout <<  b->getPerson() << " the " << b->getName() << " from "
            << b->getTeam()<< "\n";
            
            
            getpoints(b, a);        //Gets the pointer for winner a
            std::cout << "**" << points << "**" << " points earned for " << b->getTeam() << " and player "
                                << b->getPerson() << std::endl;
            
            b->setpoints(points);  //Sets points for player
            b->setrestore();       //Preforms restore function of winner a
            
            
            if(b->getTeam()=="Team 1")
            {
                team1p+=points;         //Sets points for team1
                team1.addBack(b);   //adds winner to the back of a
                team1.removeFront();  //removes (old)a from the front.
                team2.removeFront();
            }
            
            if(b->getTeam()=="Team 2")
            {
                team2p+=points;         //Sets points for team1
                team2.addBack(b);   //adds winner to the back of a
                team2.removeFront();  //removes (old)a from the front.
                team1.removeFront();
            }
            
            
            
            loserpile.push(a); // the loser b is added to loser pile!
        }
        
        
    }
    
    if(exit2==true)
    {
        exit3=true;
    }
    
    else if(team1.isEmpty() || team2.isEmpty() )
    {
        exit3=true;
        
        std::cout << "»»»»»»»»»»»»»»»»»»»»»»»»»»»»»»  The Tournament had ended!!  ««««««««««««««««««««««««««\n\n";
        
    }
    
    else{
        
        
        std::cout << "<<>>NEW TEAM 1 LINEUP: \n";  // Following recursive functions display's lineup after match of each team
                                                  //  Also displays the loser pile (stack)
        team1.recursion(team1);
        std::cout << "<<>>NEW TEAM 2 LINEUP: \n";
        team2.recursion(team2);
        std::cout << "Loser Pile (stack): \n";
        loserpile.recursion(loserpile);
        
        
        cont();
    }
    
    
}






/************************************************************************************/
// Play again?
/************************************************************************************/


void battleField::onceagain(){
    
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











/************************************************************************************/
// Determines the amount of points at the end of a match.  Points given to team and individual winner.
// Loser gets no points.  See Document for how point values were calulated.
/************************************************************************************/
void battleField::getpoints(creature *&a, creature *&b)
{
    
    cr1=a->getName();  //creature a will be the winner always.
    cr2=b->getName();
    
    
    /************************************************************************************/
    // Similar creature vs each other.
    /************************************************************************************/
    if(cr1=="Barbarian" && cr2=="Barbarian")
    {
        points=35;
        
    }
    
    if(cr1=="Blue Man" && cr2=="Blue Man")
    {
        points=35;
        
    }
    if(cr1=="Goblin" && cr2=="Goblin")
    {
        points=35;
        
    }
    if(cr1=="Reptilian" && cr2=="Reptilian")
    {
        points=35;
        
    }
    if(cr1=="The Shadow" && cr2=="The Shadow")
    {
        points=35;
        
    }
    
    
    
    /************************************************************************************/
    //  Barbarian winner against 4 different oppontents
    /************************************************************************************/
    if(cr1=="Barbarian" && cr2=="Blue Man")
    {
        points=60;
        
    }
    if(cr1=="Barbarian" && cr2=="Goblin")
    {
        points=30;
        
    }
    if(cr1=="Barbarian" && cr2=="Reptilian")
    {
        points=60;
        
    }
    if(cr1=="Barbarian" && cr2=="The Shadow")
    {
        points=60;
        
    }
    /************************************************************************************/
    //  Blue Man winner against 4 different oppontents
    /************************************************************************************/
    if(cr1=="Blue Man" && cr2=="Barbarian")
    {
        points=10;
        
    }
    if(cr1=="Blue Man" && cr2=="Goblin")
    {
        points=10;
        
    }
    if(cr1=="Blue Man" && cr2=="Reptilian")
    {
        points=15;
        
    }
    if(cr1=="Blue Man" && cr2=="The Shadow")
    {
        points=20;
        
    }
    
    /************************************************************************************/
    //  Goblin winner against 4 different oppontents
    /************************************************************************************/
    
    if(cr1=="Goblin" && cr2=="Barbarian")
    {
        points=40;
        
    }
    if(cr1=="Goblin" && cr2=="Blue Man")
    {
        points=60;
        
    }
    if(cr1=="Goblin" && cr2=="Reptilian")
    {
        points=60;
        
    }
    if(cr1=="Goblin" && cr2=="The Shadow")
    {
        points=60;
        
    }
    
    /************************************************************************************/
    //  Reptilian winner against 4 different oppontents
    /************************************************************************************/
    
    if(cr1=="Reptilian" && cr2=="Barbarian")
    {
        points=10;
        
    }
    if(cr1=="Reptilian" && cr2=="Goblin")
    {
        points=10;
        
    }
    if(cr1=="Reptilian" && cr2=="Blue Man")
    {
        points=55;
        
    }
    if(cr1=="Reptilian" && cr2=="The Shadow")
    {
        points=10;
        
    }
    
    /************************************************************************************/
    //  The Shadow winner against 4 different oppontents
    /************************************************************************************/
    
    if(cr1=="The Shadow" && cr2=="Reptilian")
    {
        points=60;
        
    }
    if(cr1=="The Shadow" && cr2=="Blue Man")
    {
        points=50;
        
    }
    if(cr1=="The Shadow" && cr2=="Goblin")
    {
        points=10;
        
    }
    if(cr1=="The Shadow" && cr2=="Barbarian")
    {
        points=10;
        
    }
    
    
    
    
    
    
}


/************************************************************************************/
// Resets variables for user to play again.
/************************************************************************************/

void battleField::reset()
{
    
    exit3=false;
    exit2=false;
    team1p=0;
    team2p=0;
    round=0;
    
    
    
}


/************************************************************************************/
// Displays team winner's and a ranking of all creatures.
/************************************************************************************/
void battleField::displaystats()
{
    
    if (team1p > team2p)
    {
        std::cout << " [] [] [] [] [] [] [] [] [] [] Team one wins!  [] [] [] [] [] [] [] [] [] []\n\n";
    }
    
    if (team1p < team2p)
    {
        std::cout << " [] [] [] [] [] [] [] [] [] [] Team two wins!  [] [] [] [] [] [] [] [] [] []\n\n";
    }
    if (team1p == team2p)
    {
        std::cout << " [] [] [] [] [] [] [] [] [] [] It was a tie!  [] [] [] [] [] [] [] [] [] []\n\n";
    }
    
    
    std::cout << "The final team scores were: \n";
    std::cout << "Team 1: " << team1p << std::endl;
    std::cout << "Team 2: " << team2p << std::endl << std::endl;
    
    std::cout << "The individual player rankings are as so:\n\n";
    
    
    creatarr= new creature*[twocount];
    
    int inc=0;
    while(!team1.isEmpty())
    {
        creatarr[inc]=team1.getFront();
        team1.removeFront();
        inc++;
        
    }
    while(!team2.isEmpty())
    {
        creatarr[inc]=team2.getFront();
        team2.removeFront();
        inc++;
        
    }
    while(!loserpile.isEmpty())
    {
        creatarr[inc]=loserpile.peek();
        loserpile.pop();
        inc++;
    }
    
    
    
    selectionSort();
    
    
    for (unsigned int x=0; x < twocount; x++)
    {
        
        std::cout << "#"<< x+1 << " : " << creatarr[x]->getPerson() << " the " << creatarr[x]->getName()
        << " from " << creatarr[x]->getTeam() << " had "
        << creatarr[x]->getpoints() << " points!" <<std::endl;
        
        
        
    }
    std::cout << std::endl;
 
    delete[] creatarr;     //Dekete dynamic array
    
}





/************************************************************************************/
// Using seclection sort, the creatures are sorted in terms of points after tourney has ended.
/************************************************************************************/

void battleField::selectionSort ()
{
    int swap=0;
    int place=0;
    for(unsigned int x=0; x< twocount; x++)
    {
        temp1=creatarr[x];
        temp2=creatarr[x];
        
        for(unsigned int y=x+1; y < twocount; y++)
        {
            
            if((temp1->getpoints() < creatarr[y]->getpoints())&& (creatarr[y]->getpoints() > temp2->getpoints()))
            {
                temp2=creatarr[y];
                place=y;
                swap++;
                
            }
            
           
            
        }
        
        if(swap >0)
        {
            creatarr[x]=temp2;
            creatarr[place]=temp1;
            
        }
        
        swap=0;
        
    }
}







