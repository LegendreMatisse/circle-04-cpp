/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 21:53:22 by mlegendr          #+#    #+#             */
/*   Updated: 2024/08/04 21:53:22 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>
#include "main.hpp"

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << USAGE_ERR << std::endl;
		return (1);
	}
	else if (argv[1] == "" || argv[2] == "" || argv[3] == "")
	{
		std::cout << USAGE_ERR << std::endl;
		return (1);
	}
}