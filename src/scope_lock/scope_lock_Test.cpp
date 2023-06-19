

#include <iostream>
#include "scope_lock.hpp"

pthread_mutex_t g_mutex;

void TestLock(bool test_mutex)
{
    ilrd::ScopedLock lock(g_mutex);

    if(test_mutex)
    {
        std::cout << "Throwing an exception" << std::endl;
        throw 1;
    }
}

int main()
{
    pthread_mutex_init(&g_mutex, NULL);

    try
    {
        TestLock(true);
    } 
    catch(...)
    {
        std::cout << "Exception caught" << std::endl;
    }

    TestLock(false);

    return 0;
}
