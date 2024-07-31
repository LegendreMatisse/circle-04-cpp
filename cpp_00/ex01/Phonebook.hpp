/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 18:00:50 by mlegendr          #+#    #+#             */
/*   Updated: 2024/07/26 20:20:49 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include "Contact.hpp"

class Phonebook
{
	public:
		Phonebook(void); //constructor
		~Phonebook(); //destructor

		//functions
		void	AddContact(std::string firstName, std::string lastName, std::string nickName, std::string phoneNum, std::string secret);
		void	SearchContact(std::string input);
		void	PrintSearch(void);
		
	private:
		//variables
		Contact	_contacts[8];
		int		_contactIndex;
		int		_contactCount;

		//functions
		void	_PrintHeader(void);
};

#endif