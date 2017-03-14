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

static const int POISON = 10005;


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
	void dump() const;
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
		Array<Type> victim(R);
		if (this != &R)
		{
			/*delete[] data_;
			size_ = R.size_;
			data_ = new value_type[size_];
			for (size_t i = 0; i < size_; i++)
				data_[i] = R.data_[i];
				*/
//			Array:: ~Array();

			swap(victim);
			
		}
		cout << "---------------------------------------------\n";
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
//		ASSERT_OK();
		std::cout << "Operator []  was called" << endl;
		cout << "Print dump: " << endl;
//		dump();
		_getch();
//		ASSERT_OK();
		return *(data_+i);
	}

//--------------------------
//! Operator new
//--------------------------
	void * operator new[](size_t size, Type init, size_t n)
	{
		cout << "uyvu\n";
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
	}

	void* operator new[](size_t size, Type init, void* WhereToCreate)
	{
		cout << "xxx\n"
		WhereToCreate = malloc(size);
		memset(WhereToCreate, init, size);
		return WhereToCreate;
	}

	void* operator new [](size_t size, Type init)
	{
		std::cout << "ded hi\n"
		data_= (Type*)malloc(size);
		std::cout << data_ << endl;
		memset(data_, init, size);
		assert(data_);
		return data_;
	} 
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

//==========================================================================
//typedef float value_type; // Elements type


						  //template <typename Type>
						  //static const POISON = (Type)NAN;

template <typename Type>

Array<Type>::Array() :
	size_(0),
	data_(NULL)
{
	//	size_ = 10;
	//	data_ = new Type[size_];
	//	for (size_t i = 0; i < size_; i++)
	//		*(data_ + i) = 0;
	std::cout << "Constructor without parametres was called" << endl;
	INFO
		dump();
}

template <typename Type>
Array<Type>::Array(size_t size) :
	size_(size),
	data_(new Type[size_])
{
	//	data_ = new Type[size];
	//	size_ = size;
		for (size_t i = 0; i < size_; i++)
			data_[i] = 0;
	std::cout << "Constructor with parametr was called" << endl;
	INFO
		dump();
}

template <typename Type>
Array<Type>::~Array()
{
	for (size_t i = 0; i < size_; i++)
	{
		data_[i] = 1;
		size_ = 1;
	}
	delete[] data_;

	std::cout << "Distructor was called" << endl;
	INFO
		dump();
}

template <typename Type>

Array<Type>::Array<Type>(Array<Type> const& that)
{
	ASSERT_OK();


	size_ = that.size_;
	//data_ = new value_type[that.size_];

	//data_ = Vector::operator new(size_, 0, data_);
	//new(size_, 0, data_)Vector(that);
	data_ = new Type[size_];

	for (size_t i = 0; i < size_; i++)
	{
		data_[i] = that.data_[i];
		if (data_[i] != that.data_[i])
			std::cout << "aaaaaaaaa\n";
	}

	//std::cout << "Copy was called" << endl;
	INFO
		dump();
}

template <typename Type>
void Array<Type>::ReSize(size_t newsize)
{
	ASSERT_OK();
	Array<Type> t(newsize);
	//size_t p = newsize > size_ ? size_ : newsize;
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
	for (size_t i = 0; i < newsize; i++)
	{
		data_[i] = t.data_[i];
	}

	//std::cout << "Function Resize was called" << endl;
	INFO
		dump();
}

template <typename Type>
void Array<Type>::dump() const
{
	std::cout << "Masssive's name: " << data_ << endl;
	std::cout << "size: " << size_ << endl;
	std::cout << "aaaaa\n";
	for (size_t i = 0; i < size_; ++i)
	{
		std::cout << "gfafhafje\n" << i << '\n';
		std::cout << "[" << i << "] = " << *(data_ + i) << endl;
	}
	INFO
}

template <typename Type>
size_t Array<Type>::Size()
{
	ASSERT_OK();
	//std::cout << "Function Size was called" << endl;
	INFO
		dump();
	return size_;
}

template <typename Type>
Type Array<Type>::GetEl(size_t i) const
{
	//std::cout << "Function GetEl was called" << endl;
	INFO
		return data_[i];
}


//---------------------------
//!Check the mass
//---------------------------
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
		return true;
}

template <typename Type>
Type& Array<Type>::front()
{
	ASSERT_OK();
	INFO
		return data_[0];
}

template <typename Type>
Type & Array<Type>::at(size_t i)
{
	if (i <= size_)
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

template <typename Type>
Type & Array<Type>::back()
{
	ASSERT_OK();
	INFO
		return *(data_ + size_ - 1);
}

template <typename Type>
void Array<Type>::swap(Array<Type>& a)
{
	size_t t = size_;
	size_ = a.size_;
	a.size_ = t;

	cout << "Swaped size_t size_" << endl;

	Type *d = data_;
	cout << d << "=========================="<< endl;
	data_ = a.data_;
	a.data_ = d;

	cout << "Swaped value_type* data_" << endl;

	INFO
}

template <typename Type>
const Type* Array<Type>::data()
{
	ASSERT_OK();
	INFO
		return data_;
}

template <typename Type>
Type* Array<Type>::begin()
{
	ASSERT_OK();
	INFO
		return &data_[0];
}

template <typename Type>
Type * Array<Type>::end()
{
	ASSERT_OK();
	INFO
		return &data_[size_];
}

template <typename Type>
bool Array<Type>::empty()
{
	ASSERT_OK();
	if (begin() == end())
	{
		INFO
			return true;
	}
	else
	{
		INFO
			return false;
	}
}

template <typename Type>
size_t Array<Type>::size()
{
	ASSERT_OK();
	size_t size = std::distance(begin(), end());
	INFO
		return size;
}