/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 18:00:25 by mlegendr          #+#    #+#             */
/*   Updated: 2024/08/08 20:32:14 by mlegendr         ###   ########.fr       */
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
	std::cout << "Copy constructor called" << std::endl;
	*this = copyCo;
}

//assignment operator overload
Fixed &Fixed::operator=(const Fixed &copyOp)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copyOp)
	{
		this->_fixedValue = copyOp.getRawBits();
	}
	return (*this);
}

//parameterized constructor
Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	this->_fixedValue = value << _fractionalBits;
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	this->_fixedValue = roundf(value * (1 << _fractionalBits));
}

//destructor
Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

//getter
int		Fixed::getRawBits(void) const
{
	//std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixedValue);
}

//setter
void	Fixed::setRawBits(int const raw)
{
	//the setter doesn't appear to be printing anything in the example subject
	this->_fixedValue = raw;
}

//functions
float	Fixed::toFloat(void) const
{
	return ((float)this->_fixedValue / (1 << _fractionalBits));
}

int		Fixed::toInt(void) const
{
	return (this->_fixedValue >> _fractionalBits);
}

//operator overload
std::ostream &operator<<(std::ostream &out, Fixed const &value)
{
	out << value.toFloat();
	return (out);
}

//comparison operators
bool	Fixed::operator>(Fixed const &greOp) const
{
	if (this->_fixedValue > greOp.getRawBits())
		return (true);
	return (false);	
}

bool	Fixed::operator<(Fixed const &smaOp) const
{
	if (this->_fixedValue < smaOp.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator>=(Fixed const &greEqOp) const
{
	if (this->_fixedValue >= greEqOp.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator<=(Fixed const &smaEqOp) const
{
	if (this->_fixedValue <= smaEqOp.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator==(Fixed const &eqOp) const
{
	if (this->_fixedValue == eqOp.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator!=(Fixed const &notEq) const
{
	if (this->_fixedValue != notEq.getRawBits())
		return (true);
	return (false);
}