/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 23:16:59 by mlegendr          #+#    #+#             */
/*   Updated: 2024/08/03 23:16:59 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

int main(void)
{
	int n = 5;

	Zombie zombie("Steve");
	zombie.announce();
	test(n);
	return (0);
}