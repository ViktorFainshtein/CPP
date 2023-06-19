
#ifndef __STACK_HPP__
#define __STACK_HPP__

#include <cstddef> //size_t//

namespace ilrd
{

class Stack
{
private:
    int *m_arr;
    size_t m_size;
    size_t m_capacity;
public:
    explicit Stack(size_t capacity = 10);   //CTOR
    ~Stack();                               //DROT
    void StackPush(int);
    void StackPop();
    int StackPeek();
    size_t StackSize();
};

}//namespace
#endif

