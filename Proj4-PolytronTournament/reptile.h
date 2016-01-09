/*<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
 The file reptile.h is the specification file for the reptile.cpp file/class.
 <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>*/

#ifndef __Polytron__reptile__
#define __Polytron__reptile__



#include "creature.h"


class reptile :public creature
{
    
public:
    reptile();
    virtual int damage ();
    virtual int defend ();
    virtual void sayItatk();
    virtual void sayItdef();
    
private:
    
    int rolls;
    int def;
    
    
};


















#endif /* defined(__Polytron__reptile__) */
