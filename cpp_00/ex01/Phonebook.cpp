/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 18:00:45 by mlegendr          #+#    #+#             */
/*   Updated: 2024/07/26 20:24:00 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include <string>
#include "Phonebook.hpp"
#include "Contact.hpp"

//constructors
Phonebook::Phonebook(void): _contactIndex(0), _contactCount(0)
{
	std::cout << "Phonebook constructor called" << std::endl;
	return;
}

Phonebook::~Phonebook()
{
	std::cout << "\nPhonebook destructor called" << std::endl;
	return;
}

//functions
void Phonebook::_PrintHeader(void)
{
	std::cout << "|" << std::right << std::setw(10) << "Index" << "|" << std::flush;
	std::cout << std::right << std::setw(10) << "First name" << "|" << std::flush;
	std::cout << std::right << std::setw(10) << "Last name" << "|" << std::flush;
	std::cout << std::right << std::setw(10) << "Nickname" << "|" << std::endl;
}

void	Phonebook::AddContact(std::string firstName, std::string lastName, std::string nickName, std::string phoneNum, std::string secret)
{
	if (!firstName.length() || !lastName.length() || !nickName.length() || !phoneNum.length() || !secret.length())
	{
		std::cout << "Please fill in all fields." << std::endl;
		return;
	}
	if (this->_contactIndex == 8)
	{
		this->_contactIndex = 0;	
	}
	this->_contacts[this->_contactIndex].SaveContact(firstName, lastName, nickName, phoneNum, secret);
	this->_contactIndex++;
	if (this->_contactCount < 8)
	{
		this->_contactCount++;
	}
}

void	Phonebook::SearchContact(std::string input)
{
	std::stringstream ss(input);
	int index;

	ss >> index;
	index--;
	
	if (index < 0 || index >= this->_contactCount)
	{
		std::cout << "Index not present." << std::endl;
		return;
	}
	this->_contacts[index].PrintContactFull();
}

void	Phonebook::PrintSearch(void)
{
	int i = 0;

	Phonebook::_PrintHeader();
	while (i < 8)
	{
		if (i >= this->_contactCount)
			break;
		this->_contacts[i].PrintContact(i);
		i++;
	}
}
