//===============================================
//! @file ServiceLib.h
//===============================================

//===============================================
//! @brief Servic Macros Library
//===============================================


#ifndef __MACROS_H
#define __MACROS_H
#include <assert.h>
static const bool TRUE    = true;
static const bool FALSE   = false;
static bool SERVICE       = TRUE;

//===============================================
//! @brief ASSERT_OK associated with Stack.h
//! Macros to test object integrity
//===============================================
#if SERVICE == TRUE  
		#define ASSERT_OK()				\
		if (!ok())						\
		{								\
			dump();						\
			assert (!"Object is OK");	\
		}
#else ;
#endif
//===============================================

//===============================================
#define INFO std::cout << __FUNCTION__, __FILE__, __LINE__ << '\n';



#endif