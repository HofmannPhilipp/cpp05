/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 11:37:56 by phhofman          #+#    #+#             */
/*   Updated: 2025/09/01 11:42:08 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm::AForm("Default", false, 25, 5)
{
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
    : AForm::AForm(target, false, 145, 137)
{
    // if (signGrade < 1 || executeGrade < 1)
    // 	throw PresidentialPardonForm::GradeTooHighException();
    // if (signGrade > 150 || executeGrade > 150)
    // 	throw PresidentialPardonForm::GradeTooLowException();
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm::AForm(other)
{
}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
    if (this != &other)
        AForm::operator=(other);
    return *this;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
    if (this != &other)
        AForm::operator=(other);
    return *this;
}

void PresidentialPardonForm::executeAction() const
{
    std::cout << this->getName()
              << " has been pardoned by Zaphod Beeblebrox 👽✨"
              << std::endl;
}