/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 10:21:58 by phhofman          #+#    #+#             */
/*   Updated: 2025/09/02 09:43:38 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int main(void)
{
	// 1. Test construction too high
	std::cout << "\n// 1. Test construction too high\n";
	try
	{
		Bureaucrat b1("Alice", 0); // grade < 1
		std::cout << b1 << "\n";
	}
	catch (const std::exception &e)
	{
		std::cout << "Caught exception: " << e.what() << "\n";
	}

	// 2. Test construction too low
	std::cout << "\n// 2. Test construction too low\n";
	try
	{
		Bureaucrat b2("Bob", 200); // grade > 150
		std::cout << b2 << "\n";
	}
	catch (const std::exception &e)
	{
		std::cout << "Caught exception: " << e.what() << "\n";
	}

	// 3. Test increment beyond limit
	std::cout << "\n// 3. Test increment beyond limit\n";
	try
	{
		Bureaucrat b3("Charlie", 1);
		std::cout << b3 << "\n";
		b3.incrementGrade();	 // should throw
		std::cout << b3 << "\n"; // won’t execute
	}
	catch (const std::exception &e)
	{
		std::cout << "Caught exception: " << e.what() << "\n";
	}

	// 4. Test decrement beyond limit
	std::cout << "\n// 4. Test decrement beyond limit\n";
	try
	{
		Bureaucrat b4("Diana", 150);
		std::cout << b4 << "\n";
		b4.decrementGrade();	 // should throw
		std::cout << b4 << "\n"; // won’t execute
	}
	catch (const std::exception &e)
	{
		std::cout << "Caught exception: " << e.what() << "\n";
	}

	// 5. Test valid bureaucrat with increment & decrement
	std::cout << "\n// 5. Test valid bureaucrat with increment & decrement\n";
	try
	{
		Bureaucrat b5("Eve", 42);
		std::cout << b5 << "\n";
		b5.incrementGrade();
		std::cout << "After increment: " << b5 << "\n";
		b5.decrementGrade();
		std::cout << "After decrement: " << b5 << "\n";
	}
	catch (const std::exception &e)
	{
		std::cout << "Caught exception: " << e.what() << "\n";
	}

	return 0;
}