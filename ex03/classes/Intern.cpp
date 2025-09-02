/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 14:56:27 by phhofman          #+#    #+#             */
/*   Updated: 2025/09/02 13:07:30 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {};

Intern::Intern(const Intern &other) : Intern()
{
    (void)other;
};

Intern &Intern::operator=(const Intern &other)
{
    (void)other;
    return *this;
}

Intern::~Intern() {};

AForm *Intern::makeForm(const std::string &name, const std::string &target)
{
    std::string formTypes[] = {"shrubbery", "robotomy", "presidential"};

    AForm *(*constructors[])(const std::string &) =
        {
            [](const std::string &target) -> AForm *
            { return new ShrubberyCreationForm(target); },
            [](const std::string &target) -> AForm *
            { return new RobotomyRequestForm(target); },
            [](const std::string &target) -> AForm *
            { return new PresidentialPardonForm(target); },
        };

    for (int i = 0; i < 3; i++)
    {
        if (formTypes[i] == name)
            return constructors[i](target);
    }

    std::cerr << "Error: Unknown form name " << name << std::endl;
    return nullptr;
}