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
	std::cout << "A Cat has been constructed." << std::endl;
	this->setType("Cat");
}

Cat::Cat(Cat const &copyCo) : Animal(copyCo)
{
	std::cout << "A Cat has been created by copy." << std::endl;
	*this = copyCo;
}

Cat &Cat::operator=(Cat const &copyOp)
{
	if (this == &copyOp)
		return *this;
	_type = copyOp._type;
	std::cout << "A Cat has been assigned" << std::endl;
	return *this;
}

Cat::~Cat()
{
	std::cout << "A Cat has been destroyed." << std::endl;
}

void Cat::makeSound(void) const
{
	std::cout << "Miaauw! Miaauw! Miaauw!" << std::endl;
}