
#include "bit_Array.hpp"
#include <iostream>


using namespace ilrd;


int main()
{
    //---------------------//
    BitArray<30> arr1;
    BitArray<64> arr2;
    BitArray<74> arr3;
    BitArray<128> arr4;
    BitArray<640> arr5;
    //---------------------//
    BitArray<30> brr1;
    BitArray<64> brr2;
    BitArray<74> brr3;
    BitArray<128> brr4;
    BitArray<128> brr5;

    if(arr1 == brr1)
    {
        std::cout << "arr1 == brr2" << std::endl;
    }
    
    arr1[2] = true;

    if(arr1 == brr1)
    {
        std::cout << "arr[2] == brr1[2] == 1" << std::endl;
    }

    brr1[2] = true;

    if(arr1 == brr1)
    {
        std::cout << "arr1 == brr1" << std::endl;
    }

    brr2[50] = 1;
    arr2[50] = brr2[50];

    if(arr2 == brr2)
    {
        std::cout << "arr2[50] == brr2[50] == 1" << std::endl;
    }

    arr3[70] = true;
    brr3[50] = true;

    if(arr3 == brr3)
    {
        std::cout << "arr3[70] == brr[50]" << std::endl;
    }

    for(size_t i = 0; i < 128; ++i)
    {
        arr4[i] = true;
    }

    for (size_t i = 0; i < 64; ++i)
    {
        brr4[i] = true;
    }

    if(arr4 == brr4)
    {
        std::cout << "arr4 == brr4" << std::endl;
    }

    for (size_t i = 0; i < 128; ++i)
    {
        if(arr4[i] == brr4[i]){}
        else
        {
            std::cout << "arr4[" << i << "] != brr4[" << i <<"]" << std::endl; 
            break;
        }
    }

    std::cout << "num of set bits on at arr4: " << arr4.Count() << std::endl;
    std::cout << "num of set bits on at brr4: " << brr4.Count() << std::endl;

    for (size_t i = 100; i <= 200; ++i)
    {
        arr5[i] = true;
    }

    if(arr5[100] == true)
    {
        std::cout << "arr5[100] = 1" << std::endl;
    }
    if(arr5[200] == true)
    {
        std::cout << "arr5[200] = 1" << std::endl;
    }

    for (size_t i = 639; i > 0; --i)
    {
        //std::cout << "brr4[" << i << "] = " << brr4[i] << std::endl;
        if(i%64 == 0)
        {
            std::cout << std::endl;
        }
        std::cout << arr5[i];
    }
    std::cout << std::endl;
    arr5 <<= 64;
    
    std::cout << std::endl;
    for (size_t i = 639; i > 0; --i)
    {
        //std::cout << "brr4[" << i << "] = " << brr4[i] << std::endl;
        if(i%64 == 0)
        {
            std::cout << std::endl;
        }
        std::cout << arr5[i];
    }
    std::cout << std::endl;

    if(arr5[230] == true)
    {
        std::cout << "arr5[230] = 1" << std::endl;
    }
    if(arr5[330] == true)
    {
        std::cout << "arr5[330] = 1" << std::endl;
    }

    
/*----------------------------------------------------------------------------*/

/* 	BitArray<128> ba;

	ba[62] = true;

	if (ba[62] != true)
	{
		std::cout << "Test Failed on line " << __LINE__ << std::endl;
	}

	ba[126] = ba[62];

	if (true != ba[126])
	{
		std::cout << "Test Failed on line " << __LINE__ << std::endl;
	}

	bool bul = ba[126];

	if (bul != true)
	{
		std::cout << "Test Failed on line " << __LINE__ << std::endl;
	}
	
	const BitArray<128> bb(ba);

	bul = bb[126];

	if (bul != true)
	{
		std::cout << "Test Failed on line " << __LINE__ << std::endl;
	}

	ba[126] = false;

	if (ba[126] != false)
	{
		std::cout << "Test Failed on line " << __LINE__ << std::endl;
	} */

	// bb[2] = true;





    return 0;
}


















