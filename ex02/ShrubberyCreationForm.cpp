/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 10:28:48 by phhofman          #+#    #+#             */
/*   Updated: 2025/08/29 13:21:48 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm::AForm("Default", false, 145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
	: AForm::AForm(target + "_shrubbery", false, 145, 137)
{
	// if (signGrade < 1 || executeGrade < 1)
	// 	throw ShrubberyCreationForm::GradeTooHighException();
	// if (signGrade > 150 || executeGrade > 150)
	// 	throw ShrubberyCreationForm::GradeTooLowException();
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm::AForm(other)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other)
		AForm::operator=(other);
	return *this;
}

void ShrubberyCreationForm::executeAction() const
{
	std::ofstream file(this->getName());
	if (!file)
		throw std::runtime_error("Could not open file");

	file << R"(							,@@@@@@@,
					,,,.   ,@@@@@@/@@,  .oo8888o.
				,&%%&%&&%,@@@@@/@@@@@@,8888\88/8o
				,%&\%&&%&&%,@@@\@@@/@@@88\88888/88'
				%&&%&%&/%&&%@@\@@/ /@@@88888\88888'
				%&&%/ %&%%&&@@\ V /@@' `88\8 `/88'
				`&%\ ` /%&'    |.|        \ '|8'
					|o|        | |         | |
					|.|        | |         | |
				 \\/ ._\//_/__/  ,\_//__\\/.  \_//__/_ )";
	file.close();
}