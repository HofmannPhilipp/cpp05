/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 10:22:50 by phhofman          #+#    #+#             */
/*   Updated: 2025/09/01 13:18:52 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
private:
	const std::string _name;
	unsigned short _grade;

public:
	class GradeTooHighException;
	class GradeTooLowException;

	Bureaucrat();
	Bureaucrat(const std::string &name, unsigned short grade);
	~Bureaucrat();
	Bureaucrat(const Bureaucrat &other);
	Bureaucrat &operator=(const Bureaucrat &other);

	void signForm(AForm &form);
	void executeForm(AForm const &form) const;

	const std::string getName() const;
	unsigned short getGrade() const;
	void incrementGrade();
	void decrementGrade();
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b);
