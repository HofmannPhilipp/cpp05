/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 10:45:50 by phhofman          #+#    #+#             */
/*   Updated: 2025/09/01 14:38:12 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm::AForm("RobotomyRequestForm", false, 72, 45), _target("Default_Target")
{
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
	: AForm::AForm("RobotomyRequestForm", false, 72, 45), _target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm::AForm(other), _target(other._target)
{
}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		this->_target = other._target;
	}
	return *this;
}

void RobotomyRequestForm::executeAction() const
{
	std::cout << "Bzzzzzzzzz... *drilling noises* 🛠️" << std::endl;

	std::srand(static_cast<unsigned>(std::time(nullptr)));
	if (std::rand() % 2 == 0)
		std::cout << this->_target << " has been robotomized successfully 🤖✅" << std::endl;
	else
		std::cout << "The robotomy of " << this->_target << " has failed ❌" << std::endl;
}