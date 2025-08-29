/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 10:45:50 by phhofman          #+#    #+#             */
/*   Updated: 2025/08/29 13:52:02 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm::AForm("Default_shrubbery", false, 72, 45)
{
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
	: AForm::AForm(target + "_shrubbery", false, 145, 137)
{
	// if (signGrade < 1 || executeGrade < 1)
	// 	throw RobotomyRequestForm::GradeTooHighException();
	// if (signGrade > 150 || executeGrade > 150)
	// 	throw RobotomyRequestForm::GradeTooLowException();
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm::AForm(other)
{
}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this != &other)
		AForm::operator=(other);
	return *this;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this != &other)
		AForm::operator=(other);
	return *this;
}

void RobotomyRequestForm::executeAction() const
{

}