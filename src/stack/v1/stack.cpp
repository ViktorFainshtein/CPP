
#include "stack.hpp"
namespace ilrd
{

void Stack::StackCreate(int capacity)
{
    m_arr = new int[capacity];
    m_size = 0;
    m_capacity = capacity;
}

void Stack::StackDestroy()
{
    delete[] m_arr;
    m_size = 0;
    m_capacity = 0;
}

void Stack::StackPush(int value)
{
    *(m_arr + m_size) = value;
    ++m_size;
}
void Stack::StackPop()
{
    --m_size;
}
int Stack::StackPeek()
{
    return *(m_arr+m_size-1);
}
int Stack::StackSize()
{
    return m_size;
}

}//namespace