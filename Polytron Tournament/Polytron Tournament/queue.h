/*<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
 The file queue.h  is the specification file for the queue.cpp file/class.
 <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>*/

#ifndef __LabF__queue__
#define __LabF__queue__

#include <cstddef>
#include "creature.h"
#include <string>

class creatque
{
    
protected:
    
     struct QueNode{
        
        QueNode(creature* killer, QueNode *next1=NULL)
        {
            this->killer=killer;
            next=next1;
        }
        
        creature* killer;
        QueNode *next;
        
    };
    
    
    QueNode *front;
    QueNode *end;
    int count;
    
public:
    creatque();
    void addBack(creature*);
    creature* getFront();
    void removeFront();
    bool isEmpty();
 
    void recursion(creatque);
};

#endif /* defined(__LabF__queue__) */
