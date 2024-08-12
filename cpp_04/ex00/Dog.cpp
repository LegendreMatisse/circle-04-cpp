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

Dog::Dog(void) : _type("Dog")
{
	std::cout << "A dog has been constructed." << std::endl;
}

Dog::Dog(std::string const &type) : _type("Dog")
{
	std::cout << "A dog has been constructed." << std::endl;
}

Dog::Dog(Dog const &copyCo) : Animal(copyCo)
{
	std::cout << "A dog has been created by copy." << std::endl;
	*this = copyCo;
}

Dog &Dog::operator=(Dog const &copyOp)
{
	if (this == &copyOp)
		return *this;
	_type = copyOp._type;
	std::cout << "A dog has been assigned" << std::endl;
	return *this;
}

Dog::~Dog()
{
	std::cout << "A dog has been destroyed." << std::endl;
}

void Dog::makeSound(void) const
{
	std::cout << "Woof! Woof! Woof!" << std::endl;
}