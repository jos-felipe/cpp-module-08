/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josfelip <josfelip@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 10:00:00 by josfelip          #+#    #+#             */
/*   Updated: 2025/02/18 19:12:14 by josfelip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <stdexcept>

/*
** easyfind - Generic function to find an integer in a container
** @T: The container type (must be a container of integers)
** @container: Reference to the container to search in
** @value: The integer value to find
**
** Returns: Iterator to the first occurrence of value in the container
** Throws: std::runtime_error if value is not found
*/
template <typename T>
typename T::iterator easyfind(T &container, int value)
{
	typename T::iterator it;

	it = std::find(container.begin(), container.end(), value);
	if (it == container.end())
		throw std::runtime_error("Value not found in container");
	return (it);
}

#endif