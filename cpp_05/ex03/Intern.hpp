/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 02:17:07 by mlegendr          #+#    #+#             */
/*   Updated: 2024/09/02 02:17:07 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <exception>
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class	Intern
{
	public:
		// Constructor
		Intern(void);

		// Copy constructor
		Intern(const Intern &other);

		// Copy assignment operator overload
		Intern &operator= (const Intern &other);

		// Destructor
		~Intern();

		//functions
		AForm *chooseForm(const std::string &form, const std::string &target);

		//exception classes
		class NoFormFound : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

	private:
		AForm *_makePardon(const std::string &target);
		AForm *_makeRobotomy(const std::string &target);
		AForm *_makeShrub(const std::string &target);
};

#endif
