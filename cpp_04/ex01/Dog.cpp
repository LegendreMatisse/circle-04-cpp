/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 18:16:26 by mlegendr          #+#    #+#             */
/*   Updated: 2024/08/12 18:16:26 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal()
{
	this->setType("Dog");
	this->_brain = new Brain();
	std::cout << "A dog has been constructed." << std::endl;
}

Dog::Dog(Dog const &copyCo) : Animal(copyCo)
{
	this->_brain = new Brain();
	*this = copyCo;
	std::cout << "A dog has been created by copy." << std::endl;
}

Dog &Dog::operator=(Dog const &copyOp)
{
	if (this == &copyOp)
		return *this;
	_type = copyOp._type;
	*(this->_brain) = *(copyOp._brain);
	std::cout << "A dog has been assigned" << std::endl;
	return *this;
}

Dog::~Dog()
{
	delete this->_brain;
	std::cout << "A dog has been destroyed." << std::endl;
}

void Dog::makeSound(void) const
{
	std::cout << "Woof! Woof! Woof!" << std::endl;
}