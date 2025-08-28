/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 16:27:45 by phhofman          #+#    #+#             */
/*   Updated: 2025/08/28 18:03:07 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include <iostream>

std::ostream &operator<<(std::ostream &os, const Form &form)
{
	os << "Form \"" << form.getName() << "\" ["
	   << "sign grade: " << form.getSignGrade()
	   << ", execute grade: " << form.getExecuteGrade()
	   << ", signed: " << (form.isSigned() ? "yes" : "no")
	   << "]";
	return os;
}
class Form::GradeTooHighException : public std::exception
{
public:
	const char *what() const noexcept override
	{
		return "Form grade is too high!";
	}
};

class Form::GradeTooLowException : public std::exception
{
public:
	const char *what() const noexcept override
	{
		return "Form grade is too low!";
	}
};

Form::Form() : _name("Default"), _isSigned(false), _signGrade(1), _executeGrade(1)
{
}

Form::Form(const std::string &name, bool isSigned, unsigned short signGrade, unsigned short executeGrade)
	: _name(name),
	  _isSigned(isSigned),
	  _signGrade(signGrade),
	  _executeGrade(executeGrade)
{
	if (signGrade < 1 || executeGrade < 1)
		throw Form::GradeTooHighException();
	if (signGrade > 150 || executeGrade > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form &other) : _name(other._name), _isSigned(false), _signGrade(1), _executeGrade(1)
{
}

Form::~Form() {}

Form &Form::operator=(const Form &other)
{
	if (this != &other)
		this->_isSigned = other._isSigned;
	return *this;
}

void Form::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() > _signGrade)
		throw Form::GradeTooHighException();
	_isSigned = true;
}

const std::string Form::getName() const
{
	return _name;
}

bool Form::isSigned() const
{
	return _isSigned;
}

unsigned short Form::getSignGrade() const
{
	return _signGrade;
}

unsigned short Form::getExecuteGrade() const
{
	return _executeGrade;
}