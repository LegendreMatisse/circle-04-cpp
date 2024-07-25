/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 18:01:11 by mlegendr          #+#    #+#             */
/*   Updated: 2024/07/24 18:46:50 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

int main(void)
{
	Contact contact;

	std::string first_name = "John";
	std::string last_name = "Doe";
	std::string nickname = "JD";
	std::string phone_number = "123456789";
	std::string darkest_secret = "I'm Batman";

	contact.SetFirstName(first_name);
	contact.SetLastName(last_name);
	contact.SetNickname(nickname);
	contact.SetPhoneNumber(phone_number);
	
	std::cout << "First name: " << contact.GetFirstName() << std::endl;
	std::cout << "Last name: " << contact.GetLastName() << std::endl;
	std::cout << "Nickname: " << contact.GetNickname() << std::endl;
	std::cout << "Phone number: " << contact.GetPhoneNumber() << std::endl;
}