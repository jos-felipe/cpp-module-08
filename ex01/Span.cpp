/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josfelip <josfelip@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 12:30:00 by josfelip          #+#    #+#             */
/*   Updated: 2025/02/20 12:09:41 by josfelip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(void) : _maxSize(0)
{
}

Span::Span(unsigned int n) : _maxSize(n)
{
}

Span::Span(Span const &src) : _maxSize(src._maxSize), _numbers(src._numbers)
{
}

Span::~Span(void)
{
}

Span &Span::operator=(Span const &rhs)
{
	if (this != &rhs)
	{
		_maxSize = rhs._maxSize;
		_numbers = rhs._numbers;
	}
	return (*this);
}

void Span::addNumber(int number)
{
	if (_numbers.size() >= _maxSize)
		throw std::overflow_error("Cannot add number: Span is full");
	
	_numbers.push_back(number);
}

unsigned int Span::shortestSpan(void) const
{
	if (_numbers.size() <= 1)
		throw std::logic_error("Need at least 2 numbers to find a span");

	std::vector<int> sorted = _numbers;
	std::sort(sorted.begin(), sorted.end());

	unsigned int minSpan = std::numeric_limits<unsigned int>::max();
	
	for (size_t i = 1; i < sorted.size(); ++i)
	{
		unsigned int currentSpan = sorted[i] - sorted[i - 1];
		if (currentSpan < minSpan)
			minSpan = currentSpan;
	}
	
	return (minSpan);
}

unsigned int Span::longestSpan(void) const
{
	if (_numbers.size() <= 1)
		throw std::logic_error("Need at least 2 numbers to find a span");

	int min = *std::min_element(_numbers.begin(), _numbers.end());
	int max = *std::max_element(_numbers.begin(), _numbers.end());
	
	return (max - min);
}