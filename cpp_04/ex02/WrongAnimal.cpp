/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 00:43:13 by mlegendr          #+#    #+#             */
/*   Updated: 2024/08/13 00:43:13 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void)
{
	std::cout << "An WrongAnimal has been created" << std::endl;
	this->setType("WrongAnimal");
}

WrongAnimal::WrongAnimal(WrongAnimal const &copyCo)
{
	std::cout << "An WrongAnimal has been created by copy" << std::endl;
	*this = copyCo;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal const &copyOp)
{
	if (this == &copyOp)
		return *this;
	_type = copyOp._type;
	std::cout << "An WrongAnimal has been assigned" << std::endl;
	return *this;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "An WrongAnimal has been destroyed" << std::endl;
}

std::string WrongAnimal::getType() const
{
	return _type;
}

void	WrongAnimal::setType(std::string const &type)
{
	this->_type = type;
}

void WrongAnimal::makeSound() const
{
	std::cout << "This WrongAnimal shrieks in a sound only audible to the Gods..." << std::endl;
}