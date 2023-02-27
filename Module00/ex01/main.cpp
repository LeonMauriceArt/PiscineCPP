#include "Contact.hpp"

void AddContact(Contact Phonebook[], int i)
{
	Phonebook[i] = CreateContact();
	std::cout << "You added " << Phonebook[i].getFname() << " to your phonebook !" << std::endl;
	return;
}

int main(void)
{
	int	i = 0;
	int	nbr_contacts = 0;
	Contact	Phonebook[MAX_CONTACTS];
	std::cout << "Hello and welcome to Leon's phonebook !\n To add an user, enter ADD.\n To search for and user, enter SEARCH.\n Finally, enter EXIT to quit this phonebook !\n";
	std::string input;
	getline(std::cin, input);
	while (input.compare("EXIT") != 0)
	{
		if (i == MAX_CONTACTS)
			i = 0;
		if(input.compare("ADD") == 0)
		{
			AddContact(Phonebook, i);
			i++;
			if (nbr_contacts != 8)
				nbr_contacts++;
		}
		if(input.compare("SEARCH") == 0)
		{
			if (nbr_contacts == 0)
				std::cout << "Your phonebook is empty !" << std::endl;
			else
				displayPhonebook(Phonebook, nbr_contacts);
		}
		getline(std::cin, input);
	}
	return (0);
}