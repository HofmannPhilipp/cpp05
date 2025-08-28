/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phhofman <phhofman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 10:22:50 by phhofman          #+#    #+#             */
/*   Updated: 2025/08/28 10:38:41 by phhofman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>

class Bureaucrat
{
private:
	const std::string _name;
	unsigned short _grade;

public:
	Bureaucrat();
	Bureaucrat(const std::string &name, unsigned short &grade);
	~Bureaucrat();
	Bureaucrat(const Bureaucrat &other);
	Bureaucrat &operator=(const Bureaucrat &other);

	const std::string getName() const;
	unsigned short getGrade() const;
	void incrementGrade();
	void decrementGrade();
};