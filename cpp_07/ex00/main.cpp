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

	int c = 875412, d = 5;
	//again, template, no std:: or className::
	std::cout << "Max of c and d: " << ::min(c, d) << std::endl;
	std::cout << "Min of c and d: " << ::min(c, d) << std::endl;

	//main from subject
	int e = 2;
	int f = 3;
	::swap( e, f );
	std::cout << "e = " << e << ", f = " << f << std::endl;
	std::cout << "min( e, f ) = " << ::min( e, f ) << std::endl;
	std::cout << "max( e, f ) = " << ::max( e, f ) << std::endl;
	std::string g = "chaine1";
	std::string h = "chaine2";
	::swap(g, h);
	std::cout << "g = " << g << ", h = " << h << std::endl;
	std::cout << "min( g, h ) = " << ::min( g, h ) << std::endl;
	std::cout << "max( g, h ) = " << ::max( g, h ) << std::endl;

	return 0;
}