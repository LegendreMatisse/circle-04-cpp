/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 18:01:11 by mlegendr          #+#    #+#             */
/*   Updated: 2024/07/26 20:26:47 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "Phonebook.hpp"
#include <iostream>
#include <string>
#include <iomanip>
#include <ios>
#include <limits>
#include <cstdlib>

int main(void)
{	
	std::string command = "";
	bool exit = false;
	Phonebook phonebook;

	std::cout << "Enter a command: \n" << std::flush;
	std::cout << "Use ADD to add a contact\n" << std::flush;
	std::cout << "Use SEARCH to search for a contact\n" << std::flush;
	std::cout << "Use EXIT to exit the program\n" << std::flush;
	
	while (exit == false)
	{
		std::cout << "> " << std::flush;
        std::getline(std::cin, command);

		if (std::cin.eof())
		{
			exit = true;
			std::cout << "Exiting program." << std::endl;
			std::exit(0);		
		}
		if (command.compare("ADD") == 0)
		{
			std::string first_name;
			std::string last_name;
			std::string nickname;
			std::string phone_number;
			std::string darkest_secret;
			

			std::cout << std::left << std::setw(20) << "Enter first name" << ": " << std::flush;
			std::getline(std::cin, first_name);
			if (std::cin.eof()) break;
			std::cout << std::left << std::setw(20) << "Enter last name" << ": " << std::flush;
			std::getline(std::cin, last_name);
			if (std::cin.eof()) break;
			std::cout << std::left << std::setw(20) << "Enter nickname" << ": " << std::flush;
			std::getline(std::cin, nickname);
			if (std::cin.eof()) break;
			std::cout << std::left << std::setw(20) << "Enter phone number" << ": " << std::flush;
			std::getline(std::cin, phone_number);
			if (std::cin.eof()) break;
			std::cout << "Enter darkest secret: " << std::flush;
			std::getline(std::cin, darkest_secret);
			if (std::cin.eof()) break;
			phonebook.AddContact(first_name, last_name, nickname, phone_number, darkest_secret);
		}
		else if (command.compare("SEARCH") == 0)
		{
			std::string index;
			
			phonebook.PrintSearch();
			
			std::cout << "Enter the index of the contact you want to search for: " << std::flush;
			std::getline(std::cin, index);
			if (std::cin.eof()) break;
			phonebook.SearchContact(index);
		}
		else if (command.compare("EXIT") == 0)
		{
			exit = true;
			std::cout << "Exiting program." << std::endl;
			std::exit(0);
		}
		else
		{
			std::cout << "Invalid command." << std::endl;
		}
	}
	return (0);
}
