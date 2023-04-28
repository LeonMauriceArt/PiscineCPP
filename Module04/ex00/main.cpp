#include "includes/Classes.hpp"
#include "includes/WrongAnimal.hpp"
#include "includes/WrongCat.hpp"

int main()
{
	const Animal *meta = new Animal();
	const Animal *j = new Dog();
	const Animal *i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); // will output the cat sound!
	j->makeSound();
	meta->makeSound();
	delete (meta);
	delete (i);
	delete (j);

	const WrongAnimal *wrong = new WrongCat();
	std::cout << wrong->getType() << " " << std::endl;
	wrong->makeSound();

	WrongCat kitty;
	kitty.makeSound();

	Animal lll;
	lll.makeSound();
	delete(wrong);
	return 0;
}