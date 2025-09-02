/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 10:21:58 by phhofman          #+#    #+#             */
/*   Updated: 2025/09/02 09:44:13 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main(void)
{
	// 1. Test form creation with too high sign grade
	std::cout << "\n// 1. Form creation too high\n";
	try
	{
		Form f1("ImpossibleForm", false, 0, 10); // signGrade < 1
	}
	catch (const std::exception &e)
	{
		std::cout << "Caught exception: " << e.what() << "\n";
	}

	// 2. Test form creation with too low execute grade
	std::cout << "\n// 2. Form creation too low\n";
	try
	{
		Form f2("LazyForm", false, 50, 200); // executeGrade > 150
	}
	catch (const std::exception &e)
	{
		std::cout << "Caught exception: " << e.what() << "\n";
	}

	// 3. Bureaucrat tries to sign but grade is too low
	std::cout << "\n// 3. Bureaucrat grade too low to sign\n";
	try
	{
		Bureaucrat b1("Bob", 100);			 // bureaucrat with grade 100
		Form f3("TopSecret", false, 50, 50); // requires grade 50 to sign
		b1.signForm(f3);					 // should fail
	}
	catch (const std::exception &e)
	{
		std::cout << "Unexpected exception in test 3\n";
	}

	// 4. Bureaucrat signs successfully
	std::cout << "\n// 4. Bureaucrat can sign successfully\n";
	try
	{
		Bureaucrat b2("Alice", 30);		  // bureaucrat with grade 30
		Form f4("Report", false, 50, 50); // requires grade 50 to sign
		b2.signForm(f4);				  // should succeed
		std::cout << f4 << "\n";		  // use operator<< for Form
	}
	catch (const std::exception &e)
	{
		std::cout << "Unexpected exception in test 4\n";
	}

	// 5. Bureaucrat with exactly the required grade
	std::cout << "\n// 5. Bureaucrat with exact grade\n";
	try
	{
		Bureaucrat b3("Charlie", 50);
		Form f5("Budget", false, 50, 100); // needs exactly 50 to sign
		b3.signForm(f5);				   // should succeed
		std::cout << f5 << "\n";
	}
	catch (const std::exception &e)
	{
		std::cout << "Unexpected exception in test 5\n";
	}

	return 0;
}