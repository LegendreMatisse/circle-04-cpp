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

Contact::Contact(void): 
{
	std::cout << "Contact constructor called" << std::endl;
	return;
}

Contact::~Contact(void)
{
	std::cout << "Contact destructor called" << std::endl;
	return;
}

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

void Contact::SaveContact(std::string firstName, std::string lastName, std::string nickName, std::string phoneNum, std::string secret)
{
	//Contact::SetFirstName(firstName);
	this->_firstName = firstName;
	Contact::SetLastName(lastName);
	Contact::SetNickName(nickName);
	Contact::SetPhoneNumber(phoneNum);
	Contact::SetDarkestSecret(secret);
}

void Contact::PrintContact(int index)
{
	std::cout << "|" << std::setw(10) << index + 1 << "|";
	if (Contact::GetFirstName().length() > 10)
		std::cout << std::setw(10) << Contact::GetFirstName().substr(0, 9) + '.' << "|";
	else
		std::cout << std::setw(10) << Contact::GetFirstName() << "|";
	if (Contact::GetLastName().length() > 10)
		std::cout << std::setw(10) << Contact::GetLastName().substr(0, 9) + '.' << "|";
	else
		std::cout << std::setw(10) << Contact::GetLastName() << "|";
	if (Contact::GetNickName().length() > 10)
		std::cout << std::setw(10) << Contact::GetNickName().substr(0, 9) + '.' << "|";
	else
		std::cout << std::setw(10) << Contact::GetNickName() << "|";
	std::cout << std::endl;	
}

void Contact::PrintContactFull(int index)
{
	std::cout << "Index: " << index + 1 << std::endl;
	std::cout << "First name: " << Contact::GetFirstName() << std::endl;
	std::cout << "Last name: " << Contact::GetLastName() << std::endl;
	std::cout << "Nickname: " << Contact::GetNickName() << std::endl;
	std::cout << "Phone number: " << Contact::GetPhoneNumber() << std::endl;
	std::cout << "Darkest secret: " << Contact::GetDarkestSecret() << std::endl;
}
