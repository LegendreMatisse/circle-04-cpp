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

Animal::Animal() : type_("Animal")
{
	std::cout << "An animal has been created" << std::endl;
}

Animal::Animal(std::string const &type) : type_(type)
{
	std::cout << "An animal has been created" << std::endl;
}

Animal::Animal(Animal const &other) : type_(other.type_)
{
	std::cout << "An animal has been created by copy" << std::endl;
}

Animal &Animal::operator=(Animal const &other)
{
	if (this == &other)
		return *this;
	type_ = other.type_;
	std::cout << "An animal has been assigned" << std::endl;
	return *this;
}

Animal::~Animal()
{
	std::cout << "An animal has been destroyed" << std::endl;
}

std::string Animal::getType() const
{
	return type_;
}

void Animal::makeSound() const
{
	std::cout << "This animal is just an animal, therefor it does not make a sound." << std::endl;
}

