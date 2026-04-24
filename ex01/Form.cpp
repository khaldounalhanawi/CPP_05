/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalhanaw <kalhanaw@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 10:00:40 by kalhanaw          #+#    #+#             */
/*   Updated: 2026/04/24 10:47:58 by kalhanaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
# include "Bureaucrat.hpp"

// ________________________ Constructors / destructor ________________________ //

Form::Form(std::string name, int signatureGrade, int executionGrade):
_name(name),
_signatureGrade(signatureGrade),
_executionGrade(executionGrade),
_signatureStatus (false)
{
	if (signatureGrade < 1 || executionGrade < 1)
		throw Form::GradeTooLowException ();
	else if (signatureGrade > 150 || executionGrade > 150)
		throw Form::GradeTooHighException ();
	
	std::cout	<< this->_name	<< " has been created!"
				<< std::endl;
	return ;
}

Form::Form(const Form& other):
_name (other.getName() + "_copy"),
_signatureGrade(other.getSignatureGrade ()),
_executionGrade(other.getExecutionGrade ())
{
	this->_signatureStatus = other.getSignatureStatus ();
	return ;
}

Form::~Form()
{
	return;
}

// ________________________ Operator overloads ________________________ //


Form	&Form::operator=(const Form& source)
{
	if (this != &source)
		this->_signatureStatus = source.getSignatureStatus ();
	return *this;
}

std::ostream	&operator<<(std::ostream &os, Form &form)
{
	return (os	<< "Name: "				<< form.getName ()
				<< "\nSignature status: "	<< form.getSignatureStatus ()
				<< "\nSignature grade: "	<< form.getSignatureGrade ()
				<< "\nExecution grade: "	<< form.getExecutionGrade ());
}

// ________________________ Setter & Getters ________________________ //

const std::string	&Form::getName() const
{
	return (this->_name);
}

const int			&Form::getSignatureGrade() const
{
	return (this->_signatureGrade);
}

const int			&Form::getExecutionGrade() const
{
	return (this->_executionGrade);
}

bool				Form::getSignatureStatus() const
{
	return (this->_signatureStatus);
}

// ________________________ Member functions ________________________ //

void	Form::beSigned(Bureaucrat &agent)
{
	if (agent.getGrade () > this->_signatureGrade)
		throw Form::GradeTooLowException ();

	this->_signatureStatus = true;
	return ;
}

// ________________________ Exception functions ________________________ //

const char *Form::GradeTooLowException::what() const throw ()
{
	return	"Grade too LOW:"
			"it has to be higher than 0 and smaller/equal to 150!";
}

const char *Form::GradeTooHighException::what() const throw ()
{
	return	"Grade too HIGH:\n"
			"it has to be higher than 0 and smaller/equal to 150!";
}