/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 10:21:58 by phhofman          #+#    #+#             */
/*   Updated: 2025/09/02 09:01:54 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main(void)
{
	try
	{
		// Create Bureaucrats with different grades
		Bureaucrat low("LowGrade", 150);
		Bureaucrat mid("MidGrade", 50);
		Bureaucrat high("HighGrade", 1);

		// 1. ShrubberyCreationForm test
		std::cout << "\n// 1. ShrubberyCreationForm Test\n";
		ShrubberyCreationForm shrub("Garden");
		std::cout << shrub << std::endl;

		// Attempt signing with low-grade bureaucrat (should fail)
		low.signForm(shrub);
		// Mid-grade bureaucrat signs successfully
		mid.signForm(shrub);
		// Execution by mid-grade
		mid.executeForm(shrub);
		// Execution by high-grade
		high.executeForm(shrub);

		// 2. RobotomyRequestForm test
		std::cout << "\n// 2. RobotomyRequestForm Test\n";
		RobotomyRequestForm robo("R2D2");
		std::cout << robo << std::endl;

		// Sign with mid-grade bureaucrat
		mid.executeForm(robo);
		mid.signForm(robo);
		// Execute with high-grade bureaucrat
		high.executeForm(robo);

		// 3. PresidentialPardonForm test
		std::cout << "\n// 3. PresidentialPardonForm Test\n";
		PresidentialPardonForm pardon("Arthur");
		std::cout << pardon << std::endl;

		// Attempt signing with mid-grade bureaucrat (should fail)
		mid.signForm(pardon);
		// High-grade bureaucrat signs successfully
		high.signForm(pardon);
		// Execute with high-grade bureaucrat
		high.executeForm(pardon);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
