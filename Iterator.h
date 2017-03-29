#ifndef ITERATOR_H
#define ITERATOR_H

#include <iostream>
#include <conio.h>

using namespace std;

template <typename T>
class Iterator : public std::iterator<std::forward_iterator_tag, T>
{
public:
	Iterator(T* ptr) :
		ptr_(ptr)
	{}

	Iterator& operator ++()
	{
		ptr_++;
		std::cout << "Iterator::operator ++ was called" << endl;
		return *this;
	}

	T& operator *()
	{
		std::cout << "Iterator::operator * was called" << endl;
		return *ptr_;
	}

	bool operator != (const Iterator& rhs) const
	{
		std::cout << "Iterator::operator != was called" << endl;
		return (ptr_ != rhs.ptr_);
	}

private:
	T* ptr_;
};


#endif 
