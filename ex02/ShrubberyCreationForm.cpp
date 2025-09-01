/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 10:28:48 by phhofman          #+#    #+#             */
/*   Updated: 2025/09/01 14:38:29 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm::AForm("Default_shrubbery", false, 145, 137), _target("Default_Target")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
	: AForm::AForm(target + "_shrubbery", false, 145, 137), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm::AForm(other), _target(other._target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		this->_target = other._target;
	}
	return *this;
}

void ShrubberyCreationForm::executeAction() const
{
	std::ofstream file(this->_target);
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