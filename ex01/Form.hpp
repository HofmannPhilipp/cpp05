/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 16:27:52 by phhofman          #+#    #+#             */
/*   Updated: 2025/08/28 17:53:46 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	const std::string _name;
	bool _isSigned;
	const unsigned short _signGrade;
	const unsigned short _executeGrade;

public:
	class GradeTooHighException;
	class GradeTooLowException;

	Form();
	Form(const std::string &name, bool isSigned, unsigned short signGrade, unsigned short executeGrade);
	~Form();
	Form(const Form &other);
	Form &operator=(const Form &other);

	void beSigned(const Bureaucrat &b);

	const std::string getName() const;
	bool isSigned() const;
	unsigned short getSignGrade() const;
	unsigned short getExecuteGrade() const;
};

std::ostream &operator<<(std::ostream &os, const Form &form);
