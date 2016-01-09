/*<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
 The file loaded.h is the specification file for the loaded.cpp file/class.
 <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>*/

#ifndef __Polytron__creature__
#define __Polytron__creature__


#include <string>



class creature{
    
public:
    creature( std::string, int, int);
    
    void attack();
    void defense();
    
    int getArmor();
    int getStrength ();
    std::string getName();
    
    std::string getPerson();
    std::string getTeam();
    int getpoints();
    
    
    void setnameteam(std::string,std::string);
    void setpoints(int);
    void setrestore();
    
    int rollSix ();
    int rollTen();
    
    virtual int damage ()=0;
    virtual int defend()=0;
    virtual void sayItatk()=0;
    virtual void sayItdef()=0;
    
    static void reSetGoblin();
    

    
 

    
private:
    
    std::string name;
    std::string person;
    std::string team;
    int armor;
    int strength;
    int attk;
    int initstr;
    int points;
    bool tag;
    
    
    
protected:
    static int damg;
    static int goblin;
    int defn;
    
    
    
    
    
};

#endif /* defined(__Polytron__creature__) */
