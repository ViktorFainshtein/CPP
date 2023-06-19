#include <iostream>
#include "stack.hpp"

//before fix:
size_t GetSize(ilrd::Stack s)
{
    return s.StackSize();
}
//after fix:
/* size_t GetSize(ilrd::Stack &s)
{
    return s.StackSize();
} */

int main()
{
    ilrd::Stack s_empty;
    ilrd::Stack s1(10);

    for(int i = 0; i < 10; ++i)
    {
        s1.StackPush(i);
        
    }

    for (int i = 0; i < 10; i++)
    {
        s_empty.StackPush(i);
    }
    

    std::cout << "stack size after push:" << s1.StackSize() << std::endl;
    std::cout << "stack poping for s1:" << std::endl;
    int temp = 0;
    for(int i = 0; i < 10; ++i)
    {
        temp = s1.StackPeek();
        s1.StackPop();
        std::cout << "temp:" << temp << std::endl;
    }

    std::cout << "stack size after pop:" << s1.StackSize() << std::endl;
    std::cout << "stack poping for s_empty:" << std::endl;
    for (int i = 0; i < 10; ++i)
    {
        temp = s_empty.StackPeek();
        s_empty.StackPop();
        std::cout << "temp:" << temp << std::endl;        
    }

    temp = GetSize(s1);
    std::cout << "GetSize func ret:" << temp << std::endl;
    

    return 0;
}