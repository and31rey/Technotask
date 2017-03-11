#pragma once
#include <iostream>
#include <conio.h>
#include "ServiceLib.h"

//-----------------------------
//! @file Massive.h
//! Implements a massive class
//!
//! @author Ruslan, 2017
//-----------------------------

//-----------------------------
//! Massive class
//-----------------------------

//typedef float value_type;
using namespace std;
template <typename Type>

class Array
{
public:
	//typedef float value_type; //!< Elements type
//---------------------------
//!A constructor
//---------------------------
	Array();
//---------------------------
//!A constructor with parametres
//---------------------------
	Array(size_t size);
//---------------------------
//! A destructor
//---------------------------
	~Array();

//---------------------------
//!Return a size of the array
//---------------------------
	size_t Size();
//---------------------------
//!Return an element with index = i
//---------------------------
	Type GetEl(size_t i) const;
	
//---------------------------
//!Changes a size of the array
//---------------------------
	void ReSize(size_t newsize);
//---------------------------
//!Print dump
//---------------------------
	void dump();
//---------------------------
//!Check the array
//---------------------------
	bool ok();
//---------------------------
//!Copy metod
//---------------------------
	Array<Type> (Array<Type> const& that);
//---------------------------
//! Operator =
//---------------------------
	const Array& operator = (const Array<Type>&R)
	{
		if (this != &R)
		{
			/*delete[] data_;
			size_ = R.size_;
			data_ = new value_type[size_];
			for (size_t i = 0; i < size_; i++)
				data_[i] = R.data_[i];
				*/
			Array:: ~Array();

			Array<Type> victim(R);
			swap(victim);
			
		}
		
		std::cout << "Operator =  was called" << endl;
		cout << "Print dump: " << endl;
		dump();
		_getch();
		return *this;
	}
	
//---------------------------
//! Operator =
//---------------------------
	Type & operator [](size_t i)
	{
		std::cout << "Operator []  was called" << endl;
		cout << "Print dump: " << endl;
		dump();
		_getch();
		return *(data_+i);
	}

//--------------------------
//! Operator new
//--------------------------
	/*void * operator new(unsigned int size,size_t n, int init)
	{
		void * p = malloc(size*n);
	
	if (p != NULL)
		{
			cout << "Allocated memory" << endl;
			_getch();
			memset(p, init, size*n);
			cout << "Filled memory" << endl;
			_getch();
			return p;
	}
	else
	{
		cout << "Not enough memory" << endl;
		_getch();
		return p;
	}
	}*/

	/*void* operator new(size_t size, size_t init, void* WhereToCreate)
	{
		WhereToCreate = malloc(size);
		memset(WhereToCreate, init, size);
		return WhereToCreate;
	}*/

	/*void* operator new(size_t size, int init, Type * data)
	{
		data = (Type*)malloc(size);
		memset(data, init, size);
		return data;
	}*/
//---------------------------
//! It provides access to the first element
//---------------------------
	Type & front();
//---------------------------
//! It provides access to the last element
//---------------------------
	Type & back();
//---------------------------
//! It provides access to the i element
//---------------------------
	Type & at(size_t i);

//---------------------------
//! Function swaps fields
//---------------------------
	void swap(Array<Type> &a);
	
//---------------------------
//!Returns pointer to the underlying array serving as element storage
//---------------------------
	const Type * data();

//--------------------------
//!Returns pointer to the first element
//--------------------------
	Type * begin();

//--------------------------
//!Returns pointer to the imaginary nonexistent element following the last.
//--------------------------
	Type * end();

//--------------------------
//!Returns TRUE if vector is empty
//--------------------------
	bool empty();

//--------------------------
//!Returns the number of elements in the container
//--------------------------
	size_t size();


private:
	size_t size_;
	Type * data_;
		
};


