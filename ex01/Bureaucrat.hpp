/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 10:22:50 by phhofman          #+#    #+#             */
/*   Updated: 2025/08/28 17:49:45 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include "Form.hpp"

class Form;

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

	void signForm(Form &form);

	const std::string getName() const;
	unsigned short getGrade() const;
	void incrementGrade();
	void decrementGrade();
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b);
