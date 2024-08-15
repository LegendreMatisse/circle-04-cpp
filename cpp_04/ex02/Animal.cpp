/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 17:33:09 by mlegendr          #+#    #+#             */
/*   Updated: 2024/08/12 17:33:09 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void)
{
	std::cout << "An animal has been created" << std::endl;
	this->setType("Animal");
}

Animal::Animal(Animal const &copyCo)
{
	std::cout << "An animal has been created by copy" << std::endl;
	*this = copyCo;
}

Animal &Animal::operator=(Animal const &copyOp)
{
	if (this == &copyOp)
		return *this;
	_type = copyOp._type;
	std::cout << "An animal has been assigned" << std::endl;
	return *this;
}

Animal::~Animal()
{
	std::cout << "An animal has been destroyed" << std::endl;
}

std::string Animal::getType() const
{
	return _type;
}

void	Animal::setType(std::string const &type)
{
	this->_type = type;
}

void Animal::makeSound() const
{
	std::cout << "This animal is just an animal, therefore it does not make a sound." << std::endl;
}

