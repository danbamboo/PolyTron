/************************************************************************************
 Class Filename: theStack.cpp
 Author: Danny McMurrough
 Date: 8/8/2015
 Description: Class that acts as an stack ABT.
 Input: Intgers.
 Output: Integers from stack.
 ************************************************************************************/

#include "theStack.h"
#include <iostream>




creatstk::creatstk(): count(1)
{
    top=NULL;
}




/************************************************************************************/
// Adds creature to the stack.
/************************************************************************************/
void creatstk::push(creature* a){
    
    top= new listNode(a, top);  // This works because the equation reads right to left
    
}






/************************************************************************************/
//Peek, or display if the top is not NULL
/************************************************************************************/
creature* creatstk::peek()
{
    
    if(top!=NULL)
    {
        return top->listNode::loser;
    }
    
    else
    {
        
        std::cout << "No values in list!\n";
        return 0;
    }
}






/************************************************************************************/
// Pop or remove item and delete dynamic variables.
/************************************************************************************/
void creatstk::pop()
{
    listNode *temp;
    
    if(isEmpty())
    {
        std::cout<< "List is empty!\n";
    }
    
    else{
        
        temp = top;
        top= top->next;
        delete temp;
        
        
        
    }
    
    
}




/************************************************************************************/
// Checks to see if stack is empty
/************************************************************************************/
bool creatstk::isEmpty()
{
    
    if(!top)
    {
        return true;
    }
    
    else{
        return false;
    }
    
    
}

/************************************************************************************/
// Uses recursion to print out all creatures in the stack.
/************************************************************************************/
void creatstk::recursion(creatstk c)
{
    
    if(c.top->next==NULL)
    {
        std::cout << "#" << count << " ";
        std::cout << c.top->listNode::loser->getPerson() << " the "
        <<c.top->listNode::loser->getName() << std::endl;
        count=1;
        return;
    }
    else
    {
        std::cout << "#" << count << " ";
        count++;
        std::cout << c.top->listNode::loser->getPerson() << " the "
        <<c.top->listNode::loser->getName() << std::endl;
        c.top=c.top->next;
        recursion(c);
    }
    
    
    
}


