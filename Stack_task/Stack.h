//===============================================
//! @file Stack.h
//===============================================

//===============================================
//! @brief Stack library
//===============================================

#ifndef __STACK_H
#define __STACK_H

#include <iostream>
#include <assert.h>
#include <fstream>
#include "ServiceLib.h"
template <typename T>

class Stack 
{
	public:

	//===========================================
	//! @brief Standart constructor for static stack
	//===========================================

	Stack();

	//===========================================
	//! @brief Standart constructor for dynamic stack
	//===========================================

//	Stack(size_t capasity);

//  Stack(size_t capasity);

	~Stack();

	//===========================================
	//! @brief Pushes a value to the stack
	//! @param value is an element to be pushed
	//! @return succes of operation
	//===========================================

	bool push(T value);

	//===========================================
	//! @brief Take the last element from the stack 
	//! @return last element in the stack or NAN if stack empty
	//===========================================

	T pop();

	//===========================================
	//! @brief Maximum number of elements to be pushed 
	//! @return stack capasity
	//===========================================

	size_t capasity() const;

	//===========================================
	//! Show the last element of the stac
	//! @return last element of stack
	//===========================================

//	T peek(); //TODO

	//===========================================
	//! @brief Information about stack
	//! @detailed Send all info about stack in logfile.	
	//===========================================

	void dump() const;


	private:
	
	//===========================================
	//! Silent validation
	//! @return success to validation
	//===========================================

	bool ok() const;

	//===========================================
	//! @brief Information about stack
	//! @detailed Send all info about stack in logfile.
	//===========================================

//	void dump() const;

	//===========================================
    //! variables
	//===========================================

	static const size_t capasity_ = 6; //! maximum number of elements to be pushed 

//	Static stack
	T data_[capasity_]; //! data storage
	size_t count_; //! counter


/* Dynamic Stack
	value_type data_; //! Data pointer
	size_t count_;    //! Counter
	size_t size_;     //! Stack capasity
*/

}; //! End of class stack


   //===============================================
   //! @brief Source code stack library.
   //===============================================

   //-----------------------------------------------
static const int POISON_INIT = 100500; //! Initialization const.
static const double POISON_DEST = NAN;    //! Destruct const.
										  //-----------------------------------------------

template <typename T>
Stack<T>::Stack():
	count_(0),
	data_()
{
	PRINT("Стек инициализирован");
	INFO
}

//-----------------------------------------------

/*Stack::Stack(size_t capasity) :
data_(new value_type[capasity]),
count_(0),
size_(size)
{}
*/
template <typename T>
Stack<T>::~Stack()
{
	count_ = POISON_DEST;
	for (size_t i = 0; i < capasity_; i++)
		data_[i] = POISON_DEST;
	PRINT("Стек уничтожен");
}

//-----------------------------------------------
template <typename T>
bool Stack<T>::push(T value)
{
	ASSERT_OK(); //! Entry verification

	if (count_ >= capasity_)
	{
		ASSERT_OK(); //! Exit verification
		return false;
	}
	data_[count_++] = value;
	WRITE("push", value)
	dump();
	ASSERT_OK(); //! Exit verification
	return true;
}

//-----------------------------------------------

template <typename T>
T Stack<T>::Stack::pop()
{
	ASSERT_OK(); //! Entry verification
	if (count_ == 0)
	{
		ASSERT_OK();
		WRITE("pop NAN", 0)
		return NAN; // Exit verification 
	}
	T result = data_[--count_];
	WRITE("pop", result)
	ASSERT_OK(); //! Exit verification
	return result;
}

//-----------------------------------------------

template <typename T>
size_t Stack<T>::capasity() const
{
	ASSERT_OK(); //! Verification
	return capasity_;
}

//-----------------------------------------------

template <typename T>
bool Stack<T>::ok() const
{
	return (count_ <= capasity_ || data_ != NULL);
}


template <typename T>
void Stack<T>::dump() const

{

	//-----------------------------------------------
	bool correct = true;
	char symbol ='*';
#define DUMP(verif)															\
	if (verif == true)														\
		symbol = '*';													\
	else																	\
		symbol = ' ';													\
	if (data_[i] != data_[i])												\
	{																		\
		correct = false;													\
		log << symbol <<"[" << i << "] = " << data_[i] << "\t (Correct?)\n";			\
	}													     				\
	else if (data_[i] == POISON_INIT)										\
	{																		\
		correct = false;													\
		log << symbol << "[" << i << "] = " << data_[i] << "\t (Poison?)\n";\
	}																		\
	else																	\
	log << symbol << "[" << i << "] = " << data_[i] << '\n';

	//-----------------------------------------------




	std::ofstream log;  //! Write in log.txt
	log.open("log.txt", std::ios_base::app); //! Open file for addition info.

	log << "--------------------------------------------------\n\n";
	log << "Info about stack." << '\n' << '\n';
	log << "Stack max size = " << capasity_ << '\n';
	log << "Amount of elements in the stack = " << count_ << '\t';
	if (count_ <= capasity_)
	{	//! Start first block.
		log << "\n\n";
		for (size_t i = 0; i < count_; i++) // Write data from the stack memory.
		{	// Start first for .
			DUMP(true)
		} //! End first for.

		for (size_t i = count_; i < capasity_; i++) // Write data from the memory off the stack.
		{ // Start second for.
			DUMP(false)
		} //! End second for.
	} //! End of first block.
	else
	{   //! Second block.
		correct = false;
		log << "Correct???\n\n";
		for (size_t i = 0; i < capasity_; i++) // Write data from the memory off the stack.
		{ // Start for.
			DUMP(false)
		} // End for. 
	} // End if.
	if (correct != true)
		log << "Stack is NOT OK\n";
	else
		log << "Stack is OK\n";

	log << "--------------------------------------------------\n\n";

	log.close();

}

//-----------------------------------------------

#endif