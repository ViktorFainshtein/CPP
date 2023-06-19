
#ifndef __STACK_HPP__
#define __STACK_HPP__

#include <cstddef> //size_t//

namespace ilrd
{

class Stack
{
public:
    explicit Stack(size_t capacity = 10);
    Stack(const Stack& other_);
    ~Stack();
    void StackPush(int);
    void StackPop();
    int StackPeek()const;
    size_t StackSize()const;
private:
    size_t m_size;
    size_t m_capacity;
    int *m_arr;
};

}//namespace
#endif

