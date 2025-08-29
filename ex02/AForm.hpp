/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 16:27:52 by phhofman          #+#    #+#             */
/*   Updated: 2025/08/29 13:22:18 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
	const std::string _name;
	bool _isSigned;
	const unsigned short _signGrade;
	const unsigned short _executeGrade;

public:
	class GradeTooHighException : public std::exception
	{
	public:
		const char *what() const noexcept override;
	};

	class GradeTooLowException : public std::exception
	{
	public:
		const char *what() const noexcept override;
	};

	class NotSignedException : public std::exception
	{
	public:
		const char *what() const noexcept override;
	};

	AForm();
	AForm(const std::string &name, bool isSigned, unsigned short signGrade, unsigned short executeGrade);
	virtual ~AForm();
	AForm(const AForm &other);
	AForm &operator=(const AForm &other);

	void beSigned(const Bureaucrat &b);
	void execute(Bureaucrat const &executor) const;
	virtual void executeAction() const = 0;

	const std::string getName() const;
	bool isSigned() const;
	unsigned short getSignGrade() const;
	unsigned short getExecuteGrade() const;
};

std::ostream &operator<<(std::ostream &os, const AForm &form);
