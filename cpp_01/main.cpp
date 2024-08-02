/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 20:35:25 by mlegendr          #+#    #+#             */
/*   Updated: 2024/07/31 20:39:17 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

int main(void)
{	
	Zombie *heap_zombie;

	heap_zombie = newZombie("heap_zombie");
	heap_zombie->announce();
	
	randomChump("stack_zombie");

	delete heap_zombie;
	return (0);
}