/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 17:17:33 by mlegendr          #+#    #+#             */
/*   Updated: 2024/08/06 17:45:28 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

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

		//destructor
		~Fixed();

		//functions
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif
