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
#include "Debug.h"
#include "Array.h"
#include "super_func.h"

using std::cin;
using std::cout;
#ifndef ARRAY_H
	static std::ofstream logfile;  //! Write in log.txt
#endif

const size_t CAPACITY = 6;

template <typename T>
class Stack 
{
	public:

	//-------------------------------------------
	//! @brief Default constructor.
	//-------------------------------------------

	Stack();

	//-------------------------------------------
	//! @brief Standart constructor for dynamic stack
	//-------------------------------------------

//	Stack(size_t capacity);

//  Stack(size_t capacity);

	~Stack();

	//-------------------------------------------
	//! @brief Pushes a value
	//! @param value is an item to be pushed
	//! @return success of operation
	//-------------------------------------------

	bool push(T value);

	//-------------------------------------------
	//! @brief Removes the top item
	//! @return void
	//-------------------------------------------

	void pop();

	//-------------------------------------------
	//! @brief Maximum number of elements to be pushed 
	//! @return stack capasity
	//-------------------------------------------

	size_t capacity() const;

	//-------------------------------------------
	//! @return top element
	//-------------------------------------------

//	T top(); //

    //-------------------------------------------
	//! @brief Information about stack
	//! @detailed Send all info about stack to logfile.	
	//-------------------------------------------

	void dump() ;


	private:
	
    //-------------------------------------------
	//! Silent validation
	//! @return success to validation
	//-------------------------------------------

	bool ok();

    //-------------------------------------------
    //! variables
	//-------------------------------------------
#ifndef ARRAY_H
	size_t capacity_ = CAPACITY; //! maximum number of elements to be pushed 
	T data_[CAPACITY]; //! data storage
#endif
	Array<int> data_;
	size_t count_; //! counter


}; //! End of class stack


   //-----------------------------------------------
   //! @brief Source code stack library
   //-----------------------------------------------


static const int POISON_INIT = 100500;    //! Initialization const
static const size_t POISON_DEST = 0xFFFFFFFF;    //! Destruct const

//-----------------------------------------------

template <typename T>
Stack<T>::Stack() :
	count_(0)
{
	if (!logfile.is_open()) // 
	{
		logfile.open("log.txt", std::ios_base::app); //! Open file for addition info.
		logfile << "==================================================================================================================================\n";
	}
	INFO
	ASSERT_OK; //Exit verification
	logfile << "Successfully\n" << "Stack adress = " << this;
	logfile << "\n==================================================\n";
}

//-----------------------------------------------

template <typename T>
Stack<T>::~Stack()
{
	if (!logfile.is_open()) // 
		logfile.open("log.txt", std::ios_base::app); //! Open file for addition info.
	INFO
//	dump();
	count_ = POISON_DEST;
//	for (size_t i = 0; i < data_.size(); i++)
//		data_[i] = POISON_DEST;
//	capacity_ = 0;
//
	data_.~Array();
	cout << "~Destruct\n";
//	logfile.close();
}

//-----------------------------------------------

const double COEFFICIENT = 1.5;

template <typename T>
bool Stack<T>::push(T value)
{
	cout << "Push was called\n";
	INFO
	ASSERT_OK; //! Entry verification
	if (count_ >= data_.Size())
/*	{
		ASSERT_OK //! Exit verification
		logfile << "Stack overflow, failed\n";
		return false;
	}*/
		data_.ReSize(COEFFICIENT);
	data_[count_++] = value;
	ASSERT_OK //! Exit verification
	logfile << "Successfully, value = " << value << '\n';
	return true;
}

//-----------------------------------------------

template <typename T>
void Stack<T>::Stack::pop()
{
	INFO
	ASSERT_OK //! Entry verification
		if (count_ <= 0)
		{
			ASSERT_OK; // Exit verification 
			logfile << "Stack is empty, failed\n"; 
		}
	logfile << "Successfully, item has been removed = " << data_[count_--] << '\n';
	ASSERT_OK; //! Exit verification
}

//-----------------------------------------------

template <typename T>
size_t Stack<T>::capacity() const
{
	ASSERT_OK; //! Verification
	logfile << "Successfuly, stack capacity = " << data_.size() << '\n';
	return data_.size();
}

//-----------------------------------------------

template <typename T>
bool Stack<T>::ok() 
{
	return (data_.ok() && count_ <= data_.Size());
}

//-----------------------------------------------


/*
template <typename T>
void Stack<T>::dump() 
{

	//-----------------------------------------------
	bool correct = ok();
	char symbol = '*';	     
	logfile << "Stack max size = " << data_.Size() << '\n';
	logfile << "Amount of elements in the stack = " << count_ << '\n';
	logfile << "Stack adress = " << this << '\n';
	if (correct)
	{	//! Start first block.
		for (size_t i = 0; i < data_.Size(); i++) // Write data.
		{	// Start  for .
			if (i < count_)													     	
				symbol = '*';													        
			else																      
				symbol = ' ';												          	
			if (data_[i] != data_[i])												    
			{																		    
				correct = false;													    
				logfile << symbol << "[" << i << "] = " << data_[i] << "\t (Correct?)\n";
			}													     			       	
			else if (data_[i] == POISON_INIT)										    
			{																		    
				correct = false;													    
				logfile << symbol << "[" << i << "] = " << data_[i] << "\t (Poison?)\n";
			}																	     	
			else	
			{																    
				logfile << symbol << "[" << i << "] = " << data_[i] << '\n';
			}
			//-----------------------------------------------
		} //! End for.
	} //! End of first block.
	else 
		logfile << "Stack has been destruct???\n\n";
	if (correct != true)
		logfile << "Stack is NOT OK\n";
	else
		logfile << "Stack is OK\n";

	logfile << "\n==================================================\n";

}

//-----------------------------------------------
*/

template <typename T>
void Stack<T>::dump()
{
	INFO
	//-----------------------------------------------
	bool correct = ok();
	logfile << "Amount of elements in the stack = " << count_ << '\n';
	logfile << "Stack adress = " << this << '\n';
	data_.dump();
	if (correct != true)
		logfile << "Stack is NOT OK\n";
	else
		logfile << "Stack is OK\n";

	logfile << "\n==================================================\n";
}

#endif