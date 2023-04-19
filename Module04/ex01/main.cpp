#include "includes/Classes.hpp"
#include "includes/WrongAnimal.hpp"
#include "includes/WrongCat.hpp"

int main()
{
	// const Animal *meta = new Animal();
	// const Animal *j = new Dog();
	// const Animal *i = new Cat();
	// std::cout << j->getType() << " " << std::endl;
	// std::cout << i->getType() << " " << std::endl;
	// i->makeSound(); // will output the cat sound!
	// j->makeSound();
	// meta->makeSound();
	// delete (meta);
	// delete (i);
	// delete (j);

	Animal *animals[3];
	for (int i = 0; i < 2; i++)
	{
		animals[i] = new Dog();
	}
	animals[0]->makeSound();
	animals[1]->makeSound();
	return 0;
}