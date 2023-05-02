#include "includes/Classes.hpp"
#include "includes/WrongAnimal.hpp"
#include "includes/WrongCat.hpp"

int main()
{
	std::cout << "---DELETE TEST---" << std::endl;
	Animal *animals[10];
	for (int i = 0; i < 10; i++)
	{
		if (i < 5)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}
	for (int i = 0; i < 10; i++)
		animals[i]->makeSound();
	for (int i = 0; i < 10; i++)
		delete (animals[i]);
	std::cout << "---END OF DELETE TEST---" << std::endl;
	std::cout << "---DEEP COPY TEST---" << std::endl;
	Dog zeus;
	zeus.think();
	{
		Dog tmp;
		tmp = zeus;
		tmp.remember();
	}
	zeus.remember();
	std::cout << "---END OF DEEP COPY TEST---" << std::endl;
	Animal *lol = new Dog();
	delete lol;
	return 0;
}