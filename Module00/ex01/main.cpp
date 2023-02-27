#include "Contact.hpp"
using namespace std;

void AddContact(Contact Phonebook[], int i)
{
	Phonebook[i] = addContact();
	cout << "You added " << Phonebook[i].getFname() << " to your phonebook !" << endl;
	return;
}

int main(void)
{
	int	i = 0;
	int	nbr_contacts = 0;
	Contact	Phonebook[MAX_CONTACTS];
	cout << "Hello and welcome to Leon's phonebook !\n To add an user, enter ADD.\n To search for and user, enter SEARCH.\n Finally, enter EXIT to quit this phonebook !\n";
	string input;
	getline(cin, input);
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
				cout << "Your phonebook is empty !" << endl;
			else
				displayPhonebook(Phonebook, nbr_contacts);
		}
		getline(cin, input);
	}
	return (0);
}