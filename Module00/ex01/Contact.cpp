/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaurin- <lmaurin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 19:24:59 by lmaurin-          #+#    #+#             */
/*   Updated: 2023/03/20 19:25:00 by lmaurin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
}

Contact::~Contact()
{
}

std::string Contact::getInput(std::string str) const
{
	std::string input = "";
	bool correct = false;
	while (correct == false && !std::cin.eof())
	{
		std::cout << str << std::flush;
		std::getline(std::cin, input);
		if (input.empty() == 0)
			correct = true;
	}
	return (input);
}

void Contact::init(void)
{
	// std::cin.ignore();
	this->firstName = this->getInput("Please enter your first name: ");
	this->lastName = this->getInput("Please enter your last name: ");
	this->nickName = this->getInput("Please enter your nickname: ");
	this->phoneNumber = this->getInput("Please enter your phone number: ");
	this->darkestSecret = this->getInput("Please enter your darkest secret: ");
	std::cout << std::endl;
}

std::string Contact::printLen(std::string str) const
{
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	return(str);
}

void	Contact::setIndex(int i)
{
	this->index = i;
}

void	Contact::view(int index) const
{
	if (this->firstName.empty() || this->lastName.empty() || this->nickName.empty())
		return;
	std::cout << "|" << std::setw(10) << index << std::flush;
	std::cout << "|" << std::setw(10) << this->printLen(this->firstName)<< std::flush;
	std::cout << "|" << std::setw(10) << this->printLen(this->lastName) << std::flush;
	std::cout << "|" << std::setw(10) << this->printLen(this->nickName) << std::flush;
	std::cout << "|" << std::endl;
}

void	Contact::display(void) const
{
	if (this->firstName.empty() || this->lastName.empty() || this->nickName.empty() || this->phoneNumber.empty() || this->darkestSecret.empty())
		return;
	std::cout << std::endl;
	std::cout << "---" << this->firstName << " informations---" << std::endl;
	std::cout << std::endl;
	std::cout << "First name : " << this->firstName << std::endl;
	std::cout << "Last name : " << this->lastName << std::endl;
	std::cout << "Nickname : " << this->nickName << std::endl;
	std::cout << "Phonenumber : " << this->phoneNumber << std::endl;
	std::cout << "Darkest secret : " << this->darkestSecret << std::endl;
	std::cout << std::endl;
}