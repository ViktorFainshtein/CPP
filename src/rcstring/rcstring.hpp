/*********************************
 * Reviewer: 
 * Author: Bjarne Stroustrup			
 * File: string.hpp
 * ******************************/

#pragma once

#include <ostream>	// ostream //
#include <iostream>	// cout //
#include <cstddef>	// size_t //
#include <cstring>	// strlen //

namespace ilrd
{
	class RCString;
	bool operator==(const RCString& lhs, const RCString& rhs);
	bool operator!=(const RCString& lhs, const RCString& rhs);
	bool operator<(const RCString& lhs, const RCString& rhs);
	bool operator>(const RCString& lhs, const RCString& rhs);
	std::ostream& operator<<(std::ostream& cout, const RCString& str);

class RCString
{
public:

	explicit RCString(const char *str = "");					//CTOR
	RCString(const RCString& str);				 	 			//CCTOR
	~RCString(); 								  				//Destructor
	RCString& operator=(RCString& other_);  					//Assignment

/* 	char& operator[](size_t index);
	const char& operator[](size_t index) const; */
	const char* Cstr() const;

/* 	friend class Proxy; */
private:
	class Proxy
	{
	public:
		Proxy(RCString& str, const int index);
		const char& operator=(const Proxy& str);
		const char& operator=(const char ch);
		operator char() const;
	private:
		RCString& m_str;
		size_t m_index;
	};
	
public:
	Proxy operator[](size_t index);
	const Proxy operator[](size_t index) const;


private:
	class StringData;
	void CleanUp();
	StringData *m_str;
};


}//namespace ilrd

