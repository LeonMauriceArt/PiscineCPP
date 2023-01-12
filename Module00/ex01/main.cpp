#include "phonebook.hpp"
using namespace std;

void AddContact(Phonebook MyPhonebook, int i)
{
	Contact NewContact;
	NewContact.Create();
	MyPhonebook.PhoneContact[i] = NewContact;
}

int main(void)
{
	Phonebook 	MyPhonebook;
	int			i = 0;
	cout << "Hello and welcome to Leon's phonebook !\n To add an user, enter ADD.\n To search for and user, enter SEARCH.\n Finally, enter EXIT to quit this phonebook !\n";
	string input;
	cin >> input;
	while (input.compare("EXIT") != 0)
	{
		if(input.compare("ADD") == 0)
			AddContact(MyPhonebook, i);
		if(input.compare("SEARCH") == 0)
			cout << "search";
		cin >> input;
	}
	cout << MyPhonebook.PhoneContact[0].fname;
	return (0);
}