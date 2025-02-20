/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josfelip <josfelip@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 14:00:00 by josfelip          #+#    #+#             */
/*   Updated: 2025/02/20 17:35:12 by josfelip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>
# include <deque>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
	typedef typename std::stack<T>::container_type::iterator iterator;
	typedef typename std::stack<T>::container_type::const_iterator const_iterator;
	typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
	typedef typename std::stack<T>::container_type::const_reverse_iterator 
		const_reverse_iterator;

	MutantStack(void) : std::stack<T>() {}
	MutantStack(MutantStack const &src) : std::stack<T>(src) {}
	virtual ~MutantStack(void) {}

	MutantStack &operator=(MutantStack const &rhs)
	{
		if (this != &rhs)
			std::stack<T>::operator=(rhs);
		return (*this);
	}

	iterator begin(void) { return (this->c.begin()); }
	iterator end(void) { return (this->c.end()); }
	
	const_iterator begin(void) const { return (this->c.begin()); }
	const_iterator end(void) const { return (this->c.end()); }
	
	reverse_iterator rbegin(void) { return (this->c.rbegin()); }
	reverse_iterator rend(void) { return (this->c.rend()); }
	
	const_reverse_iterator rbegin(void) const { return (this->c.rbegin()); }
	const_reverse_iterator rend(void) const { return (this->c.rend()); }
};

#endif