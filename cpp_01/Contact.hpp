/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 18:00:30 by mlegendr          #+#    #+#             */
/*   Updated: 2024/07/24 20:46:55 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string> // ==> used for the string class
# include <iostream>
# include <iomanip> // ==> used for std::setw()

class Contact
{
	private:
			Contact(void); //constructor
			~Contact(void); //destructor

			//getters
			std::string GetFirstName() const
			{
				return _FirstName;
			}
			std::string GetLastName() const
			{
				return _SecondName;
			}
			std::string GetNickname() const
			{
				return _Nickname;
			}
			std::string GetPhoneNumber() const
			{
				return _PhoneNumber;
			}
			std::string GetDarkestSecret() const
			{
				return _DarkestSecret;
			}

			//setters
			void SetFirstName(std::string &first_name)
			{
				this->_FirstName = first_name;
			}
			void SetLastName(std::string &last_name)
			{
				this->_SecondName = last_name;
			}
			void SetNickname(std::string &nickname)
			{
				this->_Nickname = nickname;
			}
			void SetPhoneNumber(std::string &phone_number)
			{
				this->_PhoneNumber = phone_number;
			}
			void SetDarkestSecret(std::string &darkest_secret)
			{
				this->_DarkestSecret = darkest
			}

	private:
			std::string _FirstName;
			std::string _SecondName;
			std::string _Nickname;
			std::string _PhoneNumber;
			std::string _DarkestSecret;
}

#endif