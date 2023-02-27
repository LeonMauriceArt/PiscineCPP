#include "Contact.hpp"

Contact addContact(void)
{
	Contact newContact;
	string	buff;

	while(true)
	{
		cout << "Enter first name :" << endl;
		getline(cin, buff);
		if(buff.empty())
		{
			cout << "Field cannot be empty." << endl;
			continue;
		}
		newContact.setFname(buff);
		break;
	}
	while(true)
	{
		cout << "Enter last name :" << endl;
		getline(cin, buff);
		if(buff.empty())
		{
			cout << "Field cannot be empty." << endl;
			continue;
		}
		newContact.setLname(buff);
		break;
	}
	while(true)
	{
		cout << "Enter nickname :" << endl;
		getline(cin, buff);
		if(buff.empty())
		{
			cout << "Field cannot be empty." << endl;
			continue;
		}
		newContact.setNickname(buff);
		break;
	}
	while(true)
	{
		cout << "Enter phone number :" << endl;
		getline(cin, buff);
		if(buff.empty())
		{
			cout << "Field cannot be empty." << endl;
			continue;
		}
		newContact.setPhonenum(buff);
		break;
	}
	while(true)
	{
		cout << "Enter darkest secret :" << endl;
		getline(cin, buff);
		if(buff.empty())
		{
			cout << "Field cannot be empty." << endl;
			continue;
		}
		newContact.setSecret(buff);
		break;
	}
	return (newContact);
}

string	correctContact(string field)
{
	field = field.erase((FIELD_SIZE - 1), field.length() - (FIELD_SIZE - 1));
	field.append(".");
	return (field);
}

void	displayPhonebook(Contact phonebook[], int nbr_contacts)
{
	cout << "|     index|first name| last name|  nickname|" << endl;
	for (int i = 0; i < nbr_contacts; i++)
	{
		string firstname = phonebook[i].getFname();
		firstname = firstname. > FIELD_SIZE ? correctContact(firstname) : firstname;
		cout << "|" << i << "|" << phonebook[i].getFname() << "|" << endl;
	}
}