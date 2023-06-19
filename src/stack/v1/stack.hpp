
#ifndef __STACK_HPP__
#define __STACK_HPP__

namespace ilrd
{

class Stack
{
private:
    int *m_arr;
    int m_size;
    int m_capacity;
public:
    void StackCreate(int);
    void StackDestroy();
    void StackPush(int);
    void StackPop();
    int StackPeek();
    int StackSize();
};

}//namespace
#endif