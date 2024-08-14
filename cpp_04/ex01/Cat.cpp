/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 22:49:38 by mlegendr          #+#    #+#             */
/*   Updated: 2024/08/12 22:49:38 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal()
{
	this->setType("Cat");
	this->_brain = new Brain();
	std::cout << "A Cat has been constructed." << std::endl;
}

Cat::Cat(Cat const &copyCo) : Animal(copyCo)
{
	this->_brain = new Brain();
	*this = copyCo;
	std::cout << "A Cat has been created by copy." << std::endl;
}

Cat &Cat::operator=(Cat const &copyOp)
{
	if (this == &copyOp)
		return *this;
	this->_type = copyOp._type;
	*(this->_brain) = *(copyOp._brain);
	std::cout << "A Cat has been assigned" << std::endl;
	return *this;
}

Cat::~Cat()
{
	delete this->_brain;
	std::cout << "A Cat has been destroyed." << std::endl;
}

void Cat::makeSound(void) const
{
	std::cout << "Miaauw! Miaauw! Miaauw!" << std::endl;
}