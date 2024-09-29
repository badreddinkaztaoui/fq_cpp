/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaztaou <bkaztaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 18:46:18 by bkaztaou          #+#    #+#             */
/*   Updated: 2024/07/29 03:26:26 by bkaztaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_K
#define MUTANTSTACK_K

#include <iostream>
#include <stack>
#include <deque>

template <typename T, typename container = std::deque<T> >

class MutantStack: public std::stack<T, container> {
public:
    MutantStack() {};
	MutantStack(const MutantStack<T, container> &src) : std::stack<T, container>(src) {};
	MutantStack &operator=(const MutantStack &src) {
		if (this == &src)
			return *this;
		this->c = src.c;
		return *this;
	}
	~MutantStack() {};

	typedef typename container::iterator it;

	it begin() { return this->c.begin(); }
	it end() { return this->c.end(); }
};

#endif