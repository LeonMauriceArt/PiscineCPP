#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
	protected:
		std::string type;
	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal &A);
		WrongAnimal& operator=(const WrongAnimal &A);
		virtual ~WrongAnimal();
		void makeSound() const;
		std::string getType() const;
};

#endif