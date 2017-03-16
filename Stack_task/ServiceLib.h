//===============================================
//! @file ServiceLib.h
//===============================================

//===============================================
//! @brief Servic Macros Library
//===============================================

#ifndef __MACROS_H
#define __MACROS_H

static const bool TRUE    = 1;
static const bool FALSE   = 0;
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
#else #define ASSERT_OK() ;
#endif
//===============================================

//===============================================
#define INFO std::cout << __FUNCTION__, __FILE__, __LINE__ << '\n';
#define PRINT(string) std::cout << string << '\n';


#define WRITE(string, num)	std::ofstream log;								\
	log.open("log.txt", std::ios_base::app);							\
	log << "--------------------------------------------------\n\n";	\
	log << string << num << '\n';														\
	log.close();


#endif