#include "Stack.h"
#include <iostream>
using namespace std;


Stack::Stack()
{
    topPtr = NULL;
    itemCount = 0;
}

Stack::~Stack()
{
    while (!isEmpty())
        pop();
}


Stack::Stack(const Stack& aStack)
{
    if (aStack.topPtr == NULL)
    {
        topPtr = NULL;
    }
    else
    {
        topPtr = new StackNode;
        topPtr->cItem = aStack.topPtr->cItem;
        topPtr->dItem = aStack.topPtr->dItem;
        StackNode *newPtr = topPtr;
        for (StackNode *origPtr = aStack.topPtr->next; origPtr != NULL; origPtr = origPtr->next)
        {
            newPtr->next = new StackNode;
            newPtr = newPtr->next;
            newPtr->cItem = origPtr->cItem;
            newPtr->dItem = origPtr->dItem;
        }
        newPtr->next = NULL;
    }
}
bool Stack::isEmpty() const
{
    return topPtr == NULL;

}

bool Stack::push(char newItem)
{
    StackNode *newPtr = new StackNode;
    newPtr->cItem = newItem;
    newPtr->next = topPtr;
    topPtr = newPtr;
    itemCount++;
    return true;
}
bool Stack::push(double newItem)
{
    StackNode *newPtr = new StackNode;
    newPtr->dItem = newItem;
    newPtr->next = topPtr;
    topPtr = newPtr;
    itemCount++;
    return true;
}

bool Stack::pop()
{

    if (isEmpty())
    {
        return false;
    }
    else
    {
        StackNode *temp = topPtr;
        topPtr = topPtr->next;
        temp->next = NULL;
        delete temp;
        itemCount--;
        return true;
    }
}


bool Stack::pop(char& stackTop)
{
    if (isEmpty())
    {
        return false;
    }
    else
    {
        stackTop = topPtr->cItem;
        StackNode *temp = topPtr;
        topPtr = topPtr->next;
        temp->next = NULL;
        delete temp;
        itemCount--;
        return true;
    }
}


bool Stack::pop(double& stackTop)
{
    if (isEmpty())
    {
        return false;
    }
    else
    {
        stackTop = topPtr->dItem;
        StackNode *temp = topPtr;
        topPtr = topPtr->next;
        temp->next = NULL;
        delete temp;
        itemCount--;
        return true;
    }
}

bool Stack::getTop(char& stackTop) const
{
    if (isEmpty())
    {
        return false;
    }
    else
    {
        stackTop = topPtr->cItem;
        return true;
    }

}


bool Stack::getTop(double& stackTop) const
{
    if (isEmpty())
    {
        return false;
    }
    else
    {
        stackTop = topPtr->dItem;
        return true;
    }

}

int Stack::getItemCount() const
{

    return itemCount;
}



