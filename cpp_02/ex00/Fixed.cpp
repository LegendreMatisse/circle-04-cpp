/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 17:17:30 by mlegendr          #+#    #+#             */
/*   Updated: 2024/08/07 16:58:43 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

//default constructor
Fixed::Fixed(void) : _fixedValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}

//copy constructor
Fixed::Fixed(const Fixed &copyCo)
{
	//*this = copyCo; //maybe this, but I think it might be better to reassign the value
	this->_fixedValue = copyCo.getRawBits();
	std::cout << "Copy constructor called" << std::endl;
}

//assignation operator overload
//destructor
Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}
//getter
int		Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixedValue);
}

//setter
void	Fixed::setRawBits(int const raw)
{
	//the setter doesn't appear to be printing anything in the example subject
	this->_fixedValue = raw;
}