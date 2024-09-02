/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 19:20:16 by mlegendr          #+#    #+#             */
/*   Updated: 2024/09/01 19:20:16 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("default", 25, 5)
{
	std::cout << "An instance of a PresidentialPardonForm was created." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm(target, 25, 5)
{
	std::cout << "An instance of a PresidentialPardonForm was created." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copyCo) : AForm(copyCo), _target(copyCo._target)
{
	*this = copyCo;
	std::cout << "An instance of a PresidentialPardonForm was created by copy." << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &copyOp)
{
	if (this == &copyOp)
		return *this;
	this->_target = copyOp._target;
	std::cout << "An instance of a PresidentialPardonForm has been assigned." << std::endl;
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "An instance of a PresidentialPardonForm was destroyed." << std::endl;
}

void	PresidentialPardonForm::specialFeature(void) const
{
	std::cout << this->_target << " has been pardoned by Zafod Beeblebrox." << std::endl;
}
