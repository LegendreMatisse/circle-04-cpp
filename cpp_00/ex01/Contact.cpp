/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 18:00:22 by mlegendr          #+#    #+#             */
/*   Updated: 2024/07/25 20:44:35 by mlegendr         ###   ########.fr       */
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

//getters
std::string Contact::GetFirstName(void) const
{
	return _firstName;
}

std::string Contact::GetLastName(void) const
{
	return _lastName;
}

std::string Contact::GetNickName(void) const
{
	return _nickname;
}

std::string Contact::GetPhoneNumber(void) const
{
	return _phoneNumber;
}

std::string Contact::GetDarkestSecret(void) const
{
	return _darkestSecret;
}

int Contact::GetOldest(void) const
{
	return _oldest;
}

//setters
void Contact::SetFirstName(std::string &firstName)
{
	this->_firstName = firstName;
}

void Contact::SetLastName(std::string &lastName)
{
	this->_lastName = lastName;
}

void Contact::SetNickName(std::string &nickName)
{
	this->_nickname = nickName;
}

void Contact::SetPhoneNumber(std::string &phoneNumber)
{
	this->_phoneNumber = phoneNumber;
}

void Contact::SetDarkestSecret(std::string &darkestSecret)
{
	this->_darkestSecret = darkestSecret;
}

void Contact::SetOldest(int &oldest)
{
	this->_oldest = oldest;
}

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
	std::cout << "|" << std::setw(10) << index + 1 << "|";
	if (this->_firstName.length() > 10)
		std::cout << std::setw(10) << this->_firstName.substr(0, 9) + '.' << "|";
	else
		std::cout << std::setw(10) << this->_firstName << "|";
	if (this->_lastName.length() > 10)
		std::cout << std::setw(10) << this->_lastName.substr(0, 9) + '.' << "|";
	else
		std::cout << std::setw(10) << this->_lastName << "|";
	if (this->_nickname.length() > 10)
		std::cout << std::setw(10) << this->_nickname.substr(0, 9) + '.' << "|";
	else
		std::cout << std::setw(10) << this->_nickname << "|";
	std::cout << std::endl;	
}

void Contact::PrintContactFull(int index)
{
	std::cout << "Index: " << index + 1 << std::endl;
	std::cout << "First name: " << this->_firstName << std::endl;
	std::cout << "Last name: " << this->_lastName << std::endl;
	std::cout << "nickName: " << this->_nickname << std::endl;
	std::cout << "Phone number: " << this->_phoneNumber << std::endl;
	std::cout << "Darkest secret: " << this->_darkestSecret << std::endl;
}
