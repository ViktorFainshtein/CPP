
#include <algorithm>
#include <iostream>

static void Print(const int &index);
static int ShiftLeft(int *arr, size_t size, size_t shift);
static int Move(const int &num);


class PrintFunc
{
public:
    void operator() (const int& num)
    {
        m_count+=num;
    }
    PrintFunc():m_count(0){}

private:
    size_t m_count;
};




int main()
{
    int arr[30];
    size_t shift = 3;

    for (size_t i = 0; i < 30; i++)
    {
        arr[i] = i;
    }
    ShiftLeft(arr, 30, 3);
/*     std::transform(arr+shift, arr+30, arr, Move); */

    for (size_t i = 0; i < 30; i++)
    {
        std::cout << arr[i] << std::endl;
    }
    

/*     void (*ret1)(const int&) = std::for_each(arr, arr+30, Print);

    PrintFunc ret = std::for_each(arr, arr+30, PrintFunc());

    std::cout << ret1 << std::endl; */

/*     std::transform(arr, arr+30, , PrintFunc()); */


    return 0;
}

static void Print(const int &num)
{
    std::cout << num << std::endl;
}

static int Move(const int &num)
{
    return num;
}

static int ShiftLeft(int *arr, size_t size, size_t shift)
{
    std::transform(arr+shift, arr+size, arr, Move);
}