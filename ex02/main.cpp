/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josfelip <josfelip@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 14:30:00 by josfelip          #+#    #+#             */
/*   Updated: 2025/02/20 17:38:26 by josfelip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <list>
#include <string>
#include <vector>

void testSubjectExample(void)
{
	std::cout << "=== Subject Example Test ===" << std::endl;
	
	MutantStack<int> mstack;
	
	mstack.push(5);
	mstack.push(17);
	
	std::cout << "Top: " << mstack.top() << std::endl;
	
	mstack.pop();
	
	std::cout << "Size: " << mstack.size() << std::endl;
	
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	
	++it;
	--it;
	
	std::cout << "Stack contents:" << std::endl;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	
	std::stack<int> s(mstack);
}

void testComparisonWithList(void)
{
	std::cout << "\n=== Comparison with std::list ===" << std::endl;
	
	// Test MutantStack
	MutantStack<int> mstack;
	mstack.push(42);
	mstack.push(17);
	mstack.push(5);
	
	std::cout << "MutantStack contents:" << std::endl;
	for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
		std::cout << *it << std::endl;
	
	// Test std::list with same values
	std::list<int> lst;
	lst.push_back(42);
	lst.push_back(17);
	lst.push_back(5);
	
	std::cout << "\nList contents:" << std::endl;
	for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it)
		std::cout << *it << std::endl;
}

void testDifferentTypes(void)
{
	std::cout << "\n=== Testing Different Types ===" << std::endl;
	
	// Test with strings
	MutantStack<std::string> strStack;
	strStack.push("Hello");
	strStack.push("World");
	strStack.push("!");
	
	std::cout << "String stack contents:" << std::endl;
	for (MutantStack<std::string>::iterator it = strStack.begin(); 
		it != strStack.end(); ++it)
		std::cout << *it << std::endl;
	
	// Test with doubles
	MutantStack<double> dblStack;
	dblStack.push(3.14);
	dblStack.push(2.718);
	dblStack.push(1.414);
	
	std::cout << "\nDouble stack contents:" << std::endl;
	for (MutantStack<double>::iterator it = dblStack.begin(); 
		it != dblStack.end(); ++it)
		std::cout << *it << std::endl;
}

void testIteratorTypes(void)
{
	std::cout << "\n=== Testing Different Iterator Types ===" << std::endl;
	
	MutantStack<int> mstack;
	for (int i = 1; i <= 5; ++i)
		mstack.push(i);
	
	// Test regular iterators
	std::cout << "Forward iteration:" << std::endl;
	for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
	
	// Test const iterators
	std::cout << "Const iteration:" << std::endl;
	const MutantStack<int> constStack(mstack);
	for (MutantStack<int>::const_iterator it = constStack.begin(); 
		it != constStack.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
	
	// Test reverse iterators
	std::cout << "Reverse iteration:" << std::endl;
	for (MutantStack<int>::reverse_iterator it = mstack.rbegin(); 
		it != mstack.rend(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
	
	// Test const reverse iterators
	std::cout << "Const reverse iteration:" << std::endl;
	for (MutantStack<int>::const_reverse_iterator it = constStack.rbegin(); 
		it != constStack.rend(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

int main(void)
{
	testSubjectExample();
	testComparisonWithList();
	testDifferentTypes();
	testIteratorTypes();
	
	return (0);
}