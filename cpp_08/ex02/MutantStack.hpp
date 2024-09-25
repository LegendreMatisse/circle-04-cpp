/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlegendr <mlegendr@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 18:25:46 by mlegendr          #+#    #+#             */
/*   Updated: 2024/09/24 18:26:05 by mlegendr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_TPP

# include <stack>
# include <iostream>

template <typename T>
class MutantStack : public std::stack<T>
{
	private:

	public:
		//iterators
		typedef typename std::stack<T>::container_type::iterator it;
		typedef typename std::stack<T>::container_type::reverse_iterator revIt;

		//constructor
		MutantStack();

		//copy constructor
		MutantStack(const MutantStack &copyCo);

		//assignment operator overload
		MutantStack &operator=(const MutaantStack &copyOp);

		//destructor
		virtual ~MutantStack();

		//funtions
		iterator			stackStart();
		iterator			stackEnd();
		reverse_iterator	revStackStart();
		reverse_iterator	revStackEnd();
};

# include "MutantStack.tpp"

#endif