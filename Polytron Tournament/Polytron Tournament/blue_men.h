/*<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
 The file blue_men.h  is the specification file for the blue_men.cpp file/class.
 <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>*/

#ifndef __Polytron__blue_men__
#define __Polytron__blue_men__

#include "creature.h"

class blue_men :public creature
{
    
public:
    blue_men();
    virtual int damage ();
    virtual int defend ();
    virtual void sayItatk();
    virtual void sayItdef();
    
private:
    
    int rolls;
    int def;
    
    
};

#endif /* defined(__Polytron__blue_men__) */
