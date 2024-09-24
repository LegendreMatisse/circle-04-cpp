/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 19:20:20 by mlegendr          #+#    #+#             */
/*   Updated: 2024/09/19 15:29:07 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"


RobotomyRequestForm::RobotomyRequestForm(void) : AForm("RobotomyRequestForm", 72, 45)
{
	std::cout << "An instance of a RobotomyRequestForm was created." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45)
{
	this->_target = target;
	std::cout << "An instance of a RobotomyRequestForm was created." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copyCo) : AForm(copyCo), _target(copyCo._target)
{
	*this = copyCo;
	std::cout << "An instance of a RobotomyRequestForm was created by copy." << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &copyOp)
{
	if (this == &copyOp)
		return *this;
	this->_target = copyOp._target;
	std::cout << "An instance of a RobotomyRequestForm has been assigned." << std::endl;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "An instance of a RobotomyRequestForm was destroyed." << std::endl;
}

void	RobotomyRequestForm::specialFeature(void) const
{
	std::cout << "Drilling noises" << std::endl;
	if (rand() % 2)
		std::cout << this->_target << " has been robotomized successfully." << std::endl;
	else
		std::cout << this->_target << " has not been robotomized successfully." << std::endl;
}