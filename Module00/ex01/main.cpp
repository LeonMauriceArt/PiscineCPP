/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaurin- <lmaurin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:19:42 by lmaurin-          #+#    #+#             */
/*   Updated: 2023/03/20 18:13:43 by lmaurin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>

int main(void)
{
	PhoneBook book;
	std::string input = "";
	book.welcomeMsg();
	while (input.compare("EXIT"))
	{
		if (input.compare("ADD") == 0)
			book.addContact();
		else if (input.compare("SEARCH") == 0)
		{
			book.printContacts();
			book.search();
		}
		std::cout << "> " << std::flush;
		std::cin >> input;
	}
	return (0);
}