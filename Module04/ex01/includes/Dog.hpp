#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain *brain;
	public:
		Dog();
		virtual ~Dog();
		Dog(const Dog & dog);
		Dog &operator=(const Dog & other);
		void makeSound() const;
		void think();
		void remember();
};

#endif