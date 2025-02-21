/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josfelip <josfelip@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 10:30:00 by josfelip          #+#    #+#             */
/*   Updated: 2025/02/21 11:55:41 by josfelip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>

void	testVector(void)
{
	std::cout << "=== Testing std::vector ===" << std::endl;
	std::vector<int> numbers;
	
	// Fill vector with values 0, 10, 20, ..., 90
	for (int i = 0; i < 10; i++)
		numbers.push_back(i * 10);
	
	// Test finding a value that exists
	try {
		std::vector<int>::iterator it = easyfind(numbers, 50);
		std::cout << "Found value 50 in vector at position: " 
			<< std::distance(numbers.begin(), it) << std::endl;
	} catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
	
	// Test finding a value that doesn't exist
	try {
		std::vector<int>::iterator it = easyfind(numbers, 42);
		std::cout << "Found value 42 in vector at position: " 
			<< std::distance(numbers.begin(), it) << std::endl;
	} catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
}

/*
** Test the easyfind function with a std::list container
*/
void	testList(void)
{
	std::cout << "\n=== Testing std::list ===" << std::endl;
	std::list<int> numbers;
	
	// Fill list with values 0, 10, 20, ..., 90
	for (int i = 0; i < 10; i++)
		numbers.push_back(i * 10);
	
	// Test finding a value that exists
	try {
		std::list<int>::iterator it = easyfind(numbers, 30);
		std::cout << "Found value 30 in list at position: " 
			<< std::distance(numbers.begin(), it) << std::endl;
	} catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
	
	// Test finding a value that doesn't exist
	try {
		std::list<int>::iterator it = easyfind(numbers, 99);
		std::cout << "Found value 99 in list at position: " 
			<< std::distance(numbers.begin(), it) << std::endl;
	} catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
}

/*
** Test the easyfind function with a std::deque container
*/
void	testDeque(void)
{
	std::cout << "\n=== Testing std::deque ===" << std::endl;
	std::deque<int> numbers;
	
	// Fill deque with values 0, 5, 10, ..., 45
	for (int i = 0; i < 10; i++)
		numbers.push_back(i * 5);
	
	// Test finding a value that exists
	try {
		std::deque<int>::iterator it = easyfind(numbers, 25);
		std::cout << "Found value 25 in deque at position: " 
			<< std::distance(numbers.begin(), it) << std::endl;
	} catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
	
	// Test finding a value that doesn't exist
	try {
		std::deque<int>::iterator it = easyfind(numbers, 100);
		std::cout << "Found value 100 in deque at position: " 
			<< std::distance(numbers.begin(), it) << std::endl;
	} catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
}

int	main(void)
{
	testVector();
	testList();
	testDeque();
	
	return (0);
}
