/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 19:20:25 by mlegendr          #+#    #+#             */
/*   Updated: 2024/09/01 19:20:25 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("default", 145, 137)
{
	std::cout << "An instance of a ShrubberyCreationForm was created." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm(target, 145, 137)
{
	std::cout << "An instance of a ShrubberyCreationForm was created." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copyCo) : AForm(copyCo), _target(copyCo._target)
{
	*this = copyCo;
	std::cout << "An instance of a ShrubberyCreationForm was created by copy." << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copyOp)
{
	if (this == &copyOp)
		return *this;
	this->_target = copyOp._target;
	std::cout << "An instance of a ShrubberyCreationForm has been assigned." << std::endl;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "An instance of a ShrubberyCreationForm was destroyed." << std::endl;
}

void	ShrubberyCreationForm::specialFeature(void) const
{
	std::string filename = this->_target + "_shrubbery";
	std::ofstream file(filename.c_str());
	if (file.is_open())
	{
		file << "       _-_\n"
		"    /~~   ~~\\\n"
		" /~~         ~~\\\n"
		"{               }\n"
		" \\  _-     -_  /\n"
		"   ~  \\\\ //  ~\n"
		"_- -   | | _- _\n" << std::endl;
		file.close();
	}
	else
		std::cerr << "Error: could not open file." << std::endl;
}
