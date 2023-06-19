#include <assert.h>
#include "string.hpp"

namespace ilrd
{
static char *BuildString(const char *str)
{
    char *buff = new char[strlen(str)+1];
    return strcpy(buff, str);
}

void String::CleanUp()
{
    delete[] m_str;
}

String::String(const char *str): m_str(BuildString(str)){}

String::String(const String& other):m_str(BuildString(other.m_str)){}

String::~String()
{
    CleanUp();
}

size_t String::Length()
{
    if(strlen(m_str) == 0)
    {
        return 0;
    }
    return strlen(m_str);
}

const char *String::Cstr()
{
    return m_str;
}

const char& String::operator[](size_t index) const
{
    return m_str[index];
}

char& String::operator[](size_t index)
{
    return const_cast<char&>(const_cast<const String&>(*this)[index]);
}

bool operator==(const String& lhs, const String& rhs)
{
    if(&lhs == &rhs)
    {
        return true;
    }
    return (strcmp(&lhs[0], &rhs[0]) == 0) ? true : false;
}

bool operator!=(const String& lhs, const String& rhs)
{
    if(lhs == rhs)
    {
        return false;
    }
    return true;
}

std::ostream& operator<<(std::ostream& cout, const String& other)
{
    int i = 0;
    while ('\0' != other[i])
    {
        cout << other[i];
        ++i;
    }
    return cout;
}

String& String::operator=(const String& other)
{
    if(this != &other)  //prevent self assignment
    {
        char *str = BuildString(other.m_str);
        CleanUp();
        m_str = str;
    }
    return *this;
}

bool operator<(const String& lhs, const String& rhs)
{
    return (strcmp(&lhs[0], &rhs[0]) < 0) ? true : false;
}

bool operator>(const String& lhs, const String& rhs)
{
    return (&lhs < &rhs) ? false : true;
}
} // namespace ilrd
