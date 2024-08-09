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

	bool test = a > b;
	std::cout << test << std::endl;
	test = b > a;
	std::cout << test << std::endl;
	test = a > c;
	std::cout << test << std::endl;
	std::cout << std::endl;
	
	test = a < b;
	std::cout << test << std::endl;
	test = b < a;
	std::cout << test << std::endl;
	test = a < c;
	std::cout << test << std::endl;
	std::cout << std::endl;
	
	test = a >= b;
	std::cout << test << std::endl;
	test = b >= a;
	std::cout << test << std::endl;
	test = a >= c;
	std::cout << test << std::endl;
	test = a >= a;
	std::cout << test << std::endl;
	std::cout << std::endl;
	
	test = a <= b;
	std::cout << test << std::endl;
	test = b <= a;
	std::cout << test << std::endl;
	test = a <= c;
	std::cout << test << std::endl;
	test = a <= a;
	std::cout << test << std::endl;
	std::cout << std::endl;
	
	test = a == b;
	std::cout << test << std::endl;
	test = b == a;
	std::cout << test << std::endl;
	test = a == c;
	std::cout << test << std::endl;
	test = a == a;
	std::cout << test << std::endl;
	std::cout << std::endl;
	
	test = a != b;
	std::cout << test << std::endl;
	test = b != a;
	std::cout << test << std::endl;
	test = a != c;
	std::cout << test << std::endl;
	test = a != a;
	std::cout << test << std::endl;
	std::cout << std::endl;
}
