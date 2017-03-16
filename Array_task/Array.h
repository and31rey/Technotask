//-----------------------------
//! @file Massive.h
//! Implements a massive class
//!
//! @author Ruslan, 2017
//-----------------------------

//-----------------------------
//! Massive class
//-----------------------------

#ifndef __ARRAY_H
#define __ARRAY_H

#include <iostream>
#include <conio.h>
#include "ServiceLib.h"

static const int POISON = NAN;

using std::cout;
using std::cin;

template <typename Type>
class Array
{
public:
	//---------------------------
	//! A constructor
	//---------------------------

	Array();

	//---------------------------
	//! A constructor with parametres
	//---------------------------

	Array(size_t size);

	//---------------------------
	//! A destructor
	//---------------------------

	~Array();

	//---------------------------
	//! @return a size of the array
	//---------------------------

	size_t Size();

	//---------------------------
	//! @return an element with index = i
	//---------------------------

	Type GetEl(size_t i) const;

	//---------------------------
	//! Changes a size of the array
	//---------------------------

	void ReSize(size_t newsize);

	//---------------------------
	//! Print dump
	//---------------------------

	void dump() const;

	//---------------------------
	//! Copy metod
	//---------------------------

	Array<Type>(Array<Type> const& that);

	//---------------------------
	//! @brief Operator = for arrays
	//! @detailed Method copy and swap 
	//---------------------------

	const Array<Type>& operator = (const Array<Type> &);
	
	//---------------------------
	//! @brief Operator []
	//---------------------------

	Type & operator [](const size_t);

	//--------------------------
	//! Operator new 1 TODO
	//--------------------------

	void* operator new[](size_t, Type);

	//--------------------------
	//! Operator new 2 TODO
	//--------------------------
	
	void* operator new[](size_t, Type, void*);

	//--------------------------
	//! Operator new 3 TODO
	//--------------------------

	//	void* operator new[](size_t, Type); equal new ¹1 but it isn't verificate.
 

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
	//!Returns TRUE if array is empty
	//--------------------------

	bool empty();

	//--------------------------
	//!Returns the number of elements in the container
	//--------------------------
	size_t size();


private:

	//---------------------------
	//! Function swaps fields
	//---------------------------

	void swap(Array<Type> &a);

	//---------------------------
	//! Check the array
	//---------------------------

	bool ok();

	size_t size_;
	Type * data_;

};

//==========================================================================


//-----------------------------------------------

template <typename Type>
Array<Type>::Array() :
	size_(0),
	data_(nullptr)
{
	//	size_ = 10;
	//	data_ = new Type[size_];
	//	for (size_t i = 0; i < size_; i++)
	//		*(data_ + i) = 0;
	#ifdef __MACROS_H
		std::cout << "Constructor without parametres was called" << endl;
	#endif	
	INFO
	dump();
	_getch();
}

//-----------------------------------------------

template <typename Type>
Array<Type>::Array(size_t size) :
	size_(size),
	data_(new Type[size_])
{
	//	data_ = new Type[size];
	//	size_ = size;
	for (size_t i = 0; i < size_; i++)
		data_[i] = 0;
	#ifdef __MACROS_H
		std::cout << "Constructor with parametr was called" << endl;
	#endif
	INFO
	dump();
	_getch();
}

//-----------------------------------------------

template <typename Type>
Array<Type>::~Array()
{
	for (size_t i = 0; i < size_; i++)
	{
		data_[i] = POISON;
	}

	size_ = NULL;
	delete[] data_;

	#ifdef __MACROS_H
		cout << "Distructor was called" << endl;
	#endif
	INFO
	dump();
	_getch();
}

//-----------------------------------------------

template <typename Type>
Array<Type>::Array<Type>(Array<Type> const& that)
{
	ASSERT_OK();

	size_ = that.size_;
	data_ = new Type[size_];

	if (ok())	
	{
		cout << "Copy was called" << endl;
		for (size_t i = 0; i < size_; i++)
		{
			data_[i] = that.data_[i];
		}
	}
	else 
		cout << "Copy was called with empty or incorrect array" << endl;
	INFO
	dump();
	_getch();
}

//-----------------------------------------------

template <typename Type>
const Array<Type>& Array<Type>::operator = (const Array<Type> &that)
{
	Array<Type> victim(that);
	if (this != &that)
	{
		/*
		delete[] data_;
		size_ = that.size_;
		data_ = new value_type[size_];
		for (size_t i = 0; i < size_; i++)
		data_[i] = that.data_[i];
		Array:: ~Array();
		*/

		swap(victim);

	}
	cout << "---------------------------------------------\n";
	std::cout << "Operator =  was called" << endl;
	cout << "Print dump: " << endl;
	dump();
	_getch();
	return *this;
}

//-----------------------------------------------

template <typename Type>
Type & Array<Type>::operator [](const size_t i)
{
	assert(i < size_);
	std::cout << "Operator []  was called" << endl;
	cout << "Print dump: " << endl;
	dump();
	_getch();
	assert (i < size_);
	return *(data_ + i);
}

//-----------------------------------------------

