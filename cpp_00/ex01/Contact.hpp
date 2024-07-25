/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 18:00:30 by mlegendr          #+#    #+#             */
/*   Updated: 2024/07/25 20:59:10 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP


# include <string> // ==> used for the string class
# include <iostream>
# include <iomanip> // ==> used for std::setw()

class Contact
{
	public:
			Contact(void); //constructor
			~Contact(void); //destructor

			//getters
			std::string	GetFirstName(void) const;
			std::string	GetLastName(void) const;
			std::string	GetNickName(void) const;
			std::string	GetPhoneNumber(void) const;
			std::string	GetDarkestSecret(void) const;
			int			GetOldest(void) const;

			//setters
			void		SetFirstName(std::string &first_name);
			void		SetLastName(std::string &last_name);
			void		SetNickName(std::string &nickname);
			void		SetPhoneNumber(std::string &phone_number);
			void		SetDarkestSecret(std::string &darkest_secret);
			void		SetOldest(int &oldest);

			//functions
			void		SaveContact(std::string firstName, std::string lastName, std::string nickName, std::string phoneNum, std::string secret);
			void		PrintContact(int index);
			void		PrintContactFull(int index);

	private:
			std::string	_firstName;
			std::string	_lastName;
			std::string	_nickname;
			std::string	_phoneNumber;
			std::string	_darkestSecret;
			int			_oldest;
};

#endif