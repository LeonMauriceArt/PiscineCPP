/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaurin- <lmaurin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:24:43 by lmaurin-          #+#    #+#             */
/*   Updated: 2023/03/20 19:06:50 by lmaurin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

// void addContact(void);
// void printContacts(void) const;
// void search(void) const;

PhoneBook::PhoneBook()
{
}

PhoneBook::~PhoneBook()
{
}

void PhoneBook::welcomeMsg(void) const
{
	std::cout << std::endl;
	std::cout << "Welcome to your new Phonebook !" << std::endl;
	std::cout << std::endl;
	std::cout << "------How to use it ?------" << std::endl;
	std::cout << "ADD\t: To add a contact." << std::endl;
	std::cout << "SEARCH\t: To search for a contact." << std::endl;
	std::cout << "EXIT\t: to quit the PhoneBook." << std::endl;
	std::cout << std::endl;
}

void PhoneBook::addContact(void)
{
	static int i;
	this->contacts[i % 8].init();
	this->contacts[i % 8].setIndex(i % 8);
	i++;
}

void PhoneBook::printContacts(void) const
{
	std::cout << "|     index|first name| last name|  nickname|" << std::endl;
	for (int i = 0; i < 8; i++)
		this->contacts[i].view(i);
	std::cout << std::endl;
}

int	PhoneBook::readInput() const
{
	int input = -1;
	bool correct = false;
	while (correct == false)
	{
		std::cout << "Enter the desired contact index: " << std::flush;
		std::cin >> input;
		if (std::cin.good() && (input >= 0 && input < 8))
			correct = true;
		else
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid index" << std::endl;
		}
	}
	return (input);
}

void PhoneBook::search(void) const
{
	int i = this->readInput();
	this->contacts[i].display();
}