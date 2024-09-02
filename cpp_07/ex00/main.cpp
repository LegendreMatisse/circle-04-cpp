/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 16:55:59 by mlegendr          #+#    #+#             */
/*   Updated: 2024/09/02 16:55:59 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"
#include <iostream>

int main(void)
{
	std::string a = "Dit is een ", b = "banaan.";
	std::cout << "Value of a (pre swap): " << a << std::endl;
	std::cout << "Value of b (pre swap): " << b << std::endl;
	//it's a template, so no std:: or className::
	::swap(a, b);
	std::cout << "Value of a: " << a << std::endl;
	std::cout << "Value of b: " << b << std::endl;

	int a = 875412, b = 5;
	//again, template, no std:: or className::
	std::cout << "Max of a and b: " << ::min(a, b) << std::endl;
	std::cout << "Min of a and b: " << ::min(a, b) << std::endl;

	//main from subject
	int a = 2;
	int b = 3;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	
	return 0;
}