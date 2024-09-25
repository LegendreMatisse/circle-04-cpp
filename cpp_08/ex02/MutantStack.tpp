/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 16:55:21 by mlegendr          #+#    #+#             */
/*   Updated: 2024/09/25 16:55:21 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_TPP
# define MUTANTSTACK_TPP

# include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack() : std::stack<T>()
{
	std::cout << "Default stack constructor called." << std::endl;
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack<T> &copyCo) : std::stack<T>(copyCo)
{
	std::cout << "Stack copy constructor called." << std::endl;
}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack<T> &copyOp)
{
	if (this == &copyOp)
		return *this;
	std::stack<T>::operator=(copyOp);
	std::cout << "Stack copy constructor called." << std::endl;
	return *this;
}

template <typename T>
MutantStack<T>::~MutantStack() : std::stack<T>()
{
	std::cout << "Stack deconstructor called." << std::endl;
}

template <typename T>
typename std::stack<T>::container_type::iterator MutantStack<T>::begin()
{
	return std::stack<T>::c.begin();
}

template <typename T>
typename std::stack<T>::container_type::iterator MutantStack<T>::end()
{
	return std::stack<T>::c.end();
}

template <typename T>
typename std::stack<T>::container_type::reverse_iterator MutantStack<T>::rbegin()
{
	return std::stack<T>::c.rbegin();
}

template <typename T>
typename std::stack<T>::container_type::reverse_iterator MutantStack<T>::rend()
{
	return std::stack<T>::c.rend();
}

#endif