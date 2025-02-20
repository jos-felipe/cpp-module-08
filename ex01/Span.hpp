/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josfelip <josfelip@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 12:00:00 by josfelip          #+#    #+#             */
/*   Updated: 2025/02/20 12:08:12 by josfelip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <algorithm>
# include <stdexcept>
# include <limits>

class Span
{
private:
	unsigned int		_maxSize;
	std::vector<int>	_numbers;

public:
	Span(void);
	Span(unsigned int n);
	Span(Span const &src);
	~Span(void);

	Span &operator=(Span const &rhs);

	void addNumber(int number);
	unsigned int shortestSpan(void) const;
	unsigned int longestSpan(void) const;

	template <typename Iterator>
	void addRange(Iterator begin, Iterator end)
	{
		unsigned int distance = std::distance(begin, end);
		
		if (_numbers.size() + distance > _maxSize)
			throw std::overflow_error("Cannot add range: would exceed capacity");
		
		_numbers.insert(_numbers.end(), begin, end);
	}
};

#endif