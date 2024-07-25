/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.s19.be>              +#+  +:+       +#+   */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 01:35:04 by mlegendr            #+#    #+#           */
/*   Updated: 2024/07/24 01:35:04 by mlegendr           ###   ########.fr     */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (int i = 1; i < argc; i++)
		{
			for (int j = 0; argv[i][j]; j++)
			{
				/*
					Using a static_cast cast the output of toupper to a char.
					It's safer than using a C-style cast, or so I've been told.
				*/
				/*
					Adding std:: to the toupper function call will make
					the code more consistent and clear. Especially when
					mixing C and C++ functions.
					This seems to be a good practice to follow, 
					or so I've been told...
				*/
				std::cout << static_cast<char>(std::toupper(argv[i][j]));
			}
		}
		//Prints a new line at the end of the output.
		std::cout << std::endl;
	}
	return 0;
}