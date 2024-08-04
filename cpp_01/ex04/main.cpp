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
#include <cstdlib>
#include "main.hpp"

static std::ifstream &openInputFile(const std::string &filename, std::ifstream &file)
{
	file.open(filename.c_str());
	if (!file.is_open())
	{
		std::cout << FILE_ERR << std::endl;
		std::exit(1);
	}
	return (file);
}

static std::ofstream &openOutputFile(const std::string &filename, std::ofstream &file)
{
	file.open(filename.c_str());
	if (!file.is_open())
	{
		std::cout << FILE_ERR << std::endl;
		std::exit(1);
	}
	return (file);
}

static void	replaceStringInFile(std::string filename, std::string s1, std::string s2)
{
	(void)s1;
	(void)s2;
	
	std::ifstream	inputFile;
	std::ofstream	outputFile = filename + ".replace";

	openInputFile(filename, inputFile);
	openOutputFile(outputFile, outputFile);

	std::string line;
	while (std::getline(inputFile, line))
	{
		outputFile << line << std::endl;
	}
}

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << USAGE_ERR << std::endl;
		return (1);
	}
	else if (std::string(argv[1]).empty() || std::string(argv[2]).empty() || std::string(argv[3]).empty())
	{
		std::cout << STRING_EMPTY_ERR << std::endl;
		return (1);
	}
	else
	{
		replaceString(argv[1], argv[2], argv[3]);
		return (0);
	}
	return (1);
}