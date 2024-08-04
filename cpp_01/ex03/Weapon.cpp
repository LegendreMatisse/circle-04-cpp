/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 16:59:00 by mlegendr          #+#    #+#             */
/*   Updated: 2024/08/04 16:59:00 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) : _type(type)
{
	std::cout << "Weapon created" << std::endl;
	return ;
}

Weapon::~Weapon()
{
	std::cout << "Weapon destroyed" << std::endl;
	return ;
}

const std::string &Weapon::getType() const
{
	return this->_type;
}

void Weapon::setType(std::string type)
{
	this->_type = type;
	return ;
}