
#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>

const int MAX_CONTACTS = 8;
const int FIELD_SIZE = 10;

class Contact
{
public:
	Contact(void);
	std::string getFname(void);
	std::string getLname(void);
	std::string getNickname(void);
	std::string getPhonenum(void);
	std::string getSecret(void);
	void	setFname(std::string);
	void	setLname(std::string);
	void	setNickname(std::string);
	void	setPhonenum(std::string);
	void	setSecret(std::string);
private:
	std::string	fname;
	std::string	lname;
	std::string	nickname;
	std::string	phonenum;
	std::string	secret;
};

void	displayPhonebook(Contact phonebook[], int nbr_contacts);
Contact CreateContact(void);
std::string	correctContact(std::string field);
#endif