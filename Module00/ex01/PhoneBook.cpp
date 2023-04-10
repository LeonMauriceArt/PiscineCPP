/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaurin- <lmaurin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:24:43 by lmaurin-          #+#    #+#             */
/*   Updated: 2023/03/20 19:24:39 by lmaurin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

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
	std::string input = "";
	while (!std::cin.eof())
	{
		std::cout << "Enter the desired contact index: ";
		if (std::getline(std::cin, input) && input != "")
		{
			if (input.size() == 1 && input[0] >= '0' && input[0] < '8')
				break;
		}
		if (input != "")
			std::cout << "Invalid index !" << std::endl;
	}
	return (input[0] - '0');
}

void PhoneBook::search(void) const
{
	int i = this->readInput();
	this->contacts[i].display();
}