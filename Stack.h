#ifndef STACK_H
#define STACK_H


class Stack
{

public:
    Stack();
    Stack(const Stack& aStack);
    ~Stack();
    bool isEmpty() const;
    bool push(char newItem);
    bool push(double newItem);
    bool pop();
    bool pop(char& stackTop);
    bool pop(double& stackTop);
    bool getTop(char& stackTop) const;
    bool getTop(double& stackTop) const;
    int getItemCount() const;
private:
    struct StackNode
    {
        char cItem;
        double dItem;
        StackNode    *next;
    };

    StackNode *topPtr;
    int itemCount;
};
#endif
