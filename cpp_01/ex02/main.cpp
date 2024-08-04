/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 15:43:04 by mlegendr          #+#    #+#             */
/*   Updated: 2024/08/04 15:43:04 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

/*
	Exercise 02:

	- Create a string variable that contains the text "HI THIS IS BRAIN".
	- stringPTR is a pointer to the string.
	- stringREF is a reference to the string.

	- Display the address of the string variable.
	- Display the address stored in the stringPTR.
	- Display the address of the stringREF.

	- Display the value of the string variable
	- Display the value of the stringPTR.
	- Display the value of the stringREF.

	- Do this using references

	What are references and how to use them?

	As per: https://www.geeksforgeeks.org/pointers-vs-references-cpp/
	- References are aliases to variables, another name for an already existing variable.
	- A reference works like a pointer and stores the address of an object.
	- Example syntax:
		varType varName;
		varType &refName = varName;

	What are pointers and how to use them?

	As per: https://www.geeksforgeeks.org/pointers-and-references-in-c/
	- Pointerns are a symbolic representation of addresses.
	- A pointer stores the address of variables or a memory location.
	- Example syntax:
		varType varName;
		varType *ptrName = &varName;
*/

int main(void)
{
	std::string str = "HI THIS IS BRAIN";	//string variable
	std::string *stringPTR = &str;			//pointer to the string
	std::string &stringREF = str;			//reference to the string

	std::cout << "Address of the string variable: " << &str << std::endl;
	std::cout << "Address stored in the stringPTR: " << stringPTR << std::endl;
	std::cout << "Address of the stringREF: " << &stringREF << std::endl;

	std::cout << "Value of the string variable: " << str << std::endl;
	std::cout << "Value of the stringPTR: " << *stringPTR << std::endl;
	std::cout << "Value of the stringREF: " << stringREF << std::endl;

	return (0);
}