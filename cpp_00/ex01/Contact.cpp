/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 18:00:22 by mlegendr          #+#    #+#             */
/*   Updated: 2024/07/26 20:14:44 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.hpp"

//constructors
Contact::Contact(void)
{
	std::cout << "Contact constructor called" << std::endl;
	return;
}

Contact::~Contact(void)
{
	std::cout << "Contact destructor called" << std::endl;
	return;
}

//functions
void Contact::SaveContact(std::string firstName, std::string lastName, std::string nickName, std::string phoneNum, std::string secret)
{
	this->_firstName = firstName;
	this->_lastName = lastName;
	this->_nickname = nickName;
	this->_phoneNumber = phoneNum;
	this->_darkestSecret = secret;
}

void Contact::PrintContact(int index)
{
	std::cout << "|" << std::right << std::setw(10) << index + 1 << "|";
	if (this->_firstName.length() > 10)
		std::cout << std::right << std::setw(10) << this->_firstName.substr(0, 9) + '.' << "|";
	else
		std::cout << std::right << std::setw(10) << this->_firstName << "|";
	if (this->_lastName.length() > 10)
		std::cout << std::right << std::setw(10) << this->_lastName.substr(0, 9) + '.' << "|";
	else
		std::cout << std::right << std::setw(10) << this->_lastName << "|";
	if (this->_nickname.length() > 10)
		std::cout << std::right << std::setw(10) << this->_nickname.substr(0, 9) + '.' << "|";
	else
		std::cout << std::right << std::setw(10) << this->_nickname << "|";
	std::cout << std::endl;	
}

void Contact::PrintContactFull(void)
{
	std::cout << std::left << std::setw(14) << "First name" << ": " << this->_firstName << std::endl;
	std::cout << std::left << std::setw(14) << "Last name" << ": " << this->_lastName << std::endl;
	std::cout << std::left << std::setw(14) << "nickName" << ": " << this->_nickname << std::endl;
	std::cout << std::left << std::setw(14) << "Phone number" << ": " << this->_phoneNumber << std::endl;
	std::cout << "Darkest secret: " << this->_darkestSecret << std::endl;
}
