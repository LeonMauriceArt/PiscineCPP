
#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>
using namespace std;

const int MAX_CONTACTS = 8;
const int FIELD_SIZE = 10;

class Contact
{
public:
	Contact(void);
	string getFname(void);
	string getLname(void);
	string getNickname(void);
	string getPhonenum(void);
	string getSecret(void);
	void	setFname(string);
	void	setLname(string);
	void	setNickname(string);
	void	setPhonenum(string);
	void	setSecret(string);
private:
	string	fname;
	string	lname;
	string	nickname;
	string	phonenum;
	string	secret;
};

void	displayPhonebook(Contact phonebook[], int nbr_contacts);
Contact addContact(void);
string	correctContact(string field);
#endif