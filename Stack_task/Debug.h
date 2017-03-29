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
//#include "superfunc.h"

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
			dump();	                    \
			if (logfile.is_open())      \
			{						    \
				logfile.close();        \
			}         				    \
			assert (!"Object is OK");	\
		}                               
#else                               
	#define ASSERT_OK       ;                              
#endif

//-----------------------------------------------

#define INFO logfile << "==================================================\n";                  \
			 logfile << __FUNCSIG__ << '\n' << __FILE__ << '\n' <<"line = " << __LINE__ << '\n'; \
			 logfile <<"--------------------------------------------------" << "\n\n";             

//-----------------------------------------------

#define PRINT(string) std::cout << string << '\n';

//-----------------------------------------------

#define DUMP(var) var.dump(#var)

#endif

