/*********************************
 * Reviewer: 
 * Author: poli m. phizem		
 * Poly and Gavri
 * https://he.wikipedia.org/wiki/%D7%99%D7%A9%D7%A8%D7%90%D7%9C_%D7%A4%D7%95%D7%9C%D7%99%D7%90%D7%A7%D7%95%D7%91
 * File: bit_array.hpp
 * ******************************/

#pragma once
#include <iostream>
#include <cstddef>
#include <cstring>
#include <vector>
#include <algorithm>

namespace ilrd
{
	
/*------------------------------ Class BitArray ------------------------------*/

template<size_t SIZE>
class BitArray
{
private:
	class Proxy;

public:
    explicit BitArray(); // Ctor 
	bool operator==(const BitArray& other);
  	bool operator[](size_t index) const;
    BitArray& operator<<=(size_t shift);
	BitArray& operator>>=(size_t shift);
    Proxy operator[](size_t index);
	BitArray& Set(size_t index, bool tf);
	bool Get(size_t index);
	size_t Count();

private:
	static const size_t ChunkSize = sizeof(size_t) * __CHAR_BIT__;
	static const size_t m_size = (SIZE + ChunkSize - 1)/ChunkSize;
	std::vector<size_t> m_arr;				
    
};// Class BitArray

/*------------------------------ Class Proxy ---------------------------------*/

template<size_t SIZE>
class BitArray<SIZE>::Proxy
{
public:
	explicit Proxy(BitArray& arr, size_t index);
	bool operator=(const Proxy& arr);
	bool operator=(bool tf);
	operator bool() const;

private:
	BitArray& m_bit_arr;
	size_t m_bit_index;
};// Class Proxy

/*------------------------------ Functor ShiftBits ---------------------------*/

class ShiftBits
{
public:
    ShiftBits(size_t bits_to_shift): m_bits_to_shift(bits_to_shift){}
 
    // This operator overloading enables calling
    // operator function () on objects of increment
    size_t operator() (size_t first, size_t second) 
	{
        size_t temp = (first << m_bits_to_shift) | (second >> (64 - m_bits_to_shift));
		return temp;
    }
private:
    size_t m_bits_to_shift;
};

/*------------------------------ Functor Count -------------------------------*/

class CountBits
{
public:
    CountBits(): m_num_bits(0){}
    void operator ()(size_t& chunck) 
	{
		size_t temp = chunck;
		while(temp)
		{
			this->m_num_bits += 1;
			temp &= (temp-1);
		}
    }
	operator size_t() const
	{
		return m_num_bits;
	}
	size_t getCountBits(){return this->m_num_bits;}

private:
    size_t m_num_bits;
};

/*------------------------------ BitArray ------------------------------------*/

template <size_t SIZE>
BitArray<SIZE>::BitArray():m_arr(m_size, 0){}

template <size_t SIZE>
bool BitArray<SIZE>::operator==(const BitArray &other)
{
	for (size_t i = 0; i < m_size; i++)
	{
		if(m_arr[i] != other.m_arr[i])
		{
			return false;
		}
	}
	return true;
}

template <size_t SIZE>
typename BitArray<SIZE>::Proxy BitArray<SIZE>::operator[](size_t index)
{
	return Proxy(*this, index);
}

template <size_t SIZE>
bool BitArray<SIZE>::operator[](size_t index) const
{
	size_t arr_index = m_size - (index / ChunkSize) - 1;
	size_t chunk_index = index % ChunkSize;
	size_t res = 1;
	res <<= chunk_index;
	return bool((m_arr[arr_index] & res)>>chunk_index); 
}

template <size_t SIZE>
typename BitArray<SIZE>::BitArray& BitArray<SIZE>::Set(size_t index, bool tf)
{
	//--------------- Find Indexes ---------------------------//
	size_t arr_index = m_size - (index / ChunkSize) - 1;
	size_t chunck_index = index % ChunkSize;
	//--------------- Set Bit off ---------------------------//
	size_t bit = 1;
	bit <<= chunck_index;
	bit = ~bit;
	//--------------- Set Selected Bit ---------------------------//
	this->m_arr[arr_index] &= bit;
	this->m_arr[arr_index] |= (size_t(tf)<<chunck_index);

	return *this;
}

template <size_t SIZE>
bool BitArray<SIZE>::Get(size_t index)
{
	size_t arr_index = m_size - (index / ChunkSize) - 1;
	size_t chunck_index = index % ChunkSize;
	size_t res = m_arr.at(arr_index);//[arr_index];
	res >>= chunck_index;
	res &= 1;

	return res;
}

template <size_t SIZE>
size_t BitArray<SIZE>::Count()
{
/* 	CountBits temp;
	temp = std::for_each(m_arr.begin(), m_arr.end(), CountBits());
    return temp.getCountBits(); */
	size_t res = for_each(m_arr.begin(), m_arr.end(), CountBits());
	return res;
}

/* 
template<class InputIt1, class InputIt2, class OutputIt, class BinaryOperation>
OutputIt transform(InputIt1 first1, InputIt1 last1, InputIt2 first2, OutputIt d_first, BinaryOperation binary_op)
{
    while (first1 != last1)
	{
        *d_first++ = binary_op(*first1++, *first2++);
	}
 
    return d_first;
}
 */

size_t Zero(size_t& first)
{
	first = 0;
	return first;
}

template <size_t SIZE>
typename BitArray<SIZE>::BitArray& BitArray<SIZE>::BitArray::operator<<=(size_t shift)
{
	size_t index = shift/64;
	size_t temp = shift % 64;
	size_t g = 0;

	ShiftBits func(temp);

	std::transform(m_arr.begin()+index, m_arr.end()-1, m_arr.begin()+index+1, m_arr.begin(), func);	// copy and shift

	m_arr[m_size-index-1] = func(m_arr[m_size-1],g);														//copy and shift last index
	
	if(index == 0)
	{
		return *this;
	}
	
	std::fill(m_arr.end()-(index+1), m_arr.end(), g);				//zero the the original place

	return *this;
}

template <size_t SIZE>
typename BitArray<SIZE>::BitArray& BitArray<SIZE>::BitArray::operator>>=(size_t shift)
{
    // TODO: insert return statement here
}

/* ----------------------------- PROXY -------------------------------------- */

template <size_t SIZE>
BitArray<SIZE>::Proxy::Proxy(BitArray &arr, size_t index):m_bit_arr(arr), m_bit_index(index){}

template<size_t SIZE>
bool BitArray<SIZE>::Proxy::operator=(const Proxy& arr)
{
/* 	return *this = arr.m_bit_arr.Get(arr.m_bit_index); */	// Repeat operator bool() code
	return *this = static_cast<bool>(arr);		//To Not Repeat operator bool() code
}

template<size_t SIZE>
bool BitArray<SIZE>::Proxy::operator=(bool tf)
{
	m_bit_arr.Set(m_bit_index, tf);
	return *this;
}

template<size_t SIZE>
BitArray<SIZE>::Proxy::operator bool() const
{
	return m_bit_arr.Get(m_bit_index);
}

} // namespace ilrd