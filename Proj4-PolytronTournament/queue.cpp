/************************************************************************************
 Class name: queue
 Author: Danny McMurrough
 Date: 8/8/2015
 Description: Puts int values in linked list in first-in, first-out fashion
 Input: Intgers.
 Output: Enqueue and Dequeue.
 ************************************************************************************/

#include "queue.h"
#include <iostream>



creatque::creatque(): count(1)
{
    front=NULL;
    end=NULL;
    
    
}








/************************************************************************************/
//  addBack works by first setting front to first value, that points to a null pointer.
//  End is then set to the address of front, and sequential additions are added on top of end.
/************************************************************************************/
void creatque::addBack(creature *fighter)
{
    if(isEmpty())
    {
        
        front = new QueNode(fighter);
        end=front;
    }
    
    else{
        end->next = new QueNode(fighter);
        end=end->next;
        
    }
    
    
}


/************************************************************************************/
// If front is not empty, then the value of the front is displayed.
/************************************************************************************/
creature* creatque::getFront()
{
    
    
    if(front!=NULL){
        return front->QueNode::killer;}
    else{
        std::cout<< "Empty Queue!\n";
        return 0;
    }
}

//return front->QueNode::killer->getStrength();


/************************************************************************************/
// Dequeues the item in the front while front is not empty.
/************************************************************************************/

void  creatque::removeFront()
{
    
    
    if (isEmpty()==false)
    {
        
        
        QueNode *temp;
        temp=front;
        
        
        
        if(front->next!=NULL)
        {
            front=front->next;
            delete temp;
            
        }
        else
        {
            front=NULL;  // When front is the last value, set to Null
        }
        
        
    }
    
    else
    {
        std::cout << "No values to remove!\n";
    }
}


// Checks for empty linked list.
bool creatque::isEmpty()
{
    if(front==NULL)
    {
        return true;
    }
    
    else{
        return false;
    }
    
    
}


/************************************************************************************/
// Uses recursion to print out all creatures in the queue.
/************************************************************************************/
void creatque::recursion(creatque c)
{
    
    if(c.front->next==NULL)
    {
        std::cout << "#" << count << " ";
        std::cout << c.front->QueNode::killer->getPerson() << " the "
        <<c.front->QueNode::killer->getName() << std::endl;
        count=1;
        return;
    }
    else
    {
        std::cout << "#" << count << " ";
        count++;
        std::cout << c.front->QueNode::killer->getPerson() << " the "
        <<c.front->QueNode::killer->getName() << std::endl;
        c.front=c.front->next;
        recursion(c);
    }
    
    
    
}









