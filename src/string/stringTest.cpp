#include "string.hpp"

#include <vector>

ilrd::String foo()
{
    ilrd::String res("Hello");
    res[3] = 'x';
    return res;
}

int main()
{
    #if 1
    std::vector<ilrd::String> v1(30);
    v1[0] = "I am a C string";
    #else
    // your old testing code
    char str[10] = {"Hello"};
    const char *p_str = NULL;
    ilrd::String s1;
    ilrd::String s2(str);
    ilrd::String s3(s2);
    ilrd::String s4("World!");
    ilrd::String s5 = s4;
    s1[0] = s5[0];
    p_str = s4.Cstr();

    std::cout << s2 << " " << s3 << std::endl;

    if(s2 != "Hello")
    {
        std::cout << "diffrent" << std::endl;
    }
    if(s1 != s1)
    {
        std::cout << "c1 != c1 -> Error" << std::endl;
    }
    if(s3 == s4)
    {
        std::cout << "c3 == c4 -> Error" << std::endl;
    }

    std::cout << "s1 len: " << s1.Length() << std::endl
                << "s2 len: " << s2.Length() << std::endl
                << "s3 len: " << s3.Length() << std::endl
                << "s4 len: " << s4.Length() << std::endl;

    std::cout << s5 << std::endl;

    std::cout << s1 << std::endl;

    std::cout << p_str << std::endl;
    #endif

    return 0;
}