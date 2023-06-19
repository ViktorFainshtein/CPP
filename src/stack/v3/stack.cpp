#include "stack.hpp"

namespace ilrd
{

Stack::Stack(size_t capacity): m_size(0), m_capacity(capacity), m_arr(new int[capacity]){;}

Stack::Stack(const Stack& other_): m_size(other_.m_size), m_capacity(other_.m_capacity), m_arr(new int[m_capacity])
{
    for (size_t i = 0; i < m_capacity; i++)
    {
        m_arr[i] = other_.m_arr[i];
    }
}

Stack::~Stack()
{
    delete[] m_arr;
    m_capacity = 0;
    m_size = 0;
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
int Stack::StackPeek()const
{
    return *(m_arr+m_size-1);
}
size_t Stack::StackSize()const
{
    return m_size;
}

}//namespace