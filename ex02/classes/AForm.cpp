/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 16:27:45 by phhofman          #+#    #+#             */
/*   Updated: 2025/08/28 18:03:07 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include <iostream>

std::ostream &operator<<(std::ostream &os, const AForm &form)
{
	os << "AForm \"" << form.getName() << "\" ["
	   << "sign grade: " << form.getSignGrade()
	   << ", execute grade: " << form.getExecuteGrade()
	   << ", signed: " << (form.isSigned() ? "yes" : "no")
	   << "]";
	return os;
}
const char *AForm::GradeTooHighException::what() const noexcept
{
	return "AForm grade is too high!";
}

const char *AForm::GradeTooLowException::what() const noexcept
{
	return "AForm grade is too low!";
}

const char *AForm::NotSignedException::what() const noexcept
{
	return "AForm is not signed!";
}

AForm::AForm() : _name("Default"), _isSigned(false), _signGrade(1), _executeGrade(1)
{
}

AForm::AForm(const std::string &name, bool isSigned, unsigned short signGrade, unsigned short executeGrade)
	: _name(name),
	  _isSigned(isSigned),
	  _signGrade(signGrade),
	  _executeGrade(executeGrade)
{
	if (signGrade < 1 || executeGrade < 1)
		throw AForm::GradeTooHighException();
	if (signGrade > 150 || executeGrade > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &other) : _name(other._name), _isSigned(false), _signGrade(1), _executeGrade(1)
{
}

AForm::~AForm() {}

AForm &AForm::operator=(const AForm &other)
{
	if (this != &other)
		this->_isSigned = other._isSigned;
	return *this;
}

void AForm::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() > _signGrade)
		throw AForm::GradeTooHighException();
	_isSigned = true;
}

const std::string AForm::getName() const
{
	return _name;
}

bool AForm::isSigned() const
{
	return _isSigned;
}

unsigned short AForm::getSignGrade() const
{
	return _signGrade;
}

unsigned short AForm::getExecuteGrade() const
{
	return _executeGrade;
}

void AForm::execute(Bureaucrat const &executor) const
{
	if (!this->isSigned())
		throw AForm::NotSignedException();
	if (executor.getGrade() > this->getExecuteGrade())
		throw AForm::GradeTooLowException();

	this->executeAction();
}