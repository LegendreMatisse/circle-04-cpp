/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 19:53:56 by mlegendr          #+#    #+#             */
/*   Updated: 2024/08/06 19:53:59 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void)
{
	Fixed a(18);
	Fixed b(39);
	Fixed c(8);

	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	std::cout << std::endl;

	std::cout << a > b << std::endl;
	std::cout << b > a << std::endl;
	std::cout << a > c << std::endl;
	std::cout << std::endl;
	
	std::cout << a < b << std::endl;
	std::cout << b < a << std::endl;
	std::cout << a < c << std::endl;
	std::cout << std::endl;
	
	std::cout << a >= b << std::endl;
	std::cout << b >= a << std::endl;
	std::cout << a >= c << std::endl;
	std::cout << a >= a << std::endl;
	std::cout << std::endl;
	
	std::cout << a <= b << std::endl;
	std::cout << b <= a << std::endl;
	std::cout << a <= c << std::endl;
	std::cout << a <= a << std::endl;
	std::cout << std::endl;
	
	std::cout << a == b << std::endl;
	std::cout << b == a << std::endl;
	std::cout << a == c << std::endl;
	std::cout << a == a << std::endl;
	std::cout << std::endl;
	
	std::cout << a != b << std::endl;
	std::cout << b != a << std::endl;
	std::cout << a != c << std::endl;
	std::cout << a != a << std::endl;
}
