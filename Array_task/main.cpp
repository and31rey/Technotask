#include <iostream>
#include <conio.h>
#include "Array.h"

using namespace std;

int main()
{

	/*Int a(3);
	Int c(4);
	Int d;
	d == a + c;
	*/
	//PRINT_(d.number_);
	
	//cout << d.number_ << endl;
	
	Array<double> A(10);
	A[5] = 10;
	Array<double> B(10);
	cout << "/////////////////// \n" << &B << endl;
	B = A;
	cout <<"/////////////////// \n" << &B << endl;

	cout << "=================================================\n";
	B.dump();
	cout << "//////////////// \n" << &B << endl;
	cout << B[5] << endl;
	/*Vector<int> B(5);
	Vector<int> C = A;
	Vector<int> D;
	D = A;
	
	D.front() = 5;
	D.dump();
	*/
	//D.at(3) = 1;
	//D.dump();


	_getch();
	
}

