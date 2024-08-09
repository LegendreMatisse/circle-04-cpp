/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 18:00:18 by mlegendr          #+#    #+#             */
/*   Updated: 2024/08/08 18:00:19 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
	private:
		int					_fixedValue;
		static const int	_fractionalBits = 8;
	public:
		//constructor
		Fixed(void);

		//copy constructor
		Fixed(const Fixed &copyCo);

		//assignation operator overload
		Fixed &operator=(const Fixed &copyOp);

		//parameterized constructor
		Fixed(const int value);
		Fixed(const float value);

		//destructor
		~Fixed();

		//getter
		int		getRawBits(void) const;

		//setter
		void	setRawBits(int const raw);

		//functions
		float	toFloat(void) const;
		int		toInt(void) const;

		//comparison operators
		bool	operator>(Fixed const &greOp)		const;
		bool	operator<(Fixed const &smaOp)		const;
		bool	operator>=(Fixed const &greEqOp)	const;
		bool	operator<=(Fixed const &smaEqOp)	const;
		bool	operator==(Fixed const &eqOp)		const;
		bool	operator!=(Fixed const &notEq)		const;

		//arithmetic operators
		Fixed	operator+(Fixed const &add);
		Fixed	operator-(Fixed const &sub);
		Fixed	operator*(Fixed const &tim);
		Fixed	operator/(Fixed const &div);

		//in- and decrement operators
		Fixed	operator++(void);
		Fixed	operator--(void);
		Fixed	operator++(int);
		Fixed	operator--(int);

		//min max functions
		static Fixed const &min(Fixed const &testValue1, Fixed const &testValue2);
		static Fixed const &max(Fixed const &testValue1, Fixed const &testValue2);
		static Fixed &min(Fixed &testValue1, Fixed &testValue2);
		static Fixed &max(Fixed &testValue1, Fixed &testValue2);
};

std::ostream &operator<<(std::ostream &out, Fixed const &value);

#endif