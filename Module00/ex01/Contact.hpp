
#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <iomanip>
#include <limits>

class Contact
{
public:
	Contact(void);
	~Contact(void);
	void	init(void);
	void	view(int index) const;
	void	display(void) const;
	void	setIndex(int i);
private:
	std::string	firstName;
	std::string	lastName;
	std::string	nickName;
	std::string	phoneNumber;
	std::string	darkestSecret;
	int	index;
	std::string printLen(std::string str) const;
	std::string getInput(std::string str) const;
};

#endif