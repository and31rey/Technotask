#include <stdio.h>
#include <math.h>
#include <string.h>
#include <locale.h>
#include <iostream>
#include <cstdlib>
#include "Stack.h"
int EnterCommand();
bool operation(Stack<double>*, int);






int EnterCommand() //Ввод команд и их анализ
{
      int i=0;
      char c[100];
	  std::cout << "Enter\n";
      char *sc [10]={"end","push","pop","add","sub","mul","div","sin","cos","pow"};
      std::cin >> c;
	  std::cout << c << '!' << '\n';
      while (i<10)
      {
        if (_stricmp(c,sc[i])==0)
            return i;
        else ++i;
      }
      return -1;
}


bool operation(Stack<double>* s, int operand) //Выполнение команды

{
	std::cout << operand << " operand" <<'\n';

    double x = 5;

    switch(operand)
    {
        case 1:
        {

        //printf("Please enter a number\n");
		std::cin >> x;
		std::cout << operand << " operand" << '\n';
        if (!(s->push(x)))

			std::cout << "Error\n"; 
			break;
        }
        case 2:
        {
		double a = s->pop();
		if ((a - a) <= 0.001) {
			printf("%lf\n", a);s->push(0);break;
		}
		else PRINT("Error"); system("pause"); break;
        }
        case 3:
        {
		s->push(s->pop()+ s->pop());break;
        }
        case 4:
        {
		s->push(-(s->pop()- s->pop()));break;
        }
        case 5:
        {
		s->push(s->pop()*s->pop());break;
        }
        case 6:
        {
		s->push(s->pop()/ s->pop());break;
        }
        case 7:
        {
		s->push(sin(s->pop()));break;
        }
        case 8:
        {
        s->push(cos(s->pop()));break;
        }
        case 0:
        {
        return false;
        }
        case 9:
        {
        s->push(pow(s->pop(),s->pop()));break;
        }
        default:
        {
        printf("Error, bad command\n");
        }
	}
	return true;
}

int main()
{
    setlocale(LC_ALL,"Russian");
    printf("Программа обрабатывает следующие команды:\nend, push, pop, add, sub, mul, div, sin, cos, pow\n");
    int s = 1;
	Stack<double> s1;
	s1.dump();
	while (s != false)		
    {
        //int c;
        //c=EnterCommand();	
//		s1.dump();
        s = operation(&s1, EnterCommand());
		system("pause");
		std::cout << s << '\n';

    }
	
	s1.~Stack();
    s1.dump();
	printf("Completed!\n");
    return 0;
}

