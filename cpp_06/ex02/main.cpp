/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 15:14:12 by mlegendr          #+#    #+#             */
/*   Updated: 2024/09/02 15:14:12 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <iostream>

int main(void)
{
	Base *base = generate();
	std::cout << "Pointer: " << std::flush;
	identify(base);
	std::cout << "Reference: " << std::flush;
	identify(*base);
	delete base;
	return 0;
}