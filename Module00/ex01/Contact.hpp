
#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>
using namespace std;

class Contact
{
public:
	string	fname;
	string	lname;
	string	nickname;
	int		phonenum;
	string	secret;
	void	Create();
};

void Contact::Create()
{
	cout << "Enter first name :\n";
	cin >> this->fname;
	cout << "Enter last name :\n";
	cin >> this->lname;
	cout << "Enter nickname :\n";
	cin >> this->nickname;
	cout << "Enter phone number :\n";
	cin >> this->phonenum;
	cout << "Enter secret:\n";
	cin >> this->secret;
}

#endif