#include "rcstring.hpp"



namespace ilrd
{

class RCString::StringData
{
public:
    void BuildString(char *m_str, const char *str);
    static StringData *Create(const char *str);
    void Attach();
    void Detach();
    size_t getCounter();
    const char* Cstr() const;
    void SetChar(const char ch, const size_t index);
    //static size_t SetCounter();
    //static char* getStr();
private:
    explicit StringData(const char *str);
    size_t m_nMembers;
    char m_str[1];
};



const char* RCString::StringData::Cstr() const
{
    return this->m_str;
} 

const char* RCString::Cstr() const
{
    return this->m_str->Cstr();
}

RCString::StringData* RCString::StringData::Create(const char *str)
{
    size_t size = strlen(str);
    //using placment new - 1st allocated raw memory
    void *buff = operator new(offsetof(RCString::StringData, m_str) + size  +1);
    //call ctor using placment new
    return (new (buff) StringData (str));
}

RCString::RCString(const char *str): m_str(StringData::Create(str)){}

RCString::StringData::StringData(const char *str): m_nMembers(1)
{
    BuildString(m_str, str);
}


void RCString::StringData::BuildString(char *m_str, const char *str)
{
    memcpy(m_str, str, (strlen(str)+1));
}

void RCString::StringData::Attach()
{
    ++m_nMembers;
}
void RCString::StringData::Detach()
{
    --m_nMembers;
    if(this->getCounter() == 0)
    {
        delete this;
    }
}

size_t RCString::StringData::getCounter()
{
    return this->m_nMembers;
}

RCString::RCString(const RCString& str)
{
    str.m_str->Attach();
    this->m_str = str.m_str;

}

RCString::~RCString()
{
    this->m_str->Detach();
}


void RCString::CleanUp()
{
    delete this->m_str;
}

std::ostream& operator<<(std::ostream& cout, const RCString& s)
{
    return (cout << s.Cstr());
}

bool operator==(const RCString& lhs, const RCString& rhs)
{
    return ((strcmp(lhs.Cstr(), rhs.Cstr()) != 0) ? false : true);
}
bool operator!=(const RCString& lhs, const RCString& rhs)
{
    return ((lhs == rhs) ? false : true);
}
bool operator<(const RCString& lhs, const RCString& rhs)
{
    return ((strcmp(lhs.Cstr(), rhs.Cstr()) < 0) ? true : false);
}
bool operator>(const RCString& lhs, const RCString& rhs)
{
    return ((lhs < rhs) ? false : true);
}

RCString& RCString::operator=(RCString& other_)
{
    if(other_.m_str->getCounter() < 2)
    {
        other_.m_str->Detach();
        other_.~RCString();
    }
    else
    {
        other_.m_str->Detach();
        this->m_str->Attach();
        other_.m_str = this->m_str;
    }
    return *this;
}

/* char& RCString::operator[](size_t index)
{
    if(m_str->getCounter() > 1)
    {
        m_str->Detach();
        m_str = StringData::Create(this->Cstr());
    }
    return const_cast<char&>(const_cast<const RCString&>(*this)[index]);
}

const char& RCString::operator[](size_t index) const
{
    return (this->m_str->Cstr())[index];
} */

RCString::Proxy RCString::operator[](size_t index)
{
/*     if (m_str->getCounter() > 1)
    {
        m_str->Detach();
        m_str = StringData::Create(this->Cstr());
    } */
    return Proxy(*this, index);
}

const RCString::Proxy RCString::operator[](size_t index) const
{
    return Proxy(const_cast<RCString&>(*this)[index]);
}

RCString::Proxy::Proxy(RCString& str, const int index):m_str(str), m_index(index){}

RCString::Proxy::operator char() const
{
    return this->m_str.m_str->Cstr()[m_index];
}

void RCString::StringData::SetChar(const char ch, const size_t index)
{
    *(m_str + index) = ch;
}

// c = s[3] = 'a' || s1[] = s5[]
const char& RCString::Proxy::operator=(const Proxy& str)
{
    return *this = static_cast<char>(str);
}

const char& RCString::Proxy::operator=(const char ch)
{
    if(m_str.m_str->getCounter() > 1)
    {
        m_str.m_str->Detach();
        m_str.m_str = m_str.m_str->Create(m_str.Cstr());
    }
    m_str.m_str->SetChar(ch, m_index);
    return this->m_str.Cstr()[m_index];
}


} // namespace ilrd
