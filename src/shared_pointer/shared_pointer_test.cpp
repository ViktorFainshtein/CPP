
#include "shared_pointer.hpp"

using namespace ilrd;

class Widget
{
public:
    Widget(int id): m_id(id){}
private:
    int m_id;
};

int main()
{
    SharedPointer<int> iPtr(new int);

    *iPtr = 8;

    std::cout << "iPtr value = " << *iPtr << std::endl;

    SharedPointer<int> jPtr(iPtr);

    std::cout << "jPtr value = " << *jPtr << std::endl;

    SharedPointer<int> tPtr = iPtr;

    std::cout << "tPtr value = " << *tPtr << std::endl; 

    SharedPointer<int> gPtr;

    gPtr = jPtr;

    std::cout << "gPtr value = " << *gPtr << std::endl;

    Widget *p1 = new Widget(100);

    

    return 0;
}