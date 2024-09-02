/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 02:17:14 by mlegendr          #+#    #+#             */
/*   Updated: 2024/09/02 02:17:14 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void)
{
	std::cout << "An instance of an Intern was created." << std::endl;
}

Intern::Intern(const Intern &other)
{
	*this = other;
	std::cout << "An instance of an Intern was created by copy." << std::endl;

}

Intern &Intern::operator=(const Intern &other)
{
	(void)other;
	std::cout << "An instance of an Intern has been assigned." << std::endl;
	return *this;
}

Intern::~Intern()
{
	std::cout << "An instance of an Intern was destroyed." << std::endl;
}

AForm* Intern::chooseForm(const std::string& form, const std::string& target)
{
	const std::string form_types[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};

	AForm* (Intern::*functions[3])(const std::string&) = {&Intern::_makePardon, &Intern::_makeRobotomy, &Intern::_makeShrub;};

	for (short i = 0; i < 3; i++)
		if (form_types[i] == form)
			return ((this->*functions[i])(target));

	throw (NoFormFound());
}

const char *Intern::NoFormFound::what() const throw()
{
	return ("No form found by the choses command.\n");
}

AForm* Intern::_makePardon(const std::string& target)
{
	std::cout << "A pardom form has been requested!\n";
	return (new PresidentialPardonForm(target));
}

AForm* Intern::_makeRobotomy(const std::string& target)
{
	std::cout << "A robotomy has been planned.\n";
	return (new RobotomyRequestForm(target));
}

AForm* Intern::_makeShrub(const std::string& target)
{
	std::cout << "The knights who say ni are pleased.\n";
	return (new ShrubberyCreationForm(target));
}
