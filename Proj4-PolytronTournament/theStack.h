/*<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
 The file theStack.h  is the specification file for the theStack.cpp file/class.
 <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>*/

#ifndef __LabF__theStack__
#define __LabF__theStack__

#include <cstddef>
#include "creature.h"



class creatstk
{
    
protected:
    
    struct listNode{
        creature *loser;
        listNode *next;
        listNode(creature *loser, listNode *next1=NULL)
        {
            this->loser=loser;
            next=next1;
            
        }
        
        
        
    };
    
    
    listNode *top;
    int count;
    
    
public:
    creatstk();
    void push(creature*);
    creature* peek();
    void pop();
    bool isEmpty();
    
    void peekPast();

    void recursion(creatstk c);
};








#endif /* defined(__LabF__theStack__) */
