#include "Contact.hpp"

Contact CreateContact(void)
{
	Contact newContact;
	std::string	buff;

	while(true)
	{
		std::cout << "Enter first name :" << std::endl;
		getline(std::cin, buff);
		if(buff.empty())
		{
			std::cout << "Field cannot be empty." << std::endl;
			continue;
		}
		newContact.setFname(buff);
		break;
	}
	while(true)
	{
		std::cout << "Enter last name :" << std::endl;
		getline(std::cin, buff);
		if(buff.empty())
		{
			std::cout << "Field cannot be empty." << std::endl;
			continue;
		}
		newContact.setLname(buff);
		break;
	}
	while(true)
	{
		std::cout << "Enter nickname :" << std::endl;
		getline(std::cin, buff);
		if(buff.empty())
		{
			std::cout << "Field cannot be empty." << std::endl;
			continue;
		}
		newContact.setNickname(buff);
		break;
	}
	while(true)
	{
		std::cout << "Enter phone number :" << std::endl;
		getline(std::cin, buff);
		if(buff.empty())
		{
			std::cout << "Field cannot be empty." << std::endl;
			continue;
		}
		newContact.setPhonenum(buff);
		break;
	}
	while(true)
	{
		std::cout << "Enter darkest secret :" << std::endl;
		getline(std::cin, buff);
		if(buff.empty())
		{
			std::cout << "Field cannot be empty." << std::endl;
			continue;
		}
		newContact.setSecret(buff);
		break;
	}
	return (newContact);
}

std::string	correctContact(std::string field)
{
	field = field.erase((FIELD_SIZE - 1), field.length() - (FIELD_SIZE - 1));
	field.append(".");
	return (field);
}

void	displayPhonebook(Contact phonebook[], int nbr_contacts)
{
	std::cout << "|     index|first name| last name|  nickname|" << std::endl;
	for (int i = 0; i < nbr_contacts; i++)
	{
		std::string firstname = phonebook[i].getFname();
		if (firstname.length() > FIELD_SIZE)
			correctContact(firstname);
		std::cout << "|" << i << "|" << phonebook[i].getFname() << "|" << std::endl;
	}
}