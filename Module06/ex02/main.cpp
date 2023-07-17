#include "./includes/Base.hpp"
#include "./includes/A.hpp"
#include "./includes/B.hpp"
#include "./includes/C.hpp"

#include <time.h>
#include <iostream>
#include <stdlib.h>

Base::~Base()
{
}

Base *generate(void)
{
	srand(time(NULL));
	int random = rand() % 3;
	if (random == 0)
		return (new A);
	else if (random == 1)
		return(new B);
	else
		return(new C);
}

void identify(Base *p)
{
	A *testA = dynamic_cast<A*>(p);
	B *testB = dynamic_cast<B*>(p);
	C *testC = dynamic_cast<C*>(p);
	if (testA)
		std::cout << "Object is of A type" << std::endl;
	else if (testB)
		std::cout << "Object is of B type" << std::endl;
	else if (testC)
		std::cout << "Object is of C type" << std::endl;
	else
		std::cout << "Error : object has no type" << std::endl;
}

// void identify(Base &p)
// {

// }

int main(void)
{
	Base *test = generate();
	identify(test);
	return (0);
}