/*<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
 The file barb.h is the specification file for the barb.cpp file/class.
 <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>*/

#ifndef __Polytron__barb__
#define __Polytron__barb__

#include "creature.h"


class barb :public creature
{
    
public:
    barb();
    virtual int damage ();
    virtual int defend ();
    virtual void sayItatk();
    virtual void sayItdef();
    
private:
    
    int rolls;
    int def;
    
    
};



#endif /* defined(__Polytron__barb__) */
