/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 10:21:58 by phhofman          #+#    #+#             */
/*   Updated: 2025/09/02 09:36:34 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>

int main(void)
{
	Intern ryan;

	// Valid forms
	AForm *form1 = ryan.makeForm("shrubbery", "Garden");
	std::cout << *form1 << std::endl;

	AForm *form2 = ryan.makeForm("robotomy", "R2D2");
	std::cout << *form2 << std::endl;

	AForm *form3 = ryan.makeForm("presidential", "Arthur");
	std::cout << *form3 << std::endl;

	// Invalid form name
	AForm *form4 = ryan.makeForm("unknown_form", "Nobody");
	if (form4)
		std::cout << *form4 << std::endl;

	try
	{

		// Create Bureaucrats with different grades
		Bureaucrat low("LowGrade", 150);
		Bureaucrat mid("MidGrade", 50);
		Bureaucrat high("HighGrade", 1);

		// 1. ShrubberyCreationForm test
		// Attempt signing with low-grade bureaucrat (should fail)
		low.signForm(*form1);
		// Mid-grade bureaucrat signs successfully
		mid.signForm(*form1);
		// Execution by mid-grade
		mid.executeForm(*form1);

		// 2. RobotomyRequestForm test
		// Sign with mid-grade bureaucrat
		mid.executeForm(*form2);
		mid.signForm(*form2);
		// Execute with high-grade bureaucrat
		high.executeForm(*form2);

		// 3. PresidentialPardonForm test
		// Attempt signing with mid-grade bureaucrat (should fail)
		mid.signForm(*form3);
		// High-grade bureaucrat signs successfully
		high.signForm(*form3);
		// Execute with high-grade bureaucrat
		high.executeForm(*form3);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
