
#include <iostream>
#include "scope_lock.hpp"

namespace ilrd
{

ScopedLock ::ScopedLock(pthread_mutex_t& mutex) : m_lock(&mutex)
{
    std:: cout << "Scoped lock locking mutex" << std::endl;
    pthread_mutex_lock(m_lock);
    std:: cout << "Mutex has been locked" << std::endl;
}

ScopedLock ::~ScopedLock()
{
    pthread_mutex_unlock(m_lock);
    std:: cout << "Scoped lock has unlocked the mutex" << std::endl;
}


}
