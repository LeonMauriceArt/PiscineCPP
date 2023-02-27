#include "Contact.hpp"
#include <limits>
#include <cstring>
using namespace std;

Contact::Contact(void) {return ;}

string Contact::getFname(void)
{
	return (this->fname);
}

string Contact::getLname(void)
{
	return (this->lname);
}

string Contact::getNickname(void)
{
	return (this->nickname);
}

string Contact::getPhonenum(void)
{
	return (this->phonenum);
}

string Contact::getSecret(void)
{
	return (this->secret);
}

void	Contact::setFname(string str)
{
	this->fname = str;
	return;
}

void	Contact::setLname(string str)
{
	this->lname = str;
	return;
}

void	Contact::setNickname(string str)
{
	this->nickname = str;
	return;
}

void	Contact::setPhonenum(string str)
{
	this->phonenum = str;
	return;
}

void	Contact::setSecret(string str)
{
	this->secret = str;
	return;
}