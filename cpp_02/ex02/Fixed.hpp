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
};

std::ostream &operator<<(std::ostream &out, Fixed const &value);

#endif