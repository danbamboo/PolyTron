/*<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
 The file shadow.h  is the specification file for the shadow.cpp file/class.
 <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>*/

#ifndef __Polytron__shadow__
#define __Polytron__shadow__


#include "creature.h"

class shadow :public creature
{
    
public:
    shadow();
    virtual int damage ();
    virtual int defend ();
    virtual void sayItatk();
    virtual void sayItdef();
    
private:
    
    int rolls;
    int def;
    
    
};

#endif /* defined(__Polytron__shadow__) */
