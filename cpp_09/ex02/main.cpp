/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 18:33:56 by mlegendr          #+#    #+#             */
/*   Updated: 2024/09/25 18:33:56 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <typeinfo>
#include <vector>
#include <list>

int main(void)
{
	std::vector<int> v;
	std::list<int> l;

	std::cout << "Type of v: " << typeid(v).name() << std::endl;
	std::cout << "Type of l: " << typeid(l).name() << std::endl;

	return 0;

}