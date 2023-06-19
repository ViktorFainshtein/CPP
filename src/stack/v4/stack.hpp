
#ifndef __STACK_HPP__
#define __STACK_HPP__

#include <iostream> // operator<< //
#include <cstddef> // size_t //

namespace ilrd
{

class Stack
{
public:
    explicit Stack(const size_t capacity = 10);
    Stack(const Stack& other_);
    ~Stack();
    void StackPush(const int);
    void StackPop();
    int StackPeek() const;
    size_t StackSize() const;
private:
    friend Stack& operator<<(Stack& ,int);
    friend void operator>>(Stack ,int&);
    friend Stack& operator--(Stack&);
    size_t m_size;
    size_t m_capacity;
    int *m_arr;

};

}//namespace
#endif


