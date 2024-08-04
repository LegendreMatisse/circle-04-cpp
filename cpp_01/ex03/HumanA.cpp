/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 16:59:24 by mlegendr          #+#    #+#             */
/*   Updated: 2024/08/04 16:59:24 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : name_(name), weapon_(weapon)
{
	std::cout << "HumanA created" << std::endl;
	return ;
}

HumanA::~HumanA()
{
	std::cout << "HumanA destroyed" << std::endl;
	return ;
}

std::string HumanA::getName() const
{
	return this->name_;
}

void HumanA::attack() const
{
	std::cout << HumanA::getName() << " attacks with his " << this->weapon_.getType() << std::endl;
	return ;
}