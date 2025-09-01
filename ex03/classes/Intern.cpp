/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 14:56:27 by phhofman          #+#    #+#             */
/*   Updated: 2025/09/01 15:27:30 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {};

Intern::Intern(const Intern &other) : Intern() {};

Intern &Intern::operator=(const Intern &other)
{
    return *this;
}

Intern::~Intern() {};

AForm *Intern::makeForm(const std::string &name, const std::string &target)
{
    std::string levels[] = {"shrubbery", "robotomy", "presidential"};

    for (int i = 0; i < 3; i++)
    {
        if (levels[i] == name)
        {
            switch (i)
            {
            case 0:
                std::cout << "Intern creates ShrubberyCreationForm" << std::endl;
                return new ShrubberyCreationForm(target);
            case 1:
                std::cout << "Intern creates RobotomyRequestForm" << std::endl;
                return new RobotomyRequestForm(target);
            case 2:
                std::cout << "Intern creates PresidentialPardonForm" << std::endl;
                return new PresidentialPardonForm(target);
            }
        }
    }

    std::cerr << "Error: Unknown form name " << name << std::endl;
    return nullptr;
}