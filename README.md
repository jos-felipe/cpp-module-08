# C++ Module 08 - Templated Containers, Iterators, Algorithms

This module explores key components of the C++ Standard Template Library (STL): templated containers, iterators, and algorithms. Through these exercises, you'll learn how to use these powerful abstractions to write more flexible, reusable, and efficient code.

## Overview

The STL is one of C++'s most valuable features, providing a collection of templated classes and functions that implement common data structures and algorithms. This module introduces:

- **Templated Containers**: Type-generic collections that store and organize data
- **Iterators**: Objects that enable traversal through container elements
- **Algorithms**: Generic functions that operate on ranges of elements

## Exercises

### Exercise 00: Easy find
An introduction to using STL algorithms with different container types. Implements a generic `easyfind` function that locates the first occurrence of an integer value in any container.

**Key concepts:**
- Function templates
- STL container compatibility
- The `std::find` algorithm
- Error handling with exceptions

### Exercise 01: Span
Implementation of a custom class that stores a set of integers and provides methods to find the shortest and longest span (distance) between any two elements.

**Key concepts:**
- Class design
- STL vector usage
- Algorithmic problem solving
- Range-based operations with iterators

### Exercise 02: MutantStack
Creation of an extended stack container that maintains all standard stack functionality while adding iterator support.

**Key concepts:**
- Container inheritance
- STL containers and adapters
- Iterator types
- Code reusability

## Skills Developed

- Understanding container properties and selection criteria
- Implementing generic code with templates
- Working with different iterator types and categories
- Applying STL algorithms to solve problems
- Extending and customizing STL containers

## Usage

Each exercise contains its own directory with the necessary files:

```
ex00/ - Easy find
├── easyfind.hpp
├── main.cpp
└── Makefile

ex01/ - Span
├── Span.hpp
├── Span.cpp
├── main.cpp
└── Makefile

ex02/ - MutantStack
├── MutantStack.hpp
├── main.cpp
└── Makefile
```

### Building and Running

To compile any exercise:

```bash
cd ex0X
make
```

Then run the resulting executable:

```bash
./easyfind
./span
./mutantstack
```

## Notes

- All code complies with the C++98 standard
- Each exercise demonstrates different aspects of STL usage
- Tests are included to verify functionality

---

2025 | J Felipe | josfelip@student.42sp.org.br