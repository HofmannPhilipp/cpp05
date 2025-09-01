/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 11:37:56 by phhofman          #+#    #+#             */
/*   Updated: 2025/09/01 14:38:17 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm::AForm("PresidentialPardonForm", false, 25, 5), _target("Default_Target")
{
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
    : AForm::AForm("PresidentialPardonForm", false, 25, 5), _target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm::AForm(other), _target(other._target)
{
}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        this->_target = other._target;
    }
    return *this;
}

void PresidentialPardonForm::executeAction() const
{
    std::cout << this->_target
              << " has been pardoned by Zaphod Beeblebrox 👽✨"
              << std::endl;
}