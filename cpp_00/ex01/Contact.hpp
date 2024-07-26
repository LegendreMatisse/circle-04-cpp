/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 18:00:30 by mlegendr          #+#    #+#             */
/*   Updated: 2024/07/26 20:17:54 by mlegendr         ###   ########.fr       */
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
			~Contact(); //destructor

			//functions
			void		SaveContact(std::string firstName, std::string lastName, std::string nickName, std::string phoneNum, std::string secret);
			void		PrintContact(int index);
			void		PrintContactFull(void);

	private:
			std::string	_firstName;
			std::string	_lastName;
			std::string	_nickname;
			std::string	_phoneNumber;
			std::string	_darkestSecret;
};

#endif