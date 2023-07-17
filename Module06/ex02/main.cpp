#include "./includes/Base.hpp"
#include "./includes/A.hpp"
#include "./includes/B.hpp"
#include "./includes/C.hpp"

#include <ctime>
#include <iostream>

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
	
}

void identify(Base &p)
{

}

int main(void)
{
	return (0);
}