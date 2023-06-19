#include "stack.hpp"

//before fix:
size_t GetSize(ilrd::Stack s)
{
    return s.StackSize();
}

int main()
{
    ilrd::Stack s_empty;
    ilrd::Stack s1(10);

    for(int i = 0; i < 10; ++i)
    {
        //s1.StackPush(i);
        s1 << i;   
    }

    if(s1.StackSize() != 10)
    {
        std::cout << "stack s1 has the wrong size after push/(<<)" << std::endl;
    }

    for (int i = 0; i < 10; i++)
    {
        //s_empty.StackPush(i);
        s_empty << i;
    }

    if(s_empty.StackSize() != 10)
    {
        std::cout << "stack s_empty has the wrong size after push/(<<)" << std::endl;
    }

    int temp = 0;
    for(int i = 0; i < 10; ++i)
    {
        s1 >> temp;
        //temp = s1.StackPeek();
        s1.StackPop();
    }

    if(s1.StackSize() != 0)
    {
        std::cout << "stack s1 has the wrong size after pop" << std::endl;
    }

    for (int i = 0; i < 10; ++i)
    {
        s_empty >> temp;
        //temp = s_empty.StackPeek();
        s_empty.StackPop();
        std::cout << "temp:" << temp << std::endl;        
    }

    if(s_empty.StackSize() != 0)
    {
        std::cout << "stack s_empty has the wrong size after pop" << std::endl;
    }

    temp = GetSize(s1);

    if (GetSize(s1))
    {
        std::cout << "GetSize: wrong size" << std::endl;
    }
    
    s_empty << 100 << 200 << 300 << 400 << 500;

    if (s_empty.StackSize() != 5)
    {
        std::cout << "faild to concate push operator (<<)" << std::endl;
    }
    
    for (size_t i = 0; i < 5; i++)
    {
        std::cout << s_empty.StackPeek()<<std::endl;
        s_empty.StackPop();
    }

    if (s_empty.StackSize() != 0)
    {
        std::cout << "faild to clean s_empty arr" << std::endl;
    }

    s_empty << 600;

    std::cout << "stack s_empty size after insert (<<):" 
                << s_empty.StackSize() << std::endl;

    --s_empty;

    std::cout << "stack s_empty size after decrement (--):" 
                << s_empty.StackSize() << std::endl;


    return 0;
}