template <typename Type>
void * Array<Type>::operator new[](size_t size, Type init)
{
	#ifdef __MACROS_H
		PRINT("Operator new[] ¹1 was called")
	#endif
	void *p = (Type*)malloc(size * sizeof(Type));

	if (p != nullptr)
	{
		cout << "Allocated memory" << endl;
		memset(p, init, size * sizeof(Type));
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
}

//-----------------------------------------------

template <typename Type>
void* Array<Type>::operator new[](size_t size, Type init, void* WhereToCreate)
{
	#ifdef __MACROS_H
		PRINT("Operator new[] ¹2 was called")
	#endif
		WhereToCreate = malloc(size);
	memset(WhereToCreate, init, size * sizeof(Type));
	return WhereToCreate;
}

/*-----------------------------------------------

template <typename Type>

void* Array<Type>::operator new [](size_t size, Type init)
{
	#ifdef __MACROS_H
		PRINT("Operator new[] ¹3 was called")
	#endif
	data_ = (Type*)malloc(size);
	std::cout << data_ << endl;
	memset(data_, init, size);
	assert(data_);
	return data_;
}

//-----------------------------------------------*/


template <typename Type>
void Array<Type>::ReSize(size_t newsize)
{
	ASSERT_OK();
	Array<Type> t(newsize);
	if (newsize > size_)
	{
		for (size_t i = 0; i < size_; i++)
		{
			t.data_[i] = data_[i];
		}
		for (size_t i = size_; i < newsize; i++)
		{
			t.data_[i] = 0;
		}
	}
	else
	{
		for (size_t i = 0; i < newsize; i++)
		{
			t.data_[i] = data_[i];
		}
	}
	delete[] data_;
	data_ = new Type[newsize];
	size_ = newsize;
	for (size_t i = 0; i < newsize; i++)
	{
		data_[i] = t.data_[i];
	}

	cout << "Function Resize was called" << endl;
	INFO
	dump();
	_getch();
}

//-----------------------------------------------

template <typename Type>
void Array<Type>::dump() const
{
	cout << "Masssive's name: " << data_ << endl;
	cout << "size: " << size_ << endl;
	for (size_t i = 0; i < size_; ++i)
	{
		cout << "[" << i << "] = " << data_[i] << endl;
	}
	cout << "Dump was called" << endl;
	INFO
}

//-----------------------------------------------

template <typename Type>
size_t Array<Type>::Size()
{
	ASSERT_OK();
	cout << "Function Size was called" << endl;
	INFO
	dump();
	_getch();
	ASSERT_OK();
	return size_;
}

//-----------------------------------------------

template <typename Type>
Type Array<Type>::GetEl(size_t i) const
{
	cout << "Function GetEl was called" << endl;
	INFO
	_getch();
	assert (i < size_);
	return data_[i];
}

//-----------------------------------------------

template <typename Type>
bool Array<Type>::ok()
{
	for (size_t i = 0; i < size_; i++)
		if (this->GetEl(i) == POISON || this->size_ == NULL)
		{
			INFO
				return false;
		}
	INFO
	_getch();
	
	return true;
}

//-----------------------------------------------

template <typename Type>
Type& Array<Type>::front()
{
	ASSERT_OK();
	INFO
	_getch();
	
	return data_[0];
}

//-----------------------------------------------

template <typename Type>
Type & Array<Type>::at(size_t i)
{
	if (i < size_)
	{
		cout << "Provide access unto Vector's element" << endl;
		INFO
			return data_[i];
	}
	else
	{
		cout << "Index is very big, please reduce it, give a provide to the last element" << endl;
		INFO
		_getch();
	}
	
	return data_[size_ - 1];
}

//-----------------------------------------------

template <typename Type>
Type & Array<Type>::back()
{
	ASSERT_OK();
	INFO
	_getch();
		
	return data_ [size_ - 1];
}

//-----------------------------------------------

template <typename Type>
void Array<Type>::swap(Array<Type>& a)
{
	size_t t = size_;
	size_ = a.size_;
	a.size_ = t;

	cout << "Swaped size_t size_" << endl;

	Type *d = data_;
	cout << d << "==========================" << endl;
	data_ = a.data_;
	a.data_ = d;

	cout << "Swaped value_type* data_" << endl;

	INFO
	_getch();
}

//-----------------------------------------------

template <typename Type>
const Type* Array<Type>::data()
{
	ASSERT_OK();
	INFO
	_getch();
		
	return data_;
}

//-----------------------------------------------

template <typename Type>
Type* Array<Type>::begin()
{
	ASSERT_OK();
	INFO
	_getch();
	
	return data_;
}

//-----------------------------------------------

template <typename Type>
Type * Array<Type>::end()
{
	ASSERT_OK();
	INFO
	_getch();
	
	return data_+size_;
}

//-----------------------------------------------

template <typename Type>
bool Array<Type>::empty()
{
	ASSERT_OK();
	if (begin() == end())
	{
		INFO
		_getch();
		
		return true;
	}
	else
	{
		INFO
		_getch();
		
		return false;
	}
}

//-----------------------------------------------

template <typename Type>
size_t Array<Type>::size()
{
	ASSERT_OK();
	size_t size = std::distance(begin(), end());
	INFO
	_getch();
	

	return size;
}

#endif
