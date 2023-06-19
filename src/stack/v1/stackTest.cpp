#include <iostream>
#include "stack.hpp"



int main()
{
    ilrd::Stack s1;
    s1.StackCreate(10);

    for(int i = 0; i < 10; ++i)
    {
        s1.StackPush(i);
    }

    std::cout << "stack size after push:" << s1.StackSize() << std::endl;

    int temp = 0;
    for(int i = 0; i < 10; ++i)
    {
        temp = s1.StackPeek();
        s1.StackPop();
        std::cout << "temp:" << temp << std::endl;
    }

    std::cout << "stack size after pop:" << s1.StackSize() << std::endl;

    return 0;
}