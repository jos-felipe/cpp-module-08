/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josfelip <josfelip@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 13:00:00 by josfelip          #+#    #+#             */
/*   Updated: 2025/02/20 12:17:20 by josfelip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>

void testBasicFunctionality(void)
{
	std::cout << "=== Basic Functionality Test ===" << std::endl;
	
	// Test from the subject
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	
	std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest span: " << sp.longestSpan() << std::endl;
}

void testExceptions(void)
{
	std::cout << "\n=== Exception Handling Test ===" << std::endl;
	
	// Test full span
	Span sp = Span(3);
	
	try {
		std::cout << "Adding numbers: 1, 2, 3..." << std::endl;
		sp.addNumber(1);
		sp.addNumber(2);
		sp.addNumber(3);
		std::cout << "Trying to add a 4th number..." << std::endl;
		sp.addNumber(4); // Should throw exception
	} catch (std::exception &e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	
	// Test spans with insufficient elements
	Span empty = Span(5);
	
	try {
		std::cout << "\nTrying to find spans in empty Span..." << std::endl;
		std::cout << "Shortest span: " << empty.shortestSpan() << std::endl;
	} catch (std::exception &e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	
	try {
		std::cout << "Longest span: " << empty.longestSpan() << std::endl;
	} catch (std::exception &e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	
	Span single = Span(5);
	single.addNumber(42);
	
	try {
		std::cout << "\nTrying to find spans in Span with one element..." 
			<< std::endl;
		std::cout << "Shortest span: " << single.shortestSpan() << std::endl;
	} catch (std::exception &e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
}

void testRangeAddition(void)
{
	std::cout << "\n=== Range Addition Test ===" << std::endl;
	
	// Create a vector with 10,000 numbers
	std::vector<int> numbers;
	for (int i = 0; i < 10000; i++)
		numbers.push_back(i);
	
	// Add range to Span
	Span sp = Span(10000);
	try {
		sp.addRange(numbers.begin(), numbers.end());
		std::cout << "Successfully added 10,000 numbers using addRange" 
			<< std::endl;
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	} catch (std::exception &e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	
	// Test range addition with overflow
	Span smallSpan = Span(100);
	try {
		std::cout << "\nTrying to add 10,000 numbers to a Span with capacity 100..." 
			<< std::endl;
		smallSpan.addRange(numbers.begin(), numbers.end());
	} catch (std::exception &e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
}

void testLargeRandomSpan(void)
{
	std::cout << "\n=== Large Random Span Test ===" << std::endl;
	
	// Initialize random seed
	std::srand(std::time(NULL));
	
	// Create a Span with capacity 20,000
	Span sp = Span(20000);
	
	// Fill it with random numbers
	std::vector<int> randomNumbers;
	for (int i = 0; i < 20000; i++)
		randomNumbers.push_back(std::rand());
	
	sp.addRange(randomNumbers.begin(), randomNumbers.end());
	
	// Calculate spans
	std::cout << "Shortest span in 20,000 random numbers: " 
		<< sp.shortestSpan() << std::endl;
	std::cout << "Longest span in 20,000 random numbers: " 
		<< sp.longestSpan() << std::endl;
}

int main(void)
{
	testBasicFunctionality();
	testExceptions();
	testRangeAddition();
	testLargeRandomSpan();
	
	return (0);
}