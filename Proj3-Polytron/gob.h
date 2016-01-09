/*<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
 The file gob.h is the specification file for the gob.cpp file/class.
 <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>*/

#ifndef __Polytron__gob__
#define __Polytron__gob__

#include "creature.h"


class gob :public creature
{
    
public:
    gob();
    virtual int damage ();
    virtual int defend ();
    virtual void sayItatk();
    virtual void sayItdef();
    
private:
    
    int rolls;
    int def;
    
    
};

#endif /* defined(__Polytron__gob__) */
