/*********************************
 * Reviewer: 
 * Author: 
 * File: shared_pointer.hpp
 * ******************************/

#pragma once

#include <iostream>

namespace ilrd
{

template<typename T>
class SharedPointer
{
public:
    template<typename>
    friend class SharedPointer;

    template<typename Y>
    SharedPointer(const SharedPointer<Y> &other);

    explicit SharedPointer(T* ptr = NULL);
	~SharedPointer();
    SharedPointer(const SharedPointer& other); 
	SharedPointer& operator=(const SharedPointer& other);
    T& operator *() const;
	T* operator->() const;

private:
	/* Option A */
/* 	class SPData;
	SPData *m_sp; */

	/* Option B */
	T* m_ptr;
	std::size_t* m_counter;

}; // class SharedPointer

template<typename T>
SharedPointer<T>::SharedPointer(T* ptr): m_ptr(ptr),m_counter(new std::size_t(1)){}

template<typename T>
SharedPointer<T>::~SharedPointer()
{
    if(*m_counter == 1)
    {
        delete m_counter;
        delete m_ptr;
    }
    else
    {
        --(*m_counter);    
    }
}

template<typename T>
SharedPointer<T>::SharedPointer(const SharedPointer& other)
{
    this->m_ptr = other.m_ptr;
    this->m_counter = other.m_counter;
    ++(*other.m_counter);
}

template<typename T>
SharedPointer<T>& SharedPointer<T>::operator=(const SharedPointer& other)
{
    if(*(this->m_counter) == 1)
    {
        delete this->m_ptr;
    }
    else
    {
        --*(this->m_counter);
    }
    this->m_ptr = other.m_ptr;
    this->m_counter = other.m_counter;
    ++(*other.m_counter);
    return *this;
}

template<typename T>
T& SharedPointer<T>::operator *() const
{
    return *this->m_ptr;
}

template<typename T>
T* SharedPointer<T>::operator->() const
{
    return this->m_ptr;
}

template<typename T>
template<typename Y>
SharedPointer<T>::SharedPointer(const SharedPointer<Y> &other)
{
    
}

} // namespace ilrd