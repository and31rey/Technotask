#ifndef __SUPER_FUNC_H
#define __SUPER_FUNC_H
#include <iostream>


//===============================================
//! @brief My print
//! @detailed My print can differ the types automatically
//-----------------------------------------------


void print(const char* str)
{
	while (*str) putchar(*str++);
}

//-----------------------------------------------

template <typename T, typename... Args>
void print(const char* str, T value, Args... args)
{
	while (*str)
		if (*str == '#')
		{
			std::cout << value;
			print(++str, args...);
			break;
		}
		else
		{
			putchar(*str++);
		}
}

//===============================================




#endif
