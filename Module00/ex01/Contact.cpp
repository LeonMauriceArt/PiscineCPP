#include "Contact.hpp"
#include <limits>
#include <string>

Contact::Contact(void) {return ;}

std::string Contact::getFname(void)
{
	return (this->fname);
}

std::string Contact::getLname(void)
{
	return (this->lname);
}

std::string Contact::getNickname(void)
{
	return (this->nickname);
}

std::string Contact::getPhonenum(void)
{
	return (this->phonenum);
}

std::string Contact::getSecret(void)
{
	return (this->secret);
}

void	Contact::setFname(std::string str)
{
	this->fname = str;
	return;
}

void	Contact::setLname(std::string str)
{
	this->lname = str;
	return;
}

void	Contact::setNickname(std::string str)
{
	this->nickname = str;
	return;
}

void	Contact::setPhonenum(std::string str)
{
	this->phonenum = str;
	return;
}

void	Contact::setSecret(std::string str)
{
	this->secret = str;
	return;
}