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

	Fixed af(18.5856f);
	Fixed bf(39.1541f);

	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;
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

	Fixed result = a + b;
	std::cout << result << std::endl;
	result = a - b;
	std::cout << result << std::endl;
	result = a * b;
	std::cout << result << std::endl;
	result = a / b;
	std::cout << result << std::endl;
	std::cout << std::endl;

	result = af + bf;
	std::cout << result << std::endl;
	result = af - bf;
	std::cout << result << std::endl;
	result = af * bf;
	std::cout << result << std::endl;
	result = af / bf;
	std::cout << result << std::endl;
	std::cout << std::endl;

	
	int aa = 18;
	int bb = 39

	std::cout << aa++ << std::endl;
	std::cout << bb-- << std::endl;
	std::cout << std::endl;

	int aaa = 18;
	int bbb = 39;

	std::cout << ++aaa << std::endl;
	std::cout << --bbb << std::endl;
	std::cout << std::endl;
}
