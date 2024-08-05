/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 22:41:04 by mlegendr          #+#    #+#             */
/*   Updated: 2024/08/05 22:41:04 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void)
{
	std::cout << "Harl constructor called" << std::endl;
	return ;
}

Harl::~Harl()
{
	std::cout << "Harl destructor called" << std::endl;
	return ;
}

void Harl::_debug(void)
{
	std::cout << "~~DEBUG~~ Harl is currently debugging, but what is a Harl?" << std::endl;
}

void Harl::_info(void)
{
	std::cout << "~~INFO~~ I found a PDF online about a HARL-III compiler, I don't think this exercise is about the Harl compiler though." << std::endl;
}

void Harl::_warning(void)
{
	std::cout << "~~WARNING~~ Perhaps I shouldn't look too much into what Harl is, maybe I'm thinking too hard about it..." << std::endl;
}

void Harl::_error(void)
{
	std::cout << "~~ERROR~~ I can't find anything about Harl, I'm starting to think it's not a real thing..." << std::endl;
}

void Harl::complain(std::string level)
{
	void (Harl::*complaints[4])(void) = {&Harl::_debug, &Harl::_info, &Harl::_warning, &Harl::_error};
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++)
	{
		if (levels[i] == level)
		{
			(this->*complaints[i])();
			return ;
		}
	}
}