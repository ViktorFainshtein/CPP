#include "rcstring.hpp"



int main()
{
    ilrd::RCString s1("Hello");
    ilrd::RCString s2 = s1;
    ilrd::RCString s3("World");
    ilrd::RCString s4(s3);
    
    const ilrd::RCString s5("Sweet");
    const char str = s5[0];

    char a = s1[0];

    if(a != s1[0])
    {
        std::cout << "char a: is not equal to s1[0]" << std::endl;
    }

    if(s3 != s4)
    {
        std::cout << "Failed to CCTOR" << std::endl;
    } 

    s3[0] = 'a';

    if(s3[0] != 'a')
    {
        std::cout << "s3[0]: is not equal to 'a'" << std::endl;
    }

    if(s1 != s2)
    {
        std::cout << "operator assignment = failed to assign s1 to s2" << std::endl;
    }
    if(s3 == s4)
    {
        std::cout << "failed to detach after s3[0] assignment" << std::endl;
    }   
    if(s1 == s3)
    {
        std::cout << "operator== returned false result"<< std::endl;
    }
    
    s2[0] = 'J';
    s3[0] = 'Z';

    if(s1 > s2)
    {
        std::cout << "(s1 > s2): s2 is bigger then s1" << std::endl;
    }

    if(s2 > s3)
    {
        std::cout << "(s2 > s3): s2 is smaller then s3" << std::endl;
    }

    if(s3 < s4)
    {
        std::cout << "(s3 < s4): s3 is bigger then s4" << std::endl;
    }

    // test: const operator[]
    if(str != 'S')
    {
        std::cout << str << std::endl; 
    }

    if(strcmp(s1.Cstr(), "Hello") != 0)
    {
        std::cout << "s1 is incorrect" << std::endl;
    }
    if(strcmp(s2.Cstr(), "Jello") != 0)
    {
        std::cout << "s1 is incorrect" << std::endl;
    }
    if (strcmp(s3.Cstr(), "Zorld") != 0)
    {
        std::cout << "s1 is incorrect" << std::endl;
    }
    if(strcmp(s4.Cstr(), "World") != 0)
    {
        std::cout << "s1 is incorrect" << std::endl;
    }
    
    s1[0] = s5[0];

    if(s1[0] != s5[0])
    {
        std::cout << "s1[0] = s5[0]: s1[0] is not equal to s5[0]" << s1 << std::endl;
    }
    
    char temp = 'a';

    temp = s1[0] = 'b';

    if (temp != 'b' || temp != s1[0] || s1[0] != 'b')
    {
        std::cout << "temp = s1[0] = 'b': chaining was not sucessful" << std::endl;
    }
    


    return 0;
}