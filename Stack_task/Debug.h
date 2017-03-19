//-----------------------------------------------
//! @IDE Microsoft Visual Studio 
//! @file Macros.h
//!
//! @autor Andrey, 2017
//-----------------------------------------------

//-----------------------------------------------
//! @brief Servic Macros Library
//-----------------------------------------------


#ifndef __DEBUG_H
#define __DEBUG_H
#include <assert.h>
#include <iostream>
#include "superfunc.h"

using std::cin;
using std::cout;

#define MACROS_ON true

// static const MACROS_ON = true;  Если написать так, то макрос работает не так, как читается.

//-----------------------------------------------
//! @brief ASSERT_OK
//! Macros to test object integrity
//-----------------------------------------------

#if MACROS_ON == true
	#define ASSERT_OK			     	\
		if (!ok())						\
		{								\
			dump();						\
			assert (!"Object is OK");	\
		}
#else                               
	#define ASSERT_OK() ;                                
#endif

//-----------------------------------------------

#define INFO std::cout << __FUNCTION__, __FILE__, __LINE__ << '\n';

//-----------------------------------------------

#define PRINT(string) std::cout << string << '\n';

//-----------------------------------------------

#define WRITE(string, num)	std::ofstream log;							\
	log.open("log.txt", std::ios_base::app);							\
	log << "--------------------------------------------------\n\n";	\
	log << string << num << '\n';										\
	log.close();
#endif

